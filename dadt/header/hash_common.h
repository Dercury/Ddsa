/******************************************************************************/
/**
 * @file          hash_common.h
 * @brief         hash_common.h
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef HASH_COMMON_H
#define HASH_COMMON_H

/******************************************************************************/

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
typedef struct tagHashEntry
{
    void* key;
    void* ad;
} HashEntry;

typedef int (*HashFunc)(const void* key);

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif // HASH_COMMON_H

