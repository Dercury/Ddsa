/******************************************************************************/
/**
 * @file          dtrace.h
 * @brief         trace and record runtime information for debug
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef DTRACE_H
#define DTRACE_H 1

/***************************** include files **********************************/
#include "func_ptr.h"
#include "func_rtn.h"
#include <stdarg.h>
#include "str_op.h"

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
/* 
 * Tracing has some different types(ways), such as print, log.
 * Each type can record info in different levels, such as error, warn, info.
 *
 * Tracing functions provided here should be easy to build OutputFunc:
 *     typedef int (*OutputFunc)(char* format, ...);
 */
/******************************************************************************/

/******************************************************************************/
/*                             Trace Level                                    */
/******************************************************************************/
typedef enum tagTraceLevel
{
    TRACE_CLOSE = 0,    // close trace
    TRACE_ERROR,        // error only
    TRACE_WARN,         // error and warn
    TRACE_INFO,         // error, warn and info
    TRACE_ALL,          // equals TRACE_INFO now
} TraceLevel;

/******************************************************************************/
/**
 * @func          char* trace_level_to_str(TraceLevel level)
 * @brief         TraceLevel to string
 * @param[in]     TraceLevel level:
 * @return        char*:
 * @complexity    O(1)
 * @notes         nothing
 */
/******************************************************************************/
extern char* trace_level_to_str(const TraceLevel level);

/******************************************************************************/
/*                             Print Trace                                    */
/******************************************************************************/
extern void set_print_level(const TraceLevel level);
extern TraceLevel get_print_level(void);

/******************************************************************************/
extern void set_print_func(const PrintfFunc func);
extern PrintfFunc get_print_func(void);

/******************************************************************************/
/*                             Log Trace                                      */
/******************************************************************************/
extern void set_log_level(const TraceLevel level);
extern TraceLevel get_log_level(void);

/******************************************************************************/
extern void set_log_func(const FprintfFunc func);
extern FprintfFunc get_log_func(void);

/******************************************************************************/
/*                             Log File                                       */
/******************************************************************************/
extern void set_log_filename(const char* filename);
extern int get_log_filename(char* name_buffer, size_t buffer_len);

/******************************************************************************/
/*                               Color                                        */
/******************************************************************************/
typedef enum tagColor
{
    COLOR_NORMAL ,
    COLOR_BLACK  ,
    COLOR_GRAY   ,
    COLOR_RED    ,
    COLOR_GREEN  ,
    COLOR_YELLOW ,
    COLOR_BLUE   ,
    COLOR_MAGENTA,
    COLOR_AQUA   ,
    COLOR_WHITE  ,
    COLOR_BLINK  
} Color;

/******************************************************************************/
/*                               Trace Functions                              */
/******************************************************************************/
#define DTRACE_POS_FORMAT   "<file: %s, func: %s, line: %u>: "
#define DTRACE_POS_ARGS     SHORT_FILENAME, (char*)__FUNCTION__, __LINE__

#define DTRACE_LEVEL_FORMAT "[%s]: "

#define DTRACE_POS_LEVEL_FORMAT "<file: %s, func: %s, line: %u>[%s]: "

/******************************************************************************/
/* Trace: Print, log                                                         */
/* Pos  : file, function, line                                                */
/* Debug: level                                                               */
/* Color: red, blue, green, ...                                               */
/******************************************************************************/
extern int trace(char* format, ...);
extern int trace_with_pos(char* file, char* func, size_t line, char* format, ...);
extern int trace_with_level(TraceLevel level, char* format, ...);
extern int trace_with_color(Color color, char* format, ...);
extern int trace_with_pos_level(char* file, char* func, size_t line, TraceLevel level, char* format, ...);
extern int trace_with_pos_color(char* file, char* func, size_t line, Color color, char* format, ...);
extern int trace_with_level_color(TraceLevel level, Color color, char* format, ...);
extern int trace_with_pos_level_color(char* file, char* func, size_t line, TraceLevel level, Color color, char* format, ...);

/******************************************************************************/
#define DTRACE      trace

#define DTRACE_LEVEL    trace_with_level

#define DTRACE_COLOR    trace_with_color

#define DTRACE_LEVEL_COLOR  trace_with_level_color

#define DTRACE_POS(format, args...) \
    trace_with_pos(DTRACE_POS_ARGS, format, ##args)

#define DTRACE_POS_LEVEL(level, format, args...) \
    trace_with_pos_level(DTRACE_POS_ARGS, level, format, ##args)

#define DTRACE_POS_COLOR(color, format, args...) \
    trace_with_pos_color(DTRACE_POS_ARGS, color, format, ##args)

#define DTRACE_POS_LEVEL_COLOR(level, color, format, args...) \
    trace_with_pos_level_color(DTRACE_POS_ARGS, level, color, format, ##args)

/******************************************************************************/
/*                               Colored Trace Level                          */
/******************************************************************************/
/* Default map between TraceLevel and Color */
/*   TRACE_CLOSE   <=>   COLOR_NORMAL   */
/*   TRACE_ERROR   <=>   COLOR_RED      */
/*   TRACE_WARN    <=>   COLOR_YELLOW   */
/*   TRACE_INFO    <=>   COLOR_GREEN    */
/*   TRACE_ALL     <=>   COLOR_BLUE     */
/******************************************************************************/
extern Color get_trace_level_color(const TraceLevel level);
extern void set_trace_level_color(const TraceLevel level, Color color);

extern int trace_with_pos_colored_level(char* file, char* func, size_t line, TraceLevel level, char* format, ...);
#define DTRACE_POS_COLORED_LEVEL(level, format, args...) \
    trace_with_pos_colored_level(DTRACE_POS_ARGS, level, format, ##args)

/******************************************************************************/
/*                              Trace Functions                               */
/******************************************************************************/
extern char trace_getchar(void);

/******************************************************************************/
extern int trace_getint(void);

/******************************************************************************/
#ifdef OS_LINUX
#include "dtrace_linux.h"
#endif // OS_LINUX

#ifdef OS_WIN32
#include "dtrace_win32.h"
#endif // OS_WIN32

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

#endif // DTRACE_H

