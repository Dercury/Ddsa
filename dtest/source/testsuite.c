/******************************************************************************/
/**
 * @file        testsuite.c
 * @brief       test suite
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/

#include "dtrace.h"
#include "macro.h"
#include "mem_op.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "testcase_in.h"
#include "testsuite_in.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
FuncRtn ts_node_data_create(TestSuiteInfo* ts, DList* list, TsNodeData** data)
{
    IF_ERROR_EXIT(alloc_memory((void **)data, sizeof(TsNodeData)));
    (*data)->ts_info = ts;
    (*data)->tc_list = list;

    return FUNC_OK;
}

/******************************************************************************/
void ts_node_data_free(void** data)
{
    TsNodeData** ts_data = (TsNodeData **)(data);

    IF_ERROR_PRINT(dlist_destroy(&((*ts_data)->tc_list)));
    free_memory((void **)&((*ts_data)->tc_list));

    free_memory(data);

    return;
}

/******************************************************************************/
void ts_node_data_title_print(void)
{
    DTRACE("==================================================================\n");
    DTRACE("Id       Name               Enable       TcNum\n");
}

/******************************************************************************/
void ts_node_data_print(const void* data)
{
    TsNodeData* node_data = (TsNodeData *)data;

    if (FALSE == node_data->ts_info->enable)
    {
        DTRACE_COLOR(COLOR_BLUE, "%2d    %-20s  %-9s        %u\n", node_data->id, node_data->ts_info->name,
            bool_to_str(node_data->ts_info->enable), dlist_get_size(node_data->tc_list));
    }
    else
    {
        DTRACE_COLOR(COLOR_MAGENTA, "%2d    %-20s  %-9s        %u\n", node_data->id, node_data->ts_info->name,
            bool_to_str(node_data->ts_info->enable), dlist_get_size(node_data->tc_list));
    }

    tc_node_data_title_print();
    IF_ERROR_PRINT(dlist_print(node_data->tc_list, tc_node_data_print));
    DTRACE("==================================================================\n");

    return;
}

/******************************************************************************/
FuncRtn testsuite_run(void* data, void* context)
{
    TsNodeData* node_data = (TsNodeData *)data;

    DTRACE("==================================================================\n");
    DTRACE("Running Test Suite - %s: \n", node_data->ts_info->name);

    if (FALSE == node_data->ts_info->enable)
    {
        DTRACE_COLOR(COLOR_BLUE, "\t\t\t\t\t\t   =====> DISABLED\n");
        return FUNC_OK;
    }

    if (NULL != node_data->ts_info->init_func)
    {
        DTRACE("\t init_func\n");
        (node_data->ts_info->init_func)();
    }

    IF_ERROR_PRINT(dlist_foreach(node_data->tc_list, testcase_run, NULL));

    if (NULL != node_data->ts_info->cleanup_func)
    {
        DTRACE("\t cleanup_func\n");
        (node_data->ts_info->cleanup_func)();
    }

    return FUNC_OK;
}

/******************************************************************************/
void testsuite_disable(void* data)
{
    TsNodeData* node_data = (TsNodeData *)data;

    node_data->ts_info->enable = FALSE;

    return;
}

/******************************************************************************/
void testsuite_enable(void* data)
{
    TsNodeData* node_data = (TsNodeData *)data;

    node_data->ts_info->enable = TRUE;

    return;
}

/******************************************************************************/
FuncRtn ts_array_to_dlist(TestSuiteInfo* ts_array, size_t ts_num, DList* ts_list)
{
    size_t i = 0;
    TsNodeData* data = NULL;
    DList* tc_list = NULL;

    for (i = 0; i < ts_num; i++)
    {
        tc_list = dlist_create(tc_node_data_free, NULL);
        IF_ERROR_RETURN(tc_array_to_dlist((ts_array[i]).tc_array, tc_list));

        IF_ERROR_RETURN(ts_node_data_create(ts_array + i, tc_list, &data));
        data->id = i;
        IF_ERROR_RETURN(dlist_append_tail(ts_list, data));
    }

    return FUNC_OK;
}

/******************************************************************************/

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

