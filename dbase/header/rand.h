/******************************************************************************/
/**
 * @file          rand.h
 * @brief         random
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef _RAND_H
#define _RAND_H 1

/***************************** include files **********************************/
#include <stdint.h>

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
/**
 * @func          uint32_t random_uint(uint32_t max)
 * @brief         random_uint
 * @param[in]     uint32_t max:
 * @return        uint32:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern uint32_t random_uint(uint32_t max);

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif // _RAND_H

