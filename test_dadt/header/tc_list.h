/******************************************************************************/
/**
 * @file          tc_list.h
 * @brief         tc_list.h
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef TC_LIST_H
#define TC_LIST_H 1

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
extern TestCaseInfo     g_list_tcs[];
extern size_t           g_list_tcs_num;

/******************************************************************************/
/**
 * @func          void tc_list_int(void)
 * @brief         tc_list_int
 * @param[in]     void: 
 * @return        void: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
void tc_list_int(void);

/******************************************************************************/
/**
 * @func          void tc_list_double(void)
 * @brief         tc_list_double
 * @param[in]     void: 
 * @return        void: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
void tc_list_double(void);

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif // TC_LIST_H

