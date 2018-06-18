/******************************************************************************/
/**
* @file        macro.c
* @brief       macro definition
* @version     0.0.1
* @author      dercury
* @date        2015-5-24
*/
/******************************************************************************/

#include "macro.h"

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
static OutputFunc g_output_func = (OutputFunc)printf;

/******************************************************************************/
void set_output_func(OutputFunc func)
{
    if (NULL != func)
    {
        g_output_func = func;
    }

    return;
}

/******************************************************************************/
OutputFunc get_output_func(void)
{
    return g_output_func;
}

/******************************************************************************/

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

