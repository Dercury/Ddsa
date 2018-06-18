/******************************************************************************/
/**
 * @file        str_op.c
 * @brief       string operation
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/

#include <assert.h>     /* assert */
#include "bool.h"
#include "macro.h"
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* exit */
#include <string.h>     /* strlen */
#include "str_op.h"
#include <time.h>       /* time localtime */

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
char* reverse_string(char* string)
{
    char c = 0;
    unsigned int i, j;

    for (i = 0, j = strlen(string) - 1; i < j; i++, j--)
    {
        c = string[i];
        string[i] = string[j];
        string[j] = c;
    }

    return string;
}

/******************************************************************************/
char* replace_string(char* str_buf, char* ori_str, char* sub_str)
{
    int str_buf_len = 0, ori_str_len = 0, sub_str_len =0;
    int i = 0, j = 0;

    assert(NULL != str_buf && NULL != ori_str && NULL != sub_str);
    str_buf_len = strlen(str_buf);
    ori_str_len = strlen(ori_str);
    sub_str_len = strlen(sub_str);
    assert(str_buf_len >= ori_str_len && ori_str_len == sub_str_len);

    for (i = 0; i < str_buf_len - ori_str_len + 1; i++)
    {
        if (0 == strncmp(str_buf + i, ori_str, ori_str_len))
        {
            for (j = 0; j < ori_str_len; j++)
            {
                str_buf[i++] = sub_str[j];
            }
            i--;
        }
    }

    return str_buf;
}

/******************************************************************************/
char* short_filename(char* filename)
{
    char* short_name = NULL;
    size_t len = 0;

    assert(NULL != filename);

    len = strlen(filename);
    for (short_name = filename + len; short_name >= filename; short_name--)
    {
        if ('\\' == short_name[0] || '/' == short_name[0])
        {
            short_name++;
            break;
        }
    }

    return short_name;
}

/******************************************************************************/
FuncRtn print_to_file(const char* string, const char* filename, const char* mode)
{
    FILE* file = NULL;

    PARAM_CHECK_NULL_POINTER(string);
    PARAM_CHECK_NULL_POINTER(filename);
    PARAM_CHECK_NULL_POINTER(mode);

    file = fopen(filename, mode);
    if (NULL == file)
    {
        fprintf(stderr, "Can't open %s using mode-%s!\n", filename, mode);
        return FUNC_FILE_OPEN;
    }

    fprintf(file, "%s\n", string);

    fclose(file);

    return FUNC_OK;
}

/******************************************************************************/
char* int_to_string(int number, unsigned int base, char* string, size_t len)
{
    unsigned int i = 0;
    int remainder;
    Bool is_negative = FALSE;

    /* 2: binary; 36: 10 numbers and 26 letters */
    if (base < 2 || base > 36)
    {
        exit(-1);
    }
    if (len == 0)
    {
        exit(-1);
    }

    len--;  // for '\0'
    if (number < 0)
    {
        is_negative = TRUE;
        number = -number;
        len--;  // for '-'
    }

    do
    {
        remainder = number % base;
        string[i++] = (10 > remainder) ? remainder + '0' : remainder - 10 + 'A';
    } while ((number /= base) > 0 && i < len);

    if (is_negative)
    {
        string[i++] = '-';
    }

    string[i++] = '\0';

    return reverse_string(string);
}

/******************************************************************************/
char* decimal_int_to_str(int data, char* buffer, size_t buffer_len)
{
    memset(buffer, 0, buffer_len);

    (void)snprintf(buffer, buffer_len, "%d", data);

    return buffer;
}

/******************************************************************************/
FuncRtn cur_time_string(char* buffer, size_t buffer_len)
{
    time_t cur_time;
    struct tm* tp;

    PARAM_CHECK_NULL_POINTER(buffer);
    PARAM_CHECK_MIN(buffer_len, CUR_TIME_STR_MIN_LEN);

    if (-1 == time(&cur_time))
    {
        return FUNC_UNREACHABLE;
    }

    tp = localtime(&cur_time);
    memset(buffer, 0, buffer_len);
    snprintf(buffer, CUR_TIME_STR_MIN_LEN - 1, "%04d-%02d-%02d_%02d-%02d-%02d",
            tp->tm_year + 1900, tp->tm_mon + 1, tp->tm_mday,
            tp->tm_hour, tp->tm_min, tp->tm_sec);

    return FUNC_OK;
}

/******************************************************************************/

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

