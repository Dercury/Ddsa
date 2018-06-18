/******************************************************************************/
/**
 * @file          str_op.h
 * @brief         string operation
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef _STR_OP_H
#define _STR_OP_H 1

/***************************** include files **********************************/
#include "func_rtn.h"
#include <stdlib.h>

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#ifndef SHORT_FILENAME
#define SHORT_FILENAME          short_filename(__FILE__)
#endif

/******************************************************************************/
/**
 * @func          char* reverse_string(char* string)
 * @brief         reverse_string
 * @param[in/out] char* string:
 * @return        char*:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern char* reverse_string(char* string);

/******************************************************************************/
/**
 * @func          char* replace_string(char* str_buf, char* ori_str, char* sub_str)
 * @brief         replace_string
 * @param[in/out] char* str_buf:
 * @param[in/out] char* ori_str:
 * @param[in/out] char* sub_str:
 * @return        char*:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern char* replace_string(char* str_buf, char* ori_str, char* sub_str);

/******************************************************************************/
/**
 * @func          char* short_filename(char* filename)
 * @brief         short_filename
 * @param[in/out] char* filename:
 * @return        char*:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern char* short_filename(char* filename);

/******************************************************************************/
/**
 * @func          char* short_filename(char* filename)
 * @brief         short_filename
 * @param[in/out] char* filename:
 * @return        FuncRtn:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn print_to_file(const char* string, const char* filename, const char* mode);

/******************************************************************************/
/**
 * @func          char* int_to_string(int number, unsigned int base, char* string)
 * @brief         int_to_string
 * @param[in]     int number:
 * @param[in]     unsigned int base:
 * @param[in/out] char* buffer: string buffer
 * @param[in]     size_t buffer_len: bytes of buffer
 * @return        char*:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern char* int_to_string(int number, unsigned int base, char* buffer, size_t buffer_len);

/******************************************************************************/
/**
 * @func          char* decimal_int_to_str(int data)
 * @brief         decimal_int_to_str
 * @param[in]     int data:
 * @param[in/out] char* buffer: string buffer
 * @param[in]     size_t buffer_len: bytes of buffer
 * @return        char*:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern char* decimal_int_to_str(int data, char* buffer, size_t buffer_len);

/******************************************************************************/
/**
 * @func          FuncRtn cur_time_string(char* buffer, size_t buffer_len)
 * @brief         current time string: year-month-day_hour-minute-second
 * @param[in/out] char* buffer: string buffer
 * @param[in]     size_t buffer_len: bytes of buffer, at least 20 bytes
 * @return        FuncRtn:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
#define CUR_TIME_STR_MIN_LEN    20
extern FuncRtn cur_time_string(char* buffer, size_t buffer_len);

/******************************************************************************/

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif // _STR_OP_H

