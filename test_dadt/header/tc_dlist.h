/******************************************************************************/
/**
 * @file          tc_dlist.h
 * @brief         tc_dlist.h
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef TC_DLIST_H
#define TC_DLIST_H 1

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
extern TestCaseInfo     g_dlist_tcs[];
extern size_t           g_dlist_tcs_num;

/******************************************************************************/
/**
 * @func          void tc_dlist_int(void)
 * @brief         tc_dlist_int
 * @param[in]     void: 
 * @return        void: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
void tc_dlist_int(void);
/******************************************************************************/
/**
 * @func          void tc_dlist_double(void)
 * @brief         tc_dlist_double
 * @param[in]     void: 
 * @return        void: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
void tc_dlist_double(void);

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif // TC_DLIST_H

