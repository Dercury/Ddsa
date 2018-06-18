/******************************************************************************/
/**
 * @file          tc_graph.h
 * @brief         tc_graph.h
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef TC_GRAPH_H
#define TC_GRAPH_H 1

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
extern TestCaseInfo     g_graph_tcs[];
extern size_t           g_graph_tcs_num;

/******************************************************************************/
/**
 * @func          void tc_graph_int(void)
 * @brief         tc_graph_int
 * @param[in]     void: 
 * @return        void: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
void tc_graph_int(void);
/******************************************************************************/
/**
 * @func          void tc_graph_double(void)
 * @brief         tc_graph_double
 * @param[in]     void: 
 * @return        void: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
void tc_graph_double(void);

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif // TC_GRAPH_H

