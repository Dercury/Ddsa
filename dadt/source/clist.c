/******************************************************************************/
/**
 * @file        clist.c
 * @brief       circular linked list
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/

#include "clist.h"
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

#if CODE_SEPARATOR("Inner Definition", 1)
/******************************************************************************/
/**
 * @struct      CListNode
 * @brief       structure for circular linked list elements
 */
/******************************************************************************/
typedef struct tagCListNode
{
    void* data;
    struct tagCListNode* next;
} CListNode;

/******************************************************************************/
/**
 * @struct      CList
 * @brief       structure for circular linked list
 */
/******************************************************************************/
struct tagCList
{
    CListNode* head;
    CListNode* tail;
    size_t              size;
    FreeFunc            data_free;
    CmpFunc             data_cmp;
};

#endif /* CODE_SEPARATOR("Inner Definition", 1) */

#if CODE_SEPARATOR("Inner Function", 1)
/******************************************************************************/
static FuncRtn clist_make_node(const void* data, CListNode** node)
{
    IF_ERROR_EXIT(alloc_memory((void **)node, sizeof(CListNode)));

    (*node)->data = (void *)data;

    return FUNC_OK;
}

/******************************************************************************/
static FuncRtn clist_free_node(CListNode** node, Bool free_flag, FreeFunc data_free)
{
    if (TRUE == free_flag && NULL != data_free)
    {
        data_free(&((*node)->data));
    }

    free_memory((void **)node);

    return FUNC_OK;
}

/******************************************************************************/
static FuncRtn clist_get_prev_node(CList* thiz, CListNode* node, CListNode** prev)
{
    if (node == thiz->head)
    {
        *prev = NULL;

        return FUNC_OK;
    }

    *prev = thiz->head;
    while ((*prev)->next != node && NULL != *prev)
    {
        *prev = (*prev)->next;
        if (thiz->head == *prev)
        {
            break;
        }
    }
    if (NULL == *prev || thiz->head == *prev)
    {
        return FUNC_NOT_EXIST;
    }

    return FUNC_OK;
}

/******************************************************************************/
static FuncRtn clist_get_node_by_index(const CList* thiz, size_t index, CListNode** node)
{
    size_t i = 0;

    *node = thiz->head;
    for (i = 0; i < index; i++)
    {
        *node = (*node)->next;
    }

    return FUNC_OK;
}

/******************************************************************************/
static FuncRtn clist_get_node_by_value(const CList* thiz, const void* data, CListNode** node, size_t* index)
{
    *index = 0;

    *node = thiz->head;
    while (NULL != *node && (thiz->data_cmp)((void *)data, (*node)->data) != 0)
    {
        *node = (*node)->next;
        (*index)++;
        if (thiz->head == *node)
        {
            break;
        }
    }

    if (NULL == *node || thiz->head == *node)
    {
        return FUNC_NOT_EXIST;
    }

    return FUNC_OK;
}

/******************************************************************************/
static FuncRtn clist_insert_next(CList* thiz, CListNode* node, const void* data)
{
    CListNode* new_node = NULL;

    PARAM_CHECK_NULL_POINTER(node);

    /* Allocate storage for the node */
    IF_ERROR_RETURN(clist_make_node(data, &new_node));

    new_node->next = node->next;
    node->next = new_node;
    if (thiz->tail == new_node->next)
    {
        thiz->tail = new_node;
    }

    /* Adjust the size of the list to account for the inserted node */
    thiz->size++;

    return FUNC_OK;
}

/******************************************************************************/
static FuncRtn clist_remove_next(CList* thiz, CListNode* node, Bool free_flag, void** data)
{
    CListNode* old_node = NULL;

    PARAM_CHECK_NULL_POINTER(node);
    PARAM_CHECK_NULL_POINTER(node->next);

    /* Handle removing other than the last node */
    old_node = node->next;
    node->next = old_node->next;

    /* Adjust the size of the list to account for the removed node */
    thiz->size--;

    /* Free the storage allocated by the abstract datatype */
    *data = old_node->data;
    IF_ERROR_RETURN(clist_free_node(&old_node, free_flag, thiz->data_free));

    return FUNC_OK;
}

/******************************************************************************/
static FuncRtn clist_swap_node(CListNode* node1, CListNode* node2)
{
    void* temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;

    return FUNC_OK;
}

#endif

#if CODE_SEPARATOR("Outer Function", 1)
/******************************************************************************/
CList* clist_create(FreeFunc data_free, CmpFunc data_cmp)
{
    CList* thiz = NULL;

    IF_ERROR_EXIT(alloc_memory((void **)&thiz, sizeof(CList)));

    thiz->head      = NULL;
    thiz->tail      = NULL;
    thiz->size      = 0;
    thiz->data_free = data_free;
    thiz->data_cmp  = data_cmp;

    return thiz;
}

/******************************************************************************/
FuncRtn clist_destroy(CList** thiz)
{
    void* data = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);

    while (0 < (*thiz)->size)
    {
        IF_ERROR_RETURN(clist_remove_head(*thiz, TRUE, &data));
    }

    free_memory((void **)thiz);

    return FUNC_OK;
}

/******************************************************************************/
size_t clist_get_size(CList* thiz)
{
    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return 0;
    }

    return thiz->size;
}

/******************************************************************************/
FreeFunc clist_get_free_func(const CList* thiz)
{
    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return NULL;
    }

    return thiz->data_free;
}

/******************************************************************************/
void clist_set_free_func(CList* thiz, FreeFunc data_free)
{
    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return;
    }

    thiz->data_free = data_free;
}

/******************************************************************************/
CmpFunc clist_get_cmp_func(const CList* thiz)
{
    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return NULL;
    }

    return thiz->data_cmp;
}

/******************************************************************************/
void clist_set_cmp_func(CList* thiz, CmpFunc data_cmp)
{
    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return;
    }

    thiz->data_cmp = data_cmp;
}

/******************************************************************************/
FuncRtn clist_insert_head(CList* thiz, const void* data)
{
    CListNode* node = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);

    IF_ERROR_RETURN(clist_make_node(data, &node));

    node->next = thiz->head;
    thiz->head = node;
    if (0 == thiz->size)
    {
        thiz->tail = node;
    }
    else
    {
        thiz->tail->next = node;
    }
    thiz->size++;

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn clist_remove_head(CList* thiz, Bool free_flag, void** data)
{
    CListNode* node = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(data);

    if (0 == thiz->size)
    {
        return FUNC_UNREACHABLE;
    }

    node = thiz->head;
    thiz->head = node->next;
    node->next = NULL;
    thiz->size--;
    if (0 == thiz->size)
    {
        thiz->tail = NULL;
    }
    else
    {
        thiz->tail->next = thiz->head;
    }

    *data = node->data;
    IF_ERROR_RETURN(clist_free_node(&node, free_flag, thiz->data_free));

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn clist_append_tail(CList* thiz, const void* data)
{
    CListNode* node = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);

    IF_ERROR_RETURN(clist_make_node(data, &node));

    if (0 == thiz->size)
    {
        thiz->head = node;
    }
    else
    {
        thiz->tail->next = node;
    }
    thiz->tail = node;
    thiz->tail->next = thiz->head;

    thiz->size++;

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn clist_remove_tail(CList* thiz, Bool free_flag, void** data)
{
    CListNode* node = NULL;
    CListNode* prev = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(data);

    if (0 == thiz->size)
    {
        return FUNC_UNREACHABLE;
    }

    node = thiz->tail;
    IF_ERROR_RETURN(clist_get_prev_node(thiz, node, &prev));
    thiz->tail = prev;
    if (NULL == prev)
    {
        thiz->head = NULL;
    }
    else
    {
        prev->next = thiz->head;
    }
    *data = node->data;
    IF_ERROR_RETURN(clist_free_node(&node, free_flag, thiz->data_free));
    thiz->size--;

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn clist_insert_by_index(CList* thiz, size_t index, const void* data)
{
    CListNode* prev = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_MAX(index, thiz->size);

    if (0 == index)
    {
        return clist_insert_head(thiz, data);
    }

    IF_ERROR_RETURN(clist_get_node_by_index(thiz, index - 1, &prev));
    IF_ERROR_RETURN(clist_insert_next(thiz, prev, data));

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn clist_remove_by_index(CList* thiz, size_t index, Bool free_flag, void** data)
{
    CListNode* prev = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_MAX(index, thiz->size - 1);
    PARAM_CHECK_NULL_POINTER(data);

    if (0 == index)
    {
        return clist_remove_head(thiz, free_flag, data);
    }
    else if (thiz->size -1 == index)
    {
        return clist_remove_tail(thiz, free_flag, data);
    }

    IF_ERROR_RETURN(clist_get_node_by_index(thiz, index - 1, &prev));
    IF_ERROR_RETURN(clist_remove_next(thiz, prev, free_flag, data));

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn clist_insert_by_value(CList* thiz, const void* data)
{
    CListNode* node, *prev, *iter;
    node = prev = iter = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);

    if (0 == thiz->size || (thiz->data_cmp)((void *)data, thiz->head->data) < 0)
    {
        return clist_insert_head(thiz, data);
    }

    prev = thiz->head;
    iter = prev->next;
    while (NULL != iter)
    {
        if ((thiz->data_cmp)((void *)data, iter->data) < 0)
        {
            break;
        }
        prev = iter;
        iter = iter->next;
        if (thiz->head == iter)
        {
            break;
        }
    }

    if (NULL == iter || thiz->head == iter)
    {
        return clist_append_tail(thiz, data);
    }

    IF_ERROR_RETURN(clist_make_node(data, &node));
    node->next = prev->next;
    prev->next = node;
    thiz->size++;

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn clist_remove_by_value(CList* thiz, const void* data, Bool free_flag)
{
    CListNode* prev, *iter;
    prev = iter = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);

    if (0 == thiz->size)
    {
        return FUNC_UNREACHABLE;
    }

    if ((thiz->data_cmp)((void *)data, thiz->head->data) == 0)
    {
        return clist_remove_head(thiz, free_flag, (void **)&data);
    }

    prev = thiz->head;
    iter = prev->next;
    while (NULL != iter)
    {
        if ((thiz->data_cmp)((void *)data, iter->data) == 0)
        {
            break;
        }
        prev = iter;
        iter = iter->next;
        if (thiz->head == iter)
        {
            break;
        }
    }

    if (NULL == iter || thiz->head == iter)
    {
        return FUNC_NOT_EXIST;
    }

    prev->next = iter->next;
    thiz->size--;
    if (NULL == prev->next)
    {
        thiz->tail = prev;
    }
    IF_ERROR_RETURN(clist_free_node(&iter, free_flag, thiz->data_free));

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn clist_get_by_index(const CList* thiz, size_t index, void** data)
{
    CListNode* node = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_MAX(index, thiz->size - 1);
    PARAM_CHECK_NULL_POINTER(data);

    IF_ERROR_RETURN(clist_get_node_by_index(thiz, index, &node));
    *data = node->data;

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn clist_get_by_value(const CList* thiz, const void* data, size_t* index)
{
    CListNode* node = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(index);

    IF_ERROR_RETURN(clist_get_node_by_value(thiz, data, &node, index));

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn clist_set_by_index(const CList* thiz, size_t index, const void* data)
{
    CListNode* node = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_MAX(index, thiz->size - 1);

    IF_ERROR_RETURN(clist_get_node_by_index(thiz, index, &node));

    if (NULL != thiz->data_free)
    {
        (thiz->data_free)(&(node->data));
    }
    node->data = (void *)data;

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn clist_set_by_value(const CList* thiz, const void* data, const void* new_data)
{
    CListNode* node = NULL;
    size_t index = 0;

    PARAM_CHECK_NULL_POINTER(thiz);

    IF_ERROR_RETURN(clist_get_node_by_value(thiz, data, &node, &index));

    if (NULL != thiz->data_free)
    {
        (thiz->data_free)(&(node->data));
    }
    node->data = (void *)new_data;

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn clist_print(const CList* thiz, DataPrintFunc print)
{
    CListNode* iter = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(print);

    iter = thiz->head;
    while (NULL != iter)
    {
        print(iter->data);
        iter = iter->next;
        if (thiz->head == iter)
        {
            break;
        }
    }

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn clist_foreach(CList* thiz, VisitFunc visit, void* context)
{
    CListNode* iter = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(visit);

    iter = thiz->head;
    while (NULL != iter)
    {
        IF_ERROR_RETURN(visit(iter->data, context));
        iter = iter->next;
        if (thiz->head == iter)
        {
            break;
        }
    }

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn clist_quick_sort(CList* thiz, size_t start_index, size_t end_index)
{
    void* mid_data = NULL;
    int i, j;
    CListNode* i_node, *j_node;
    Bool flag = FALSE;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_MIN(end_index, 1);
    PARAM_CHECK_MAX(start_index, end_index - 1);
    PARAM_CHECK_MAX(end_index, thiz->size - 1);

    i = start_index;
    j = end_index;
    IF_ERROR_RETURN(clist_get_node_by_index(thiz, i, &i_node));
    IF_ERROR_RETURN(clist_get_node_by_index(thiz, j, &j_node));
    mid_data = i_node->data;
    while (i < j)
    {
        if (flag)
        {
            if ((thiz->data_cmp)(i_node->data, mid_data) < 0)
            {
                i++;
                i_node = i_node->next;
            }
            else
            {
                IF_ERROR_RETURN(clist_swap_node(i_node, j_node));
                j--;
                IF_ERROR_RETURN(clist_get_node_by_index(thiz, j, &j_node));
				flag = FALSE;
            }
        }
        else
        {
            if ((thiz->data_cmp)(j_node->data, mid_data) > 0)
            {
                j--;
                IF_ERROR_RETURN(clist_get_node_by_index(thiz, j, &j_node));
            }
            else
            {
                IF_ERROR_RETURN(clist_swap_node(i_node, j_node));
                i++;
                i_node = i_node->next;
				flag = TRUE;
            }
        }
    }

    if ((int)start_index < i)
    {
        IF_ERROR_RETURN(clist_quick_sort(thiz, start_index, i));
    }

    if (j + 1 < (int)end_index)
    {
        IF_ERROR_RETURN(clist_quick_sort(thiz, j + 1, end_index));
    }

    return FUNC_OK;
}

#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

