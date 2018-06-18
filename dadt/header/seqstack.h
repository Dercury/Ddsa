/******************************************************************************/
/**
 * @file          seqstack.h
 * @brief         seqstack.h
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef SEQSTACK_H
#define SEQSTACK_H

/******************************************************************************/
#include "func_rtn.h"

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
struct tagSeqStack;
typedef struct tagSeqStack SeqStack;

/******************************************************************************/
/**
 * @func          SeqStack* seqstack_create(size_t max_size)
 * @brief         seqstack_create
 * @param[in]     size_t max_size: 
 * @return        SeqStack*: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern SeqStack* seqstack_create(size_t max_size);

/******************************************************************************/
/**
 * @func          FuncRtn seqstack_destroy(SeqStack** thiz)
 * @brief         seqstack_destroy
 * @param[in/out] SeqStack** thiz: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn seqstack_destroy(SeqStack** thiz);

/******************************************************************************/
/**
 * @func          size_t seqstack_get_size(SeqStack* thiz)
 * @brief         seqstack_get_size
 * @param[in/out] SeqStack* thiz: 
 * @return        size_t: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern size_t seqstack_get_size(SeqStack* thiz);

/******************************************************************************/
/**
 * @func          FuncRtn seqstack_push(SeqStack* thiz, const void* data)
 * @brief         seqstack_push
 * @param[in/out] SeqStack* thiz: 
 * @param[in]     void* data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn seqstack_push(SeqStack* thiz, const void* data);

/******************************************************************************/
/**
 * @func          FuncRtn seqstack_pop(SeqStack* thiz, void** data)
 * @brief         seqstack_pop
 * @param[in/out] SeqStack* thiz: 
 * @param[in/out] void** data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn seqstack_pop(SeqStack* thiz, void** data);

/******************************************************************************/
/**
 * @func          FuncRtn seqstack_peek(SeqStack* thiz, void** data)
 * @brief         seqstack_peek
 * @param[in/out] SeqStack* thiz: 
 * @param[in/out] void** data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn seqstack_peek(SeqStack* thiz, void** data);

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif // SEQSTACK_H

