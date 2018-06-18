/******************************************************************************/
/**
 * @file          list.h
 * @brief         linked list
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef LIST_H
#define LIST_H

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
struct tagList;
typedef struct tagList List;

/******************************************************************************/
/**
 * @func          List* list_create(FreeFunc data_free, CmpFunc data_cmp)
 * @brief         create list
 * @param[in]     FreeFunc data_free: 
 * @param[in]     CmpFunc data_cmp: 
 * @return        List*: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern List* list_create(FreeFunc data_free, CmpFunc data_cmp);

/******************************************************************************/
/**
 * @func          FuncRtn list_destroy(List** thiz)
 * @brief         list_destroy
 * @param[in/out] List** thiz: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn list_destroy(List** thiz);

/******************************************************************************/
/**
 * @func          size_t list_get_size(List* thiz)
 * @brief         list_get_size
 * @param[in/out] List* thiz: 
 * @return        size_t: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern size_t list_get_size(List* thiz);

/******************************************************************************/
/**
 * @func          FreeFunc list_get_free_func(const List* thiz)
 * @brief         list_get_free_func
 * @param[in]     List* thiz: 
 * @return        FreeFunc: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FreeFunc list_get_free_func(const List* thiz);

/******************************************************************************/
/**
 * @func          void list_set_free_func(List* thiz, FreeFunc data_free)
 * @brief         list_set_free_func
 * @param[in/out] List* thiz: 
 * @param[in]     FreeFunc data_free: 
 * @return        void: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern void list_set_free_func(List* thiz, FreeFunc data_free);

/******************************************************************************/
/**
 * @func          CmpFunc list_get_cmp_func(const List* thiz)
 * @brief         list_get_cmp_func
 * @param[in]     List* thiz: 
 * @return        CmpFunc: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern CmpFunc list_get_cmp_func(const List* thiz);

/******************************************************************************/
/**
 * @func          void list_set_cmp_func(List* thiz, CmpFunc data_cmp)
 * @brief         list_set_cmp_func
 * @param[in/out] List* thiz: 
 * @param[in]     CmpFunc data_cmp: 
 * @return        void: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern void list_set_cmp_func(List* thiz, CmpFunc data_cmp);

/******************************************************************************/
/**
 * @func          FuncRtn list_insert_head(List* thiz, const void* data)
 * @brief         list_insert_head
 * @param[in/out] List* thiz: 
 * @param[in]     void* data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn list_insert_head(List* thiz, const void* data);

/******************************************************************************/
/**
 * @func          FuncRtn list_remove_head(List* thiz, Bool free_flag, void** data)
 * @brief         list_remove_head
 * @param[in/out] List* thiz: 
 * @param[in]     Bool free_flag: 
 * @param[in/out] void** data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn list_remove_head(List* thiz, Bool free_flag, void** data);

/******************************************************************************/
/**
 * @func          FuncRtn list_append_tail(List* thiz, const void* data)
 * @brief         list_append_tail
 * @param[in/out] List* thiz: 
 * @param[in]     void* data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn list_append_tail(List* thiz, const void* data);

/******************************************************************************/
/**
 * @func          FuncRtn list_remove_tail(List* thiz, Bool free_flag, void** data)
 * @brief         list_remove_tail
 * @param[in/out] List* thiz: 
 * @param[in]     Bool free_flag: 
 * @param[in/out] void** data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn list_remove_tail(List* thiz, Bool free_flag, void** data);

/******************************************************************************/
/**
 * @func          FuncRtn list_insert_by_index(List* thiz, size_t index, const void* data)
 * @brief         list_insert_by_index
 * @param[in/out] List* thiz: 
 * @param[in]     size_t index: 
 * @param[in]     void* data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn list_insert_by_index(List* thiz, size_t index, const void* data);

/******************************************************************************/
/**
 * @func          FuncRtn list_remove_by_index(List* thiz, size_t index, Bool free_flag, void** data)
 * @brief         list_remove_by_index
 * @param[in/out] List* thiz: 
 * @param[in]     size_t index: 
 * @param[in]     Bool free_flag: 
 * @param[in/out] void** data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn list_remove_by_index(List* thiz, size_t index, Bool free_flag, void** data);

/******************************************************************************/
/**
 * @func          FuncRtn list_insert_by_value(List* thiz, const void* data)
 * @brief         list_insert_by_value
 * @param[in/out] List* thiz: 
 * @param[in]     void* data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn list_insert_by_value(List* thiz, const void* data);

/******************************************************************************/
/**
 * @func          FuncRtn list_remove_by_value(List* thiz, const void* data, Bool free_flag)
 * @brief         list_remove_by_value
 * @param[in/out] List* thiz: 
 * @param[in]     void* data: 
 * @param[in]     Bool free_flag: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn list_remove_by_value(List* thiz, const void* data, Bool free_flag);

/******************************************************************************/
/**
 * @func          FuncRtn list_get_by_index(const List* thiz, size_t index, void** data)
 * @brief         list_get_by_index
 * @param[in]     List* thiz: 
 * @param[in]     size_t index: 
 * @param[in/out] void** data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn list_get_by_index(const List* thiz, size_t index, void** data);

/******************************************************************************/
/**
 * @func          FuncRtn list_get_by_value(const List* thiz, const void* data, size_t* index)
 * @brief         list_get_by_value
 * @param[in]     List* thiz: 
 * @param[in]     void* data: 
 * @param[in/out] size_t* index: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn list_get_by_value(const List* thiz, const void* data, size_t* index);

/******************************************************************************/
/**
 * @func          FuncRtn list_set_by_index(const List* thiz, size_t index, const void* data)
 * @brief         list_set_by_index
 * @param[in]     List* thiz: 
 * @param[in]     size_t index: 
 * @param[in]     void* data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn list_set_by_index(const List* thiz, size_t index, const void* data);

/******************************************************************************/
/**
 * @func          FuncRtn list_set_by_value(const List* thiz, const void* data, const void* new_data)
 * @brief         list_set_by_value
 * @param[in]     List* thiz: 
 * @param[in]     void* data: 
 * @param[in]     void* new_data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn list_set_by_value(const List* thiz, const void* data, const void* new_data);

/******************************************************************************/
/**
 * @func          FuncRtn list_print(const List* thiz, DataPrintFunc print)
 * @brief         list_print
 * @param[in]     List* thiz: 
 * @param[in]     DataPrintFunc print: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn list_print(const List* thiz, DataPrintFunc print);

/******************************************************************************/
/**
 * @func          FuncRtn list_foreach(List* thiz, VisitFunc visit, void* context)
 * @brief         list_foreach
 * @param[in/out] List* thiz: 
 * @param[in]     VisitFunc visit: 
 * @param[in/out] void* context: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn list_foreach(List* thiz, VisitFunc visit, void* context);

/******************************************************************************/
/**
 * @func          FuncRtn list_quick_sort(List* thiz, size_t start_index, size_t end_index)
 * @brief         list_quick_sort
 * @param[in/out] List* thiz: 
 * @param[in]     size_t start_index: 
 * @param[in]     size_t end_index: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn list_quick_sort(List* thiz, size_t start_index, size_t end_index);

/******************************************************************************/
/**
 * @func          FuncRtn list_link(List* list1, List* list2)
 * @brief         list_link
 * @param[in/out] List* list1: 
 * @param[in/out] List* list2: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn list_link(List* list1, List* list2);

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif // LIST_H

