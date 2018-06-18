/******************************************************************************/
/**
 * @file          tc_bitree.h
 * @brief         tc_bitree.h
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef TC_BITREE_H
#define TC_BITREE_H 1

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
extern TestCaseInfo     g_bitree_tcs[];
extern size_t           g_bitree_tcs_num;

/******************************************************************************/
/**
 * @func          void tc_bitree_int(void)
 * @brief         tc_bitree_int
 * @param[in]     void: 
 * @return        void: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
void tc_bitree_int(void);
/******************************************************************************/
/**
 * @func          void tc_bitree_double(void)
 * @brief         tc_bitree_double
 * @param[in]     void: 
 * @return        void: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
void tc_bitree_double(void);

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif // TC_BITREE_H

