/******************************************************************************/
/**
 * @file          dtest_main.h
 * @brief         dtest_main.h
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef DTEST_MAIN_H
#define DTEST_MAIN_H 1

/******************************************************************************/
#include "func_rtn.h"
#include "testsuite.h"

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
/**
 * @func          FuncRtn dtest_main(TestSuiteInfo* ts_array, size_t ts_num)
 * @brief         main function of dtest
 * @param[in/out] TestSuiteInfo* ts_array: array of testsuites
 * @param[in]     size_t ts_num: number of element in ts_array
 * @return        FuncRtn:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
FuncRtn dtest_main(TestSuiteInfo* ts_array, size_t ts_num);

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif // DTEST_MAIN_H

