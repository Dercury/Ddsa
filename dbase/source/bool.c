/******************************************************************************/
/**
* @file        bool.c
* @brief       boolean type
* @version     0.0.1
* @author      dercury
* @date        2015-5-24
*/
/******************************************************************************/

#include "bool.h"

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
char* bool_to_str(const Bool value)
{
    char* str[] = {
        "FALSE",
        "TRUE",
        };
    return str[value];
}

/******************************************************************************/

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

