/******************************************************************************/
/**
 * @file        dtest_usage.c
 * @brief       dercury test
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/

#include "dtest_usage.h"
#include "dtrace.h"
#include "testcase_in.h"
#include "testsuite_in.h"

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
void dtest_expect_true(char* filename, unsigned int linenum, void* expr, char* expr_str)
{
    if (filename == NULL || expr_str == NULL)
    {
        DTRACE_POS_COLORED_LEVEL(TRACE_ERROR, "Null pointer param\n");
        dtest_set_tc_result(TC_FAIL);
        return;
    }

    if (TRUE == (Bool)expr)
    {
        dtest_set_tc_result(TC_PASS);
    }
    else
    {
        DTRACE_LEVEL(TRACE_ERROR, "<%s:%d> Error: %s should be TURE!\n", filename, linenum, expr_str);
        dtest_set_tc_result(TC_FAIL);
    }

    return;
}

/******************************************************************************/
void dtest_expect_false(char* filename, unsigned int linenum, void* expr, char* expr_str)
{
    if (filename == NULL || expr_str == NULL)
    {
        DTRACE_POS_COLORED_LEVEL(TRACE_ERROR, "Null pointer param\n");
        dtest_set_tc_result(TC_FAIL);
        return;
    }

    if (FALSE == (Bool)expr)
    {
        dtest_set_tc_result(TC_PASS);
    }
    else
    {
        DTRACE_LEVEL(TRACE_ERROR, "<%s:%d> Error: %s should be FALSE!\n", filename, linenum, expr_str);
        dtest_set_tc_result(TC_FAIL);
    }

    return;
}

/******************************************************************************/
void dtest_expect_equal(char* filename, unsigned int linenum, void* expr1, char* expr1_str, void* expr2, char* expr2_str)
{
    if (filename == NULL || expr1_str == NULL || expr2_str == NULL)
    {
        DTRACE_POS_COLORED_LEVEL(TRACE_ERROR, "Null pointer param\n");
        dtest_set_tc_result(TC_FAIL);
        return;
    }

    if ((expr1) == (expr2))
    {
        dtest_set_tc_result(TC_PASS);
    }
    else
    {
        DTRACE_LEVEL(TRACE_ERROR, "<%s:%d> Error: %s should be EQUAL to %s!\n", filename, linenum, expr1_str, expr2_str);
        dtest_set_tc_result(TC_FAIL);
    }

    return;
}

/******************************************************************************/
void dtest_expect_unequal(char* filename, unsigned int linenum, void* expr1, char* expr1_str, void* expr2, char* expr2_str)
{
    if (filename == NULL || expr1_str == NULL || expr2_str == NULL)
    {
        DTRACE_POS_COLORED_LEVEL(TRACE_ERROR, "Null pointer param\n");
        dtest_set_tc_result(TC_FAIL);
        return;
    }

    if ((expr1) != (expr2))
    {
        dtest_set_tc_result(TC_PASS);
    }
    else
    {
        DTRACE_LEVEL(TRACE_ERROR, "<%s:%d> Error: %s should be UNEQUAL to %s!\n", filename, linenum, expr1_str, expr2_str);
        dtest_set_tc_result(TC_FAIL);
    }

    return;
}

/******************************************************************************/

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

