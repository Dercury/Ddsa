/******************************************************************************/
/**
 * @file        tc_dlist.c
 * @brief       test cases for doubly linked list
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/

#include "dlist.h"

#include "dtest_usage.h"
#include "dtrace.h"
#include "int_op.h"
#include "macro.h"
#include "rand.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str_op.h"

#include "tc_dlist.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
TestCaseInfo    g_dlist_tcs[] =
{
    /*     Name                Enable    Init Function    Cleanup Function    Test Function */
    { "tc_dlist_int",       TRUE,       NULL,              NULL,        tc_dlist_int },
    { "tc_dlist_double",    TRUE,       NULL,              NULL,        tc_dlist_double },
    TEST_CASE_INFO_END
};

size_t g_dlist_tcs_num = ARRAY_SIZE(g_dlist_tcs);

/******************************************************************************/
void tc_dlist_int(void)
{
    DList* list = dlist_create(NULL, (CmpFunc)cmp_int);
    DataPrintFunc print = (DataPrintFunc)print_int;
    FuncRtn rtn = FUNC_OK;
    void* data = NULL;
    int data_max = 20, i;

    for (i = 0; i < 3; i++)
    {
        data = (void*)random_uint(data_max);
        rtn = dlist_insert_head(list, data);
        DTEST_EXPECT_EQUAL(rtn, FUNC_OK);
    }
    DTEST_EXPECT_EQUAL(dlist_print(list, print), FUNC_OK);
    DTRACE("\n");

    for (i = 0; i < 4; i++)
    {
        data = (void*)random_uint(data_max);
        rtn = dlist_append_tail(list, data);
        DTEST_EXPECT_EQUAL(rtn, FUNC_OK);
    }
    DTEST_EXPECT_EQUAL(dlist_print(list, print), FUNC_OK);
    DTRACE("\n");

    for (i = 0; i < 5; i++)
    {
        data = (void*)random_uint(data_max);
        rtn = dlist_insert_by_value(list, data);
        DTEST_EXPECT_EQUAL(rtn, FUNC_OK);
    }
    DTEST_EXPECT_EQUAL(dlist_print(list, print), FUNC_OK);
    DTRACE("\n");

    for (i = 0; i < 3; i++)
    {
        data = (void*)random_uint(data_max);
        rtn = dlist_remove_by_value(list, data, FALSE);
        if (rtn != FUNC_OK)
        {
            DTEST_EXPECT_EQUAL(rtn, FUNC_NOT_EXIST);
        }
    }
    DTEST_EXPECT_EQUAL(dlist_print(list, print), FUNC_OK);
    DTRACE("\n");

    rtn = dlist_quick_sort(list, 0, dlist_get_size(list) - 1);
    DTEST_EXPECT_EQUAL(rtn, FUNC_OK);
    DTRACE("list after sort:\n");
    DTEST_EXPECT_EQUAL(dlist_print(list, print), FUNC_OK);
    DTRACE("\n");

    for (i = 0; i < 3; i++)
    {
        data = (void*)random_uint(data_max);
        rtn = dlist_set_by_index(list, i + 4, data);
        DTEST_EXPECT_EQUAL(rtn, FUNC_OK);
    }
    DTEST_EXPECT_EQUAL(dlist_print(list, print), FUNC_OK);
    DTRACE("\n");

    for (i = 3; i > 0; i--)
    {
        data = (void*)random_uint(data_max);
        rtn = dlist_remove_by_index(list, i + 1, FALSE, &data);
        DTEST_EXPECT_EQUAL(rtn, FUNC_OK);
    }
    DTEST_EXPECT_EQUAL(dlist_print(list, print), FUNC_OK);
    DTRACE("\n");

    rtn = dlist_quick_sort(list, 0, dlist_get_size(list) - 1);
    DTEST_EXPECT_EQUAL(rtn, FUNC_OK);
    DTRACE("list after sort 2:\n");
    DTEST_EXPECT_EQUAL(dlist_print(list, print), FUNC_OK);
    DTRACE("\n");

    rtn = dlist_destroy(&list);
    DTEST_EXPECT_EQUAL(rtn, FUNC_OK);

    return;
}

/******************************************************************************/
void tc_dlist_double(void)
{
    DList* list = dlist_create(NULL, NULL);
    FuncRtn rtn = FUNC_OK;

    rtn = dlist_destroy(&list);
    DTEST_EXPECT_EQUAL(rtn, FUNC_OK);

    return;
}

/******************************************************************************/

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

