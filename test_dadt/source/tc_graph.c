/******************************************************************************/
/**
 * @file        tc_graph.c
 * @brief       test cases for graph
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/

#include "graph.h"

#include "bool.h"
#include "dtest_usage.h"
#include "int_op.h"
#include "macro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str_op.h"

#include "tc_graph.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
TestCaseInfo    g_graph_tcs[] =
{
    /*     Name    Enable    Init Function    Cleanup Function    Test Function */
    { "tc_graph_int",    TRUE,            NULL,               NULL,     tc_graph_int },
    { "tc_graph_double", FALSE,           NULL,               NULL,     tc_graph_double },
    TEST_CASE_INFO_END
};

size_t g_graph_tcs_num = ARRAY_SIZE(g_graph_tcs);

/******************************************************************************/
void tc_graph_int(void)
{
    int i;
    void* data = NULL;
    Graph* graph = graph_create(NULL, (CmpFunc)cmp_int);
    for (i = 0; i < 10; i++)
    {
        data = (void *)((i + 1) * 567389 % 100);
        DTEST_EXPECT_EQUAL(FUNC_OK, graph_insert_vertex(graph, data));
    }
    DTEST_EXPECT_EQUAL(FUNC_OK, graph_destroy(&graph));

    return;
}

/******************************************************************************/
void tc_graph_double(void)
{
    DTEST_EXPECT_TRUE(FALSE);
    return;
}

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

