/******************************************************************************/
/**
 * @file          tc_bintree.h
 * @brief         tc_bintree.h
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef TC_BINTREE_H
#define TC_BINTREE_H 1

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
extern TestCaseInfo     g_bintree_tcs[];
extern size_t           g_bintree_tcs_num;

/******************************************************************************/
/**
 * @func          void tc_bintree_int(void)
 * @brief         tc_bintree_int
 * @param[in]     void: 
 * @return        void: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
void tc_bintree_int(void);
/******************************************************************************/
/**
 * @func          void tc_bintree_double(void)
 * @brief         tc_bintree_double
 * @param[in]     void: 
 * @return        void: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
void tc_bintree_double(void);

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif // TC_BINTREE_H

