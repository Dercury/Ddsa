/******************************************************************************/
/**
 * @file          tc_avltree.h
 * @brief         tc_avltree.h
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef TC_AVLTREE_H
#define TC_AVLTREE_H 1

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
extern TestCaseInfo     g_avltree_tcs[];
extern size_t           g_avltree_tcs_num;

/******************************************************************************/
/**
 * @func          void tc_avltree_int(void)
 * @brief         tc_avltree_int
 * @param[in]     void: 
 * @return        void: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
void tc_avltree_int(void);
/******************************************************************************/
/**
 * @func          void tc_avltree_double(void)
 * @brief         tc_avltree_double
 * @param[in]     void: 
 * @return        void: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
void tc_avltree_double(void);

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif // TC_AVLTREE_H

