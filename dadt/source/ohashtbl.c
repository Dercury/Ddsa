/******************************************************************************/
/**
 * @file        ohashtbl.c
 * @brief       open-addressed hash table
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/

#include "macro.h"
#include "mem_op.h"
#include "ohashtbl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

#if CODE_SEPARATOR("Inner Definition", 1)
/******************************************************************************/
struct tagOHashTbl
{
    HashEntry** table;
    size_t                positions;  /* place for hash entry */
    void* vacated;
    size_t                size;       /* number of already used positions */
    HashFunc                hash1;
    HashFunc                hash2;
    FreeFunc                data_free;
    CmpFunc                 data_cmp;   /* should only compare the key */
};

#endif /* CODE_SEPARATOR("Inner Definition", 1) */

#if CODE_SEPARATOR("Inner Function", 1)
/******************************************************************************/
/* Reserve a sentinel memory address for vacated elements */
static char vacated = 0;

/******************************************************************************/
FuncRtn ohashtbl_search(OHashTbl* thiz, const void* key, HashEntry** entry, size_t* position)
{
    size_t      i = 0;
    FuncRtn     ret = FUNC_OK;
    HashEntry* iter = NULL;
    HashEntry   temp;

    memset((void *)&temp, 0, sizeof(HashEntry));
    temp.key = (void *)key;
    temp.ad  = NULL;

    /* Use double hashing to hash the key */
    *position = 0;
    for (i = 0; i < thiz->positions; i++)
    {
        *position = ((thiz->hash1)(key) + (i* (thiz->hash2)(key))) % (thiz->positions);
        iter = (thiz->table)[*position];
        if (thiz->data_cmp(iter, &temp) == 0)
        {
            *entry = iter;  /* Pass back the data from the table */
            ret = FUNC_OK;
            break;
        }
        else if (NULL == iter)
        {
            ret = FUNC_NOT_EXIST;  /* Return that the data was not found */
            break;
        }
#if 0
        else if (htbl->vacated == iter)
        {
            continue;   /* Search beyond vacated positions */
        }
#endif
    }

    /* Return that the data was not found */
    return ret;
}

#endif

#if CODE_SEPARATOR("Outer Function", 1)
/******************************************************************************/
OHashTbl* ohashtbl_create(size_t positions, HashFunc hash1, HashFunc hash2,
                           FreeFunc data_free, CmpFunc data_cmp)
{
    OHashTbl* thiz = NULL;
    size_t  i = 0;

    IF_ERROR_EXIT(alloc_memory((void **)&thiz, sizeof(OHashTbl)));

    /* Allocate space for the hash table */
    IF_ERROR_EXIT(alloc_memory((void **)(thiz->table), positions* sizeof(HashEntry *)));

    /* Initialize each position */
    thiz->positions = positions;
    for (i = 0; i < thiz->positions; i++)
    {
        (thiz->table)[i] = NULL;
    }

    /* Set the vacated member to the sentinel memory address reserved for this */
    thiz->vacated = (void *)&vacated;

    /* Encapsulate the functions */
    thiz->hash1 = hash1;
    thiz->hash2 = hash2;
    thiz->data_cmp = data_cmp;
    thiz->data_free = data_free;

    /* Initialize the number of elements in the table */
    thiz->size = 0;

    return thiz;
}

/******************************************************************************/
FuncRtn ohashtbl_destroy(OHashTbl** thiz)
{
    size_t  i = 0;

    PARAM_CHECK_NULL_POINTER(thiz);

    if (NULL != (*thiz)->data_free)
    {
        /* Call a user-defined function to free dynamically allocated data */
        for (i = 0; i < (*thiz)->positions; i++)
        {
            if (NULL != ((*thiz)->table)[i] && (*thiz)->vacated != ((*thiz)->table)[i])
            {
                ((*thiz)->data_free)((void **)&(((*thiz)->table)[i]));
            }
        }
    }

    /* Free the storage allocated for the hash table */
    free_memory((void **)((*thiz)->table));
    free_memory((void **)thiz);

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn ohashtbl_get_size(OHashTbl* thiz, size_t* size)
{
    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(size);

    *size = thiz->size;

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn ohashtbl_insert(OHashTbl* thiz, const HashEntry* entry)
{
    void* key = entry->key;
    size_t   position = 0, i = 0;
    HashEntry* temp = NULL;
    HashEntry* iter = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(entry);

    /* Do not exceed the number of positions in the table */
    if (thiz->positions <= thiz->size)
    {
        return FUNC_SPACE_FULL;
    }

    /* Do nothing if the data is already in the table */
    if (FUNC_OK == ohashtbl_search(thiz, key, &temp, &position))
    {
        return FUNC_ALREADY_EXIST;
    }

    /* Use double hashing to hash the key */
    for (i = 0; i < thiz->positions; i++)
    {
        position = ((thiz->hash1)(key) + (i* (thiz->hash2)(key))) % (thiz->positions);
        iter = (thiz->table)[position];
        if (NULL == iter || thiz->vacated == iter)
        {
            /* Insert the data into the table */
            (thiz->table)[position] = (HashEntry *)entry;
            thiz->size++;

            return FUNC_OK;
        }
    }

    /* Return that the hash functions were selected incorrectly */
    return FUNC_ERROR;
}

/******************************************************************************/
FuncRtn ohashtbl_remove(OHashTbl* thiz, const void* key, Bool free_flag, void** ad)
{
    size_t    position = 0;
    HashEntry* entry = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(key);
    PARAM_CHECK_NULL_POINTER(ad);

    IF_ERROR_RETURN(ohashtbl_search(thiz, key, &entry, &position));
    *ad = entry->ad;
    (thiz->table)[position] = thiz->vacated;
    thiz->size--;

    if (TRUE == free_flag && NULL != thiz->data_free)
    {
        (thiz->data_free)((void **)&entry);
    }

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn ohashtbl_lookup(OHashTbl* thiz, const void* key, void** ad)
{
    size_t    position = 0;
    HashEntry* entry = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(key);
    PARAM_CHECK_NULL_POINTER(ad);

    IF_ERROR_RETURN(ohashtbl_search(thiz, key, &entry, &position));
    *ad = entry->ad;

    return FUNC_OK;
}

/******************************************************************************/

#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

