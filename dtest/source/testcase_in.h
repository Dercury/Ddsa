/******************************************************************************/
/**
 * @file        testcase_in.h
 * @brief       test case
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/
#ifndef TESTCASE_IN_H
#define TESTCASE_IN_H

/******************************************************************************/
#include "dlist.h"
#include "testcase.h"

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
typedef enum tagTestCaseResult
{
    TC_UNKNOWN = 0,
    TC_FAIL       ,
    TC_PASS       ,
} eTestCaseResult;

/******************************************************************************/
typedef struct tagTcNodeData
{
    TestCaseInfo*        tc_info    ;
    size_t               id         ;
    eTestCaseResult      result     ;
} TcNodeData;

/******************************************************************************/
void dtest_set_tc_result(eTestCaseResult result);
void dtest_get_tc_result(eTestCaseResult* result);

FuncRtn tc_node_data_create(TestCaseInfo* tc, TcNodeData** data);
void tc_node_data_free(void** data);

char* tc_result_string(eTestCaseResult result);
void tc_node_data_title_print(void);
void tc_node_data_print(const void* data);

FuncRtn testcase_run(void* data, void* context);
void testcase_disable(void* data);
void testcase_enable(void* data);

FuncRtn tc_array_to_dlist(TestCaseInfo* tc_array, DList* tc_list);

/******************************************************************************/

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

#endif /* TESTCASE_IN_H */

