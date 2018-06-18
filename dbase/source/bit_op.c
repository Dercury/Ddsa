/******************************************************************************/
/**
 * @file        bit_op.c
 * @brief       bit operation
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/

#include "bit_op.h"

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
uint32_t set_bit(uint32_t data, uint8_t bit_pos, uint8_t bit_value)
{
    return ((data & (~(1 << bit_pos))) | ((bit_value & 0x1) << bit_pos));
}

/******************************************************************************/
uint8_t get_bit(uint32_t data, uint8_t bit_pos)
{
    return ((data >> bit_pos) & 0x1);
}

/******************************************************************************/

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

