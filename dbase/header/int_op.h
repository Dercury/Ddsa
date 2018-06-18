/******************************************************************************/
/**
 * @file          int_op.h
 * @brief         type definition
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef DTYPE_H
#define DTYPE_H 1

/***************************** include files **********************************/

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
/**
 * @func          void print_int(int data)
 * @brief         print_int
 * @param[in]     int data:
 * @return        void:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern void print_int(const int data);

/******************************************************************************/
/**
 * @func          int cmp_int(int data1, int data2)
 * @brief         cmp_int
 * @param[in]     int data1:
 * @param[in]     int data2:
 * @return        int:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern int cmp_int(const int data1, const int data2);

/******************************************************************************/
/**
 * @func          int cmp_long(long data1, long data2)
 * @brief         cmp_long
 * @param[in]     long data1:
 * @param[in]     long data2:
 * @return        int:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern int cmp_long(const long data1, const long data2);

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif // DTYPE_H

