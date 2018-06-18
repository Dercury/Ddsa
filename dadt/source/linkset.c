/******************************************************************************/
/**
 * @file        set.c
 * @brief       set
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/

#include "linkset.h"
#include "macro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

#if CODE_SEPARATOR("Inner Definition", 1)
#endif /* CODE_SEPARATOR("Inner Definition", 1) */

#if CODE_SEPARATOR("Inner Function", 1)
#endif

#if CODE_SEPARATOR("Outer Function", 1)

/******************************************************************************/
FuncRtn linkset_insert(LinkSet* thiz, const void* data)
{
    /* Do not allow insert duplicates */
    if (TRUE == linkset_has_member(thiz, data))
    {
        return FUNC_ALREADY_EXIST;
    }

    return dlist_append_tail(thiz, data);
}

/******************************************************************************/
FuncRtn linkset_remove(LinkSet* thiz, void* data, Bool free_flag)
{
    return dlist_remove_by_value(thiz, data, free_flag);
}

/******************************************************************************/
FuncRtn linkset_union(const LinkSet* set1, const LinkSet* set2, LinkSet* setu)
{
    size_t i = 0;
    size_t size1 = 0, size2 =0;
    void* data = NULL;

    PARAM_CHECK_NULL_POINTER(set1);
    PARAM_CHECK_NULL_POINTER(set2);
    PARAM_CHECK_EQUAL(linkset_get_free_func(set1), linkset_get_free_func(set2));
    PARAM_CHECK_EQUAL(linkset_get_cmp_func(set1), linkset_get_cmp_func(set2));

    /* Initialize the set for the union */
    setu = linkset_create(linkset_get_free_func(set1), linkset_get_cmp_func(set1));

    /* Insert the members of the first set */
    size1 = linkset_get_size(set1);
    for (i = 0; i < size1; i++)
    {
        IF_ERROR_RETURN(dlist_get_by_index(set1, i, &data));
        IF_ERROR_RETURN(dlist_append_tail(setu, data));
    }

    /* Insert the members of the second set */
    size2 = linkset_get_size(set2);
    for (i = 0; i < size2; i++)
    {
        IF_ERROR_RETURN(dlist_get_by_index(set2, i, &data));
        if (TRUE == linkset_has_member(set1, data))
        {
            /* Do not allow the insertion of duplicates */
            continue;
        }
        else
        {
            IF_ERROR_RETURN(dlist_append_tail(setu, data));
        }
    }

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn linkset_intersect(const LinkSet* set1, const LinkSet* set2, LinkSet* seti)
{
    size_t i = 0;
    size_t size1 = 0;
    void* data = NULL;

    PARAM_CHECK_NULL_POINTER(set1);
    PARAM_CHECK_NULL_POINTER(set2);
    PARAM_CHECK_EQUAL(linkset_get_free_func(set1), linkset_get_free_func(set2));
    PARAM_CHECK_EQUAL(linkset_get_cmp_func(set1), linkset_get_cmp_func(set2));

    /* Initialize the set of the intersection */
    seti = linkset_create(linkset_get_free_func(set1), linkset_get_cmp_func(set1));

    /* Insert the members present in both sets */
    size1 = linkset_get_size(set1);
    for (i = 0; i < size1; i++)
    {
        IF_ERROR_RETURN(dlist_get_by_index(set1, i, &data));
        if (TRUE == linkset_has_member(set2, data))
        {
            IF_ERROR_RETURN(dlist_append_tail(seti, data));
        }
    }

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn linkset_differ(const LinkSet* set1, const LinkSet* set2, LinkSet* setd)
{
    size_t i = 0;
    size_t size1 = 0;
    void* data = NULL;

    PARAM_CHECK_NULL_POINTER(set1);
    PARAM_CHECK_NULL_POINTER(set2);
    PARAM_CHECK_EQUAL(linkset_get_free_func(set1), linkset_get_free_func(set2));
    PARAM_CHECK_EQUAL(linkset_get_cmp_func(set1), linkset_get_cmp_func(set2));

    /* Initialize the set for the difference */
    setd = linkset_create(linkset_get_free_func(set1), linkset_get_cmp_func(set1));

    /* Insert the members from set1 but not in set2 */
    size1 = linkset_get_size(set1);
    for (i = 0; i < size1; i++)
    {
        IF_ERROR_RETURN(dlist_get_by_index(set1, i, &data));
        if (FALSE == linkset_has_member(set2, data))
        {
            IF_ERROR_RETURN(dlist_append_tail(setd, data));
        }
    }

    return FUNC_OK;
}

/******************************************************************************/
Bool linkset_has_member(const LinkSet* thiz, const void* data)
{
    size_t index = 0;
    FuncRtn ret = FUNC_OK;

    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return FALSE;
    }

    ret = dlist_get_by_value(thiz, data, &index);

    return (FUNC_OK == ret ? TRUE : FALSE);
}

/******************************************************************************/
Bool linkset_is_subset(const LinkSet* set1, const LinkSet* set2)
{
    size_t i = 0;
    size_t size1 = 0, size2 =0;
    void* data = NULL;
    Bool result = FALSE;

    if (NULL == set1 || NULL == set2)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return FALSE;
    }

    if (linkset_get_free_func(set1) != linkset_get_free_func(set2)
     || linkset_get_cmp_func(set1) != linkset_get_cmp_func(set2))
    {
        IF_ERROR_PRINT(FUNC_PARAM_EQUAL);
        return FALSE;
    }

    /* Do a quick test to rule out some cases */
    size1 = linkset_get_size(set1);
    size2 = linkset_get_size(set2);
    if (size1 > size2)
    {
        result = FALSE;
    }
    else
    {
        /* Determine if set1 is a subset of set2 */
        for (i = 0; i < size1; i++)
        {
            IF_ERROR_PRINT(dlist_get_by_index(set1, i, &data));
            if (FALSE == linkset_has_member(set2, data))
            {
                result = FALSE;
                break;
            }
        }
        if (size1 == i)
        {
            result = TRUE;
        }
    }

    return result;
}

/******************************************************************************/
Bool linkset_is_equal(const LinkSet* set1, const LinkSet* set2)
{
    if (NULL == set1 || NULL == set2)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return FALSE;
    }

    if (linkset_get_free_func(set1) != linkset_get_free_func(set2)
        || linkset_get_cmp_func(set1) != linkset_get_cmp_func(set2))
    {
        IF_ERROR_PRINT(FUNC_PARAM_EQUAL);
        return FALSE;
    }

    /* Do a quick test to rule out some cases */
    if (linkset_get_size(set1) != linkset_get_size(set2))
    {
        return FALSE;
    }
    else
    {
        /* Sets of the same size are equal if they are subsets */
        return linkset_is_subset(set1, set2);
    }
}

#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

