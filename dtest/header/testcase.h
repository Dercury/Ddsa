/******************************************************************************/
/**
 * @file          testcase.h
 * @brief         testcase.h
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef TESTCASE_H
#define TESTCASE_H 1

/******************************************************************************/
#include "bool.h"

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
typedef void (*TestFunc)(void)     ;
typedef TestFunc		InitFunc   ;
typedef TestFunc	    CleanupFunc;

/******************************************************************************/
/**
 * @struct      TestCaseInfo
 * @brief       structure for test case information
 */
/******************************************************************************/
typedef struct tagTestCaseInfo
{
    char*       name        ;   // Can't be NULL
    Bool        enable      ;
    InitFunc    init_func   ;
    CleanupFunc cleanup_func;
    TestFunc    function    ;
} TestCaseInfo;

/******************************************************************************/
/* A testsuite is usually consist of many testcases, which are usually defined
 * in an array. The number of the testcases in the testsuite must be known to
 * do testing operations defined by the testcases. However, it does takes some 
 * efforts to count the number, because the number may be very large, the number 
 * changes when testcase(s) be inserted or removed, and there are usually many
 * testsuites whose numbers of testcases need to be count.
 * So, to avoid counting the numbers of testcases in testsuites, the following
 * macro is defined as a ending mark of testcase which needs to be added at the
 * end of testcases array definition.
 */
/******************************************************************************/
#define TEST_CASE_INFO_END      {NULL, FALSE, NULL, NULL, NULL}

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif // TESTCASE_H

