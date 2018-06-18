/******************************************************************************/
/**
 * @file        testsuite_in.h
 * @brief       test suite
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/
#ifndef TESTSUITE_IN_H
#define TESTSUITE_IN_H

/******************************************************************************/
#include "dlist.h"
#include "testsuite.h"

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
typedef struct tagTsNodeData
{
    TestSuiteInfo*  ts_info ;
    size_t        id      ;
    DList*          tc_list ;
} TsNodeData;

/******************************************************************************/
FuncRtn ts_node_data_create(TestSuiteInfo* ts, DList* list, TsNodeData** data);
void ts_node_data_free(void** data);

void ts_node_data_title_print(void);
void ts_node_data_print(const void* data);

FuncRtn testsuite_run(void* data, void* context);
void testsuite_disable(void* data);
void testsuite_enable(void* data);

FuncRtn ts_array_to_dlist(TestSuiteInfo* ts_array, size_t ts_num, DList* ts_list);
/******************************************************************************/

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

#endif /* TESTSUITE_IN_H */

