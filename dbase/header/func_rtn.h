/******************************************************************************/
/**
 * @file          func_rtn.h
 * @brief         function returned value
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef _FUNC_RTN_H
#define _FUNC_RTN_H 1

/***************************** include files **********************************/

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
/**
 * @agreement   Every function should return a value except very special ones.
 */
/******************************************************************************/
typedef enum tagFuncRtn
{
    FUNC_OK = 0,
    FUNC_ERROR,                 // common error
    FUNC_PARAM_NULL_POINTER,
    FUNC_PARAM_MIN,
    FUNC_PARAM_MAX,
    FUNC_PARAM_RANGE,
    FUNC_PARAM_EQUAL,
    FUNC_PARAM_UNEQUAL,
    FUNC_PARAM_ELSE,
    FUNC_NULL_POINTER,
    FUNC_MEMORY_ALLOC,
    FUNC_NOT_EXIST,
    FUNC_ALREADY_EXIST,
    FUNC_UNREACHABLE,
    FUNC_SPACE_FULL,
    FUNC_SPACE_EMPTY,
    FUNC_FILE_OPEN,
    FUNC_UNDEFINED,
} FuncRtn;

/******************************************************************************/
/**
 * @func          char* func_rtn_to_str(FuncRtn rtn)
 * @brief         change function returned value to string
 * @param[in]     FuncRtn rtn: function returned value
 * @return        char*: string of function returned value
 * @complexity    O(1)
 * @notes         nothing
 */
/******************************************************************************/
extern char* func_rtn_to_str(const FuncRtn rtn);

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif // _FUNC_RTN_H

