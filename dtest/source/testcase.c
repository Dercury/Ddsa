/******************************************************************************/
/**
 * @file        testcase.c
 * @brief       test case
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

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
eTestCaseResult g_tc_result = TC_UNKNOWN;

/******************************************************************************/
void dtest_set_tc_result(eTestCaseResult result)
{
    if (TC_FAIL != g_tc_result)
    {
        g_tc_result = result;
    }

    return;
}

/******************************************************************************/
void dtest_get_tc_result(eTestCaseResult* result)
{
    *result = g_tc_result;

    return;
}

/******************************************************************************/
FuncRtn tc_node_data_create(TestCaseInfo* tc, TcNodeData** data)
{
    IF_ERROR_EXIT(alloc_memory((void **)data, sizeof(TcNodeData)));
    (*data)->tc_info = tc;

    return FUNC_OK;
}

/******************************************************************************/
void tc_node_data_free(void** data)
{
    TcNodeData** tc_data = (TcNodeData **)data;

    free_memory((void **)tc_data);

    return;
}

/******************************************************************************/
char* tc_result_string(eTestCaseResult result)
{
    switch (result)
    {
    case TC_PASS:
        return "PASS";
        break;
    case TC_FAIL:
        return "FAIL";
        break;
    case TC_UNKNOWN:
        return "UNKNOWN";
        break;
    default:
        IF_ERROR_EXIT(FUNC_UNREACHABLE);
        break;
    }
    return NULL;
}

/******************************************************************************/
void tc_node_data_title_print(void)
{
    DTRACE("------------------------------------------------------------------\n");
    DTRACE("\tId       Name               Enable         Result\n");
}

/******************************************************************************/
void tc_node_data_print(const void* data)
{
    TcNodeData* node_data = (TcNodeData *)data;

    if (FALSE == node_data->tc_info->enable)
    {
        DTRACE_COLOR(COLOR_BLUE, "\t%2d    %-20s  %-9s      %-8s\n", node_data->id, node_data->tc_info->name,
                bool_to_str(node_data->tc_info->enable), tc_result_string(node_data->result));
        return;
    }

    switch (node_data->result)
    {
    case TC_UNKNOWN:
        DTRACE_COLOR(COLOR_YELLOW, "\t%2d    %-20s  %-9s      %-8s\n", node_data->id, node_data->tc_info->name,
                bool_to_str(node_data->tc_info->enable), tc_result_string(node_data->result));
        break;
    case TC_FAIL:
        DTRACE_COLOR(COLOR_RED, "\t%2d    %-20s  %-9s      %-8s\n", node_data->id, node_data->tc_info->name,
                bool_to_str(node_data->tc_info->enable), tc_result_string(node_data->result));
        break;
    case TC_PASS:
        DTRACE_COLOR(COLOR_GREEN, "\t%2d    %-20s  %-9s      %-8s\n", node_data->id, node_data->tc_info->name,
                bool_to_str(node_data->tc_info->enable), tc_result_string(node_data->result));
        break;
    default:
        IF_ERROR_PRINT(FUNC_UNREACHABLE);
        break;
    }

    return;
}

/******************************************************************************/
FuncRtn testcase_run(void* data, void* context)
{
    TcNodeData* node_data = (TcNodeData *)data;

    DTRACE("------------------------------------------------------------------\n");
    DTRACE("\t Running Test Case - %s: \n", node_data->tc_info->name);

    g_tc_result = TC_UNKNOWN;

    if (FALSE == node_data->tc_info->enable)
    {
        DTRACE_COLOR(COLOR_BLUE, "\t\t\t\t\t\t   -----> DISABLED\n");
        return FUNC_OK;
    }

    if (NULL != node_data->tc_info->init_func)
    {
        DTRACE("\t\t init_func\n");
        (node_data->tc_info->init_func)();
    }

    if (NULL != node_data->tc_info->function)
    {
        DTRACE("\t\t tc_func\n");
        (node_data->tc_info->function)();
    }
    else
    {
        return FUNC_NULL_POINTER;
    }

    if (NULL != node_data->tc_info->cleanup_func)
    {
        DTRACE("\t\t cleanup_func\n");
        (node_data->tc_info->cleanup_func)();
    }

    dtest_get_tc_result(&(node_data->result));

    switch (node_data->result)
    {
    case TC_UNKNOWN:
        DTRACE_COLOR(COLOR_YELLOW, "\n\t\t\t\t\t\t   -----> %-8s\n",
                            tc_result_string(node_data->result));
        break;
    case TC_FAIL:
        DTRACE_COLOR(COLOR_RED, "\n\t\t\t\t\t\t   -----> %-8s\n",
                            tc_result_string(node_data->result));
        break;
    case TC_PASS:
        DTRACE_COLOR(COLOR_GREEN, "\n\t\t\t\t\t\t   -----> %-8s\n",
                            tc_result_string(node_data->result));
        break;
    default:
        IF_ERROR_RETURN(FUNC_UNREACHABLE);
        break;
    }

    return FUNC_OK;
}

/******************************************************************************/
void testcase_disable(void* data)
{
    TcNodeData* node_data = (TcNodeData *)data;

    node_data->tc_info->enable = FALSE;

    return;
}

/******************************************************************************/
void testcase_enable(void* data)
{
    TcNodeData* node_data = (TcNodeData *)data;

    node_data->tc_info->enable = TRUE;

    return;
}

/******************************************************************************/
FuncRtn tc_array_to_dlist(TestCaseInfo* tc_array, DList* tc_list)
{
    size_t i = 0;
    TcNodeData* data = NULL;

    for (i = 0; NULL != (tc_array[i]).name; i++)
    {
        IF_ERROR_RETURN(tc_node_data_create(tc_array + i, &data));
        data->id = i;
        IF_ERROR_RETURN(dlist_append_tail(tc_list, data));
    }

    return FUNC_OK;
}

/******************************************************************************/

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

