/******************************************************************************/
/**
 * @file          testsuite.h
 * @brief         testsuite.h
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef TESTSUITE_H
#define TESTSUITE_H 1

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
/**
 * @struct      TestSuiteInfo
 * @brief       structure for testsuite information
 */
/******************************************************************************/
typedef struct tagTestSuiteInfo
{
    char*           name        ;   // Can't be NULL
    Bool            enable      ;
    InitFunc        init_func   ;
    CleanupFunc     cleanup_func;
    TestCaseInfo*   tc_array    ;
    size_t          tc_num      ;
} TestSuiteInfo;

//#define TEST_SUITE_INFO_END     {NULL, DISABLED, NULL, NULL, NULL}

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif // TESTSUITE_H

