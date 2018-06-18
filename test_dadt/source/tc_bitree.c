/******************************************************************************/
/**
 * @file        tc_list.c
 * @brief       test cases for linked list
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/

#include "bitree.h"

#include "dtest_usage.h"
#include "int_op.h"
#include "macro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str_op.h"

#include "tc_bitree.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
TestCaseInfo    g_bitree_tcs[] =
{
    /*     Name    Enable    Init Function    Cleanup Function    Test Function */
    { "tc_bitree_int",    TRUE,            NULL,               NULL,     tc_bitree_int },
    { "tc_bitree_double", FALSE,           NULL,               NULL,     tc_bitree_double },
    TEST_CASE_INFO_END
};

size_t g_bitree_tcs_num = ARRAY_SIZE(g_bitree_tcs);

/******************************************************************************/
void tc_bitree_int(void)
{
    BiTree* tree = bitree_create(NULL, (CmpFunc)cmp_int);

    DTEST_EXPECT_TRUE(FUNC_OK == bitree_destroy(&tree));

    return;
}

/******************************************************************************/
void tc_bitree_double(void)
{
    DTEST_EXPECT_TRUE(FALSE);
    return;
}

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

