/******************************************************************************/
/**
 * @file          priqueue.h
 * @brief         priqueue.h
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef PRIQUEUE_H
#define PRIQUEUE_H

/******************************************************************************/
#include "heap.h"

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
typedef Heap    PriQueue;

#define priqueue_create         heap_create

#define priqueue_destroy        heap_destroy

#define priqueue_get_size       heap_get_size

#define priqueue_get_free_func  heap_get_free_func
#define priqueue_set_free_func  heap_set_free_func

#define priqueue_get_cmp_func   heap_get_cmp_func
#define priqueue_set_cmp_func   heap_set_cmp_func

#define priqueue_insert         heap_insert
#define priqueue_extract        heap_extract
#define priqueue_peek           heap_peek

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif // PRIQUEUE_H

