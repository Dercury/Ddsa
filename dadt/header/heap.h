/******************************************************************************/
/**
 * @file          heap.h
 * @brief         heap.h
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef HEAP_H
#define HEAP_H

/******************************************************************************/
#include "bool.h"
#include "func_ptr.h"
#include "func_rtn.h"
#include <stdlib.h>

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
struct tagHeap;
typedef struct tagHeap Heap;

/******************************************************************************/
/**
 * @func          Heap* heap_create(FreeFunc data_free, CmpFunc data_cmp)
 * @brief         heap_create
 * @param[in]     FreeFunc data_free: 
 * @param[in]     CmpFunc data_cmp: 
 * @return        Heap*: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern Heap* heap_create(FreeFunc data_free, CmpFunc data_cmp);

/******************************************************************************/
/**
 * @func          FuncRtn heap_destroy(Heap** thiz)
 * @brief         heap_destroy
 * @param[in/out] Heap** thiz: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn heap_destroy(Heap** thiz);

/******************************************************************************/
/**
 * @func          size_t heap_get_size(const Heap* thiz)
 * @brief         heap_get_size
 * @param[in]     Heap* thiz: 
 * @return        size_t: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern size_t heap_get_size(const Heap* thiz);

/******************************************************************************/
/**
 * @func          FreeFunc heap_get_free_func(const Heap* thiz)
 * @brief         heap_get_free_func
 * @param[in]     Heap* thiz: 
 * @return        FreeFunc: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FreeFunc heap_get_free_func(const Heap* thiz);
/******************************************************************************/
/**
 * @func          void heap_set_free_func(Heap* thiz, FreeFunc data_free)
 * @brief         heap_set_free_func
 * @param[in/out] Heap* thiz: 
 * @param[in]     FreeFunc data_free: 
 * @return        void: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern void heap_set_free_func(Heap* thiz, FreeFunc data_free);

/******************************************************************************/
/**
 * @func          CmpFunc heap_get_cmp_func(const Heap* thiz)
 * @brief         heap_get_cmp_func
 * @param[in]     Heap* thiz: 
 * @return        CmpFunc: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern CmpFunc heap_get_cmp_func(const Heap* thiz);
/******************************************************************************/
/**
 * @func          void heap_set_cmp_func(Heap* thiz, CmpFunc data_cmp)
 * @brief         heap_set_cmp_func
 * @param[in/out] Heap* thiz: 
 * @param[in]     CmpFunc data_cmp: 
 * @return        void: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern void heap_set_cmp_func(Heap* thiz, CmpFunc data_cmp);

/******************************************************************************/
/**
 * @func          FuncRtn heap_insert(Heap* thiz, const void* data)
 * @brief         heap_insert
 * @param[in/out] Heap* thiz: 
 * @param[in]     void* data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn heap_insert(Heap* thiz, const void* data);
/******************************************************************************/
/**
 * @func          FuncRtn heap_extract(Heap* thiz, void** data)
 * @brief         heap_extract
 * @param[in/out] Heap* thiz: 
 * @param[in/out] void** data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn heap_extract(Heap* thiz, void** data);
/******************************************************************************/
/**
 * @func          FuncRtn heap_peek(Heap* thiz, void** data)
 * @brief         heap_peek
 * @param[in/out] Heap* thiz: 
 * @param[in/out] void** data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn heap_peek(Heap* thiz, void** data);

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif // HEAP_H

