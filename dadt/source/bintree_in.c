/******************************************************************************/
/**
 * @file        btree.h
 * @brief       binary tree
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/

#include "bintree_in.h"
#include "macro.h"
#include "mem_op.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

#if CODE_SEPARATOR("Inner Function", 1)

/******************************************************************************/
FuncRtn bintree_get_max_node(BinTreeNode* root, BinTreeNode** max)
{
    BinTreeNode* iter = NULL;

    for (iter = root; NULL != iter->right; iter = iter->right)
    {
        /* nothing need to be done */
    }
    *max = iter;

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn bintree_get_min_node(BinTreeNode* root, BinTreeNode** min)
{
    BinTreeNode* iter = NULL;

    for (iter = root; NULL != iter->left; iter = iter->left)
    {
        /* nothing need to be done */
    }
    *min = iter;

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn bintree_get_place(CmpFunc data_cmp, const void* data, BinTreeNode*** place)
{
    int cmp_rslt = 0;
    FuncRtn func_rslt = FUNC_ERROR;

    if (NULL == **place)
    {
        func_rslt = FUNC_NOT_EXIST;
    }
    else
    {
        cmp_rslt = data_cmp(data, (**place)->data);
        if (cmp_rslt < 0)
        {
            *place = &((**place)->left);
            func_rslt = bintree_get_place(data_cmp, data, place);
        }
        else if (cmp_rslt == 0)
        {
            func_rslt = FUNC_ALREADY_EXIST;
        }
        else
        {
            *place = &((**place)->right);
            func_rslt = bintree_get_place(data_cmp, data, place);
        }
    }

    return func_rslt;
}

/******************************************************************************/
FuncRtn bintree_remove_root(BinTree* thiz, Bool free_flag)
{
    BinTreeNode* current = thiz->root;
    BinTreeNode* prev = NULL;

    if (NULL == current->left)
    {
        thiz->root = current->right;
    }
    else if (NULL == current->right)
    {
        thiz->root = current->left;
    }
    else
    {
        IF_ERROR_RETURN(bintree_get_max_node(current->left, &prev));
        prev->right = current->right;
        thiz->root = current->left;
    }
    thiz->size--;

    return bitree_free_node(&current, free_flag, thiz->data_free);
}

/******************************************************************************/
FuncRtn bintree_remove_leaf(BinTree* thiz, BinTreeNode** place, Bool free_flag)
{
    BinTreeNode* current = *place;

    *place = NULL;
    thiz->size--;

    return bintree_free_node(&current, free_flag, thiz->data_free);
}

/******************************************************************************/
FuncRtn bintree_remove_bole(BinTree* thiz, BinTreeNode** place, Bool free_flag)
{
    BinTreeNode* current = *place;
    BinTreeNode* left_max = NULL;

    if (NULL == current->left)
    {
        *place = current->right;
    }
    else if (NULL == current->right)
    {
        *place = current->left;
    }
    else
    {
        IF_ERROR_RETURN(bintree_get_max_node(current->left, &left_max));
        left_max->right = current->right;
        *place = current->left;
    }
    thiz->size--;

    return bintree_free_node(&current, free_flag, thiz->data_free);
}

/******************************************************************************/
FuncRtn bintree_remove_child(BinTree* thiz, BinTreeNode** place, Bool free_flag)
{
    FuncRtn func_rslt = FUNC_ERROR;
    BinTreeNode* current = *place;

    if (bintree_is_leaf(current))
    {
        func_rslt = bintree_remove_leaf(thiz, place, free_flag);
    }
    else
    {
        func_rslt = bintree_remove_bole(thiz, place, free_flag);
    }

    return func_rslt;
}

#endif  /* CODE_SEPARATOR("Inner Function", 1) */

#if CODE_SEPARATOR("Outer Function", 1)
/******************************************************************************/
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

