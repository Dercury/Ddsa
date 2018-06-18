/******************************************************************************/
/**
 * @file        stack.c
 * @brief       stack
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/

#include "macro.h"
#include "mem_op.h"
#include "seqstack.h"
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
struct tagSeqStack
{
    void** base;
    void** top;
    size_t    size;
};
#endif /* CODE_SEPARATOR("Inner Definition", 1) */

#if CODE_SEPARATOR("Inner Function", 1)
#endif /* CODE_SEPARATOR("Inner Function", 1) */

#if CODE_SEPARATOR("Outer Function", 1)
/******************************************************************************/
SeqStack* seqstack_create(size_t max_size)
{
    SeqStack* thiz = NULL;

    if (1 > max_size)
    {
        IF_ERROR_PRINT(FUNC_PARAM_MIN);
        return NULL;
    }

    IF_ERROR_EXIT(alloc_memory((void **)&thiz, sizeof(SeqStack)));

    IF_ERROR_EXIT(alloc_memory((void **)&(thiz->base), max_size* sizeof(void *)));
    thiz->top = thiz->base;
    thiz->size = max_size;

    return thiz;
}

/******************************************************************************/
FuncRtn seqstack_destroy(SeqStack** thiz)
{
    PARAM_CHECK_NULL_POINTER(thiz);

    free_memory((*thiz)->base);
    free_memory((void **)thiz);

    return FUNC_OK;
}

/******************************************************************************/
size_t seqstack_get_size(SeqStack* thiz)
{
    size_t size = 0;

    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return 0;
    }

    size = (size_t)(thiz->top - thiz->base);

    return size;
}

/******************************************************************************/
FuncRtn seqstack_push(SeqStack* thiz, const void* data)
{
    PARAM_CHECK_NULL_POINTER(thiz);

    if ((size_t)(thiz->top - thiz->base) >= thiz->size)
    {
        return FUNC_SPACE_FULL;
    }

    *(thiz->top) = (void *)data;
    thiz->top++;

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn seqstack_pop(SeqStack* thiz, void** data)
{
    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(data);

    if (thiz->top <= thiz->base)
    {
        return FUNC_SPACE_EMPTY;
    }

    thiz->top--;
    *data = *(thiz->top);

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn seqstack_peek(SeqStack* thiz, void** data)
{
    void** temp = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(data);

    if (thiz->top <= thiz->base)
    {
        return FUNC_SPACE_EMPTY;
    }

    temp = thiz->top - 1;
    *data = *temp;

    return FUNC_OK;
}

#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

