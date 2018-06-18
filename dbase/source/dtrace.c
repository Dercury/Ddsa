/******************************************************************************/
/**
 * @file        dtrace.c
 * @brief       trace
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/

#include <assert.h>
#include "bool.h"
#include "dtrace.h"
#include "macro.h"
#include <stdio.h>      /* fprintf sprintf */
#include <stdlib.h>     /* memset */
#include <string.h>     /* strncat */
#include <str_op.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
/*                             Trace Level                                    */
/******************************************************************************/
char* trace_level_to_str(const TraceLevel level)
{
    char* str[] = {
        "CLOSE",
        "ERROR",
        "WARN",
        "INFO",
        "ALL"
    };
    return str[level];
}

/******************************************************************************/
/*                             Print Trace                                    */
/******************************************************************************/
static TraceLevel g_print_level = TRACE_ERROR;

/******************************************************************************/
void set_print_level(const TraceLevel level)
{
    g_print_level = level;

    return;
}

/******************************************************************************/
TraceLevel get_print_level(void)
{
    return g_print_level;
}

/******************************************************************************/
static PrintfFunc g_print_func = (PrintfFunc)printf;

/******************************************************************************/
void set_print_func(const PrintfFunc func)
{
    g_print_func = func;

    return;
}

/******************************************************************************/
PrintfFunc get_print_func(void)
{
    return g_print_func;
}

/******************************************************************************/
/*                             Log Trace                                      */
/******************************************************************************/
#define LOG_FILENAME_LEN    36
static TraceLevel g_log_level                      = TRACE_CLOSE;
static Bool       g_log_is_open                    = FALSE;
static char       g_log_filename[LOG_FILENAME_LEN] = {0};
static FILE*      g_log_file                       = NULL;

/******************************************************************************/
void default_log_filename(char* name_buffer, size_t buffer_len)
{
    char time_str[CUR_TIME_STR_MIN_LEN] = {0};

    (void)cur_time_string(time_str, CUR_TIME_STR_MIN_LEN);
    strncat(name_buffer, time_str, CUR_TIME_STR_MIN_LEN);
    strncat(name_buffer, ".log", 4);

    return;
}

/******************************************************************************/
void set_log_level(TraceLevel level)
{
    char filename[36] = "log_";

    if ((level > TRACE_CLOSE) && (g_log_is_open == FALSE))
    {
        /* open log file */
        if (get_log_filename(filename, LOG_FILENAME_LEN) <= 0)
        {
            default_log_filename(filename, LOG_FILENAME_LEN);
        }

        g_log_file = fopen(filename, "w+");
        if (NULL == g_log_file)
        {
            exit(EXIT_FAILURE);
        }
        g_log_is_open = TRUE;
    }
    else if ((level == TRACE_CLOSE) && (TRUE == g_log_is_open))
    {
        /* close log file */
        if (fclose(g_log_file))
        {
            exit(EXIT_FAILURE);
        }
        g_log_is_open = FALSE;
        memset(g_log_filename, 0, sizeof(g_log_filename));
    }

    g_log_level = level;

    return;
}

/******************************************************************************/
TraceLevel get_log_level(void)
{
    return g_log_level;
}

/******************************************************************************/
static FprintfFunc g_log_func = (FprintfFunc)fprintf;

/******************************************************************************/
void set_log_func(const FprintfFunc func)
{
    g_log_func = func;

    return;
}

/******************************************************************************/
FprintfFunc get_log_func(void)
{
    return g_log_func;
}

/******************************************************************************/
/*                             Log File                                       */
/******************************************************************************/
void set_log_filename(const char* filename)
{
    size_t filename_len = 0;

    assert(filename != NULL);
    
    filename_len = GET_LESS(strlen(filename), LOG_FILENAME_LEN - 1);
    (void)snprintf(g_log_filename, filename_len, "%s", filename);

    return;
}

/******************************************************************************/
int get_log_filename(char* name_buffer, size_t buffer_len)
{
    assert(name_buffer != NULL);

    return snprintf(name_buffer, buffer_len - 1, "%s", g_log_filename);
}

/******************************************************************************/
/*                              Trace Functions                               */
/******************************************************************************/
#define MAX_STR_LEN      10240
/******************************************************************************/
int vtrace(char* format, va_list args)
{
    int num;
    char str_buffer[MAX_STR_LEN] = {0};

    num = vsnprintf(str_buffer, MAX_STR_LEN - 1, format, args);

    if (g_print_level != TRACE_CLOSE && g_print_func != NULL)
    {
        g_print_func("%s", str_buffer);
    }
    
    if (g_log_level != TRACE_CLOSE && g_log_func != NULL)
    {
        g_log_func(g_log_file, "%s", str_buffer);
    }

    return num;
}

/******************************************************************************/
int trace(char* format, ...)
{
    int num;
    va_list args;

    va_start(args, format);
    num = vtrace(format, args);
    va_end(args);

    return num;
}

/******************************************************************************/
int vtrace_with_pos(char* file, char* func, size_t line, char* format, va_list args)
{
    int num;

    num = trace(DTRACE_POS_FORMAT, file, func, line);
    num += vtrace(format, args);

    return num;
}

/******************************************************************************/
int trace_with_pos(char* file, char* func, size_t line, char* format, ...)
{
    int num;
    va_list args;

    va_start(args, format);
    num = vtrace_with_pos(file, func, line, format, args);
    va_end(args);

    return num;
}

/******************************************************************************/
int vtrace_with_level(TraceLevel level, char* format, va_list args)
{
    int num;

    num = trace(DTRACE_LEVEL_FORMAT, trace_level_to_str(level));
    num += vtrace(format, args);

    return num;
}

/******************************************************************************/
int trace_with_level(TraceLevel level, char* format, ...)
{
    int num;
    va_list args;

    va_start(args, format);
    num = vtrace_with_level(level, format, args);
    va_end(args);

    return num;
}

/******************************************************************************/
int vtrace_with_pos_level(char* file, char* func, size_t line, TraceLevel level, char* format, va_list args)
{
    int num;

    num = trace(DTRACE_POS_LEVEL_FORMAT, file, func, line, trace_level_to_str(level));
    num += vtrace(format, args);

    return num;
}

/******************************************************************************/
int trace_with_pos_level(char* file, char* func, size_t line, TraceLevel level, char* format, ...)
{
    int num;
    va_list args;

    va_start(args, format);
    num = vtrace_with_pos_level(file, func, line, level, format, args);
    va_end(args);

    return num;
}

/******************************************************************************/
char* get_color_fmt_str(Color color)
{
    char* str[] = {
        "\033[0m"   , // NORMAL 
        "\033[30m"  , // BLACK  
        "\033[1;30m", // GRAY   
        "\033[1;31m", // RED    
        "\033[1;32m", // GREEN  
        "\033[1;33m", // YELLOW 
        "\033[1;34m", // BLUE   
        "\033[1;35m", // MAGENTA
        "\033[1;36m", // AQUA   
        "\033[1;37m", // WHITE  
        "\033[5m"   , // BLINK  
    };

    return str[color];
}

/******************************************************************************/
int vtrace_with_color(Color color, char* format, va_list args)
{
    int num;
    char str_buffer[MAX_STR_LEN] = {0};
    char* color_str = get_color_fmt_str(color);
    size_t color_len = strlen(color_str);
    char fmt_buffer[MAX_STR_LEN] = {0};

    /* print to stdout with color */
    (void)strncat(fmt_buffer, color_str, color_len);
    (void)strncat(fmt_buffer, format, MAX_STR_LEN - 1 - color_len);
    (void)vsnprintf(str_buffer, MAX_STR_LEN - 1, fmt_buffer, args);
    if (g_print_level != TRACE_CLOSE && g_print_func != NULL)
    {
        g_print_func("%s", str_buffer);
    }
    
    /* Color is NOT supported in log files. */
    num = vsnprintf(str_buffer, MAX_STR_LEN - 1, format, args);
    if (g_log_level != TRACE_CLOSE && g_log_func != NULL)
    {
        g_log_func(g_log_file, "%s", str_buffer);
    }

    return num;
}

/******************************************************************************/
int trace_with_color(Color color, char* format, ...)
{
    int num;
    va_list args;

    va_start(args, format);
    num = vtrace_with_color(color, format, args);
    va_end(args);

    return num;
}

/******************************************************************************/
int vtrace_with_pos_color(char* file, char* func, size_t line, Color color, char* format, va_list args)
{
    int num;

    num = trace_with_color(color, DTRACE_POS_FORMAT, file, func, line);
    num += vtrace_with_color(color, format, args);

    return num;
}

/******************************************************************************/
int trace_with_pos_color(char* file, char* func, size_t line, Color color, char* format, ...)
{
    int num;
    va_list args;

    va_start(args, format);
    num = vtrace_with_pos_color(file, func, line, color, format, args);
    va_end(args);

    return num;
}

/******************************************************************************/
int vtrace_with_level_color(TraceLevel level, Color color, char* format, va_list args)
{
    int num;

    num = trace_with_color(color, DTRACE_LEVEL_FORMAT, trace_level_to_str(level));
    num += vtrace_with_color(color, format, args);

    return num;
}

/******************************************************************************/
int trace_with_level_color(TraceLevel level, Color color, char* format, ...)
{
    int num;
    va_list args;

    va_start(args, format);
    num = vtrace_with_level_color(level, color, format, args);
    va_end(args);

    return num;
}

/******************************************************************************/
int vtrace_with_pos_level_color(char* file, char* func, size_t line, TraceLevel level, Color color, char* format, va_list args)
{
    int num;

    num = trace_with_color(color, DTRACE_POS_LEVEL_FORMAT, file, func, line, trace_level_to_str(level));
    num += vtrace_with_color(color, format, args);

    return num;
}

/******************************************************************************/
int trace_with_pos_level_color(char* file, char* func, size_t line, TraceLevel level, Color color, char* format, ...)
{
    int num;
    va_list args;

    va_start(args, format);
    num = vtrace_with_pos_level_color(file, func, line, level, color, format, args);
    va_end(args);

    return num;
}

/******************************************************************************/
/*                               Color                                        */
/******************************************************************************/
static Color g_trace_level_color[] =
{
    COLOR_NORMAL,       // TRACE_CLOSE
    COLOR_RED,          // TRACE_ERROR
    COLOR_YELLOW,       // TRACE_WARN
    COLOR_GREEN,        // TRACE_INFO
    COLOR_BLUE          // TRACE_ALL
};

/******************************************************************************/
Color get_trace_level_color(TraceLevel level)
{
    assert(level <= TRACE_ALL);

    return g_trace_level_color[level];
}

/******************************************************************************/
void set_trace_level_color(TraceLevel level, Color color)
{
    assert(level <= TRACE_ALL);

    g_trace_level_color[level] = color;

    return;
}

/******************************************************************************/
int trace_with_pos_colored_level(char* file, char* func, size_t line, TraceLevel level, char* format, ...)
{
    int num;
    va_list args;
    Color color = get_trace_level_color(level);

    va_start(args, format);
    num = vtrace_with_pos_level_color(file, func, line, level, color, format, args);
    va_end(args);

    return num;
}

/******************************************************************************/
/*                              Trace Functions                               */
/******************************************************************************/
char trace_getchar(void)
{
    char ch = getchar();

    (void)getchar();
    if (g_log_level != TRACE_CLOSE && g_log_func != NULL)
    {
        g_log_func(g_log_file, "%c\n", ch);
    }

    return ch;
}

/******************************************************************************/
int trace_getint(void)
{
    int i = 0;
    
    scanf("%d", &i);
    (void)getchar();
    if (g_log_level != TRACE_CLOSE && g_log_func != NULL)
    {
        g_log_func(g_log_file, "%d\n", i);
    }

    return i;
}

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

