/******************************************************************************/
/**
 * @file          clist.h
 * @brief         clist.h
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef CLIST_H
#define CLIST_H

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
struct tagCList;
typedef struct tagCList CList;

/******************************************************************************/
/**
 * @func          CList* clist_create(FreeFunc data_free, CmpFunc data_cmp)
 * @brief         clist_create
 * @param[in]     FreeFunc data_free: 
 * @param[in]     CmpFunc data_cmp: 
 * @return        CList*: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern CList* clist_create(FreeFunc data_free, CmpFunc data_cmp);

/******************************************************************************/
/**
 * @func          FuncRtn clist_destroy(CList** thiz)
 * @brief         clist_destroy
 * @param[in/out] CList** thiz: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn clist_destroy(CList** thiz);

/******************************************************************************/
/**
 * @func          size_t clist_get_size(CList* thiz)
 * @brief         clist_get_size
 * @param[in/out] CList* thiz: 
 * @return        size_t: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern size_t clist_get_size(CList* thiz);

/******************************************************************************/
/**
 * @func          FreeFunc clist_get_free_func(const CList* thiz)
 * @brief         clist_get_free_func
 * @param[in]     CList* thiz: 
 * @return        FreeFunc: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FreeFunc clist_get_free_func(const CList* thiz);

/******************************************************************************/
/**
 * @func          void clist_set_free_func(CList* thiz, FreeFunc data_free)
 * @brief         clist_set_free_func
 * @param[in/out] CList* thiz: 
 * @param[in]     FreeFunc data_free: 
 * @return        void: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern void clist_set_free_func(CList* thiz, FreeFunc data_free);

/******************************************************************************/
/**
 * @func          CmpFunc clist_get_cmp_func(const CList* thiz)
 * @brief         clist_get_cmp_func
 * @param[in]     CList* thiz: 
 * @return        CmpFunc: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern CmpFunc clist_get_cmp_func(const CList* thiz);

/******************************************************************************/
/**
 * @func          void clist_set_cmp_func(CList* thiz, CmpFunc data_cmp)
 * @brief         clist_set_cmp_func
 * @param[in/out] CList* thiz: 
 * @param[in]     CmpFunc data_cmp: 
 * @return        void: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern void clist_set_cmp_func(CList* thiz, CmpFunc data_cmp);

/******************************************************************************/
/**
 * @func          FuncRtn clist_insert_head(CList* thiz, const void* data)
 * @brief         clist_insert_head
 * @param[in/out] CList* thiz: 
 * @param[in]     void* data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn clist_insert_head(CList* thiz, const void* data);

/******************************************************************************/
/**
 * @func          FuncRtn clist_remove_head(CList* thiz, Bool free_flag, void** data)
 * @brief         clist_remove_head
 * @param[in/out] CList* thiz: 
 * @param[in]     Bool free_flag: 
 * @param[in/out] void** data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn clist_remove_head(CList* thiz, Bool free_flag, void** data);

/******************************************************************************/
/**
 * @func          FuncRtn clist_append_tail(CList* thiz, const void* data)
 * @brief         clist_append_tail
 * @param[in/out] CList* thiz: 
 * @param[in]     void* data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn clist_append_tail(CList* thiz, const void* data);

/******************************************************************************/
/**
 * @func          FuncRtn clist_remove_tail(CList* thiz, Bool free_flag, void** data)
 * @brief         clist_remove_tail
 * @param[in/out] CList* thiz: 
 * @param[in]     Bool free_flag: 
 * @param[in/out] void** data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn clist_remove_tail(CList* thiz, Bool free_flag, void** data);

/******************************************************************************/
/**
 * @func          FuncRtn clist_insert_by_index(CList* thiz, size_t index, const void* data)
 * @brief         clist_insert_by_index
 * @param[in/out] CList* thiz: 
 * @param[in]     size_t index: 
 * @param[in]     void* data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn clist_insert_by_index(CList* thiz, size_t index, const void* data);

/******************************************************************************/
/**
 * @func          FuncRtn clist_remove_by_index(CList* thiz, size_t index, Bool free_flag, void** data)
 * @brief         clist_remove_by_index
 * @param[in/out] CList* thiz: 
 * @param[in]     size_t index: 
 * @param[in]     Bool free_flag: 
 * @param[in/out] void** data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn clist_remove_by_index(CList* thiz, size_t index, Bool free_flag, void** data);

/******************************************************************************/
/**
 * @func          FuncRtn clist_insert_by_value(CList* thiz, const void* data)
 * @brief         clist_insert_by_value
 * @param[in/out] CList* thiz: 
 * @param[in]     void* data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn clist_insert_by_value(CList* thiz, const void* data);

/******************************************************************************/
/**
 * @func          FuncRtn clist_remove_by_value(CList* thiz, const void* data, Bool free_flag)
 * @brief         clist_remove_by_value
 * @param[in/out] CList* thiz: 
 * @param[in]     void* data: 
 * @param[in]     Bool free_flag: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn clist_remove_by_value(CList* thiz, const void* data, Bool free_flag);

/******************************************************************************/
/**
 * @func          FuncRtn clist_get_by_index(const CList* thiz, size_t index, void** data)
 * @brief         clist_get_by_index
 * @param[in]     CList* thiz: 
 * @param[in]     size_t index: 
 * @param[in/out] void** data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn clist_get_by_index(const CList* thiz, size_t index, void** data);

/******************************************************************************/
/**
 * @func          FuncRtn clist_get_by_value(const CList* thiz, const void* data, size_t* index)
 * @brief         clist_get_by_value
 * @param[in]     CList* thiz: 
 * @param[in]     void* data: 
 * @param[in/out] size_t* index: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn clist_get_by_value(const CList* thiz, const void* data, size_t* index);

/******************************************************************************/
/**
 * @func          FuncRtn clist_set_by_index(const CList* thiz, size_t index, const void* data)
 * @brief         clist_set_by_index
 * @param[in]     CList* thiz: 
 * @param[in]     size_t index: 
 * @param[in]     void* data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn clist_set_by_index(const CList* thiz, size_t index, const void* data);

/******************************************************************************/
/**
 * @func          FuncRtn clist_set_by_value(const CList* thiz, const void* data, const void* new_data)
 * @brief         clist_set_by_value
 * @param[in]     CList* thiz: 
 * @param[in]     void* data: 
 * @param[in]     void* new_data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn clist_set_by_value(const CList* thiz, const void* data, const void* new_data);

/******************************************************************************/
/**
 * @func          FuncRtn clist_print(const CList* thiz, DataPrintFunc print)
 * @brief         clist_print
 * @param[in]     CList* thiz: 
 * @param[in]     DataPrintFunc print: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn clist_print(const CList* thiz, DataPrintFunc print);

/******************************************************************************/
/**
 * @func          FuncRtn clist_foreach(CList* thiz, VisitFunc visit, void* context)
 * @brief         clist_foreach
 * @param[in/out] CList* thiz: 
 * @param[in]     VisitFunc visit: 
 * @param[in/out] void* context: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn clist_foreach(CList* thiz, VisitFunc visit, void* context);

/******************************************************************************/
/**
 * @func          FuncRtn clist_quick_sort(CList* thiz, size_t start_index, size_t end_index)
 * @brief         clist_quick_sort
 * @param[in/out] CList* thiz: 
 * @param[in]     size_t start_index: 
 * @param[in]     size_t end_index: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn clist_quick_sort(CList* thiz, size_t start_index, size_t end_index);

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif // CLIST_H

