/******************************************************************************/
/**
 * @file          bintree.h
 * @brief         bintree.h
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef BINTREE_H
#define BINTREE_H

/******************************************************************************/
#include "bitree.h"

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
typedef BiTree      BinTree;

#define bintree_create                  bitree_create

#define bintree_destroy                 bitree_destroy

#define bintree_get_size                bitree_get_size
#define bintree_get_depth               bitree_get_depth

/******************************************************************************/
/**
 * @func          void* bintree_get_max(const BinTree* thiz)
 * @brief         bintree_get_max
 * @param[in]     BinTree* thiz: 
 * @return        void*: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern void* bintree_get_max(const BinTree* thiz);
/******************************************************************************/
/**
 * @func          void* bintree_get_min(const BinTree* thiz)
 * @brief         bintree_get_min
 * @param[in]     BinTree* thiz: 
 * @return        void*: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern void* bintree_get_min(const BinTree* thiz);

#define bintree_get_free_func           bitree_get_free_func
#define bintree_set_free_func           bitree_set_free_func

#define bintree_get_cmp_func            bitree_get_cmp_func
#define bintree_set_cmp_func            bitree_set_cmp_func

#define bintree_preorder_traversal      bitree_preorder_traversal
#define bintree_inorder_traversal       bitree_inorder_traversal
#define bintree_postorder_traversal     bitree_postorder_traversal
#define bintree_levelorder_traversal    bitree_postorder_traversal

#define bintree_get_all_data            bitree_get_all_data
#define bintree_get_pos_by_data         bitree_get_pos_by_data
#define bintree_get_data_by_pos         bitree_get_data_by_pos
#define bintree_set_data_by_pos         bitree_set_data_by_pos

#define bintree_print                   bitree_print
#define bintree_print_figure            bitree_print_figure

/******************************************************************************/
/**
 * @func          FuncRtn bintree_insert(BinTree* thiz, const void* data)
 * @brief         bintree_insert
 * @param[in/out] BinTree* thiz: 
 * @param[in]     void* data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn bintree_insert(BinTree* thiz, const void* data);

/******************************************************************************/
/**
 * @func          FuncRtn bintree_remove(BinTree* thiz, Bool free_flag, void** data)
 * @brief         bintree_remove
 * @param[in/out] BinTree* thiz: 
 * @param[in]     Bool free_flag: 
 * @param[in/out] void** data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn bintree_remove(BinTree* thiz, Bool free_flag, void** data);

/******************************************************************************/
/**
 * @func          FuncRtn bintree_search(BinTree* thiz, void** data)
 * @brief         bintree_search
 * @param[in/out] BinTree* thiz: 
 * @param[in/out] void** data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn bintree_search(BinTree* thiz, void** data);

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif // BINTREE_H

