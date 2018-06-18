/******************************************************************************/
/**
 * @file          tc_heap.h
 * @brief         tc_heap.h
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef TC_HEAP_H
#define TC_HEAP_H 1

/******************************************************************************/
#include <stdlib.h>
#include "testcase.h"

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
extern TestCaseInfo     g_heap_tcs[];
extern size_t           g_heap_tcs_num;

/******************************************************************************/
/**
 * @func          void tc_heap_int(void)
 * @brief         tc_heap_int
 * @param[in]     void: 
 * @return        void: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
void tc_heap_int(void);
/******************************************************************************/
/**
 * @func          void tc_heap_double(void)
 * @brief         tc_heap_double
 * @param[in]     void: 
 * @return        void: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
void tc_heap_double(void);

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif // TC_HEAP_H

