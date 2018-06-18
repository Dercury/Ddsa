/******************************************************************************/
/**
 * @file        stack.c
 * @brief       stack
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/

#include "linkstack.h"
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
FuncRtn linkstack_push(LinkStack* thiz, const void* data)
{
    return dlist_insert_head(thiz, data);
}

/******************************************************************************/
FuncRtn linkstack_pop(LinkStack* thiz, Bool free_flag, void** data)
{
    return dlist_remove_head(thiz, free_flag, data);
}

/******************************************************************************/
FuncRtn linkstack_peek(LinkStack* thiz, void** data)
{
    return dlist_get_by_index(thiz, 0, data);
}

#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

