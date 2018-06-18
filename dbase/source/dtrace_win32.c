/******************************************************************************/
/**
 * @file        dtrace.c
 * @brief       trace
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/

#include "dtrace.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

#ifdef OS_WIN32
/******************************************************************************/
BOOL SetConsoleColor(WORD wAttribute)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (INVALID_HANDLE_VALUE == hConsole)
    {
        return FALSE;
    }

    return SetConsoleTextAttribute(hConsole, wAttribute);
}
/******************************************************************************/
#endif // OS_WIN32

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

