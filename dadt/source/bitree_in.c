/******************************************************************************/
/**
 * @file        btree.h
 * @brief       binary tree
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/

#include "bit_op.h"
#include "bitree.h"
#include "bitree_in.h"
#include "dlist.h"      /* used by biree_get_all_data */
#include "macro.h"
#include "mem_op.h"
#include "seqqueue.h"   /* used by bitree_levelorder_traversal */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

#if CODE_SEPARATOR("Inner Definition", 1)

#endif /* CODE_SEPARATOR("Inner Definition", 1) */

#if CODE_SEPARATOR("Inner Function", 1)
/******************************************************************************/
FuncRtn bitree_make_node(const void* data, BiTreeNode** node)
{
    IF_ERROR_EXIT(alloc_memory((void **)node, sizeof(BiTreeNode)));
    (*node)->data = (void *)data;

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn bitree_free_node(BiTreeNode** node, Bool free_flag, FreeFunc data_free)
{
    if (TRUE == free_flag && NULL != data_free)
    {
        data_free(&((*node)->data));
    }

    free_memory((void **)node);

    return FUNC_OK;
}

/******************************************************************************/
size_t bitree_inner_get_depth(const BiTreeNode* root)
{
    if (NULL == root)
    {
        return 0;
    }

    return GET_MORE(bitree_inner_get_depth(root->left), bitree_inner_get_depth(root->right)) + 1;
}

/******************************************************************************/
BiTreeNode* bitree_get_max_node(const BiTreeNode* root, CmpFunc data_cmp)
{
    BiTreeNode* max = NULL;
    BiTreeNode* sub_max = NULL;

    if (NULL == root || NULL == root->left || NULL == root->right)
    {
        return (BiTreeNode *)root;
    }

    max = (BiTreeNode *)root;
    if (NULL != root->left)
    {
        sub_max = bitree_get_max_node(root->left, data_cmp);
        if (data_cmp(sub_max->data, max->data) > 0)
        {
            max = sub_max;
        }
    }

    if (NULL != root->right)
    {
        sub_max = bitree_get_max_node(root->right, data_cmp);
        if (data_cmp(sub_max->data, max->data) > 0)
        {
            max = sub_max;
        }
    }

    return max;
}

/******************************************************************************/
BiTreeNode* bitree_get_min_node(const BiTreeNode* root, CmpFunc data_cmp)
{
    BiTreeNode* min = NULL;
    BiTreeNode* sub_min = NULL;

    if (NULL == root || NULL == root->left || NULL == root->right)
    {
        return (BiTreeNode *)root;
    }

    min = (BiTreeNode *)root;
    if (NULL != root->left)
    {
        sub_min = bitree_get_min_node(root->left, data_cmp);
        if (data_cmp(sub_min->data, min->data) < 0)
        {
            min = sub_min;
        }
    }

    if (NULL != root->right)
    {
        sub_min = bitree_get_min_node(root->right, data_cmp);
        if (data_cmp(sub_min->data, min->data) < 0)
        {
            min = sub_min;
        }
    }

    return min;
}

/******************************************************************************/
BiTreeNode* bitree_get_root(const BiTree* thiz)
{
    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return NULL;
    }

    return thiz->root;
}

/******************************************************************************/
Bool bitree_is_root(BiTree* thiz, BiTreeNode* node)
{
    if (thiz->root == node)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/******************************************************************************/
Bool bitree_is_leaf(BiTreeNode* node)
{
    if (NULL == node->left && NULL == node->right)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/******************************************************************************/
FuncRtn bitree_insert_child(BiTree* thiz, BiTreeNode* parent, eBiTreeChildPos pos, const void* data)
{
    BiTreeNode* child = NULL, **place = NULL;

    if (NULL == parent)
    {
        if (0 < thiz->size)
        {
            return FUNC_UNREACHABLE;
        }
        place = &(thiz->root);
    }
    else if (BITREE_CHILD_LEFT == pos)
    {
        if (NULL != parent->left)
        {
            return FUNC_UNREACHABLE;
        }
        place = &(parent->left);
    }
    else if (BITREE_CHILD_RIGHT == pos)
    {
        if (NULL != parent->right)
        {
            return FUNC_UNREACHABLE;
        }
        place = &(parent->right);
    }
    else
    {
        return FUNC_UNREACHABLE;
    }

    IF_ERROR_RETURN(bitree_make_node(data, &child));

    *place = child;
    thiz->size++;

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn bitree_remove_child(BiTree* thiz, BiTreeNode* parent, 
        eBiTreeChildPos pos, Bool free_flag, void** data)
{
    BiTreeNode** place = NULL;

    if (0 == thiz->size)
    {
        return FUNC_NOT_EXIST;
    }

    if (NULL == parent)
    {
        place = &(thiz->root);
    }
    else if (BITREE_CHILD_LEFT == pos)
    {
        place = &(parent->left);
    }
    else if (BITREE_CHILD_RIGHT == pos)
    {
        place = &(parent->right);
    }
    else
    {
        return FUNC_UNREACHABLE;
    }

    if (NULL != *place)
    {
        bitree_remove_child(thiz, *place, BITREE_CHILD_LEFT, TRUE, data);
        bitree_remove_child(thiz, *place, BITREE_CHILD_RIGHT, TRUE, data);

        if (TRUE == free_flag && NULL != thiz->data_free)
        {
            *data = NULL;
        }
        else
        {
            *data = (*place)->data;
        }
        IF_ERROR_RETURN(bitree_free_node(place, free_flag, thiz->data_free));
        thiz->size--;
    }
    else
    {
        return FUNC_NOT_EXIST;
    }

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn bitree_preorder_traverse(const BiTreeNode* root, VisitFunc visit, void* context)
{
    if (NULL != root)
    {
        IF_ERROR_RETURN(visit(root->data, context));
        IF_ERROR_RETURN(bitree_preorder_traverse(root->left, visit, context));
        IF_ERROR_RETURN(bitree_preorder_traverse(root->right, visit, context));
    }

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn bitree_inorder_traverse(const BiTreeNode* root, VisitFunc visit, void* context)
{
    if (NULL != root)
    {
        IF_ERROR_RETURN(bitree_inorder_traverse(root->left, visit, context));
        IF_ERROR_RETURN(visit(root->data, context));
        IF_ERROR_RETURN(bitree_inorder_traverse(root->right, visit, context));
    }

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn bitree_postorder_traverse(const BiTreeNode* root, VisitFunc visit, void* context)
{
    if (NULL != root)
    {
        IF_ERROR_RETURN(bitree_postorder_traverse(root->left, visit, context));
        IF_ERROR_RETURN(bitree_postorder_traverse(root->right, visit, context));
        IF_ERROR_RETURN(visit(root->data, context));
    }

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn bitree_inner_print(BiTreeNode* root, DataPrintFunc print)
{
    if (NULL != root)
    {
        IF_ERROR_RETURN(bitree_inner_print(root->left, print));
        print(root->data);
        IF_ERROR_RETURN(bitree_inner_print(root->right, print));
    }

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn bitree_get_data_by_traversal(void* data, void* context)
{
    DList* list = (DList *)context;

    IF_ERROR_RETURN(dlist_append_tail(list, data));

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn bitree_inner_get_pos_by_data(CmpFunc data_cmp, const BiTreeNode* sub_root, const void* data, BiTreeNodePos* pos)
{
    int cmp_rslt = data_cmp(data, sub_root->data);
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
            return bitree_inner_get_pos_by_data(data_cmp, sub_root->left, data, pos);
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
            return bitree_inner_get_pos_by_data(data_cmp, sub_root->right, data, pos);
        }
    }

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn bitree_get_node_by_pos(const BiTree* thiz, const BiTreeNodePos* pos, BiTreeNode** node)
{
    size_t row, flag;

    if (pos->col >= (size_t)(1 << pos->row))
    {
        return FUNC_PARAM_RANGE;
    }
    *node = thiz->root;

    for (row = pos->row; row > 0 && NULL != *node; row--)
    {
        flag = get_bit(pos->col, row - 1);
        if (0 == flag)
        {
            *node = (*node)->left;
        }
        else
        {
            *node = (*node)->right;
        }
    }

    if (NULL == *node)
    {
        return FUNC_NOT_EXIST;
    }
    return FUNC_OK;
}

/******************************************************************************/

#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

