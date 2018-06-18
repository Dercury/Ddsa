/******************************************************************************/
/**
 * @file          bit_op.h
 * @brief         bit operation
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef _BIT_OP_H
#define _BIT_OP_H 1

/***************************** include files **********************************/
#include <stdint.h>

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#ifndef BIT_POS
#define BIT_POS(n)          (1 << ((n) & 0x1F))
#endif

/******************************************************************************/
/**
 * @func          uint32_t set_bit(uint32_t data, uint8_t bit_pos, uint8_t bit_value)
 * @brief         set_bit
 * @param[in]     uint32_t data:
 * @param[in]     uint8_t bit_pos:
 * @param[in]     uint8_t bit_value:
 * @return        uint32:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern uint32_t set_bit(uint32_t data, uint8_t bit_pos, uint8_t bit_value);
/******************************************************************************/
/**
 * @func          uint8_t get_bit(uint32_t data, uint8_t bit_pos)
 * @brief         get_bit
 * @param[in]     uint32_t data:
 * @param[in]     uint8_t bit_pos:
 * @return        uint8:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern uint8_t get_bit(uint32_t data, uint8_t bit_pos);

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif // _BIT_OP_H

