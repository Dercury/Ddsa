/******************************************************************************/
/**
 * @file        bintree.h
 * @brief       binary tree
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/
#ifndef BINTREE_IN_H
#define BINTREE_IN_H

#include "bintree.h"
#include "bitree_in.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
typedef BiTreeNode BinTreeNode;

/******************************************************************************/
#define bintree_make_node           bitree_make_node
#define bintree_free_node           bitree_free_node

/******************************************************************************/
#define bintree_get_root            bitree_get_root

/******************************************************************************/
#define bintree_is_root             bitree_is_root
#define bintree_is_leaf             bitree_is_leaf

/******************************************************************************/
#define bintree_insert_child        bitree_insert_child

/******************************************************************************/
FuncRtn bintree_get_max_node(BinTreeNode* root, BinTreeNode** max);
FuncRtn bintree_get_min_node(BinTreeNode* root, BinTreeNode** min);

/******************************************************************************/
FuncRtn bintree_get_place(CmpFunc data_cmp, const void* data, BinTreeNode*** place);

/******************************************************************************/
FuncRtn bintree_remove_root(BinTree* thiz, Bool free_flag);
FuncRtn bintree_remove_leaf(BinTree* thiz, BinTreeNode** place, Bool free_flag);
FuncRtn bintree_remove_bole(BinTree* thiz, BinTreeNode** place, Bool free_flag);
FuncRtn bintree_remove_child(BinTree* thiz, BinTreeNode** place, Bool free_flag);

/******************************************************************************/


#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

#endif /* BINTREE_IN_H */

