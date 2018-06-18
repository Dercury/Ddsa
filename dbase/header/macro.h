/******************************************************************************/
/**
 * @file          macro.h
 * @brief         macro definition
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef _MACRO_H
#define _MACRO_H 1

/***************************** include files **********************************/
#include "func_ptr.h"
#include "func_rtn.h"

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#ifndef CODE_SEPARATOR
#define CODE_SEPARATOR(tag, enable)         (enable)
#endif

/******************************************************************************/
typedef PrintfFunc OutputFunc;

/******************************************************************************/
/**
 * @func          void set_output_func(OutputFunc func)
 * @brief         set user-defined output function
 * @param[in]     OutputFunc func: user-defined output function, can't be NULL
 * @return        void
 * @complexity    O(1)
 * @notes         If no output function is specified, 'printf' will be used.
 */
/******************************************************************************/
extern void set_output_func(OutputFunc func);

/******************************************************************************/
/**
 * @func          OutputFunc get_output_func(void)
 * @brief         get user-defined output function
 * @param[in]     void
 * @return        OutputFunc func: user-defined output function
 * @complexity    O(1)
 * @notes         If no output function is specified, 'printf' will be used.
 */
/******************************************************************************/
extern OutputFunc get_output_func(void);

/******************************************************************************/
/*                             return check                                   */
/******************************************************************************/
#define IF_ERROR_EXIT(ret) \
    do \
    { \
        FuncRtn _inner_rtn = (ret); \
        if (_inner_rtn != FUNC_OK) \
        { \
            get_output_func()(#ret" fail: %s!\n", func_rtn_to_str(_inner_rtn)); \
            exit(_inner_rtn); \
        } \
    } while (0)

/******************************************************************************/
#define IF_ERROR_RETURN(ret) \
    do \
    { \
        FuncRtn _inner_rtn = (ret); \
        if (_inner_rtn != FUNC_OK) \
        { \
            get_output_func()(#ret" fail: %s!\n", func_rtn_to_str(_inner_rtn)); \
            return (_inner_rtn); \
        } \
    } while (0)

/******************************************************************************/
#define IF_ERROR_BREAK(ret) \
    do \
    { \
        FuncRtn _inner_rtn = (ret); \
        if (_inner_rtn != FUNC_OK) \
        { \
            get_output_func()(#ret" fail: %s!\n", func_rtn_to_str(_inner_rtn)); \
            break; \
        } \
    } while (0)

/******************************************************************************/
#define IF_ERROR_PRINT(ret) \
    do \
    { \
        FuncRtn _inner_rtn = (ret); \
        if (_inner_rtn != FUNC_OK) \
        { \
            get_output_func()(#ret" fail: %s!\n", func_rtn_to_str(_inner_rtn)); \
        } \
    } while (0)

/******************************************************************************/
/*                              param check                                   */
/******************************************************************************/
#define PARAM_CHECK_NULL_POINTER(param) \
    do \
    { \
        if ((param) == NULL) \
        { \
            get_output_func()(#param" is NULL pointer!\n"); \
            return FUNC_PARAM_NULL_POINTER; \
        } \
    } while (0)

/******************************************************************************/
#define PARAM_CHECK_MIN(param, min) \
    do \
    { \
        if ((param) < (min)) \
        { \
            get_output_func()(#param" is less than "#min"!\n"); \
            return FUNC_PARAM_MIN; \
        } \
    } while (0)

/******************************************************************************/
#define PARAM_CHECK_MAX(param, max) \
    do \
    { \
        if ((param) > (max)) \
        { \
            get_output_func()(#param" is more than "#max"!\n"); \
            return FUNC_PARAM_MAX; \
        } \
    } while (0)

/******************************************************************************/
#define PARAM_CHECK_RANGE(param, min, max) \
    do \
    { \
        if ((param) < (min) || (param) > (max)) \
        { \
            get_output_func()(#param" is out of range ["#min", "#max"]!\n"); \
            return FUNC_PARAM_RANGE; \
        } \
    } while (0)

/******************************************************************************/
#define PARAM_CHECK_EQUAL(param, referent) \
    do \
    { \
        if ((param) != (referent)) \
        { \
            get_output_func()(#param" is equal to "#referent"!\n"); \
            return FUNC_PARAM_UNEQUAL; \
        } \
    } while (0)

/******************************************************************************/
#define PARAM_CHECK_UNEQUAL(param, referent) \
    do \
    { \
        if ((param) == (referent)) \
        { \
            get_output_func()(#param" is not equal to "#referent"!\n"); \
            return FUNC_PARAM_EQUAL; \
        } \
    } while (0)

/******************************************************************************/
/*                              data compare                                  */
/******************************************************************************/
#define GET_MORE(data0, data1)      ((data0) > (data1) ? (data0) : (data1))
#define GET_LESS(data0, data1)      ((data0) < (data1) ? (data0) : (data1))

/******************************************************************************/
#ifndef ARRAY_SIZE
#define ARRAY_SIZE(array)   (sizeof(array) / sizeof((array)[0]))
#endif

/******************************************************************************/

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

#endif // _MACRO_H

