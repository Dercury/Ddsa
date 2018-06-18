/******************************************************************************/
/**
 * @file        tc_list.c
 * @brief       test cases for linked list
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/

#include "list.h"

#include "dtest_usage.h"
#include "int_op.h"
#include "macro.h"
#include "rand.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str_op.h"

#include "tc_list.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
TestCaseInfo    g_list_tcs[] =
{
    /*     Name    Enable    Init Function    Cleanup Function    Test Function */
    { "tc_list_int",    TRUE,            NULL,               NULL,     tc_list_int },
    { "tc_list_double", FALSE,           NULL,               NULL,     tc_list_double },
    TEST_CASE_INFO_END
};

size_t g_list_tcs_num = ARRAY_SIZE(g_list_tcs);

/******************************************************************************/
void tc_list_int(void)
{
    int i;
    void* data = NULL;
    List* list = list_create(NULL, (CmpFunc)cmp_int);
    for (i = 0; i < 10; i++)
    {
        data = (void *)random_uint(100);
        DTEST_EXPECT_EQUAL(FUNC_OK, list_insert_head(list, data));
    }
    DTEST_EXPECT_EQUAL(FUNC_OK, list_destroy(&list));

    return;
}

/******************************************************************************/
void tc_list_double(void)
{
    DTEST_EXPECT_TRUE(FALSE);
    return;
}

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

