/******************************************************************************/
/**
 * @file        avltree.h
 * @brief       binary tree
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/
#ifndef AVLTREE_IN_H
#define AVLTREE_IN_H

#include "avltree.h"
#include "bintree_in.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

typedef enum tagAvlFactor
{
    AVL_LEFT_HEAVY  = 0,
    AVL_BALANCED,
    AVL_RIGHT_HEAVY,
} eAvlFactor;

/******************************************************************************/
/**
 * @struct      AvlTreeNode
 * @brief       structure for binary tree elements
 */
/******************************************************************************/
typedef struct tagAvlTreeNode
{
    void* data;
    eAvlFactor              factor;
    Bool                  valid;
} AvlNodeData;

/******************************************************************************/
typedef BinTreeNode     AvlTreeNode;

/******************************************************************************/
#define AVLTREE_NODE_DATA(node)     (((AvlNodeData *)((node)->data))->data)
#define AVLTREE_NODE_FACTOR(node)   (((AvlNodeData *)((node)->data))->factor)
#define AVLTREE_NODE_VALID(node)    (((AvlNodeData *)((node)->data))->valid)

/******************************************************************************/
FuncRtn avltree_make_node(const void* data, AvlTreeNode** node);
FuncRtn avltree_free_node(AvlTreeNode** node, Bool free_flag, FreeFunc data_free);
FuncRtn avltree_update_node(AvlNodeData* node, const void* data, FreeFunc data_free);

/******************************************************************************/
#define avltree_get_root            bintree_get_root

/******************************************************************************/
#define avltree_is_root             bintree_is_root
#define avltree_is_leaf             bintree_is_leaf

/******************************************************************************/
#define avltree_get_max_node        bintree_get_max_node
#define avltree_get_min_node        bintree_get_min_node

/******************************************************************************/
FuncRtn avltree_insert_root(AvlTree* thiz, const void* data);
FuncRtn avltree_insert_child(CmpFunc data_cmp, AvlTreeNode** sub_root, const void* data, Bool* balanced);

/******************************************************************************/
FuncRtn avltree_get_place(CmpFunc data_cmp, const void* data, AvlTreeNode*** place);

/******************************************************************************/
FuncRtn avltree_preorder_traverse(const AvlTreeNode* root, VisitFunc visit, void* context);
FuncRtn avltree_inorder_traverse(const AvlTreeNode* root, VisitFunc visit, void* context);
FuncRtn avltree_postorder_traverse(const AvlTreeNode* root, VisitFunc visit, void* context);

FuncRtn avltree_inner_print(AvlTreeNode* root, DataPrintFunc print);

#define avltree_get_data_by_traversal   bitree_get_data_by_traversal
FuncRtn avltree_inner_get_pos_by_data(CmpFunc data_cmp, const AvlTreeNode* sub_root, const void* data, AvlTreeNodePos* pos);
#define avltree_get_node_by_pos         bitree_get_node_by_pos

FuncRtn avltree_inorder_get_all_nodes(const AvlTreeNode* root, DList* list);

/******************************************************************************/

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

#endif /* AVLTREE_IN_H */

