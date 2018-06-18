/******************************************************************************/
/**
 * @file          dtest_usage.h
 * @brief         dtest_usage.h
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef DTEST_USAGE_H
#define DTEST_USAGE_H

/******************************************************************************/
#include "str_op.h"

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
/**
 * @func          void dtest_expect_true(char* filename, unsigned int linenum, void* expr, char* expr_str)
 * @brief         dtest_expect_true
 * @param[in/out] char* filename: 
 * @param[in]     unsigned int linenum: 
 * @param[in/out] void* expr: 
 * @param[in/out] char* expr_str: 
 * @return        void: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
void dtest_expect_true(char* filename, unsigned int linenum, void* expr, char* expr_str);

/******************************************************************************/
/**
 * @func          void dtest_expect_false(char* filename, unsigned int linenum, void* expr, char* expr_str)
 * @brief         dtest_expect_false
 * @param[in/out] char* filename: 
 * @param[in]     unsigned int linenum: 
 * @param[in/out] void* expr: 
 * @param[in/out] char* expr_str: 
 * @return        void: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
void dtest_expect_false(char* filename, unsigned int linenum, void* expr, char* expr_str);

/******************************************************************************/
/**
 * @func          void dtest_expect_equal(char* filename, unsigned int linenum, void* expr1, char* expr1_str, void* expr2, char* expr2_str)
 * @brief         dtest_expect_equal
 * @param[in/out] char* filename: 
 * @param[in]     unsigned int linenum: 
 * @param[in/out] void* expr1: 
 * @param[in/out] char* expr1_str: 
 * @param[in/out] void* expr2: 
 * @param[in/out] char* expr2_str: 
 * @return        void: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
void dtest_expect_equal(char* filename, unsigned int linenum, void* expr1, char* expr1_str, void* expr2, char* expr2_str);

/******************************************************************************/
/**
 * @func          void dtest_expect_unequal(char* filename, unsigned int linenum, void* expr1, char* expr1_str, void* expr2, char* expr2_str)
 * @brief         dtest_expect_unequal
 * @param[in/out] char* filename: 
 * @param[in]     unsigned int linenum: 
 * @param[in/out] void* expr1: 
 * @param[in/out] char* expr1_str: 
 * @param[in/out] void* expr2: 
 * @param[in/out] char* expr2_str: 
 * @return        void: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
void dtest_expect_unequal(char* filename, unsigned int linenum, void* expr1, char* expr1_str, void* expr2, char* expr2_str);

/******************************************************************************/
#define DTEST_EXPECT_TRUE(expr) \
    dtest_expect_true(SHORT_FILENAME, __LINE__, (void *)(expr), #expr)

#define DTEST_EXPECT_FALSE(expr) \
    dtest_expect_false(SHORT_FILENAME, __LINE__, (void *)(expr), #expr)

#define DTEST_EXPECT_EQUAL(expr1, expr2) \
    dtest_expect_equal(SHORT_FILENAME, __LINE__, (void *)(expr1), #expr1, (void *)(expr2), #expr2)

#define DTEST_EXPECT_UNEQUAL(expr1, expr2) \
    dtest_expect_unequal(SHORT_FILENAME, __LINE__, (void *)(expr1), #expr1, (void *)(expr2), #expr2)

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif // DTEST_USAGE_H

