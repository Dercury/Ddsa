/******************************************************************************/
/**
 * @file        mem_op.c
 * @brief       memory operation
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/

/***************************** include files **********************************/
#include "mem_op.h"
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* malloc/free */
#include <string.h>     /* memset */

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#ifdef DEBUG
static size_t g_malloc_times = 0;
static size_t g_malloc_bytes = 0;
static size_t g_free_times = 0;
static size_t g_free_bytes = 0;
#endif

/******************************************************************************/
FuncRtn alloc_memory(void** pointer, size_t bytes)
{
    if (NULL == pointer)
    {
        return FUNC_PARAM_NULL_POINTER;
    }

    if (0 == bytes)
    {
        return FUNC_PARAM_RANGE;
    }

    *pointer = malloc(bytes);
    if (NULL == *pointer)
    {
        printf("Error: memory alloc for <%u> bytes failed!\n", bytes);
        return FUNC_MEMORY_ALLOC;
    }
    else
    {
        memset(*pointer, 0, bytes);
#ifdef DEBUG
        g_malloc_times++;
        g_malloc_bytes += bytes;
#endif
    }

    return FUNC_OK;
}

/******************************************************************************/
void free_memory(void** pointer)
{
    if (NULL == pointer || NULL == *pointer)
    {
        return;
    }

    free(*pointer);
    *pointer = NULL;
#ifdef DEBUG
    g_free_times++;
#endif

    return;
}

/******************************************************************************/

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

