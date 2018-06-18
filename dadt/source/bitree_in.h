/******************************************************************************/
/**
 * @file        bintree.h
 * @brief       binary tree
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/
#ifndef BITREE_IN_H
#define BITREE_IN_H

#include "bitree.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
typedef enum tagBiTreeChildPos
{
    BITREE_CHILD_LEFT,
    BITREE_CHILD_RIGHT
} eBiTreeChildPos;

/******************************************************************************/
typedef struct tagBiTreeNode
{
    void*                   data;
    struct tagBiTreeNode*   left;
    struct tagBiTreeNode*   right;
} BiTreeNode;

/******************************************************************************/
struct tagBiTree
{
    BiTreeNode*     root;
    size_t        size;
    FreeFunc        data_free;
    CmpFunc         data_cmp;
};

/******************************************************************************/
FuncRtn bitree_make_node(const void* data, BiTreeNode** node);

/******************************************************************************/
FuncRtn bitree_free_node(BiTreeNode** node, Bool free_flag, FreeFunc data_free);

/******************************************************************************/
BiTreeNode* bitree_get_root(const BiTree* thiz);

/******************************************************************************/
BiTreeNode* bitree_get_max_node(const BiTreeNode* root, CmpFunc data_cmp);

/******************************************************************************/
BiTreeNode* bitree_get_min_node(const BiTreeNode* root, CmpFunc data_cmp);

/******************************************************************************/
size_t bitree_inner_get_depth(const BiTreeNode* root);

/******************************************************************************/
Bool bitree_is_root(BiTree* thiz, BiTreeNode* node);

/******************************************************************************/
Bool bitree_is_leaf(BiTreeNode* node);

/******************************************************************************/
FuncRtn bitree_insert_child(BiTree* thiz, BiTreeNode* parent, eBiTreeChildPos pos, const void* data);

/******************************************************************************/
FuncRtn bitree_remove_child(BiTree* thiz, BiTreeNode* parent, eBiTreeChildPos pos, Bool free_flag, void** data);

/******************************************************************************/
FuncRtn bitree_preorder_traverse(const BiTreeNode* root, VisitFunc visit, void* context);

/******************************************************************************/
FuncRtn bitree_inorder_traverse(const BiTreeNode* root, VisitFunc visit, void* context);

/******************************************************************************/
FuncRtn bitree_postorder_traverse(const BiTreeNode* root, VisitFunc visit, void* context);

/******************************************************************************/
FuncRtn bitree_inner_print(BiTreeNode* root, DataPrintFunc print);

/******************************************************************************/
FuncRtn bitree_get_data_by_traversal(void* data, void* context);
FuncRtn bitree_inner_get_pos_by_data(CmpFunc data_cmp, const BiTreeNode* sub_root, const void* data, BiTreeNodePos* pos);
FuncRtn bitree_get_node_by_pos(const BiTree* thiz, const BiTreeNodePos* pos, BiTreeNode** node);

/******************************************************************************/

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

#endif /* BITREE_IN_H */

