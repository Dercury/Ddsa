/******************************************************************************/
/**
 * @file          dtrace_win32.h
 * @brief         trace for win32
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef DTRACE_WIN32_H
#define DTRACE_WIN32_H 1

/******************************************************************************/
#include <windows.h>
/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#define DTRACE_LEVEL(level, format, ...) \
    do \
    { \
        if ((get_trace_type() & TRACE_PRINT) && (level) >= get_print_level()) \
        { \
            printf("%s: " format, trace_level_to_str(level), __VA_ARGS__); \
        } \
        if ((get_trace_type() & TRACE_LOG) && (level) >= get_log_level()) \
        { \
            fprintf(get_log_file(), "%s: " format, trace_level_to_str(level), __VA_ARGS__); \
        } \
    } while(0)

/******************************************************************************/
#define DPRINT_POS(format, ...) \
    printf("<file: %s, function: %s, line: %u>\r\n" format, \
            SHORT_FILENAME, __FUNCTION__, __LINE__, __VA_ARGS__)

#define DLOG_POS(format, ...) \
    fprintf(get_log_file(), "<file: %s, function: %s, line: %u>\r\n" format, \
            SHORT_FILENAME, __FUNCTION__, __LINE__, __VA_ARGS__)

#define DTRACE_POS_LEVEL(level, format, ...) \
    do \
    { \
        if ((get_trace_type() & TRACE_PRINT) && (level) >= get_print_level()) \
        { \
            DPRINT_POS("%s: " format, trace_level_to_str(level), __VA_ARGS__);\
        } \
        if ((get_trace_type() & TRACE_LOG) && (level) >= get_log_level()) \
        { \
            DLOG_POS("%s: " format, trace_level_to_str(level), __VA_ARGS__); \
        } \
    } while(0)

/******************************************************************************/
#define COLOR_NORMAL    FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
#define COLOR_BLACK     0
#define COLOR_GRAY      0              // ?
#define COLOR_RED       FOREGROUND_RED
#define COLOR_GREEN     FOREGROUND_GREEN
#define COLOR_YELLOW    FOREGROUND_RED | FOREGROUND_GREEN
#define COLOR_BLUE      FOREGROUND_BLUE
#define COLOR_MAGENTA   FOREGROUND_RED | FOREGROUND_BLUE
#define COLOR_AQUA      FOREGROUND_GREEN | FOREGROUND_BLUE
#define COLOR_WHITE     FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
#define COLOR_BLINK     FOREGROUND_INTENSITY

/*******************************************************************************/
/**
 * @func          BOOL SetConsoleColor(WORD wAttribute)
 * @brief         SetConsoleColor
 * @param[in]     WORD wAttribute:
 * @return        BOOL:
 * @complexity    O(?)
 * @notes         nothing
 */
/*******************************************************************************/
BOOL SetConsoleColor(WORD wAttribute);

/******************************************************************************/
#define DPRINT_COLOR(color, format, ...) \
    do \
    { \
        SetConsoleColor(color); \
        printf(format, __VA_ARGS__); \
        SetConsoleColor(COLOR_NORMAL); \
    } while(0)

#define DPRINT_POS_COLOR(color, format, ...) \
    do \
    { \
        SetConsoleColor(color); \
        DPRINT_POS(format, __VA_ARGS__); \
        SetConsoleColor(COLOR_NORMAL); \
    } while(0)

#define DPRINT_LEVEL_COLOR(level, format, ...) \
    do \
    { \
        switch (level) \
        { \
        case TRACE_ERROR: \
            SetConsoleColor(COLOR_RED); \
            break; \
        case TRACE_WARN: \
            SetConsoleColor(COLOR_YELLOW); \
            break; \
        case TRACE_INFO: \
            SetConsoleColor(COLOR_GREEN); \
            break; \
        default: \
            SetConsoleColor(COLOR_NORMAL); \
            break; \
        } \
        DTRACE_POS_LEVEL(level, format, __VA_ARGS__); \
        SetConsoleColor(COLOR_NORMAL); \
    } while(0)

/******************************************************************************/

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

#endif // DTRACE_WIN32_H

