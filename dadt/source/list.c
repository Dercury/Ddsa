/******************************************************************************/
/**
 * @file        list.c
 * @brief       linked list
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/

#include "list.h"
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
 * @struct      ListNode
 * @brief       structure for linked list elements
 */
/******************************************************************************/
typedef struct tagListNode
{
    void* data;
    struct tagListNode* next;
} ListNode;

/******************************************************************************/
/**
 * @struct      List
 * @brief       structure for linked list
 */
/******************************************************************************/
struct tagList
{
    ListNode* head;
    ListNode* tail;
    size_t                  size;
    FreeFunc                data_free;
    CmpFunc                 data_cmp;
};

#endif /* CODE_SEPARATOR("Inner Definition", 1) */

#if CODE_SEPARATOR("Inner Function", 1)
/******************************************************************************/
static FuncRtn list_make_node(const void* data, ListNode** node)
{
    IF_ERROR_EXIT(alloc_memory((void **)node, sizeof(ListNode)));

    (*node)->data = (void *)data;

    return FUNC_OK;
}

/******************************************************************************/
static FuncRtn list_free_node(ListNode** node, Bool free_flag, FreeFunc data_free)
{
    if (TRUE == free_flag && NULL != data_free)
    {
        data_free(&((*node)->data));
    }

    free_memory((void **)node);

    return FUNC_OK;
}

/******************************************************************************/
static FuncRtn list_get_prev_node(List* thiz, ListNode* node, ListNode** prev)
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
    }
    if (NULL == *prev)
    {
        return FUNC_NOT_EXIST;
    }

    return FUNC_OK;
}

/******************************************************************************/
static FuncRtn list_get_node_by_index(const List* thiz, size_t index, ListNode** node)
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
static FuncRtn list_get_node_by_value(const List* thiz, const void* data, ListNode** node, size_t* index)
{
    *index = 0;

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
static FuncRtn list_insert_next(List* thiz, ListNode* node, const void* data)
{
    ListNode* new_node = NULL;

    PARAM_CHECK_NULL_POINTER(node);

    IF_ERROR_RETURN(list_make_node(data, &new_node));

    new_node->next = node->next;
    node->next = new_node;
    if (NULL == new_node->next)
    {
        thiz->tail = new_node;
    }
    thiz->size++;

    return FUNC_OK;
}

/******************************************************************************/
static FuncRtn list_remove_next(List* thiz, ListNode* node, Bool free_flag, void** data)
{
    ListNode* old_node = NULL;

    PARAM_CHECK_NULL_POINTER(node);
    PARAM_CHECK_NULL_POINTER(node->next);

    /* Handle removal from somewhere other than the head */
    old_node = node->next;
    node->next = old_node->next;
    if (NULL == node->next)
    {
        thiz->tail = node;
    }
    thiz->size--;

    *data = old_node->data;
    IF_ERROR_RETURN(list_free_node(&old_node, free_flag, thiz->data_free));

    return FUNC_OK;
}

/******************************************************************************/
static FuncRtn list_swap_node(ListNode* node1, ListNode* node2)
{
    void* temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;

    return FUNC_OK;
}

#endif /* CODE_SEPARATOR("Inner Function", 1) */

#if CODE_SEPARATOR("Outer Function", 1)
/******************************************************************************/
List* list_create(FreeFunc data_free, CmpFunc data_cmp)
{
    List* list = NULL;

    IF_ERROR_EXIT(alloc_memory((void **)&list, sizeof(List)));

    list->head      = NULL;
    list->tail      = NULL;
    list->size      = 0;
	list->data_free = data_free;
	list->data_cmp  = data_cmp;

    return list;
}

/******************************************************************************/
FuncRtn list_destroy(List** thiz)
{
    void* data = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);

    while (0 < (*thiz)->size)
    {
        IF_ERROR_RETURN(list_remove_head(*thiz, TRUE, &data));
    }

    free_memory((void **)thiz);

    return FUNC_OK;
}

/******************************************************************************/
size_t list_get_size(List* thiz)
{
    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return 0;
    }

    return thiz->size;
}

/******************************************************************************/
FreeFunc list_get_free_func(const List* thiz)
{
    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return NULL;
    }

    return thiz->data_free;
}

/******************************************************************************/
void list_set_free_func(List* thiz, FreeFunc data_free)
{
    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return;
    }

    thiz->data_free = data_free;
}

/******************************************************************************/
CmpFunc list_get_cmp_func(const List* thiz)
{
    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return NULL;
    }

    return thiz->data_cmp;
}

/******************************************************************************/
void list_set_cmp_func(List* thiz, CmpFunc data_cmp)
{
    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return;
    }

    thiz->data_cmp = data_cmp;
}

/******************************************************************************/
FuncRtn list_insert_head(List* thiz, const void* data)
{
    ListNode* node = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);

    IF_ERROR_RETURN(list_make_node(data, &node));

    node->next = thiz->head;
    thiz->head = node;
    if (0 == thiz->size)
    {
        thiz->tail = node;
    }
    thiz->size++;

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn list_remove_head(List* thiz, Bool free_flag, void** data)
{
    ListNode* node = NULL;

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

    *data = node->data;
    IF_ERROR_RETURN(list_free_node(&node, free_flag, thiz->data_free));

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn list_append_tail(List* thiz, const void* data)
{
    ListNode* node = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);

    IF_ERROR_RETURN(list_make_node(data, &node));

    if (0 == thiz->size)
    {
        thiz->head = node;
    }
    else
    {
        thiz->tail->next = node;
    }
    thiz->tail = node;
    thiz->size++;

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn list_remove_tail(List* thiz, Bool free_flag, void** data)
{
    ListNode* node = NULL;
    ListNode* prev = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(data);

    if (0 == thiz->size)
    {
        return FUNC_UNREACHABLE;
    }

    node = thiz->tail;
    IF_ERROR_RETURN(list_get_prev_node(thiz, node, &prev));
    thiz->tail = prev;
    if (NULL == prev)
    {
        thiz->head = NULL;
    }
    else
    {
        prev->next = NULL;
    }
    *data = node->data;
    IF_ERROR_RETURN(list_free_node(&node, free_flag, thiz->data_free));
    thiz->size--;

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn list_insert_by_index(List* thiz, size_t index, const void* data)
{
    ListNode* prev = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_MAX(index, thiz->size);

    if (0 == index)
    {
        return list_insert_head(thiz, data);
    }

    IF_ERROR_RETURN(list_get_node_by_index(thiz, index - 1, &prev));
    IF_ERROR_RETURN(list_insert_next(thiz, prev, data));

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn list_remove_by_index(List* thiz, size_t index, Bool free_flag, void** data)
{
    ListNode* prev = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_MAX(index, thiz->size - 1);
    PARAM_CHECK_NULL_POINTER(data);

    if (0 == index)
    {
        return list_remove_head(thiz, free_flag, data);
    }

    IF_ERROR_RETURN(list_get_node_by_index(thiz, index - 1, &prev));
    IF_ERROR_RETURN(list_remove_next(thiz, prev, free_flag, data));

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn list_insert_by_value(List* thiz, const void* data)
{
    ListNode* node, *prev, *iter;
    node = prev = iter = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);

    if (0 == thiz->size || (thiz->data_cmp)((void *)data, thiz->head->data) < 0)
    {
        return list_insert_head(thiz, data);
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
    }

    if (NULL == iter)
    {
        return list_append_tail(thiz, data);
    }

    IF_ERROR_RETURN(list_make_node(data, &node));
    node->next = prev->next;
    prev->next = node;
    thiz->size++;

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn list_remove_by_value(List* thiz, const void* data, Bool free_flag)
{
    ListNode* prev, *iter;
    prev = iter = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);

    if (0 == thiz->size)
    {
        return FUNC_UNREACHABLE;
    }

    if ((thiz->data_cmp)((void *)data, thiz->head->data) == 0)
    {
        return list_remove_head(thiz, free_flag, (void **)&data);
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
    }

    if (NULL == iter)
    {
        return FUNC_NOT_EXIST;
    }

    prev->next = iter->next;
    thiz->size--;
    if (NULL == prev->next)
    {
        thiz->tail = prev;
    }
    IF_ERROR_RETURN(list_free_node(&iter, free_flag, thiz->data_free));

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn list_get_by_index(const List* thiz, size_t index, void** data)
{
    ListNode* node = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_MAX(index, thiz->size - 1);
    PARAM_CHECK_NULL_POINTER(data);

    IF_ERROR_RETURN(list_get_node_by_index(thiz, index, &node));
    *data = node->data;

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn list_get_by_value(const List* thiz, const void* data, size_t* index)
{
    ListNode* node = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(index);

    IF_ERROR_RETURN(list_get_node_by_value(thiz, data, &node, index));

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn list_set_by_index(const List* thiz, size_t index, const void* data)
{
    ListNode* node = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_MAX(index, thiz->size - 1);

    IF_ERROR_RETURN(list_get_node_by_index(thiz, index, &node));

    if (NULL != thiz->data_free)
    {
        (thiz->data_free)(&(node->data));
    }
    node->data = (void *)data;

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn list_set_by_value(const List* thiz, const void* data, const void* new_data)
{
    ListNode* node = NULL;
    size_t index = 0;

    PARAM_CHECK_NULL_POINTER(thiz);

    IF_ERROR_RETURN(list_get_node_by_value(thiz, data, &node, &index));

    if (NULL != thiz->data_free)
    {
        (thiz->data_free)(&(node->data));
    }
    node->data = (void *)new_data;

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn list_print(const List* thiz, DataPrintFunc print)
{
    ListNode* iter = NULL;

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
FuncRtn list_foreach(List* thiz, VisitFunc visit, void* context)
{
    ListNode* iter = NULL;

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
FuncRtn list_quick_sort(List* thiz, size_t start_index, size_t end_index)
{
    void* mid_data = NULL;
    int i, j;
    ListNode* i_node, *j_node;
    Bool flag = FALSE;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_MIN(end_index, 1);
    PARAM_CHECK_MAX(start_index, end_index - 1);
    PARAM_CHECK_MAX(end_index, thiz->size - 1);

    i = start_index;
    j = end_index;
    IF_ERROR_RETURN(list_get_node_by_index(thiz, i, &i_node));
    IF_ERROR_RETURN(list_get_node_by_index(thiz, j, &j_node));
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
                IF_ERROR_RETURN(list_swap_node(i_node, j_node));
                j--;
                IF_ERROR_RETURN(list_get_node_by_index(thiz, j, &j_node));
				flag = FALSE;
            }
        }
        else
        {
            if ((thiz->data_cmp)(j_node->data, mid_data) > 0)
            {
                j--;
                IF_ERROR_RETURN(list_get_node_by_index(thiz, j, &j_node));
            }
            else
            {
                IF_ERROR_RETURN(list_swap_node(i_node, j_node));
                i++;
                i_node = i_node->next;
				flag = TRUE;
            }
        }
    }

    if ((int)start_index < i)
    {
        IF_ERROR_RETURN(list_quick_sort(thiz, start_index, i));
    }

    if (j + 1 < (int)end_index)
    {
        IF_ERROR_RETURN(list_quick_sort(thiz, j + 1, end_index));
    }

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn list_link(List* list1, List* list2)
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
    list1->tail = list2->tail;
    list1->size += list2->size;

    memset(list2, 0, sizeof(List));
    list2 = NULL;

    return FUNC_OK;
}


#endif /* CODE_SEPARATOR("Outer Function", 1) */

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

