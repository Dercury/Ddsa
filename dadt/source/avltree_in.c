/******************************************************************************/
/**
 * @file        avltree.h
 * @brief       binary tree
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/

#include "avltree_in.h"
#include "macro.h"
#include "mem_op.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if CODE_SEPARATOR("Inner Function", 1)
/******************************************************************************/
FuncRtn avltree_make_node( const void* data, AvlTreeNode** node )
{
    AvlNodeData* node_data = NULL;

    IF_ERROR_EXIT(alloc_memory((void **)&node_data, sizeof(AvlNodeData)));
    node_data->data = (void *)data;
    node_data->factor = AVL_BALANCED;
    node_data->valid = TRUE;

    IF_ERROR_EXIT(alloc_memory((void **)node, sizeof(AvlTreeNode)));
    (*node)->data = (void *)node_data;

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn avltree_free_node(AvlTreeNode** node, Bool free_flag, FreeFunc data_free)
{
    if (TRUE == free_flag && NULL != data_free)
    {
        data_free(&(AVLTREE_NODE_DATA(*node)));
    }

    free_memory(&((*node)->data));
    free_memory((void **)node);

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn avltree_update_node(AvlNodeData* node, const void* data, FreeFunc data_free)
{
    if (NULL != data_free)
    {
        data_free(&(AVLTREE_NODE_DATA(node)));
    }
    AVLTREE_NODE_DATA(node) = (void *)data;
    AVLTREE_NODE_VALID(node) = TRUE;

    return FUNC_OK;
}

/******************************************************************************/
static void avltree_left_left_case(AvlTreeNode** grand)
{
    AvlTreeNode* parent = (*grand)->left;

    (*grand)->left = parent->right;
    parent->right = *grand;
    *grand = parent;

    AVLTREE_NODE_FACTOR(*grand) = AVL_BALANCED;
    AVLTREE_NODE_FACTOR(parent) = AVL_BALANCED;

    return;
}

/******************************************************************************/
static void avltree_right_right_case(AvlTreeNode** grand)
{
    AvlTreeNode* parent = (*grand)->right;

    (*grand)->right = parent->left;
    parent->left = *grand;
    *grand = parent;

    AVLTREE_NODE_FACTOR(*grand) = AVL_BALANCED;
    AVLTREE_NODE_FACTOR(parent) = AVL_BALANCED;

    return;
}

/******************************************************************************/
static void avltree_left_right_case(AvlTreeNode** grand)
{
    AvlTreeNode* parent = (*grand)->left;

    avltree_right_right_case(&parent);
    (*grand)->left = parent;
    avltree_left_left_case(grand);

    switch (AVLTREE_NODE_FACTOR(*grand))
    {
    case AVL_LEFT_HEAVY:
        AVLTREE_NODE_FACTOR((*grand)->left) = AVL_BALANCED;
        AVLTREE_NODE_FACTOR((*grand)->right) = AVL_RIGHT_HEAVY;
        break;
    case AVL_BALANCED:
        AVLTREE_NODE_FACTOR((*grand)->left) = AVL_BALANCED;
        AVLTREE_NODE_FACTOR((*grand)->right) = AVL_BALANCED;
        break;
    case AVL_RIGHT_HEAVY:
        AVLTREE_NODE_FACTOR((*grand)->left) = AVL_LEFT_HEAVY;
        AVLTREE_NODE_FACTOR((*grand)->right) = AVL_BALANCED;
        break;
    default:
        IF_ERROR_PRINT(FUNC_UNREACHABLE);
        break;
    }

    return;
}

/******************************************************************************/
static void avltree_right_left_case(AvlTreeNode** grand)
{
    AvlTreeNode* parent = (*grand)->right;

    avltree_left_left_case(&parent);
    (*grand)->right = parent;
    avltree_right_right_case(grand);

    switch (AVLTREE_NODE_FACTOR(*grand))
    {
    case AVL_LEFT_HEAVY:
        AVLTREE_NODE_FACTOR((*grand)->left) = AVL_LEFT_HEAVY;
        AVLTREE_NODE_FACTOR((*grand)->right) = AVL_BALANCED;
        break;
    case AVL_BALANCED:
        AVLTREE_NODE_FACTOR((*grand)->left) = AVL_BALANCED;
        AVLTREE_NODE_FACTOR((*grand)->right) = AVL_BALANCED;
        break;
    case AVL_RIGHT_HEAVY:
        AVLTREE_NODE_FACTOR((*grand)->left) = AVL_BALANCED;
        AVLTREE_NODE_FACTOR((*grand)->right) = AVL_RIGHT_HEAVY;
        break;
    default:
        IF_ERROR_PRINT(FUNC_UNREACHABLE);
        break;
    }

    return;
}

/******************************************************************************/
static void avltree_left_case(AvlTreeNode** grand)
{
    AvlTreeNode* parent = (*grand)->left;

    if (AVL_LEFT_HEAVY == AVLTREE_NODE_FACTOR(parent))
    {
        avltree_left_left_case(grand);
    }
    else if (AVL_RIGHT_HEAVY == AVLTREE_NODE_FACTOR(parent))
    {
        avltree_left_right_case(grand);
    }

    return;
}

/******************************************************************************/
static void avltree_right_case(AvlTreeNode** grand)
{
    AvlTreeNode* parent = (*grand)->right;

    if (AVL_LEFT_HEAVY == AVLTREE_NODE_FACTOR(parent))
    {
        avltree_right_left_case(grand);
    }
    else if (AVL_RIGHT_HEAVY == AVLTREE_NODE_FACTOR(parent))
    {
        avltree_right_right_case(grand);
    }

    return;
}

/******************************************************************************/
static void avltree_left_balance(AvlTreeNode** grand, Bool* balanced)
{
    switch (AVLTREE_NODE_FACTOR(*grand))
    {
    case AVL_LEFT_HEAVY:
        avltree_left_case(grand);
        *balanced = TRUE;
        break;
    case AVL_BALANCED:
        AVLTREE_NODE_FACTOR(*grand) = AVL_LEFT_HEAVY;
        break;
    case AVL_RIGHT_HEAVY:
        AVLTREE_NODE_FACTOR(*grand) = AVL_BALANCED;
        break;
    default:
        IF_ERROR_PRINT(FUNC_UNREACHABLE);
        break;
    }

    return;
}

/******************************************************************************/
static void avltree_right_balance(AvlTreeNode** grand, Bool* balanced)
{
    switch (AVLTREE_NODE_FACTOR(*grand))
    {
    case AVL_LEFT_HEAVY:
        AVLTREE_NODE_FACTOR(*grand) = AVL_BALANCED;
        break;
    case AVL_BALANCED:
        AVLTREE_NODE_FACTOR(*grand) = AVL_RIGHT_HEAVY;
        break;
    case AVL_RIGHT_HEAVY:
        avltree_right_case(grand);
        *balanced = TRUE;
        break;
    default:
        IF_ERROR_PRINT(FUNC_UNREACHABLE);
        break;
    }

    return;
}

/******************************************************************************/
FuncRtn avltree_insert_root(AvlTree* thiz, const void* data)
{
    AvlTreeNode* node = NULL;

    IF_ERROR_RETURN(avltree_make_node(data, &node));
    thiz->root = node;

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn avltree_insert_child(CmpFunc data_cmp, AvlTreeNode** sub_root, const void* data, Bool* balanced)
{
    AvlTreeNode* node = NULL;
    int cmp_rslt = data_cmp(data, AVLTREE_NODE_DATA(*sub_root));

    if (cmp_rslt < 0)
    {
        if (NULL == (*sub_root)->left)
        {
            IF_ERROR_RETURN(avltree_make_node(data, &node));
            (*sub_root)->left = node;
        }
        else
        {
            IF_ERROR_RETURN(avltree_insert_child(data_cmp, &((*sub_root)->left), data, balanced));
        }

        if (FALSE == *balanced)
        {
            avltree_left_balance(sub_root, balanced);
        }
    }
    else if (cmp_rslt == 0)
    {
        return FUNC_ALREADY_EXIST;
    }
    else
    {
        if (NULL == (*sub_root)->right)
        {
            IF_ERROR_RETURN(avltree_make_node(data, &node));
            (*sub_root)->right = node;
        }
        else
        {
            IF_ERROR_RETURN(avltree_insert_child(data_cmp, &((*sub_root)->right), data, balanced));
        }

        if (FALSE == *balanced)
        {
            avltree_right_balance(sub_root, balanced);
        }
    }

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn avltree_get_place(CmpFunc data_cmp, const void* data, AvlTreeNode*** place)
{
    int cmp_rslt = 0;
    FuncRtn func_rslt = FUNC_ERROR;

    if (NULL == **place)
    {
        func_rslt = FUNC_NOT_EXIST;
    }
    else
    {
        cmp_rslt = data_cmp(data, AVLTREE_NODE_DATA(**place));
        if (cmp_rslt < 0)
        {
            *place = &((**place)->left);
            func_rslt = avltree_get_place(data_cmp, data, place);
        }
        else if (cmp_rslt == 0)
        {
            func_rslt = FUNC_ALREADY_EXIST;
        }
        else
        {
            *place = &((**place)->right);
            func_rslt = avltree_get_place(data_cmp, data, place);
        }
    }

    return func_rslt;
}

/******************************************************************************/
FuncRtn avltree_preorder_traverse(const AvlTreeNode* root, VisitFunc visit, void* context)
{
    if (NULL != root)
    {
        IF_ERROR_RETURN(visit(AVLTREE_NODE_DATA(root), context));
        IF_ERROR_RETURN(avltree_preorder_traverse(root->left, visit, context));
        IF_ERROR_RETURN(avltree_preorder_traverse(root->right, visit, context));
    }

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn avltree_inorder_traverse(const AvlTreeNode* root, VisitFunc visit, void* context)
{
    if (NULL != root)
    {
        IF_ERROR_RETURN(avltree_inorder_traverse(root->left, visit, context));
        IF_ERROR_RETURN(visit(AVLTREE_NODE_DATA(root), context));
        IF_ERROR_RETURN(avltree_inorder_traverse(root->right, visit, context));
    }

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn avltree_postorder_traverse(const AvlTreeNode* root, VisitFunc visit, void* context)
{
    if (NULL != root)
    {
        IF_ERROR_RETURN(avltree_postorder_traverse(root->left, visit, context));
        IF_ERROR_RETURN(avltree_postorder_traverse(root->right, visit, context));
        IF_ERROR_RETURN(visit(AVLTREE_NODE_DATA(root), context));
    }

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn avltree_inner_print(AvlTreeNode* root, DataPrintFunc print)
{
    if (NULL != root)
    {
        IF_ERROR_RETURN(avltree_inner_print(root->left, print));
        print(AVLTREE_NODE_DATA(root));
        IF_ERROR_RETURN(avltree_inner_print(root->right, print));
    }

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn avltree_inner_get_pos_by_data(CmpFunc data_cmp, const AvlTreeNode* sub_root, const void* data, AvlTreeNodePos* pos)
{
    int cmp_rslt = data_cmp(data, AVLTREE_NODE_DATA(sub_root));
    if (cmp_rslt < 0)
    {
        if (NULL == sub_root->left)
        {
            return FUNC_NOT_EXIST;
        }
        else
        {
            pos->row += 1;
            pos->col <<= 1;
            return avltree_inner_get_pos_by_data(data_cmp, sub_root->left, data, pos);
        }
    }
    else if (cmp_rslt == 0)
    {
        return FUNC_OK;
    }
    else
    {
        if (NULL == sub_root->right)
        {
            return FUNC_NOT_EXIST;
        }
        else
        {
            pos->row += 1;
            pos->col <<= 1;
            pos->col |= 1;
            return avltree_inner_get_pos_by_data(data_cmp, sub_root->right, data, pos);
        }
    }

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn avltree_inorder_get_all_nodes(const AvlTreeNode* root, DList* list)
{
    if (NULL != root)
    {
        IF_ERROR_RETURN(avltree_inorder_get_all_nodes(root->left, list));
        IF_ERROR_RETURN(dlist_append_tail(list, (void *)root));
        IF_ERROR_RETURN(avltree_inorder_get_all_nodes(root->right, list));
    }

    return FUNC_OK;
}

/******************************************************************************/

#endif

#if CODE_SEPARATOR("Outer Function", 1)
/******************************************************************************/

#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

