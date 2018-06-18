/******************************************************************************/
/**
 * @file        main.c
 * @brief       main function
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/

#include "bool.h"
#include "dtest_main.h"
#include "dtrace.h"
#include "macro.h"
#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "testsuite.h"

#include "tc_list.h"
#include "tc_dlist.h"

#include "tc_bitree.h"
#include "tc_bintree.h"
#include "tc_avltree.h"

#include "tc_heap.h"

#include "tc_graph.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
/**
 * [g_testsuite] is a array of testsuites for all modules that are testing. It
 *      should NOT be changed during testing.
 *
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/
TestSuiteInfo     g_testsuites[] =
{
   /* Name          Enable     InitFunc   CleanupFunc     Testcases    TcNum*/
    {"ts_list",     TRUE,      NULL,      NULL,           g_list_tcs   , 0 /*g_list_tcs_num   */},
    {"ts_dlist",    TRUE,      NULL,      NULL,           g_dlist_tcs  , 0 /*g_dlist_tcs_num  */},

    {"ts_bitree",   TRUE,      NULL,      NULL,           g_bitree_tcs , 0 /*g_bitree_tcs_num */},
    {"ts_bintree",  TRUE,      NULL,      NULL,           g_bintree_tcs, 0 /*g_bintree_tcs_num*/},
    {"ts_avltree",  TRUE,      NULL,      NULL,           g_avltree_tcs, 0 /*g_avltree_tcs_num*/},

    {"ts_heap",     TRUE,      NULL,      NULL,           g_heap_tcs   , 0 /*g_heap_tcs_num   */},
    
    {"ts_graph",    TRUE,      NULL,      NULL,           g_graph_tcs  , 0 /*g_graph_tcs_num  */},
};

/******************************************************************************/
int main(int argc, char** argv)
{
    set_print_level(TRACE_INFO);
    set_log_level(TRACE_INFO);

    IF_ERROR_RETURN(dtest_main(g_testsuites, ARRAY_SIZE(g_testsuites)));

    set_log_level(TRACE_CLOSE);

    return EXIT_SUCCESS;
}

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

