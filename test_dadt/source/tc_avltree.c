/******************************************************************************/
/**
 * @file        tc_list.c
 * @brief       test cases for linked list
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/

#include "avltree.h"

#include "dtest_usage.h"
#include "int_op.h"
#include "macro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str_op.h"

#include "tc_avltree.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
TestCaseInfo    g_avltree_tcs[] =
{
    /*     Name    Enable    Init Function    Cleanup Function    Test Function */
    { "tc_avltree_int",    TRUE,            NULL,               NULL,     tc_avltree_int },
    { "tc_avltree_double", TRUE,            NULL,               NULL,     tc_avltree_double },
    TEST_CASE_INFO_END
};

size_t g_avltree_tcs_num = ARRAY_SIZE(g_avltree_tcs);

/******************************************************************************/
void tc_avltree_int(void)
{
    AvlTree* tree = NULL;
    void* temp = NULL;
    int data[] = {4, 7, 3, 2, 1, 9, 8, 5, 6, 0, -12, -4, -5};
    size_t i = 0, data_num = sizeof(data) / sizeof(data[0]);

    tree = avltree_create(NULL, (CmpFunc)cmp_int);

    for (i = 0; i < data_num; i++)
    {
        DTEST_EXPECT_EQUAL(FUNC_OK, avltree_insert(tree, (void *)data[i]));
    }

    DTEST_EXPECT_EQUAL(FUNC_OK, avltree_print(tree, (DataPrintFunc)print_int));

    DTEST_EXPECT_EQUAL(FUNC_OK, avltree_print_figure(tree, (DataToStrFunc)decimal_int_to_str, 3, "avltree.dat", "w+"));

    temp = (void *)data[6];
    DTEST_EXPECT_EQUAL(FUNC_OK, avltree_remove(tree, FALSE, &temp));

    temp = (void *)data[data_num - 1];
    DTEST_EXPECT_EQUAL(FUNC_OK, avltree_remove(tree, FALSE, &temp));

    DTEST_EXPECT_EQUAL(FUNC_OK, avltree_print_figure(tree, (DataToStrFunc)decimal_int_to_str, 6, "avltree.dat", "a+"));

    DTEST_EXPECT_EQUAL(FUNC_OK, avltree_destroy(&tree));

    return;
}

/******************************************************************************/
void tc_avltree_double(void)
{
    DTEST_EXPECT_TRUE(FALSE);
    return;
}

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

