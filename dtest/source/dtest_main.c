/******************************************************************************/
/**
 * @file        test_main.c
 * @brief       dercury test
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/

#include "dtest_main.h"
#include "dtrace.h"
#include "macro.h"
#include <stdio.h>
#include <string.h>
#include "testcase_in.h"
#include "testsuite_in.h"

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

#if CODE_SEPARATOR("Inner Function", 1)
/******************************************************************************/
typedef enum tagDTestOp
{
    DTEST_OP_SHOW = 0,
    DTEST_OP_RUN,
    DTEST_OP_ENABLE,
    DTEST_OP_DISABLE,
    DTEST_OP_BUTT,
} DTestOp;

/************************** Inner functions declaration **********************/
static void dtest_menu(int* choice);
static void get_id(char* msg, size_t* id);

static void all_testcases_op(DList* ts_list, DTestOp operation);
static void one_testsuite_op(DList* ts_list, DTestOp operation);
static void one_testcase_op(DList* ts_list, DTestOp operation);

/******************************************************************************/

#endif /* CODE_SEPARATOR("Inner Function", 1) */

#if CODE_SEPARATOR("Outer Function", 1)
/************************ Outer interface implementation **********************/
FuncRtn dtest_main(TestSuiteInfo* ts_array, size_t ts_num)
{
    DList* ts_list;
    int menu_choice = 0;

    PARAM_CHECK_NULL_POINTER(ts_array);
    PARAM_CHECK_MIN(ts_num, 1);

    ts_list = dlist_create(ts_node_data_free, NULL);
    IF_ERROR_RETURN(ts_array_to_dlist(ts_array, ts_num, ts_list));

    do
    {
        dtest_menu(&menu_choice);
        switch (menu_choice)
        {
        case 'A':
            all_testcases_op(ts_list, DTEST_OP_RUN);
            break;
        case 'a':
            all_testcases_op(ts_list, DTEST_OP_SHOW);
            break;
        case 'B':
            one_testsuite_op(ts_list, DTEST_OP_RUN);
            break;
        case 'b':
            one_testsuite_op(ts_list, DTEST_OP_SHOW);
            break;
        case 'C':
            one_testcase_op(ts_list, DTEST_OP_RUN);
            break;
        case 'c':
            one_testcase_op(ts_list, DTEST_OP_SHOW);
            break;
        case 'D':
            one_testsuite_op(ts_list, DTEST_OP_DISABLE);
            break;
        case 'd':
            one_testcase_op(ts_list, DTEST_OP_DISABLE);
            break;
        case 'E':
            one_testsuite_op(ts_list, DTEST_OP_ENABLE);
            break;
        case 'e':
            one_testcase_op(ts_list, DTEST_OP_ENABLE);
            break;
        case 'Q':
        case 'q':
            /* return RET_OK; */
            break;
        default:
            DTRACE("You must choose from the list!\n");
            break;
        }
    } while('Q' != menu_choice && 'q' != menu_choice);

    IF_ERROR_RETURN(dlist_destroy(&ts_list));

    return FUNC_OK;
}

/************************ Inner functions implementation *********************/
static void dtest_menu(int* choice)
{
    DTRACE("\n\n");
    DTRACE("##################################################################\n");
    DTRACE("+-------------------- Please make a choice: ---------------------+\n");
    DTRACE("|                     |  show info/result   |   run testcase     |\n");
    DTRACE("| all testcases       |          a          |          A         |\n");
    DTRACE("| one testsuite       |          b          |          B         |\n");
    DTRACE("| one testcase        |          c          |          C         |\n");
    DTRACE("+---------------------+---------------------+--------------------+\n");
    DTRACE("|                     |       testcase      |      testsuite     |\n");
    DTRACE("| disable tc/ts       |          d          |          D         |\n");
    DTRACE("| enable tc/ts        |          e          |          E         |\n");
    DTRACE("+------------------------- q or Q: to quit ----------------------+\n");
    DTRACE("Your choice is: ");
    *choice = trace_getchar();

    return;
}

/******************************************************************************/
static void get_id(char* msg, size_t* id)
{
    DTRACE("%s", msg);
    *id = trace_getint();

    return;
}

/******************************************************************************/
static void all_testcases_op(DList* ts_list, DTestOp operation)
{
    if (DTEST_OP_SHOW == operation)
    {
        ts_node_data_title_print();
        IF_ERROR_PRINT(dlist_print(ts_list, ts_node_data_print));
    }
    else if (DTEST_OP_RUN == operation)
    {
        IF_ERROR_PRINT(dlist_foreach(ts_list, testsuite_run, NULL));
    }

    return;
}

/******************************************************************************/
static void one_testsuite_op(DList* ts_list, DTestOp operation)
{
    size_t ts_id = 0;
    TsNodeData* ts_data = NULL;

    get_id("Please input Id of testsuite: ", &ts_id);
    if (ts_id >= dlist_get_size(ts_list))
    {
        DTRACE_LEVEL(TRACE_ERROR, "Error: Id of testsuite is too big!\n");
        return;
    }

    IF_ERROR_PRINT(dlist_get_by_index(ts_list, ts_id, (void **)&ts_data));

    if (DTEST_OP_SHOW == operation)
    {
        ts_node_data_title_print();
        ts_node_data_print((const void *)ts_data);
    }
    else if (DTEST_OP_RUN == operation)
    {
        IF_ERROR_PRINT(testsuite_run((void *)ts_data, NULL));
    }
    else if (DTEST_OP_DISABLE == operation)
    {
        testsuite_disable((void *)ts_data);
    }
    else if (DTEST_OP_ENABLE == operation)
    {
        testsuite_enable((void *)ts_data);
    }

    return;
}

/******************************************************************************/
static void one_testcase_op(DList* ts_list, DTestOp operation)
{
    size_t ts_id = 0;
    size_t tc_id = 0;
    TsNodeData* ts_data = NULL;
    TcNodeData* tc_data = NULL;
    DList* tc_list = NULL;

    get_id("Please input Id of testsuite: ", &ts_id);
    if (ts_id >= dlist_get_size(ts_list))
    {
        DTRACE_LEVEL(TRACE_ERROR, "Error: Id of testsuite is too big!\n");
        return;
    }

    IF_ERROR_PRINT(dlist_get_by_index(ts_list, ts_id, (void **)&ts_data));
    tc_list = ts_data->tc_list;

    get_id("Please input Id of testcase: ", &tc_id);
    if (tc_id >= dlist_get_size(tc_list))
    {
        DTRACE_LEVEL(TRACE_ERROR, "Error: Id of testcase is too big!\n");
        return;
    }

    IF_ERROR_PRINT(dlist_get_by_index(tc_list, tc_id, (void **)&tc_data));

    if (DTEST_OP_SHOW == operation)
    {
        tc_node_data_title_print();
        tc_node_data_print((const void *)tc_data);
    }
    else if (DTEST_OP_RUN == operation)
    {
        IF_ERROR_PRINT(testcase_run((void *)tc_data, NULL));
    }
    else if (DTEST_OP_DISABLE == operation)
    {
        testcase_disable((void *)tc_data);
    }
    else if (DTEST_OP_ENABLE == operation)
    {
        testcase_enable((void *)tc_data);
    }

    return;
}

/******************************************************************************/

#endif /* CODE_SEPARATOR("Outer Function", 1) */

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

