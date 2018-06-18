/******************************************************************************/
/**
 * @file        btree.h
 * @brief       binary tree
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/

#include "bintree.h"
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

#endif  /* CODE_SEPARATOR("Inner Function", 1) */

#if CODE_SEPARATOR("Outer Function", 1)
/******************************************************************************/
void* bintree_get_max(const BinTree* thiz)
{
    BinTreeNode* iter = NULL;

    if (NULL == thiz || NULL == thiz->root)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return NULL;
    }

    for (iter = thiz->root; NULL != iter->right; iter = iter->right)
    {
        /* nothing need to be done */
    }

    return iter->data;
}

/******************************************************************************/
void* bintree_get_min(const BinTree* thiz)
{
    BinTreeNode* iter = NULL;

    if (NULL == thiz || NULL == thiz->root)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return NULL;
    }

    for (iter = thiz->root; NULL != iter->left; iter = iter->left)
    {
        /* nothing need to be done */
    }

    return iter->data;
}

/******************************************************************************/
FuncRtn bintree_insert(BinTree* thiz, const void* data)
{
    FuncRtn func_rslt = FUNC_ERROR;
    BinTreeNode** place = NULL;
    BinTreeNode* node = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);

    place = &(thiz->root);
    func_rslt = bintree_get_place(thiz->data_cmp, data, &place);
    if (FUNC_NOT_EXIST == func_rslt)
    {
        IF_ERROR_RETURN(bintree_make_node(data, &node));
        *place = node;
        thiz->size++;
        func_rslt = FUNC_OK;
    }

    return func_rslt;
}

/******************************************************************************/
FuncRtn bintree_remove(BinTree* thiz, Bool free_flag, void** data)
{
    FuncRtn func_rslt = FUNC_ERROR;
    BinTreeNode** place = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(data);

    place = &(thiz->root);
    func_rslt = bintree_get_place(thiz->data_cmp, *data, &place);
    if (FUNC_ALREADY_EXIST == func_rslt)
    {
        *data = (*place)->data;
        if (*place == thiz->root)
        {
            func_rslt = bintree_remove_root(thiz, free_flag);
        }
        else
        {
            func_rslt = bintree_remove_child(thiz, place, free_flag);
        }
    }

    return func_rslt;
}

/******************************************************************************/
FuncRtn bintree_search(BinTree* thiz, void** data)
{
    FuncRtn func_rslt = FUNC_ERROR;
    BinTreeNode** place = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(data);

    place = &(thiz->root);
    func_rslt = bintree_get_place(thiz->data_cmp, *data, &place);
    if (FUNC_ALREADY_EXIST == func_rslt)
    {
        *data = (*place)->data;
        func_rslt = FUNC_OK;
    }

    return func_rslt;
}

/******************************************************************************/
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

