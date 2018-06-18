/******************************************************************************/
/**
 * @file          dlist.h
 * @brief         dlist.h
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef DLIST_H
#define DLIST_H

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
struct tagDList;
typedef struct tagDList DList;

/******************************************************************************/
/**
 * @func          DList* dlist_create(FreeFunc data_free, CmpFunc data_cmp)
 * @brief         dlist_create
 * @param[in]     FreeFunc data_free: user defined function used to destroy list node data
 * @param[in]     CmpFunc data_cmp: user defined function used to compare list node data
 * @return        DList*: pointer to dlist
 * @complexity    O(1)
 * @notes         nothing
 */
/******************************************************************************/
extern DList* dlist_create(FreeFunc data_free, CmpFunc data_cmp);

/******************************************************************************/
/**
 * @func          FuncRtn dlist_destroy(DList** thiz)
 * @brief         dlist_destroy
 * @param[in/out] DList** thiz: 
 * @return        FuncRtn: 
 * @complexity    O(n)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn dlist_destroy(DList** thiz);

/******************************************************************************/
/**
 * @func          size_t dlist_get_size(const DList* thiz)
 * @brief         dlist_get_size
 * @param[in]     DList* thiz: 
 * @return        size_t: 
 * @complexity    O(1)
 * @notes         nothing
 */
/******************************************************************************/
extern size_t dlist_get_size(const DList* thiz);

/******************************************************************************/
/**
 * @func          FreeFunc dlist_get_free_func(const DList* thiz)
 * @brief         dlist_get_free_func
 * @param[in]     DList* thiz: 
 * @return        FreeFunc: 
 * @complexity    O(1)
 * @notes         nothing
 */
/******************************************************************************/
extern FreeFunc dlist_get_free_func(const DList* thiz);

/******************************************************************************/
/**
 * @func          void dlist_set_free_func(DList* thiz, FreeFunc data_free)
 * @brief         dlist_set_free_func
 * @param[in/out] DList* thiz: 
 * @param[in]     FreeFunc data_free: 
 * @return        void: 
 * @complexity    O(1)
 * @notes         nothing
 */
/******************************************************************************/
extern void dlist_set_free_func(DList* thiz, FreeFunc data_free);

/******************************************************************************/
/**
 * @func          CmpFunc dlist_get_cmp_func(const DList* thiz)
 * @brief         dlist_get_cmp_func
 * @param[in]     DList* thiz: 
 * @return        CmpFunc: 
 * @complexity    O(1)
 * @notes         nothing
 */
/******************************************************************************/
extern CmpFunc dlist_get_cmp_func(const DList* thiz);

/******************************************************************************/
/**
 * @func          void dlist_set_cmp_func(DList* thiz, CmpFunc data_cmp)
 * @brief         dlist_set_cmp_func
 * @param[in/out] DList* thiz: 
 * @param[in]     CmpFunc data_cmp: 
 * @return        void: 
 * @complexity    O(1)
 * @notes         nothing
 */
/******************************************************************************/
extern void dlist_set_cmp_func(DList* thiz, CmpFunc data_cmp);

/******************************************************************************/
/**
 * @func          FuncRtn dlist_insert_head(DList* thiz, const void* data)
 * @brief         dlist_insert_head
 * @param[in/out] DList* thiz: 
 * @param[in]     void* data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn dlist_insert_head(DList* thiz, const void* data);

/******************************************************************************/
/**
 * @func          FuncRtn dlist_remove_head(DList* thiz, Bool free_flag, void** data)
 * @brief         dlist_remove_head
 * @param[in/out] DList* thiz: 
 * @param[in]     Bool free_flag: 
 * @param[in/out] void** data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn dlist_remove_head(DList* thiz, Bool free_flag, void** data);

/******************************************************************************/
/**
 * @func          FuncRtn dlist_append_tail(DList* thiz, const void* data)
 * @brief         dlist_append_tail
 * @param[in/out] DList* thiz: 
 * @param[in]     void* data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn dlist_append_tail(DList* thiz, const void* data);

/******************************************************************************/
/**
 * @func          FuncRtn dlist_remove_tail(DList* thiz, Bool free_flag, void** data)
 * @brief         dlist_remove_tail
 * @param[in/out] DList* thiz: 
 * @param[in]     Bool free_flag: 
 * @param[in/out] void** data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn dlist_remove_tail(DList* thiz, Bool free_flag, void** data);

/******************************************************************************/
/**
 * @func          FuncRtn dlist_insert_by_index(DList* thiz, size_t index, const void* data)
 * @brief         dlist_insert_by_index
 * @param[in/out] DList* thiz: 
 * @param[in]     size_t index: 
 * @param[in]     void* data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn dlist_insert_by_index(DList* thiz, size_t index, const void* data);

/******************************************************************************/
/**
 * @func          FuncRtn dlist_remove_by_index(DList* thiz, size_t index, Bool free_flag, void** data)
 * @brief         dlist_remove_by_index
 * @param[in/out] DList* thiz: 
 * @param[in]     size_t index: 
 * @param[in]     Bool free_flag: 
 * @param[in/out] void** data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn dlist_remove_by_index(DList* thiz, size_t index, Bool free_flag, void** data);

/******************************************************************************/
/**
 * @func          FuncRtn dlist_insert_by_value(DList* thiz, const void* data)
 * @brief         dlist_insert_by_value
 * @param[in/out] DList* thiz: 
 * @param[in]     void* data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn dlist_insert_by_value(DList* thiz, const void* data);

/******************************************************************************/
/**
 * @func          FuncRtn dlist_remove_by_value(DList* thiz, const void* data, Bool free_flag)
 * @brief         dlist_remove_by_value
 * @param[in/out] DList* thiz: 
 * @param[in]     void* data: 
 * @param[in]     Bool free_flag: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn dlist_remove_by_value(DList* thiz, const void* data, Bool free_flag);

/******************************************************************************/
/**
 * @func          FuncRtn dlist_get_by_index(const DList* thiz, size_t index, void** data)
 * @brief         dlist_get_by_index
 * @param[in]     DList* thiz: 
 * @param[in]     size_t index: 
 * @param[in/out] void** data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn dlist_get_by_index(const DList* thiz, size_t index, void** data);

/******************************************************************************/
/**
 * @func          FuncRtn dlist_get_by_value(const DList* thiz, const void* data, size_t* index)
 * @brief         dlist_get_by_value
 * @param[in]     DList* thiz: 
 * @param[in]     void* data: 
 * @param[in/out] size_t* index: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn dlist_get_by_value(const DList* thiz, const void* data, size_t* index);

/******************************************************************************/
/**
 * @func          FuncRtn dlist_set_by_index(const DList* thiz, size_t index, const void* data)
 * @brief         dlist_set_by_index
 * @param[in]     DList* thiz: 
 * @param[in]     size_t index: 
 * @param[in]     void* data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn dlist_set_by_index(const DList* thiz, size_t index, const void* data);

/******************************************************************************/
/**
 * @func          FuncRtn dlist_set_by_value(const DList* thiz, const void* data, const void* new_data)
 * @brief         dlist_set_by_value
 * @param[in]     DList* thiz: 
 * @param[in]     void* data: 
 * @param[in]     void* new_data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn dlist_set_by_value(const DList* thiz, const void* data, const void* new_data);

/******************************************************************************/
/**
 * @func          FuncRtn dlist_print(const DList* thiz, DataPrintFunc print)
 * @brief         dlist_print
 * @param[in]     DList* thiz: 
 * @param[in]     DataPrintFunc print: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn dlist_print(const DList* thiz, DataPrintFunc print);

/******************************************************************************/
/**
 * @func          FuncRtn dlist_foreach(DList* thiz, VisitFunc visit, void* context)
 * @brief         dlist_foreach
 * @param[in/out] DList* thiz: 
 * @param[in]     VisitFunc visit: 
 * @param[in/out] void* context: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn dlist_foreach(DList* thiz, VisitFunc visit, void* context);

/******************************************************************************/
/**
 * @func          FuncRtn dlist_quick_sort(DList* thiz, size_t start_index, size_t end_index)
 * @brief         dlist_quick_sort
 * @param[in/out] DList* thiz: 
 * @param[in]     size_t start_index: 
 * @param[in]     size_t end_index: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn dlist_quick_sort(DList* thiz, size_t start_index, size_t end_index);

/******************************************************************************/
/**
 * @func          FuncRtn dlist_link(DList* list1, DList* list2)
 * @brief         dlist_link
 * @param[in/out] DList* list1: 
 * @param[in/out] DList* list2: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn dlist_link(DList* list1, DList* list2);

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif // DLIST_H

