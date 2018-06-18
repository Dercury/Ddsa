/******************************************************************************/
/**
* @file        func_rtn.c
* @brief       function returned value
* @version     0.0.1
* @author      dercury
* @date        2015-5-24
*/
/******************************************************************************/

/***************************** include files **********************************/
#include "func_rtn.h"

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
char* func_rtn_to_str(const FuncRtn rtn)
{
    char* str[] = {
        "OK",
        "ERROR",
        "PARAM_NULL_PTR",
        "PARAM_MIN",
        "PARAM_MAX",
        "PARAM_RANGE",
        "PARAM_EQUAL",
        "PARAM_UNEQUAL",
        "PARAM_ELSE",
        "NULL_POINTER",
        "MEMORY_ALLOC",
        "NOT_EXIST",
        "ALREADY_EXIST",
        "UNREACHABLE",
        "SPACE_FULL",
        "SPACE_EMPTY",
        "FILE_OPEN",
        "UNDEFINED"
        };
    return str[rtn];
}

/******************************************************************************/

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

