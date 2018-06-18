/******************************************************************************/
/**
 * @file          mtrace.h
 * @brief         mtrace.h
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef MTRACE_H
#define MTRACE_H 1

/******************************************************************************/
#include "dtrace.h"

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
typedef struct tagModuleTraceInfo
{
    size_t          module_id;  // must start from 0 and increased by 1
    char*           module_name;
    TraceLevel      print_level;
    TraceLevel      log_level;
    char*           log_name;
} ModuleTraceInfo;

/******************************************************************************/
/**
 * @func          FuncRtn module_trace_init(const ModuleTraceInfo* module, const size_t num)
 * @brief         module_trace_init
 * @param[in]     ModulETraceInfo* module: could NOT be free during tracing,
                               it's suggested to be a pointer to GLOBAL variable
 * @param[in]     size_t num: number of modules
 * @return        FuncRtn:
 * @complexity    O(num)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn module_trace_init(const ModuleTraceInfo* info, const size_t num);

extern void module_trace_deinit(void);

extern void set_module_trace_info(const size_t module_id, const ModuleTraceInfo* info);

extern ModuleTraceInfo* get_module_trace_info(const size_t module_id);

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif // MTRACE_H

