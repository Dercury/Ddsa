/******************************************************************************/
/**
 * @file        btree.h
 * @brief       binary tree
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/

#include "bitree.h"
#include "bitree_in.h"
#include "dlist.h"      /* used by biree_get_all_data */
#include "macro.h"
#include "mem_op.h"
#include "seqqueue.h"   /* used by bitree_levelorder_traversal */
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

#endif  /* CODE_SEPARATOR("Inner Function", 1) */

#if CODE_SEPARATOR("Outer Function", 1)
/******************************************************************************/
BiTree* bitree_create(FreeFunc data_free, CmpFunc data_cmp)
{
    BiTree* thiz = NULL;

    IF_ERROR_EXIT(alloc_memory((void **)&thiz, sizeof(BiTree)));

    thiz->root = NULL;
    thiz->size = 0;
    thiz->data_free = data_free;
    thiz->data_cmp = data_cmp;

    return thiz;
}

/******************************************************************************/
FuncRtn bitree_destroy(BiTree** thiz)
{
    void* data = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(*thiz);

    if (NULL != (*thiz)->root)
    {
        IF_ERROR_RETURN(bitree_remove_child(*thiz, NULL, BITREE_CHILD_LEFT, TRUE, &data));
    }

    free_memory((void **)thiz);

    return FUNC_OK;
}

/******************************************************************************/
size_t bitree_get_size(const BiTree* thiz)
{
    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return 0;
    }

    return thiz->size;
}

/******************************************************************************/
size_t bitree_get_depth(const BiTree* thiz)
{
    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return 0;
    }

    return bitree_inner_get_depth(thiz->root);
}

/******************************************************************************/
void* bitree_get_max(const BiTree* thiz)
{
    BiTreeNode* max_node = NULL;

    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return NULL;
    }

    max_node = bitree_get_max_node(thiz->root, thiz->data_cmp);

    return (NULL != max_node) ? max_node->data : NULL;
}

/******************************************************************************/
void* bitree_get_min(const BiTree* thiz)
{
    BiTreeNode* min_node = NULL;

    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return NULL;
    }

    min_node = bitree_get_min_node(thiz->root, thiz->data_cmp);

    return (NULL != min_node) ? min_node->data : NULL;
}

/******************************************************************************/
FreeFunc bitree_get_free_func(const BiTree* thiz)
{
    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return NULL;
    }

    return thiz->data_free;
}

/******************************************************************************/
void bitree_set_free_func(BiTree* thiz, FreeFunc data_free)
{
    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return;
    }

    thiz->data_free = data_free;
}

/******************************************************************************/
CmpFunc bitree_get_cmp_func(const BiTree* thiz)
{
    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return NULL;
    }

    return thiz->data_cmp;
}

/******************************************************************************/
void bitree_set_cmp_func(BiTree* thiz, CmpFunc data_cmp)
{
    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return;
    }

    thiz->data_cmp = data_cmp;
}

/******************************************************************************/
FuncRtn bitree_preorder_traversal(const BiTree* thiz, VisitFunc visit, void* context)
{
    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(visit);

    return bitree_preorder_traverse(thiz->root, visit, context);
}

/******************************************************************************/
FuncRtn bitree_inorder_traversal(const BiTree* thiz, VisitFunc visit, void* context)
{
    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(visit);

    return bitree_inorder_traverse(thiz->root, visit, context);
}

/******************************************************************************/
FuncRtn bitree_postorder_traversal(const BiTree* thiz, VisitFunc visit, void* context)
{
    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(visit);

    return bitree_postorder_traverse(thiz->root, visit, context);
}

/******************************************************************************/
FuncRtn bitree_levelorder_traversal(const BiTree* thiz, VisitFunc visit, void* context)
{
    SeqQueue* queue = NULL;
    BiTreeNode* node = NULL;
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
            IF_ERROR_RETURN(visit(node->data, context));
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
FuncRtn bitree_get_all_data(const BiTree* thiz, DList* list, eBiTreeTraversalMethod method)
{
    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(list);

    switch (method)
    {
    case BITREE_PREORDER_TRAVERSAL:
        IF_ERROR_RETURN(bitree_preorder_traversal(thiz, bitree_get_data_by_traversal, list));
    	break;
    case BITREE_INORDER_TRAVERSAL:
        IF_ERROR_RETURN(bitree_inorder_traversal(thiz, bitree_get_data_by_traversal, list));
        break;
    case BITREE_POSTORDER_TRAVERSAL:
        IF_ERROR_RETURN(bitree_postorder_traversal(thiz, bitree_get_data_by_traversal, list));
        break;
    case BITREE_LEVELORDER_TRAVERSAL:
        IF_ERROR_RETURN(bitree_levelorder_traversal(thiz, bitree_get_data_by_traversal, list));
        break;
    default:
        IF_ERROR_RETURN(FUNC_UNREACHABLE);
        break;
    }

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn bitree_get_pos_by_data(const BiTree* thiz, const void* data, BiTreeNodePos* pos)
{
    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(pos);

    if (NULL == thiz->root)
    {
        return FUNC_NOT_EXIST;
    }
    IF_ERROR_RETURN(bitree_inner_get_pos_by_data(thiz->data_cmp, thiz->root, data, pos));

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn bitree_get_data_by_pos(const BiTree* thiz, const BiTreeNodePos* pos, void** data)
{
    BiTreeNode* node = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(pos);
    PARAM_CHECK_NULL_POINTER(data);

    IF_ERROR_RETURN(bitree_get_node_by_pos(thiz, pos, &node));

    *data = node->data;

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn bitree_set_data_by_pos(const BiTree* thiz, const BiTreeNodePos* pos, const void* data)
{
    BiTreeNode* node = NULL;
    void* temp = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(pos);

    IF_ERROR_RETURN(bitree_get_node_by_pos(thiz, pos, &node));

    temp = node->data;
    node->data = (void *)data;

    if (NULL != thiz->data_free)
    {
        (thiz->data_free)(&temp);
    }

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn bitree_print(BiTree* thiz, DataPrintFunc print)
{
    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(print);

    return bitree_inner_print(thiz->root, print);
}

void bitree_get_figure_size(const BiTree* thiz, size_t data_string_len,
        size_t* figure_row, size_t* figure_col)
{
    size_t depth = bitree_get_depth(thiz);

    *figure_row = (1 << (depth + 1)) - 1;
    *figure_col = (1 << depth) * (data_string_len + 1);

    return;
}

/******************************************************************************/
FuncRtn bitree_get_figure_string(const BiTree* thiz, DataToStrFunc data_to_string, 
        size_t data_string_len, char** figure_string)
{
    char* data_string = NULL;
    size_t depth, dtemp, figure_row, figure_col;
    size_t data_string_size;
    size_t row, col, i, j;
    DList* list = NULL;
    void* data = NULL;
    BiTreeNodePos pos;
    size_t bias_row, bias_col_left, bias_col_right, bias_end_row;

    depth = bitree_get_depth(thiz);
    if (0 == depth)
    {
        return FUNC_SPACE_EMPTY;
    }
    depth++;    /* to avoid conflict of invalid nodes at the deepest level */

    figure_row = (1 << depth) - 1;
    figure_col = (1 << (depth - 1)) * (data_string_len + 1);

    /* prepare figure_string */
    memset(*figure_string, ' ', figure_row * figure_col);
    for (i = 0; i < figure_row; i++)
    {
        *(*figure_string + i * figure_col + figure_col - 1) = '\n';
    }

    /* get all data */
    list = dlist_create(NULL, NULL);
    IF_ERROR_RETURN(bitree_get_all_data(thiz, list, BITREE_INORDER_TRAVERSAL));

    /* output data to figure_string */
    IF_ERROR_EXIT(alloc_memory((void**)&data_string, data_string_len));
    for (i = 0; i < thiz->size; i++)
    {
        IF_ERROR_RETURN(dlist_remove_head(list, FALSE, &data));
        memset(&pos, 0, sizeof(BiTreeNodePos));
        IF_ERROR_RETURN(bitree_get_pos_by_data(thiz, data, &pos));
        row = 0;                                    /* root pos row */
        col = (1 << depth) - (data_string_len + 1) / 2;   /* root pos col */
        for (dtemp = depth, j = 0; j < pos.row; dtemp--, j++)
        {
            row += 1 << (dtemp - 1);
            col -= 1 << (dtemp - 1);    /* col of the first node in the row */
        }
        col += pos.col * (data_string_len + 1) * (1 << (dtemp -1));

        memset(data_string, 0, data_string_len);
        (void)data_to_string(data, data_string, data_string_len);
        data_string_size = GET_LESS(data_string_len, (size_t)strlen(data_string));
        memcpy(*figure_string + row * figure_col + col, data_string, data_string_size);

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
            *(*figure_string + bias_row * figure_col + bias_col_left) = '/';
            *(*figure_string + bias_row * figure_col + bias_col_right) = '\\';
        }
    }

    free_memory((void**)&data_string);
    IF_ERROR_RETURN(dlist_destroy(&list));

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn bitree_print_figure(const BiTree* thiz, DataToStrFunc data_to_string,
            size_t data_string_len, const char* filename, const char* mode)
{
    char* figure_string = NULL;
    size_t figure_row = 0;
    size_t figure_col = 0;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(data_to_string);
    PARAM_CHECK_RANGE(data_string_len, 2, 7);
    PARAM_CHECK_NULL_POINTER(filename);
    PARAM_CHECK_NULL_POINTER(mode);

    bitree_get_figure_size(thiz, data_string_len, &figure_row, &figure_col);
    IF_ERROR_EXIT(alloc_memory((void **)&figure_string, figure_row * figure_col + 1));

    bitree_get_figure_string(thiz, data_to_string, data_string_len, &figure_string);

    IF_ERROR_RETURN(print_to_file(figure_string, filename, mode));

    free_memory((void **)&figure_string);

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn bitree_merge(BiTree* merge, BiTree* left, BiTree* right, const void* data)
{
    return FUNC_OK;
}

#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

