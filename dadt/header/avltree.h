/******************************************************************************/
/**
 * @file          avltree.h
 * @brief         avltree.h
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef AVLTREE_H
#define AVLTREE_H

/******************************************************************************/
#include "bintree.h"

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
typedef BiTreeNodePos               AvlTreeNodePos;
typedef eBiTreeTraversalMethod      eAvlTreeTraversalMethod;
typedef BinTree                     AvlTree;

#define avltree_create              bintree_create

extern FuncRtn avltree_destroy(AvlTree** thiz);

#define avltree_get_size            bintree_get_size
#define avltree_get_depth           bintree_get_depth

/******************************************************************************/
/**
 * @func          void* avltree_get_max(const AvlTree* thiz)
 * @brief         avltree_get_max
 * @param[in]     AvlTree* thiz:
 * @return        void*:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern void* avltree_get_max(const AvlTree* thiz);

/******************************************************************************/
/**
 * @func          void* avltree_get_min(const AvlTree* thiz)
 * @brief         avltree_get_min
 * @param[in]     AvlTree* thiz:
 * @return        void*:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern void* avltree_get_min(const AvlTree* thiz);

#define avltree_get_free_func           bintree_get_free_func
#define avltree_set_free_func           bintree_set_free_func

#define avltree_get_cmp_func            bintree_get_cmp_func
#define avltree_set_cmp_func            bintree_set_cmp_func

/******************************************************************************/
/**
 * @func          FuncRtn avltree_preorder_traversal(const AvlTree* thiz, VisitFunc visit, void* context)
 * @brief         avltree_preorder_traversal
 * @param[in]     AvlTree* thiz:
 * @param[in]     VisitFunc visit:
 * @param[in/out] void* context:
 * @return        FuncRtn:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn avltree_preorder_traversal(const AvlTree* thiz, VisitFunc visit, void* context);

/******************************************************************************/
/**
 * @func          FuncRtn avltree_inorder_traversal(const AvlTree* thiz, VisitFunc visit, void* context)
 * @brief         avltree_inorder_traversal
 * @param[in]     AvlTree* thiz:
 * @param[in]     VisitFunc visit:
 * @param[in/out] void* context:
 * @return        FuncRtn:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn avltree_inorder_traversal(const AvlTree* thiz, VisitFunc visit, void* context);

/******************************************************************************/
/**
 * @func          FuncRtn avltree_postorder_traversal(const AvlTree* thiz, VisitFunc visit, void* context)
 * @brief         avltree_postorder_traversal
 * @param[in]     AvlTree* thiz:
 * @param[in]     VisitFunc visit:
 * @param[in/out] void* context:
 * @return        FuncRtn:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn avltree_postorder_traversal(const AvlTree* thiz, VisitFunc visit, void* context);

/******************************************************************************/
/**
 * @func          FuncRtn avltree_levelorder_traversal(const AvlTree* thiz, VisitFunc visit, void* context)
 * @brief         avltree_levelorder_traversal
 * @param[in]     AvlTree* thiz:
 * @param[in]     VisitFunc visit:
 * @param[in/out] void* context:
 * @return        FuncRtn:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn avltree_levelorder_traversal(const AvlTree* thiz, VisitFunc visit, void* context);

/******************************************************************************/
/**
 * @func          FuncRtn avltree_get_all_data(const AvlTree* thiz, DList* list, eAvlTreeTraversalMethod method)
 * @brief         avltree_get_all_data
 * @param[in]     AvlTree* thiz:
 * @param[in/out] DList* list:
 * @param[in]     eAvlTreeTraversalMethod method:
 * @return        FuncRtn:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn avltree_get_all_data(const AvlTree* thiz, DList* list, eAvlTreeTraversalMethod method);

/******************************************************************************/
/**
 * @func          FuncRtn avltree_get_pos_by_data(const AvlTree* thiz, const void* data, AvlTreeNodePos* pos)
 * @brief         avltree_get_pos_by_data
 * @param[in]     AvlTree* thiz:
 * @param[in]     void* data:
 * @param[in/out] AvlTreeNodePos* pos:
 * @return        FuncRtn:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn avltree_get_pos_by_data(const AvlTree* thiz, const void* data, AvlTreeNodePos* pos);

/******************************************************************************/
/**
 * @func          FuncRtn avltree_get_data_by_pos(const AvlTree* thiz, const AvlTreeNodePos* pos, void** data)
 * @brief         avltree_get_data_by_pos
 * @param[in]     AvlTree* thiz:
 * @param[in]     AvlTreeNodePos* pos:
 * @param[in/out] void** data:
 * @return        FuncRtn:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn avltree_get_data_by_pos(const AvlTree* thiz, const AvlTreeNodePos* pos, void** data);

/******************************************************************************/
/**
 * @func          FuncRtn avltree_set_data_by_pos(const AvlTree* thiz, const AvlTreeNodePos* pos, const void* data)
 * @brief         avltree_set_data_by_pos
 * @param[in]     AvlTree* thiz:
 * @param[in]     AvlTreeNodePos* pos:
 * @param[in]     void* data:
 * @return        FuncRtn:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn avltree_set_data_by_pos(const AvlTree* thiz, const AvlTreeNodePos* pos, const void* data);

/******************************************************************************/
/**
 * @func          FuncRtn avltree_print(AvlTree* thiz, DataPrintFunc print)
 * @brief         avltree_print
 * @param[in/out] AvlTree* thiz:
 * @param[in]     DataPrintFunc print:
 * @return        FuncRtn:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn avltree_print(AvlTree* thiz, DataPrintFunc print);

/******************************************************************************/
/**
 * @func          FuncRtn avltree_print_figure(const AvlTree* thiz, ToStrFunc data_to_string, size_t data_string_len, const char* filename, const char* mode)
 * @brief         avltree_print_figure
 * @param[in]     AvlTree* thiz:
 * @param[in]     ToStrFunc data_to_string:
 * @param[in]     size_t data_string_len:
 * @param[in]     char* filename:
 * @param[in]     char* mode:
 * @return        FuncRtn:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn avltree_print_figure(const AvlTree* thiz, DataToStrFunc data_to_string, size_t data_string_len, const char* filename, const char* mode);

/******************************************************************************/
/**
 * @func          FuncRtn avltree_insert(AvlTree* thiz, const void* data)
 * @brief         avltree_insert
 * @param[in/out] AvlTree* thiz:
 * @param[in]     void* data:
 * @return        FuncRtn:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn avltree_insert(AvlTree* thiz, const void* data);

/******************************************************************************/
/**
 * @func          FuncRtn avltree_remove(AvlTree* thiz, Bool free_flag, void** data)
 * @brief         avltree_remove
 * @param[in/out] AvlTree* thiz:
 * @param[in]     Bool free_flag:
 * @param[in/out] void** data:
 * @return        FuncRtn:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn avltree_remove(AvlTree* thiz, Bool free_flag, void** data);

/******************************************************************************/
/**
 * @func          FuncRtn avltree_search(AvlTree* thiz, void** data)
 * @brief         avltree_search
 * @param[in/out] AvlTree* thiz:
 * @param[in/out] void** data:
 * @return        FuncRtn:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn avltree_search(AvlTree* thiz, void** data);

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif // AVLTREE_H

