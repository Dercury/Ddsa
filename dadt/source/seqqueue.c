/******************************************************************************/
/**
 * @file        queue.c
 * @brief       queue
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/

#include "macro.h"
#include "mem_op.h"
#include "seqqueue.h"
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
 * @struct      Queue
 * @brief       implement queues as linked list
 */
/******************************************************************************/
struct tagSeqQueue
{
    void** base;
    size_t head;
    size_t rear;
    size_t max_size;
};

#endif /* CODE_SEPARATOR("Inner Definition", 1) */

#if CODE_SEPARATOR("Inner Function", 1)
#endif

#if CODE_SEPARATOR("Outer Function", 1)
/******************************************************************************/
SeqQueue* seqqueue_create(size_t max_size)
{
    SeqQueue* thiz = NULL;

    if (1 > max_size)
    {
        IF_ERROR_PRINT(FUNC_PARAM_MIN);
        return NULL;
    }

    IF_ERROR_EXIT(alloc_memory((void **)&thiz, sizeof(SeqQueue)));

    /* there is a place that can not contain data,
    becase it's used to identify whether the queue is full. */
    IF_ERROR_EXIT(alloc_memory((void **)&(thiz->base), (max_size + 1) * sizeof(void *)));
    thiz->head = thiz->rear = 0;
    thiz->max_size = max_size;

    return thiz;
}

/******************************************************************************/
FuncRtn seqqueue_destroy(SeqQueue** thiz)
{
    PARAM_CHECK_NULL_POINTER(thiz);

    free_memory((*thiz)->base);
    free_memory((void **)thiz);

    return FUNC_OK;
}

/******************************************************************************/
size_t seqqueue_get_size(SeqQueue* thiz)
{
    size_t size = 0;

    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return 0;
    }

    if (thiz->head < thiz->rear)
    {
        size = thiz->rear - thiz->head;
    }
    else
    {
        size = thiz->max_size + 1 + thiz->rear - thiz->head;
    }

    return size;
}

/******************************************************************************/
FuncRtn seqqueue_enqueue(SeqQueue* thiz, const void* data)
{
    PARAM_CHECK_NULL_POINTER(thiz);

    if ((thiz->rear + 1) % (thiz->max_size + 1) == thiz->head)
    {
        return FUNC_SPACE_FULL;
    }

    (thiz->base)[thiz->rear] = (void *)data;
    thiz->rear = (thiz->rear + 1) % (thiz->max_size + 1);

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn seqqueue_dequeue(SeqQueue* thiz, void** data)
{
    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(data);

    if (thiz->rear == thiz->head)
    {
        return FUNC_SPACE_EMPTY;
    }
    *data = (thiz->base)[thiz->head];
    thiz->head = (thiz->head + 1) % (thiz->max_size + 1);

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn seqqueue_peek(SeqQueue* thiz, void** data)
{
    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(data);

    if (thiz->rear == thiz->head)
    {
        return FUNC_SPACE_EMPTY;
    }
    *data = (thiz->base)[thiz->head];

    return FUNC_OK;
}

#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

