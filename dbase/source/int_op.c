/******************************************************************************/
/**
* @file        dtype.c
* @brief       type
* @version     0.0.1
* @author      dercury
* @date        2015-5-24
*/
/******************************************************************************/

#include "int_op.h"
#include <stdio.h>    /* printf */
#include <stdlib.h>   /* exit */
#include <string.h>   /* memset strlen */

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
void print_int(const int data)
{
    printf("%d ", data);

    return;
}

/******************************************************************************/
#define CMP_BASIC_TYPE(data1, data2)    ((data1) - (data2))

/******************************************************************************/
int cmp_int(const int data1, const int data2)
{
    return CMP_BASIC_TYPE(data1, data2);
}

/******************************************************************************/
int cmp_long(const long data1, const long data2)
{
    return CMP_BASIC_TYPE(data1, data2);
}

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

