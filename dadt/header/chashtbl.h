/******************************************************************************/
/**
 * @file          chashtbl.h
 * @brief         chashtbl.h
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef CHASHTBL_H
#define CHASHTBL_H

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
struct tagCHashTbl;
typedef struct tagCHashTbl CHashTbl;

/******************************************************************************/
/**
 * @func          CHashTbl* chashtbl_create(size_t buckets, HashFunc hash, FreeFunc data_free, CmpFunc data_cmp)
 * @brief         chashtbl_create
 * @param[in]     size_t buckets: 
 * @param[in]     HashFunc hash: 
 * @param[in]     FreeFunc data_free: 
 * @param[in]     CmpFunc data_cmp: 
 * @return        CHashTbl*: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern CHashTbl* chashtbl_create(size_t buckets, HashFunc hash, FreeFunc data_free, CmpFunc data_cmp);

/******************************************************************************/
/**
 * @func          FuncRtn chashtbl_destroy(CHashTbl** thiz)
 * @brief         chashtbl_destroy
 * @param[in/out] CHashTbl** thiz: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn chashtbl_destroy(CHashTbl** thiz);

/******************************************************************************/
/**
 * @func          FuncRtn chashtbl_get_size(CHashTbl* thiz, size_t* size)
 * @brief         chashtbl_get_size
 * @param[in/out] CHashTbl* thiz: 
 * @param[in/out] size_t* size: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn chashtbl_get_size(CHashTbl* thiz, size_t* size);

/******************************************************************************/
/**
 * @func          FuncRtn chashtbl_insert(CHashTbl* thiz, const HashEntry* entry)
 * @brief         chashtbl_insert
 * @param[in/out] CHashTbl* thiz: 
 * @param[in]     HashEntry* entry: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn chashtbl_insert(CHashTbl* thiz, const HashEntry* entry);

/******************************************************************************/
/**
 * @func          FuncRtn chashtbl_remove(CHashTbl* thiz, const void* key, Bool free_flag, void** ad)
 * @brief         chashtbl_remove
 * @param[in/out] CHashTbl* thiz: 
 * @param[in]     void* key: 
 * @param[in]     Bool free_flag: 
 * @param[in/out] void** ad: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn chashtbl_remove(CHashTbl* thiz, const void* key, Bool free_flag, void** ad);

/******************************************************************************/
/**
 * @func          FuncRtn chashtbl_lookup(CHashTbl* thiz, const void* key, void** ad)
 * @brief         chashtbl_lookup
 * @param[in/out] CHashTbl* thiz: 
 * @param[in]     void* key: 
 * @param[in/out] void** ad: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn chashtbl_lookup(CHashTbl* thiz, const void* key, void** ad);

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif // CHASHTBL_H

