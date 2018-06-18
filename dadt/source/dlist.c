/******************************************************************************/
/**
 * @file        dlist.c
 * @brief       doubly linked list
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/

#include "dlist.h"
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
 * @struct      DListNode
 * @brief       structure for doubly linked list nodes
 */
/******************************************************************************/
typedef struct tagDListNode
{
    void* data;
    struct tagDListNode* prev;
    struct tagDListNode* next;
} DListNode;

/******************************************************************************/
/**
 * @struct      DList
 * @brief       structure for doubly linked lists
 */
/******************************************************************************/
struct tagDList
{
    DListNode* head;
    DListNode* tail;
    size_t            size;
    FreeFunc            data_free;
    CmpFunc             data_cmp;
};

#endif /* CODE_SEPARATOR("Inner Definition", 1) */

#if CODE_SEPARATOR("Inner Function", 1)
/******************************************************************************/
static FuncRtn dlist_make_node(const void* data, DListNode** node)
{
    IF_ERROR_EXIT(alloc_memory((void **)node, sizeof(DListNode)));

    (*node)->data = (void *)data;

    return FUNC_OK;
}

/******************************************************************************/
static FuncRtn dlist_free_node(DListNode** node, Bool free_flag, FreeFunc data_free)
{
    if (TRUE == free_flag && NULL != data_free)
    {
        data_free(&((*node)->data));
    }

    free_memory((void **)node);

    return FUNC_OK;
}

/******************************************************************************/
static FuncRtn dlist_get_node_by_index(const DList* thiz, size_t index, DListNode** node)
{
    size_t i = 0;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_MAX(index, thiz->size - 1);
    PARAM_CHECK_NULL_POINTER(node);

    *node = thiz->head;
    for (i = 0; i < index; i++)
    {
        *node = (*node)->next;
    }

    return FUNC_OK;
}

/******************************************************************************/
static FuncRtn dlist_get_node_by_value(const DList* thiz, const void* data, DListNode** node, size_t* index)
{
    *index = 0;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(node);
    PARAM_CHECK_NULL_POINTER(index);

    *node = thiz->head;
    while (NULL != *node && (thiz->data_cmp)((void *)data, (*node)->data) != 0)
    {
        *node = (*node)->next;
        (*index)++;
    }

    if (NULL == *node)
    {
        return FUNC_NOT_EXIST;
    }

    return FUNC_OK;
}

/******************************************************************************/
static FuncRtn dlist_insert_next(DList* thiz, DListNode* node, const void* data)
{
    DListNode* new_node = NULL;

    PARAM_CHECK_NULL_POINTER(node);

    IF_ERROR_RETURN(dlist_make_node(data, &new_node));

    new_node->next = node->next;
    new_node->prev = node;
    node->next= new_node;
    if (NULL == new_node->next)
    {
        thiz->tail = new_node;
    }
    else
    {
        new_node->next->prev = new_node;
    }

    thiz->size++;

    return FUNC_OK;
}

/******************************************************************************/
static FuncRtn dlist_insert_prev(DList* thiz, DListNode* node, const void* data)
{
    DListNode* new_node = NULL;

    PARAM_CHECK_NULL_POINTER(node);

    IF_ERROR_RETURN(dlist_make_node(data, &new_node));

    new_node->next = node;
    new_node->prev = node->prev;
    node->prev = new_node;
    if (NULL == new_node->prev)
    {
        thiz->head = new_node;
    }
    else
    {
        new_node->prev->next = new_node;
    }

    thiz->size++;

    return FUNC_OK;
}

/******************************************************************************/
static FuncRtn dlist_remove_node(DList* thiz, DListNode* node, Bool free_flag)
{
    /* node is never head. */
    node->prev->next = node->next;
    if (NULL == node->next)
    {
        thiz->tail = node->prev;
    }
    else
    {
        node->next->prev = node->prev;
    }
    thiz->size--;

    IF_ERROR_RETURN(dlist_free_node(&node, free_flag, thiz->data_free));

    return FUNC_OK;
}

/******************************************************************************/
static FuncRtn dlist_swap_node(DListNode* node1, DListNode* node2)
{
    void* temp = node1->data;

    node1->data = node2->data;
    node2->data = temp;

    return FUNC_OK;
}

#endif /* CODE_SEPARATOR("Inner Function", 1) */

#if CODE_SEPARATOR("Outer Function", 1)

/******************************************************************************/
DList* dlist_create(FreeFunc data_free, CmpFunc data_cmp)
{
    DList* thiz = NULL;

    IF_ERROR_EXIT(alloc_memory((void**)&thiz, sizeof(DList)));

    thiz->head      = NULL;
    thiz->tail      = NULL;
    thiz->size      = 0;
    thiz->data_free = data_free;
    thiz->data_cmp  = data_cmp;

    return thiz;
}

/******************************************************************************/
FuncRtn dlist_destroy(DList** thiz)
{
    void* data = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);

    while (0 < (*thiz)->size)
    {
        IF_ERROR_RETURN(dlist_remove_head(*thiz, TRUE, &data));
    }

    free_memory((void**)thiz);

    return FUNC_OK;
}

/******************************************************************************/
FreeFunc dlist_get_free_func(const DList* thiz)
{
    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return NULL;
    }

    return thiz->data_free;
}

/******************************************************************************/
void dlist_set_free_func(DList* thiz, FreeFunc data_free)
{
    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return;
    }

    thiz->data_free = data_free;
}

/******************************************************************************/
CmpFunc dlist_get_cmp_func(const DList* thiz)
{
    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return NULL;
    }

    return thiz->data_cmp;
}

/******************************************************************************/
void dlist_set_cmp_func(DList* thiz, CmpFunc data_cmp)
{
    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return;
    }

    thiz->data_cmp = data_cmp;
}

/******************************************************************************/
size_t dlist_get_size(const DList* thiz)
{
    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return 0;
    }

    return thiz->size;
}

/******************************************************************************/
FuncRtn dlist_insert_head(DList* thiz, const void* data)
{
    DListNode* node = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);

    IF_ERROR_RETURN(dlist_make_node(data, &node));

    node->next = thiz->head;
    thiz->head = node;
    if (0 == thiz->size)
    {
        thiz->tail = node;
    }
    else
    {
        node->next->prev = node;
    }

    thiz->size++;

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn dlist_remove_head(DList* thiz, Bool free_flag, void** data)
{
    DListNode* node = NULL;

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
        thiz->head->prev = NULL;
    }

    *data = node->data;
    IF_ERROR_RETURN(dlist_free_node(&node, free_flag, thiz->data_free));

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn dlist_append_tail(DList* thiz, const void* data)
{
    DListNode* node = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);

    IF_ERROR_RETURN(dlist_make_node(data, &node));

    if (0 == thiz->size)
    {
        thiz->head = node;
    }
    else
    {
        thiz->tail->next = node;
    }
    node->prev = thiz->tail;
    thiz->tail = node;
    thiz->size++;

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn dlist_remove_tail(DList* thiz, Bool free_flag, void** data)
{
    DListNode* node = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(data);

    if (0 == thiz->size)
    {
        return FUNC_UNREACHABLE;
    }
    thiz->size--;

    node = thiz->tail;
    thiz->tail = node->prev;
    node->prev = NULL;
    if (0 == thiz->size)
    {
        thiz->head = NULL;
    }
    else
    {
        thiz->tail->next = NULL;
    }

    *data = node->data;
    IF_ERROR_RETURN(dlist_free_node(&node, free_flag, thiz->data_free));

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn dlist_insert_by_index(DList* thiz, size_t index, const void* data)
{
    DListNode* prev = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_MAX(index, thiz->size);

    if (0 == index)
    {
        return dlist_insert_head(thiz, data);
    }

    IF_ERROR_RETURN(dlist_get_node_by_index(thiz, index - 1, &prev));
    IF_ERROR_RETURN(dlist_insert_next(thiz, prev, data));

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn dlist_remove_by_index(DList* thiz, size_t index, Bool free_flag, void** data)
{
    DListNode* node = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_MAX(index, thiz->size - 1);
    PARAM_CHECK_NULL_POINTER(data);

    if (0 == index)
    {
        return dlist_remove_head(thiz, free_flag, data);
    }

    IF_ERROR_RETURN(dlist_get_node_by_index(thiz, index, &node));
    *data = node->data;
    IF_ERROR_RETURN(dlist_remove_node(thiz, node, free_flag));

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn dlist_insert_by_value(DList* thiz, const void* data)
{
    DListNode* iter = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);

    if (0 == thiz->size || (thiz->data_cmp)((void *)data, thiz->head->data) < 0)
    {
        return dlist_insert_head(thiz, data);
    }

    iter = thiz->head->next;
    while (NULL != iter)
    {
        if ((thiz->data_cmp)((void *)data, iter->data) < 0)
        {
            break;
        }
        iter = iter->next;
    }

    if (NULL == iter)
    {
        return dlist_append_tail(thiz, data);
    }

    IF_ERROR_RETURN(dlist_insert_prev(thiz, iter, data));

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn dlist_remove_by_value(DList* thiz, const void* data, Bool free_flag)
{
    DListNode* node = NULL;
    size_t index = 0;

    PARAM_CHECK_NULL_POINTER(thiz);

    if (0 == thiz->size)
    {
        return FUNC_UNREACHABLE;
    }

    if ((thiz->data_cmp)((void *)data, thiz->head->data) == 0)
    {
        return dlist_remove_head(thiz, free_flag, (void **)&data);
    }

    IF_ERROR_RETURN(dlist_get_node_by_value(thiz, data, &node, &index));
    IF_ERROR_RETURN(dlist_remove_node(thiz, node, free_flag));

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn dlist_get_by_index(const DList* thiz, size_t index, void** data)
{
    DListNode* node = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_MAX(index, thiz->size - 1);
    PARAM_CHECK_NULL_POINTER(data);

    IF_ERROR_RETURN(dlist_get_node_by_index(thiz, index, &node));
    *data = node->data;

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn dlist_get_by_value(const DList* thiz, const void* data, size_t* index)
{
    DListNode* node = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(index);

    IF_ERROR_RETURN(dlist_get_node_by_value(thiz, data, &node, index));

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn dlist_set_by_index(const DList* thiz, size_t index, const void* data)
{
    DListNode* node = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_MAX(index, thiz->size - 1);

    IF_ERROR_RETURN(dlist_get_node_by_index(thiz, index, &node));

    if (NULL != thiz->data_free)
    {
        (thiz->data_free)(&(node->data));
    }
    node->data = (void *)data;

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn dlist_set_by_value(const DList* thiz, const void* data, const void* new_data)
{
    DListNode* node = NULL;
    size_t index = 0;

    IF_ERROR_RETURN(dlist_get_node_by_value(thiz, data, &node, &index));

    if (NULL != thiz->data_free)
    {
        (thiz->data_free)(&(node->data));
    }
    node->data = (void *)new_data;

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn dlist_print(const DList* thiz, DataPrintFunc print)
{
    DListNode* iter = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(print);

    iter = thiz->head;
    while (NULL != iter)
    {
        print(iter->data);
        iter = iter->next;
    }

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn dlist_foreach(DList* thiz, VisitFunc visit, void* context)
{
    DListNode* iter = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(visit);

    iter = thiz->head;
    while (NULL != iter)
    {
        IF_ERROR_RETURN(visit(iter->data, context));
        iter = iter->next;
    }

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn dlist_quick_sort(DList* thiz, size_t start_index, size_t end_index)
{
    void* mid_data = NULL;
    size_t mid_index = start_index;
    DListNode* i_node = NULL, *j_node = NULL;
    Bool flag = FALSE;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_MIN(end_index, 1);
    PARAM_CHECK_MAX(start_index, end_index - 1);
    PARAM_CHECK_MAX(end_index, thiz->size - 1);

    IF_ERROR_RETURN(dlist_get_node_by_index(thiz, start_index, &i_node));
    IF_ERROR_RETURN(dlist_get_node_by_index(thiz, end_index, &j_node));
    mid_data = i_node->data;
    while (i_node != j_node)
    {
        if (flag)
        {
            if ((thiz->data_cmp)(i_node->data, mid_data) < 0)
            {
                i_node = i_node->next;
                mid_index++;
            }
            else
            {
                IF_ERROR_RETURN(dlist_swap_node(i_node, j_node));
                j_node = j_node->prev;
				flag = FALSE;
            }
        }
        else
        {
            if ((thiz->data_cmp)(j_node->data, mid_data) > 0)
            {
                j_node = j_node->prev;
            }
            else
            {
                IF_ERROR_RETURN(dlist_swap_node(i_node, j_node));
                i_node = i_node->next;
				flag = TRUE;
                mid_index++;
            }
        }
    }

    if (start_index + 1 < mid_index)
    {
        IF_ERROR_RETURN(dlist_quick_sort(thiz, start_index, mid_index - 1));
    }

    if (mid_index + 1 < end_index)
    {
        IF_ERROR_RETURN(dlist_quick_sort(thiz, mid_index + 1, end_index));
    }

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn dlist_link(DList* list1, DList* list2)
{
    PARAM_CHECK_NULL_POINTER(list1);
    PARAM_CHECK_NULL_POINTER(list2);
    PARAM_CHECK_EQUAL(list1->data_cmp, list2->data_cmp);
    PARAM_CHECK_EQUAL(list1->data_free, list2->data_free);

    if (0 < list1->size)
    {
        list1->tail->next = list2->head;
    }
    else
    {
        list1->head = list2->head;
    }

    if (0 < list2->size)
    {
        list2->head->prev = list1->tail;
    }
    list1->tail = list2->tail;

    list1->size += list2->size;

    memset(list2, 0, sizeof(DList));
    list2 = NULL;

    return FUNC_OK;
}

/******************************************************************************/

#endif /* CODE_SEPARATOR("Outer Function", 1) */

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

