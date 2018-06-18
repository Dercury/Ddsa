/******************************************************************************/
/**
 * @file        btree.h
 * @brief       binary tree
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/

#include "macro.h"
#include "mem_op.h"
#include "heap.h"
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
struct tagHeap
{
    size_t    size;
    CmpFunc     data_cmp;
    FreeFunc    data_free;
    void** tree;
};

/******************************************************************************/
static size_t heap_parent_index(size_t child_index)
{
    if (0 == child_index)
    {
        return 0;
    }

    return (size_t)((child_index - 1) / 2);
}

static size_t heap_left_child_index(size_t parent_index)
{
    return (parent_index * 2) + 1;
}

static size_t heap_right_child_index(size_t parent_index)
{
    return (parent_index * 2) + 2;
}

/******************************************************************************/
#endif  /* CODE_SEPARATOR("Inner Function", 1) */

#if CODE_SEPARATOR("Outer Function", 1)
/******************************************************************************/
Heap* heap_create(FreeFunc data_free, CmpFunc data_cmp)
{
    Heap* thiz = NULL;

    IF_ERROR_EXIT(alloc_memory((void **)&thiz, sizeof(Heap)));

    thiz->size = 0;
    thiz->data_free = data_free;
    thiz->data_cmp = data_cmp;
    thiz->tree = NULL;

    return thiz;
}

/******************************************************************************/
FuncRtn heap_destroy(Heap** thiz)
{
    size_t i = 0;

    PARAM_CHECK_NULL_POINTER(thiz);

    /* Remove all the nodes from the heap. */
    if (NULL != (*thiz)->data_free)
    {
        for (i = 0; i < (*thiz)->size; i++)
        {
            ((*thiz)->data_free)(&((*thiz)->tree[i]));
        }
    }

    /* Free the storage allocated for the heap. */
    free_memory((void **)&((*thiz)->tree));

    free_memory((void **)thiz);

    return FUNC_OK;
}

/******************************************************************************/
size_t heap_get_size(const Heap* thiz)
{
    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return 0;
    }

    return thiz->size;
}

/******************************************************************************/
FreeFunc heap_get_free_func(const Heap* thiz)
{
    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return NULL;
    }

    return thiz->data_free;
}

/******************************************************************************/
void heap_set_free_func(Heap* thiz, FreeFunc data_free)
{
    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return;
    }

    thiz->data_free = data_free;
}

/******************************************************************************/
CmpFunc heap_get_cmp_func(const Heap* thiz)
{
    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return NULL;
    }

    return thiz->data_cmp;
}

/******************************************************************************/
void heap_set_cmp_func(Heap* thiz, CmpFunc data_cmp)
{
    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return;
    }

    thiz->data_cmp = data_cmp;
}

/******************************************************************************/
FuncRtn heap_insert(Heap* thiz, const void* data)
{
    void** temp, *temp_data;
    size_t i_index, parent_index;

    PARAM_CHECK_NULL_POINTER(thiz);

    if (NULL == (temp = (void **)realloc(thiz->tree, (thiz->size + 1) * sizeof(void *))))
    {
        return FUNC_MEMORY_ALLOC;
    }
    else
    {
        thiz->tree = temp;
    }

    thiz->tree[thiz->size] = (void *)data;

    i_index = thiz->size;
    parent_index = heap_parent_index(i_index);

    while (0 < i_index && thiz->data_cmp(thiz->tree[parent_index], thiz->tree[i_index]) < 0)
    {
        /* Swap the contents of the current node and its parent */
        temp_data = thiz->tree[parent_index];
        thiz->tree[parent_index] = thiz->tree[i_index];
        thiz->tree[i_index] = temp_data;

        /* Move up one level in the tree to continue heapifying. */
        i_index = parent_index;
        parent_index = heap_parent_index(i_index);
    }
    thiz->size++;

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn heap_extract(Heap* thiz, void** data)
{
    void* save, **temp, *temp_data;
    size_t ipos, lpos, rpos, mpos;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(data);

    if (0 == thiz->size)
    {
        return FUNC_SPACE_EMPTY;
    }

    *data = thiz->tree[0];
    if (0 < thiz->size - 1)
    {
        save = thiz->tree[thiz->size - 1];
        if (NULL == (temp = (void **)realloc(thiz->tree, (thiz->size - 1)* sizeof(void *))))
        {
            return FUNC_MEMORY_ALLOC;
        }
        thiz->tree = temp;
        thiz->size--;
    }
    else
    {
        free(thiz->tree);
        thiz->tree = NULL;
        thiz->size = 0;

        return FUNC_OK;
    }

    /* Copy the last node to the top */
    thiz->tree[0] = save;

    /* Heapify the tree by pushing the contents of the new top downward. */
    ipos = 0;
    while (TRUE)
    {
        /* Select the child to swap with the current node. */
        lpos = heap_left_child_index(ipos);
        rpos = heap_right_child_index(ipos);

        if (lpos < thiz->size && thiz->data_cmp(thiz->tree[lpos], thiz->tree[ipos]) > 0)
        {
            mpos = lpos;
        }
        else
        {
            mpos = ipos;
        }

        if (rpos < thiz->size && thiz->data_cmp(thiz->tree[rpos], thiz->tree[mpos]) > 0)
        {
            mpos = rpos;
        }

        if (mpos == ipos)
        {
            /* When mpos is ipos, the heap property has been restored. */
            break;
        }
        else
        {
            /* Swap the contents of the current node and the selected child. */
            temp_data = thiz->tree[mpos];
            thiz->tree[mpos] = thiz->tree[ipos];
            thiz->tree[ipos] = temp_data;

            /* Move down one level in the tree to continue heapifying. */
            ipos = mpos;
        }
    }

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn heap_peek(Heap* thiz, void** data)
{
    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(data);

    *data = (NULL == thiz->tree ? NULL : thiz->tree[0]);

    return FUNC_OK;
}

/******************************************************************************/

#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

