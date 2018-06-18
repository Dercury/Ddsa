/******************************************************************************/
/**
 * @file        rand.c
 * @brief       random
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/

#include "rand.h"
#include <stdlib.h> /* rand */

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
uint32_t random_uint(uint32_t max)
{
    return (max == 0 ? rand() : (rand() % max));
}

/******************************************************************************/

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

