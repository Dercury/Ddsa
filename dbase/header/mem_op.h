/******************************************************************************/
/**
 * @file          mem_op.h
 * @brief         memory operation
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef _MEM_OP_H
#define _MEM_OP_H 1

/***************************** include files **********************************/
#include "func_rtn.h"
#include <stdlib.h>

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
/**
 * @func          void* alloc_memory(size_t bytes)
 * @brief         alloc memory, equals malloc adding memset zero
 * @param[in/out] void** pointer: pointer of pointer of memory
 * @param[in]     size_t bytes: memory size in bytes
 * @return        FuncRtn: OK or Error
 * @complexity    O(1)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn alloc_memory(void** pointer, size_t bytes);

/******************************************************************************/
/**
 * @func          void free_memory(void** pointer)
 * @brief         free memory, equals free adding set pointer to NULL
 * @param[in/out] void** pointer: pointer of pointer of memory
 * @return        void
 * @complexity    O(1)
 * @notes         nothing
 */
/******************************************************************************/
extern void free_memory(void** pointer);

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif // _MEM_OP_H

