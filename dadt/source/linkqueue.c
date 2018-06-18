/******************************************************************************/
/**
 * @file        queue.c
 * @brief       queue
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/

#include "linkqueue.h"
#include "macro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

#if CODE_SEPARATOR("Inner Definition", 1)
#endif /* CODE_SEPARATOR("Inner Definition", 1) */

#if CODE_SEPARATOR("Inner Function", 1)
#endif

#if CODE_SEPARATOR("Outer Function", 1)
/******************************************************************************/
FuncRtn linkqueue_enqueue(LinkQueue* thiz, const void* data)
{
    return dlist_append_tail(thiz, data);
}

/******************************************************************************/
FuncRtn linkqueue_dequeue(LinkQueue* thiz, Bool free_flag, void** data)
{
    return dlist_remove_head(thiz, free_flag, data);
}

/******************************************************************************/
FuncRtn linkqueue_peek(LinkQueue* thiz, void** data)
{
    return dlist_get_by_index(thiz, 0, data);
}

#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

