/******************************************************************************/
/**
 * @file        tc_list.c
 * @brief       test cases for linked list
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/

#include "bintree.h"

#include "dtest_usage.h"
#include "int_op.h"
#include "macro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str_op.h"

#include "tc_bintree.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
TestCaseInfo    g_bintree_tcs[] =
{
    /*     Name                Enable    Init Function    Cleanup Function    Test Function */
    { "tc_bintree_int",     TRUE,            NULL,               NULL,     tc_bintree_int },
    { "tc_bintree_double",  TRUE,            NULL,               NULL,     tc_bintree_double },
    TEST_CASE_INFO_END
};

size_t g_bintree_tcs_num = ARRAY_SIZE(g_bintree_tcs);

/******************************************************************************/
void tc_bintree_int(void)
{
    int int_array[] = {23, 13, 89, 46, 3, 95, 73, 67, 35};
    void* data = NULL;
    size_t int_num = sizeof(int_array) / sizeof(int_array[0]);
    size_t i;

    BiTree* tree = bintree_create(NULL, (CmpFunc)cmp_int);

    for (i = 0; i < int_num; i++)
    {
        data = (void *)(int_array[i]);
        DTEST_EXPECT_TRUE(FUNC_OK == bintree_insert(tree, data));
    }

    DTEST_EXPECT_TRUE(FUNC_OK == bintree_print(tree, (DataPrintFunc)print_int));

    DTEST_EXPECT_TRUE(FUNC_OK == bintree_print_figure(tree, (DataToStrFunc)decimal_int_to_str, 3, "bitree.dat", "w+"));

    data = (void *)(int_array[3]);
    DTEST_EXPECT_TRUE(FUNC_OK == bintree_remove(tree, FALSE, &data));

    DTEST_EXPECT_TRUE(FUNC_OK == bintree_print(tree, (DataPrintFunc)print_int));

    DTEST_EXPECT_TRUE(FUNC_OK == bintree_print_figure(tree, (DataToStrFunc)decimal_int_to_str, 3, "bitree.dat", "a+"));

    DTEST_EXPECT_TRUE(FUNC_OK == bintree_destroy(&tree));

    return;
}

/******************************************************************************/
void tc_bintree_double(void)
{
    DTEST_EXPECT_TRUE(FALSE);
    return;
}

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

