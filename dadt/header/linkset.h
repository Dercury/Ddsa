/******************************************************************************/
/**
 * @file          linkset.h
 * @brief         linkset.h
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef SET_H
#define SET_H

#include "dlist.h"

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
typedef DList LinkSet;

#define linkset_create           dlist_create

#define linkset_destroy          dlist_destroy

#define linkset_get_size         dlist_get_size

#define linkset_get_free_func    dlist_get_free_func

#define linkset_set_free_func    dlist_set_free_func

#define linkset_get_cmp_func     dlist_get_cmp_func

#define linkset_set_cmp_func     dlist_set_cmp_func

/******************************************************************************/
/**
 * @func          FuncRtn linkset_insert(LinkSet* thiz, const void* data)
 * @brief         linkset_insert
 * @param[in/out] LinkSet* thiz: 
 * @param[in]     void* data: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn linkset_insert(LinkSet* thiz, const void* data);

/******************************************************************************/
/**
 * @func          FuncRtn linkset_remove(LinkSet* thiz, void* data, Bool free_flag)
 * @brief         linkset_remove
 * @param[in/out] LinkSet* thiz: 
 * @param[in/out] void* data: 
 * @param[in]     Bool free_flag: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn linkset_remove(LinkSet* thiz, void* data, Bool free_flag);

/******************************************************************************/
/**
 * @func          FuncRtn linkset_union(const LinkSet* set1, const LinkSet* set2, LinkSet* setu)
 * @brief         linkset_union
 * @param[in]     LinkSet* set1: 
 * @param[in]     LinkSet* set2: 
 * @param[in/out] LinkSet* setu: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn linkset_union(const LinkSet* set1, const LinkSet* set2, LinkSet* setu);

/******************************************************************************/
/**
 * @func          FuncRtn linkset_intersect(const LinkSet* set1, const LinkSet* set2, LinkSet* seti)
 * @brief         linkset_intersect
 * @param[in]     LinkSet* set1: 
 * @param[in]     LinkSet* set2: 
 * @param[in/out] LinkSet* seti: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn linkset_intersect(const LinkSet* set1, const LinkSet* set2, LinkSet* seti);

/******************************************************************************/
/**
 * @func          FuncRtn linkset_differ(const LinkSet* set1, const LinkSet* set2, LinkSet* setd)
 * @brief         linkset_differ
 * @param[in]     LinkSet* set1: 
 * @param[in]     LinkSet* set2: 
 * @param[in/out] LinkSet* setd: 
 * @return        FuncRtn: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn linkset_differ(const LinkSet* set1, const LinkSet* set2, LinkSet* setd);

/******************************************************************************/
/**
 * @func          Bool linkset_has_member(const LinkSet* set, const void* data)
 * @brief         linkset_has_member
 * @param[in]     LinkSet* set: 
 * @param[in]     void* data: 
 * @return        Bool: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern Bool linkset_has_member(const LinkSet* set, const void* data);

/******************************************************************************/
/**
 * @func          Bool linkset_is_subset(const LinkSet* set1, const LinkSet* set2)
 * @brief         linkset_is_subset
 * @param[in]     LinkSet* set1: 
 * @param[in]     LinkSet* set2: 
 * @return        Bool: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern Bool linkset_is_subset(const LinkSet* set1, const LinkSet* set2);

/******************************************************************************/
/**
 * @func          Bool linkset_is_equal(const LinkSet* set1, const LinkSet* set2)
 * @brief         linkset_is_equal
 * @param[in]     LinkSet* set1: 
 * @param[in]     LinkSet* set2: 
 * @return        Bool: 
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern Bool linkset_is_equal(const LinkSet* set1, const LinkSet* set2);

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif 
