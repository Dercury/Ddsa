/******************************************************************************/
/**
 * @file          func_ptr.h
 * @brief         function pointer
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef _FUNC_PTR_H
#define _FUNC_PTR_H 1

/***************************** include files **********************************/
#include "func_rtn.h"
#include <stdio.h>
#include <stdlib.h>

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
/**
 * @func          void free_memory(void** pointer)
 * @brief         free memory, equals free adding set pointer to NULL
 * @param[in/out] void** pointer: pointer of pointer of memory
 * @return        void
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
typedef void (*FreeFunc)(void** pointer);

/******************************************************************************/
/**
 * @func          void visit_func(void* data, void* context)
 * @brief         function pointer that visits <data> in <context>
 * @param[in/out] void* data: data that need to be visited
 * @param[in/out] void* context: context of visiting
 * @return        FuncRtn
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
typedef FuncRtn (*VisitFunc)(void* data, void* context);

/******************************************************************************/
/**
 * @func          int cmp_func(const void* data0, const void* data1)
 * @brief         function pointer that compares <data0> and <data1>
 * @param[in]     void* data0: data that need to be compared
 * @param[in]     void* data1: data that need to be compared
 * @return        int: >0, more; ==0, equal; <0, less
 * @complexity    O(?)
 * @notes         <data0> and <data1> do NOT need to be of same type.
 */
/******************************************************************************/
typedef int (*CmpFunc)(const void* data0, const void* data1);

/******************************************************************************/
/**
 * @func          char* to_str_func(const void* data)
 * @brief         function pointer that translates <data> to string
 * @param[in]     void* data: data that need to be translated
 * @return        char*: string
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
typedef char* (*ToStrFunc)(const void* data);
typedef char* (*DataToStrFunc)(const void* data, char* buffer, size_t buffer_len);

/******************************************************************************/
/**
 * @func          void printf_func(char* format, ...)
 * @brief         print formated info to stdout or logfile.
 * @param[in]     char* format: data output format
 * @return        int: number of characters or user-defined meanings
 * @complexity    O(?)
 * @notes         It takes same parameters as 'printf'.
 */
/******************************************************************************/
typedef int (*PrintfFunc)(char* format, ...);
typedef int (*FprintfFunc)(FILE* fhandle, char* format, ...);

/******************************************************************************/
/**
 * @func          void print_func(const void* data)
 * @brief         function pointer that prints <data>
 * @param[in]     void* data: data that need to be printed
 * @return        void
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
typedef void (*DataPrintFunc)(const void* data);

/******************************************************************************/

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif // _FUNC_PTR_H

