/******************************************************************************/
/**
 * @file          bitree.h
 * @brief         bitree.h
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef BITREE_H
#define BITREE_H

/******************************************************************************/
#include "dlist.h"

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
typedef enum tagBiTreeTraversal
{
    BITREE_PREORDER_TRAVERSAL,
    BITREE_INORDER_TRAVERSAL,
    BITREE_POSTORDER_TRAVERSAL,
    BITREE_LEVELORDER_TRAVERSAL,
} eBiTreeTraversalMethod;

struct tagBiTree;
typedef struct tagBiTree BiTree;

typedef struct tagBiTreeNodePos
{
    size_t    row;
    size_t    col;
} BiTreeNodePos;

/******************************************************************************/
/**
 * @func          BiTree* bitree_create(FreeFunc data_free, CmpFunc data_cmp)
 * @brief         bitree_create
 * @param[in]     FreeFunc data_free:
 * @param[in]     CmpFunc data_cmp:
 * @return        BiTree*:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern BiTree* bitree_create(FreeFunc data_free, CmpFunc data_cmp);

/******************************************************************************/
/**
 * @func          FuncRtn bitree_destroy(BiTree** thiz)
 * @brief         bitree_destroy
 * @param[in/out] BiTree** thiz:
 * @return        FuncRtn:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn bitree_destroy(BiTree** thiz);

/******************************************************************************/
/**
 * @func          size_t bitree_get_size(const BiTree* thiz)
 * @brief         bitree_get_size
 * @param[in]     BiTree* thiz:
 * @return        size_t:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern size_t bitree_get_size(const BiTree* thiz);

/******************************************************************************/
/**
 * @func          size_t bitree_get_depth(const BiTree* thiz)
 * @brief         bitree_get_depth
 * @param[in]     BiTree* thiz:
 * @return        size_t:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern size_t bitree_get_depth(const BiTree* thiz);

/******************************************************************************/
/**
 * @func          void* bitree_get_max(const BiTree* thiz)
 * @brief         bitree_get_max
 * @param[in]     BiTree* thiz:
 * @return        void*:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern void* bitree_get_max(const BiTree* thiz);

/******************************************************************************/
/**
 * @func          void* bitree_get_min(const BiTree* thiz)
 * @brief         bitree_get_min
 * @param[in]     BiTree* thiz:
 * @return        void*:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern void* bitree_get_min(const BiTree* thiz);

/******************************************************************************/
/**
 * @func          FreeFunc bitree_get_free_func(const BiTree* thiz)
 * @brief         bitree_get_free_func
 * @param[in]     BiTree* thiz:
 * @return        FreeFunc:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FreeFunc bitree_get_free_func(const BiTree* thiz);

/******************************************************************************/
/**
 * @func          void bitree_set_free_func(BiTree* thiz, FreeFunc data_free)
 * @brief         bitree_set_free_func
 * @param[in/out] BiTree* thiz:
 * @param[in]     FreeFunc data_free:
 * @return        void:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern void bitree_set_free_func(BiTree* thiz, FreeFunc data_free);

/******************************************************************************/
/**
 * @func          CmpFunc bitree_get_cmp_func(const BiTree* thiz)
 * @brief         bitree_get_cmp_func
 * @param[in]     BiTree* thiz:
 * @return        CmpFunc:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern CmpFunc bitree_get_cmp_func(const BiTree* thiz);

/******************************************************************************/
/**
 * @func          void bitree_set_cmp_func(BiTree* thiz, CmpFunc data_cmp)
 * @brief         bitree_set_cmp_func
 * @param[in/out] BiTree* thiz:
 * @param[in]     CmpFunc data_cmp:
 * @return        void:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern void bitree_set_cmp_func(BiTree* thiz, CmpFunc data_cmp);

/******************************************************************************/
/**
 * @func          FuncRtn bitree_preorder_traversal(const BiTree* thiz, VisitFunc visit, void* context)
 * @brief         bitree_preorder_traversal
 * @param[in]     BiTree* thiz:
 * @param[in]     VisitFunc visit:
 * @param[in/out] void* context:
 * @return        FuncRtn:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn bitree_preorder_traversal(const BiTree* thiz, VisitFunc visit, void* context);

/******************************************************************************/
/**
 * @func          FuncRtn bitree_inorder_traversal(const BiTree* thiz, VisitFunc visit, void* context)
 * @brief         bitree_inorder_traversal
 * @param[in]     BiTree* thiz:
 * @param[in]     VisitFunc visit:
 * @param[in/out] void* context:
 * @return        FuncRtn:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn bitree_inorder_traversal(const BiTree* thiz, VisitFunc visit, void* context);

/******************************************************************************/
/**
 * @func          FuncRtn bitree_postorder_traversal(const BiTree* thiz, VisitFunc visit, void* context)
 * @brief         bitree_postorder_traversal
 * @param[in]     BiTree* thiz:
 * @param[in]     VisitFunc visit:
 * @param[in/out] void* context:
 * @return        FuncRtn:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn bitree_postorder_traversal(const BiTree* thiz, VisitFunc visit, void* context);

/******************************************************************************/
/**
 * @func          FuncRtn bitree_levelorder_traversal(const BiTree* thiz, VisitFunc visit, void* context)
 * @brief         bitree_levelorder_traversal
 * @param[in]     BiTree* thiz:
 * @param[in]     VisitFunc visit:
 * @param[in/out] void* context:
 * @return        FuncRtn:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn bitree_levelorder_traversal(const BiTree* thiz, VisitFunc visit, void* context);

/******************************************************************************/
/**
 * @func          FuncRtn bitree_get_all_data(const BiTree* thiz, DList* list, eBiTreeTraversalMethod method)
 * @brief         bitree_get_all_data
 * @param[in]     BiTree* thiz:
 * @param[in/out] DList* list:
 * @param[in]     eBiTreeTraversalMethod method:
 * @return        FuncRtn:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn bitree_get_all_data(const BiTree* thiz, DList* list, eBiTreeTraversalMethod method);

/******************************************************************************/
/**
 * @func          FuncRtn bitree_get_pos_by_data(const BiTree* thiz, const void* data, BiTreeNodePos* pos)
 * @brief         bitree_get_pos_by_data
 * @param[in]     BiTree* thiz:
 * @param[in]     void* data:
 * @param[in/out] BiTreeNodePos* pos:
 * @return        FuncRtn:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn bitree_get_pos_by_data(const BiTree* thiz, const void* data, BiTreeNodePos* pos);

/******************************************************************************/
/**
 * @func          FuncRtn bitree_get_data_by_pos(const BiTree* thiz, const BiTreeNodePos* pos, void** data)
 * @brief         bitree_get_data_by_pos
 * @param[in]     BiTree* thiz:
 * @param[in]     BiTreeNodePos* pos:
 * @param[in/out] void** data:
 * @return        FuncRtn:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn bitree_get_data_by_pos(const BiTree* thiz, const BiTreeNodePos* pos, void** data);

/******************************************************************************/
/**
 * @func          FuncRtn bitree_set_data_by_pos(const BiTree* thiz, const BiTreeNodePos* pos, const void* data)
 * @brief         bitree_set_data_by_pos
 * @param[in]     BiTree* thiz:
 * @param[in]     BiTreeNodePos* pos:
 * @param[in]     void* data:
 * @return        FuncRtn:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn bitree_set_data_by_pos(const BiTree* thiz, const BiTreeNodePos* pos, const void* data);

/******************************************************************************/
/**
 * @func          FuncRtn bitree_print(BiTree* thiz, DataPrintFunc print)
 * @brief         bitree_print
 * @param[in/out] BiTree* thiz:
 * @param[in]     DataPrintFunc print:
 * @return        FuncRtn:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn bitree_print(BiTree* thiz, DataPrintFunc print);

/******************************************************************************/
/**
 * @func          FuncRtn bitree_print_figure(const BiTree* thiz, ToStrFunc data_to_string, size_t data_string_len, const char* filename, const char* mode)
 * @brief         bitree_print_figure
 * @param[in]     BiTree* thiz:
 * @param[in]     ToStrFunc data_to_string:
 * @param[in]     size_t data_string_len:
 * @param[in]     char* filename:
 * @param[in]     char* mode:
 * @return        FuncRtn:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn bitree_print_figure(const BiTree* thiz, DataToStrFunc data_to_string, size_t data_string_len, const char* filename, const char* mode);

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif // BITREE_H

