/******************************************************************************/
/**
 * @file          ohashtbl.h
 * @brief         ohashtbl.h
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef OHASHTBL_H
#define OHASHTBL_H

/******************************************************************************/
#include "bool.h"
#include "func_ptr.h"
#include "func_rtn.h"
#include "hash_common.h"
#include <stdlib.h>

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
struct tagOHashTbl;
typedef struct tagOHashTbl OHashTbl;

/******************************************************************************/
/**
 * @func          OHashTbl* ohashtbl_create(size_t positions, HashFunc hash1, HashFunc hash2, FreeFunc data_free, CmpFunc data_cmp)
 * @brief         ohashtbl_create
 * @param[in]     size_t positions: 
 * @param[in]     HashFunc hash1: 
 * @param[in]     HashFunc hash2: 
 * @param[in]     FreeFunc data_free: 
 * @param[in]     CmpFunc data_cmp: 
 * @return        OHashTbl*: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern OHashTbl* ohashtbl_create(size_t positions, HashFunc hash1, HashFunc hash2, FreeFunc data_free, CmpFunc data_cmp);

/******************************************************************************/
/**
 * @func          FuncRtn ohashtbl_destroy(OHashTbl** thiz)
 * @brief         ohashtbl_destroy
 * @param[in/out] OHashTbl** thiz: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn ohashtbl_destroy(OHashTbl** thiz);

/******************************************************************************/
/**
 * @func          FuncRtn ohashtbl_get_size(OHashTbl* thiz, size_t* size)
 * @brief         ohashtbl_get_size
 * @param[in/out] OHashTbl* thiz: 
 * @param[in/out] size_t* size: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn ohashtbl_get_size(OHashTbl* thiz, size_t* size);

/******************************************************************************/
/**
 * @func          FuncRtn ohashtbl_insert(OHashTbl* thiz, const HashEntry* entry)
 * @brief         ohashtbl_insert
 * @param[in/out] OHashTbl* thiz: 
 * @param[in]     HashEntry* entry: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn ohashtbl_insert(OHashTbl* thiz, const HashEntry* entry);

/******************************************************************************/
/**
 * @func          FuncRtn ohashtbl_remove(OHashTbl* thiz, const void* key, Bool free_flag, void** ad)
 * @brief         ohashtbl_remove
 * @param[in/out] OHashTbl* thiz: 
 * @param[in]     void* key: 
 * @param[in]     Bool free_flag: 
 * @param[in/out] void** ad: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn ohashtbl_remove(OHashTbl* thiz, const void* key, Bool free_flag, void** ad);

/******************************************************************************/
/**
 * @func          FuncRtn ohashtbl_lookup(OHashTbl* thiz, const void* key, void** ad)
 * @brief         ohashtbl_lookup
 * @param[in/out] OHashTbl* thiz: 
 * @param[in]     void* key: 
 * @param[in/out] void** ad: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn ohashtbl_lookup(OHashTbl* thiz, const void* key, void** ad);

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif // OHASHTBL_H

