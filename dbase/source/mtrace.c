/******************************************************************************/
/**
 * @file        dtrace.c
 * @brief       trace
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/

#include "macro.h"
#include "mem_op.h"
#include "mtrace.h"
#include <stdio.h>      /* fprintf sprintf */
#include <stdlib.h>     /* memset */
#include <string.h>     /* strncat */

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
static ModuleTraceInfo* g_trace_info = NULL;
static size_t g_trace_info_num = 0;
static FILE** g_trace_logs = NULL;

/******************************************************************************/
FuncRtn module_trace_init(const ModuleTraceInfo* info, const size_t num)
{
    void* temp = NULL;
    FILE* file = NULL;
    FuncRtn rtn = FUNC_OK;
    size_t i;

    PARAM_CHECK_NULL_POINTER(info);
    PARAM_CHECK_MIN(num, 1);

    g_trace_info_num = num;

    // allot memory for g_trace_info and g_trace_logs together
    IF_ERROR_RETURN(alloc_memory(&temp, num * (sizeof(ModuleTraceInfo*) + sizeof(FILE*))));
    g_trace_info = temp;
    g_trace_logs = temp + num * sizeof(ModuleTraceInfo);

    memcpy(g_trace_info, info, num * sizeof(ModuleTraceInfo));

    for (i = 0; i < num; i++)
    {
        if ((info->log_level != TRACE_CLOSE) && (info->log_name == NULL))
        {
            printf("Error: log_name must be set for module_id=%u\n", info->module_id);
            rtn = FUNC_PARAM_NULL_POINTER;
            break;
        }

        // how to avoid fopen a file more than once?
        file = fopen(info->log_name, "a+");
        if (NULL == file)
        {
            printf("Error: Can't open %s!\n", info->log_name);
            rtn = FUNC_FILE_OPEN;
            break;
        }
        g_trace_logs[i] = file;
    }

    if (rtn != FUNC_OK)
    {
        module_trace_deinit();
    }

    return rtn;
}

/******************************************************************************/
void module_trace_deinit(void)
{
    size_t i;

    for (i = 0; i < g_trace_info_num; i++)
    {
        if (g_trace_logs[i] != NULL)
        {
            fclose(g_trace_logs[i]);
        }
    }

    // Free memory of g_trace_info and g_trace_logs together
    free_memory((void**)&g_trace_info);
    g_trace_info_num = 0;

    return;
}

/******************************************************************************/
void set_module_trace_info(const size_t module_id, const ModuleTraceInfo* info)
{
    if (module_id >= g_trace_info_num)
    {
        printf("Error: module_id out of range!\n");
        return;
    }

    if (info->log_level != TRACE_CLOSE && info->log_name == NULL)
    {
        printf("Error: log_name must be set!\n");
    }

    memcpy(g_trace_info + module_id, info, sizeof(ModuleTraceInfo));

    return;
}

/******************************************************************************/
ModuleTraceInfo* get_module_trace_info(const size_t module_id)
{
    if (module_id >= g_trace_info_num)
    {
        printf("Error: module_id out of range!\n");
        return NULL;
    }

    return (g_trace_info + module_id);
}

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

