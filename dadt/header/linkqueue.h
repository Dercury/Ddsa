/******************************************************************************/
/**
 * @file          linkqueue.h
 * @brief         linkqueue.h
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef LINK_QUEUE_H
#define LINK_QUEUE_H

#include "dlist.h"

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
typedef DList            LinkQueue;

#define linkqueue_create      dlist_create

#define linkqueue_destroy   dlist_destroy

#define linkqueue_get_size    dlist_get_size

#define linkqueue_get_free_func    dlist_get_free_func

#define linkqueue_set_free_func    dlist_set_free_func

#define linkqueue_get_cmp_func    dlist_get_cmp_func

#define linkqueue_set_cmp_func    dlist_set_cmp_func

/******************************************************************************/
/**
 * @func          FuncRtn linkqueue_enqueue(LinkQueue* thiz, const void* data)
 * @brief         linkqueue_enqueue
 * @param[in/out] LinkQueue* thiz: 
 * @param[in]     void* data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn linkqueue_enqueue(LinkQueue* thiz, const void* data);

/******************************************************************************/
/**
 * @func          FuncRtn linkqueue_dequeue(LinkQueue* thiz, Bool free_flag, void** data)
 * @brief         linkqueue_dequeue
 * @param[in/out] LinkQueue* thiz: 
 * @param[in]     Bool free_flag: 
 * @param[in/out] void** data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn linkqueue_dequeue(LinkQueue* thiz, Bool free_flag, void** data);

/******************************************************************************/
/**
 * @func          FuncRtn linkqueue_peek(LinkQueue* thiz, void** data)
 * @brief         linkqueue_peek
 * @param[in/out] LinkQueue* thiz: 
 * @param[in/out] void** data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn linkqueue_peek(LinkQueue* thiz, void** data);

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif 
