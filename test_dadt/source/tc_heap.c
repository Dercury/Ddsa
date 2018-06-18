/******************************************************************************/
/**
 * @file        tc_heap.c
 * @brief       test cases for heap
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/

#include "heap.h"

#include "dtest_usage.h"
#include "int_op.h"
#include "macro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str_op.h"

#include "tc_heap.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
TestCaseInfo    g_heap_tcs[] =
{
    /*     Name    Enable    Init Function    Cleanup Function    Test Function */
    { "tc_heap_int",    TRUE,            NULL,               NULL,     tc_heap_int },
    { "tc_heap_double", TRUE,            NULL,               NULL,     tc_heap_double },
    TEST_CASE_INFO_END
};

size_t g_heap_tcs_num = ARRAY_SIZE(g_heap_tcs);

/******************************************************************************/
void tc_heap_int(void)
{
    int i;
    void* data = NULL;
    Heap* heap = heap_create(NULL, (CmpFunc)cmp_int);

    for (i = 0; i < 10; i++)
    {
        data = (void *)((i + 1) * 567389 % 100);
        DTEST_EXPECT_EQUAL(FUNC_OK, heap_insert(heap, data));
    }

    for (i = 0; i < 10; i++)
    {
        data = NULL;
        DTEST_EXPECT_EQUAL(FUNC_OK, heap_extract(heap, &data));
    }

    DTEST_EXPECT_EQUAL(FUNC_OK, heap_destroy(&heap));

    return;
}

/******************************************************************************/
void tc_heap_double(void)
{
    DTEST_EXPECT_TRUE(FALSE);
    return;
}

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

