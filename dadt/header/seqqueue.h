/******************************************************************************/
/**
 * @file          seqqueue.h
 * @brief         seqqueue.h
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef SEQQUEUE_H
#define SEQQUEUE_H

/******************************************************************************/
#include "func_rtn.h"

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
struct tagSeqQueue;
typedef struct tagSeqQueue SeqQueue;

/******************************************************************************/
/**
 * @func          SeqQueue* seqqueue_create(size_t max_size)
 * @brief         seqqueue_create
 * @param[in]     size_t max_size: 
 * @return        SeqQueue*: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern SeqQueue* seqqueue_create(size_t max_size);

/******************************************************************************/
/**
 * @func          FuncRtn seqqueue_destroy(SeqQueue** thiz)
 * @brief         seqqueue_destroy
 * @param[in/out] SeqQueue** thiz: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn seqqueue_destroy(SeqQueue** thiz);

/******************************************************************************/
/**
 * @func          size_t seqqueue_get_size(SeqQueue* thiz)
 * @brief         seqqueue_get_size
 * @param[in/out] SeqQueue* thiz: 
 * @return        size_t: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern size_t seqqueue_get_size(SeqQueue* thiz);

/******************************************************************************/
/**
 * @func          FuncRtn seqqueue_enqueue(SeqQueue* thiz, const void* data)
 * @brief         seqqueue_enqueue
 * @param[in/out] SeqQueue* thiz: 
 * @param[in]     void* data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn seqqueue_enqueue(SeqQueue* thiz, const void* data);

/******************************************************************************/
/**
 * @func          FuncRtn seqqueue_dequeue(SeqQueue* thiz, void** data)
 * @brief         seqqueue_dequeue
 * @param[in/out] SeqQueue* thiz: 
 * @param[in/out] void** data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn seqqueue_dequeue(SeqQueue* thiz, void** data);

/******************************************************************************/
/**
 * @func          FuncRtn seqqueue_peek(SeqQueue* thiz, void** data)
 * @brief         seqqueue_peek
 * @param[in/out] SeqQueue* thiz: 
 * @param[in/out] void** data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn seqqueue_peek(SeqQueue* thiz, void** data);

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif // SEQQUEUE_H

