/******************************************************************************/
/**
 * @file          linkstack.h
 * @brief         linkstack.h
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef LINK_STACK_H
#define LINK_STACK_H

#include "dlist.h"

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
typedef DList LinkStack;

#define linkstack_create      dlist_create

#define linkstack_destroy   dlist_destroy

#define linkstack_get_size      dlist_get_size

#define linkstack_get_free_func    dlist_get_free_func

#define linkstack_set_free_func    dlist_set_free_func

#define linkstack_get_cmp_func    dlist_get_cmp_func

#define linkstack_set_cmp_func    dlist_set_cmp_func

/******************************************************************************/
/**
 * @func          FuncRtn linkstack_push(LinkStack* thiz, const void* data)
 * @brief         linkstack_push
 * @param[in/out] LinkStack* thiz: 
 * @param[in]     void* data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn linkstack_push(LinkStack* thiz, const void* data);

/******************************************************************************/
/**
 * @func          FuncRtn linkstack_pop(LinkStack* thiz, Bool free_flag, void** data)
 * @brief         linkstack_pop
 * @param[in/out] LinkStack* thiz: 
 * @param[in]     Bool free_flag: 
 * @param[in/out] void** data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn linkstack_pop(LinkStack* thiz, Bool free_flag, void** data);

/******************************************************************************/
/**
 * @func          FuncRtn linkstack_peek(LinkStack* thiz, void** data)
 * @brief         linkstack_peek
 * @param[in/out] LinkStack* thiz: 
 * @param[in/out] void** data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn linkstack_peek(LinkStack* thiz, void** data);

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif 
