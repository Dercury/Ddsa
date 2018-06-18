/******************************************************************************/
/**
 * @file        avltree.h
 * @brief       binary tree
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/

#include "avltree.h"
#include "avltree_in.h"
#include "macro.h"
#include "mem_op.h"
#include "seqqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str_op.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

#if CODE_SEPARATOR("Inner Function", 1)
/******************************************************************************/
FuncRtn avltree_remove_child(AvlTree* thiz, AvlTreeNode* parent, 
        eBiTreeChildPos pos, Bool free_flag, void** data)
{
    AvlTreeNode** place = NULL;

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
        avltree_remove_child(thiz, *place, BITREE_CHILD_LEFT, TRUE, data);
        avltree_remove_child(thiz, *place, BITREE_CHILD_RIGHT, TRUE, data);

        if (TRUE == free_flag && NULL != thiz->data_free)
        {
            *data = NULL;
        }
        else
        {
            *data = (*place)->data;
        }
        IF_ERROR_RETURN(avltree_free_node(place, free_flag, thiz->data_free));
        thiz->size--;
    }
    else
    {
        return FUNC_NOT_EXIST;
    }

    return FUNC_OK;
}

#endif

#if CODE_SEPARATOR("Outer Function", 1)
/******************************************************************************/
FuncRtn avltree_destroy(AvlTree** thiz)
{
    void* data = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(*thiz);

    if (NULL != (*thiz)->root)
    {
        IF_ERROR_RETURN(avltree_remove_child(*thiz, NULL, BITREE_CHILD_LEFT, TRUE, &data));
    }

    free_memory((void **)thiz);

    return FUNC_OK;
}

/******************************************************************************/
void* avltree_get_max(const AvlTree* thiz)
{
    AvlTreeNode* node = NULL;

    if(NULL != thiz && FUNC_OK == avltree_get_max_node(thiz->root, &node))
    {
        return AVLTREE_NODE_DATA(node);
    }

    return NULL;
}

/******************************************************************************/
void* avltree_get_min(const AvlTree* thiz)
{
    AvlTreeNode* node = NULL;

    if(NULL != thiz && FUNC_OK == avltree_get_min_node(thiz->root, &node))
    {
        return AVLTREE_NODE_DATA(node);
    }

    return NULL;
}

/******************************************************************************/
FuncRtn avltree_preorder_traversal(const AvlTree* thiz, VisitFunc visit, void* context)
{
    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(visit);

    return avltree_preorder_traverse(thiz->root, visit, context);
}

/******************************************************************************/
FuncRtn avltree_inorder_traversal(const AvlTree* thiz, VisitFunc visit, void* context)
{
    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(visit);

    return avltree_inorder_traverse(thiz->root, visit, context);
}

/******************************************************************************/
FuncRtn avltree_postorder_traversal(const AvlTree* thiz, VisitFunc visit, void* context)
{
    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(visit);

    return avltree_postorder_traverse(thiz->root, visit, context);
}

/******************************************************************************/
FuncRtn avltree_levelorder_traversal(const AvlTree* thiz, VisitFunc visit, void* context)
{
    SeqQueue* queue = NULL;
    AvlTreeNode* node = NULL;
    size_t i = 0;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(visit);

    queue = seqqueue_create(thiz->size);
    IF_ERROR_RETURN(seqqueue_enqueue(queue, thiz->root));

    for (i = 0; i < thiz->size; )
    {
        IF_ERROR_RETURN(seqqueue_dequeue(queue, (void **)&node));
        if (NULL != node)
        {
            IF_ERROR_RETURN(visit(AVLTREE_NODE_DATA(node), context));
            if (NULL != node->left)
            {
                IF_ERROR_RETURN(seqqueue_enqueue(queue, node->left));
            }
            if (NULL != node->right)
            {
                IF_ERROR_RETURN(seqqueue_enqueue(queue, node->right));
            }
            i++;
        }
    }

    IF_ERROR_RETURN(seqqueue_destroy(&queue));

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn avltree_get_all_data(const AvlTree* thiz, DList* list, eAvlTreeTraversalMethod method)
{
    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(list);

    switch (method)
    {
    case BITREE_PREORDER_TRAVERSAL:
        IF_ERROR_RETURN(avltree_preorder_traversal(thiz, avltree_get_data_by_traversal, list));
        break;
    case BITREE_INORDER_TRAVERSAL:
        IF_ERROR_RETURN(avltree_inorder_traversal(thiz, avltree_get_data_by_traversal, list));
        break;
    case BITREE_POSTORDER_TRAVERSAL:
        IF_ERROR_RETURN(avltree_postorder_traversal(thiz, avltree_get_data_by_traversal, list));
        break;
    case BITREE_LEVELORDER_TRAVERSAL:
        IF_ERROR_RETURN(avltree_levelorder_traversal(thiz, avltree_get_data_by_traversal, list));
        break;
    default:
        IF_ERROR_RETURN(FUNC_UNREACHABLE);
        break;
    }

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn avltree_get_pos_by_data(const AvlTree* thiz, const void* data, AvlTreeNodePos* pos)
{
    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(pos);

    if (NULL == thiz->root)
    {
        return FUNC_NOT_EXIST;
    }
    IF_ERROR_RETURN(avltree_inner_get_pos_by_data(thiz->data_cmp, thiz->root, data, pos));

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn avltree_get_data_by_pos(const AvlTree* thiz, const AvlTreeNodePos* pos, void** data)
{
    AvlTreeNode* node = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(pos);
    PARAM_CHECK_NULL_POINTER(data);

    IF_ERROR_RETURN(avltree_get_node_by_pos(thiz, pos, &node));

    *data = AVLTREE_NODE_DATA(node);

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn avltree_set_data_by_pos(const AvlTree* thiz, const AvlTreeNodePos* pos, const void* data)
{
    AvlTreeNode* node = NULL;
    void* temp = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(pos);

    IF_ERROR_RETURN(avltree_get_node_by_pos(thiz, pos, &node));

    temp = AVLTREE_NODE_DATA(node);
    AVLTREE_NODE_DATA(node) = (void *)data;

    if (NULL != thiz->data_free)
    {
        (thiz->data_free)(&temp);
    }

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn avltree_insert(AvlTree* thiz, const void* data)
{
    FuncRtn func_rslt = FUNC_OK;
    Bool balanced = FALSE;

    PARAM_CHECK_NULL_POINTER(thiz);

    if (NULL == thiz->root)
    {
        func_rslt = avltree_insert_root(thiz, data);
    }
    else
    {
        func_rslt = avltree_insert_child(thiz->data_cmp, &(thiz->root), data, &balanced);
    }

    if (FUNC_OK == func_rslt)
    {
        thiz->size++;
    }

    return func_rslt;
}

/******************************************************************************/
FuncRtn avltree_remove(AvlTree* thiz, Bool free_flag, void** data)
{
    FuncRtn func_rslt = FUNC_ERROR;
    AvlTreeNode** place = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);

    place = &(thiz->root);
    func_rslt = avltree_get_place(thiz->data_cmp, *data, &place);
    if (FUNC_ALREADY_EXIST == func_rslt && TRUE == AVLTREE_NODE_VALID(*place))
    {
        *data = AVLTREE_NODE_DATA(*place);
        AVLTREE_NODE_VALID(*place) = FALSE;
        func_rslt = FUNC_OK;
    }

    return func_rslt;
}

/******************************************************************************/
FuncRtn avltree_search(AvlTree* thiz, void** data)
{
    FuncRtn func_rslt = FUNC_ERROR;
    AvlTreeNode** place = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);

    place = &(thiz->root);
    func_rslt = avltree_get_place(thiz->data_cmp, *data, &place);
    if (FUNC_ALREADY_EXIST == func_rslt && TRUE == AVLTREE_NODE_VALID(*place))
    {
        *data = AVLTREE_NODE_DATA(*place);
        func_rslt = FUNC_OK;
    }

    return func_rslt;
}

/******************************************************************************/
FuncRtn avltree_print(AvlTree* thiz, DataPrintFunc print)
{
    return avltree_inner_print(thiz->root, print);
}

/******************************************************************************/
FuncRtn avltree_get_figure_string(const AvlTree* thiz, DataToStrFunc data_to_string, size_t data_string_len, char** figure_string)
{
    char* data_string = NULL;
    size_t depth, dtemp, figure_row, figure_col;
    size_t data_string_size;
    size_t row, col, i, j;
    DList* list = NULL;
    AvlTreeNode* node = NULL;
    AvlTreeNodePos pos;
    size_t bias_row, bias_col_left, bias_col_right, bias_end_row;

    depth = avltree_get_depth(thiz);
    if (0 == depth)
    {
        return FUNC_SPACE_EMPTY;
    }
    depth++;    /* to avoid conflict of invalid nodes at the deepest level */

    figure_row = (1 << depth) - 1;
    figure_col = (1 << (depth - 1)) * (data_string_len + 1);

    /* get all data */
    list = dlist_create(NULL, NULL);
    IF_ERROR_RETURN(avltree_inorder_get_all_nodes(thiz->root, list));

    /* prepare figure_string */
    IF_ERROR_EXIT(alloc_memory((void **)figure_string, figure_row* figure_col + 1));
    memset(*figure_string, ' ', figure_row* figure_col);
    for (i = 0; i < figure_row; i++)
    {
        *(*figure_string + i* figure_col + figure_col - 1) = '\n';
    }

    /* output data to figure_string */
    IF_ERROR_EXIT(alloc_memory((void **)&data_string, data_string_len));
    for (i = 0; i < thiz->size; i++)
    {
        IF_ERROR_RETURN(dlist_remove_head(list, FALSE, (void **)&node));
        memset(&pos, 0, sizeof(AvlTreeNodePos));
        IF_ERROR_RETURN(avltree_get_pos_by_data(thiz, AVLTREE_NODE_DATA(node), &pos));
        row = 0;                                            /* root pos row */
        col = (1 << depth) - (data_string_len + 1) / 2;     /* root pos col */
        for (dtemp = depth, j = 0; j < pos.row; dtemp--, j++)
        {
            row += 1 << (dtemp - 1);
            col -= 1 << (dtemp - 1);    /* col of the first node in the row */
        }
        col += pos.col * 4* (1 << (dtemp -1));

        memset(data_string, 0, data_string_len);
        (void)data_to_string(AVLTREE_NODE_DATA(node), data_string, data_string_len);
        data_string_size = GET_LESS(data_string_len, (size_t)strlen(data_string));
        memcpy(*figure_string + row* figure_col + col, data_string, data_string_size);

        if (FALSE == AVLTREE_NODE_VALID(node))
        {
            *(*figure_string + row* figure_col + col - 1) = '(';
            *(*figure_string + row* figure_col + col + data_string_size) = ')';
        }

        bias_row = row + 1;
        bias_col_left = col + data_string_len / 2 - 1;
        bias_col_right = col + data_string_len / 2 + 1;
        if (1 > dtemp)
        {
            continue;
        }
        bias_end_row = row + (1 << (dtemp - 1));
        for (; bias_row < bias_end_row; bias_row++, bias_col_left--, bias_col_right++)
        {
            *(*figure_string + bias_row* figure_col + bias_col_left) = '/';
            *(*figure_string + bias_row* figure_col + bias_col_right) = '\\';
        }
    }

    free_memory((void **)&data_string);
    IF_ERROR_RETURN(dlist_destroy(&list));

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn avltree_print_figure(const AvlTree* thiz, DataToStrFunc data_to_string,
            size_t data_string_len, const char* filename, const char* mode)
{
    char* figure_string = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(data_to_string);
    PARAM_CHECK_RANGE(data_string_len, 2, 7);

    avltree_get_figure_string(thiz, data_to_string, data_string_len, &figure_string);

    IF_ERROR_RETURN(print_to_file(figure_string, filename, mode));

    free_memory((void **)&figure_string);

    return FUNC_OK;
}

/******************************************************************************/

#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

