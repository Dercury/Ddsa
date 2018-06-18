/******************************************************************************/
/**
 * @file        chashtbl.c
 * @brief       chained hash table
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/

#include "chashtbl.h"
#include "dlist.h"
#include "macro.h"
#include "mem_op.h"
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
struct tagCHashTbl
{
    DList** table;
    size_t                buckets;
    size_t                size;
    HashFunc                hash;
    FreeFunc                data_free;
    CmpFunc                 data_cmp;   /* should only compare the key */
};

#endif /* CODE_SEPARATOR("Inner Definition", 1) */

#if CODE_SEPARATOR("Inner Function", 1)
#endif /* CODE_SEPARATOR("Inner Function", 1) */

#if CODE_SEPARATOR("Outer Function", 1)
/******************************************************************************/
CHashTbl* chashtbl_create(size_t buckets, HashFunc hash,
                           FreeFunc data_free, CmpFunc data_cmp)
{
    CHashTbl* thiz = NULL;
    size_t  i = 0;

    IF_ERROR_EXIT(alloc_memory((void **)&thiz, sizeof(CHashTbl)));

    /* Allocate space for the hash table */
    IF_ERROR_EXIT(alloc_memory((void **)(thiz->table), buckets* sizeof(DList *)));

    /* Initialize the buckets */
    thiz->buckets = buckets;
    for (i = 0; i < thiz->buckets; i++)
    {
        (thiz->table)[i] = dlist_create(data_free, data_cmp);
    }

    /* Encapsulate the functions */
    thiz->hash = hash;
    thiz->data_cmp = data_cmp;
    thiz->data_free = data_free;

    /* Initialize the number of elements in the table */
    thiz->size = 0;

    return thiz;
}

/******************************************************************************/
FuncRtn chashtbl_destroy(CHashTbl** thiz)
{
    size_t  i = 0;

    PARAM_CHECK_NULL_POINTER(thiz);

    /* Destroy each bucket */
    for (i = 0; i < (*thiz)->buckets; i++)
    {
        IF_ERROR_RETURN(dlist_destroy(&(((*thiz)->table)[i])));
    }

    /* Free the storage allocated for the hash table */
    free_memory((void **)&((*thiz)->table));
    free_memory((void **)thiz);

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn chashtbl_get_size(CHashTbl* thiz, size_t* size)
{
    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(size);

    *size = thiz->size;

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn chashtbl_insert(CHashTbl* thiz, const HashEntry* entry)
{
    void* key = entry->key;
    void* ad = NULL;
    size_t  bucket = 0;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(entry);

    /* Do nothing if the data is already in the table */
    if (FUNC_OK == chashtbl_lookup(thiz, key, &ad))
    {
        return FUNC_ALREADY_EXIST;
    }

    /* Hash the key */
    bucket = ((thiz->hash)(key)) % (thiz->buckets);

    /* Insert the data into the bucket */
    IF_ERROR_RETURN(dlist_insert_head((thiz->table)[bucket], (void *)entry));
    thiz->size++;

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn chashtbl_remove(CHashTbl* thiz, const void* key, Bool free_flag, void** ad)
{
    size_t  bucket = 0;
    HashEntry entry;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(key);
    PARAM_CHECK_NULL_POINTER(ad);

    memset((void *)&entry, 0, sizeof(HashEntry));
    entry.key = (void *)key;
    entry.ad = *ad;

    /* Hash the key */
    bucket = ((thiz->hash)(key)) % (thiz->buckets);

    /* Search for the data in the bucket */
    IF_ERROR_RETURN(dlist_remove_by_value((thiz->table)[bucket], (void *)&entry, free_flag));
    thiz->size--;

    /* Return that the data was not found */
    return FUNC_OK;
}

/******************************************************************************/
FuncRtn chashtbl_lookup(CHashTbl* thiz, const void* key, void** ad)
{
    size_t  bucket = 0;
    size_t  index = 0;
    HashEntry entry;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(key);
    PARAM_CHECK_NULL_POINTER(ad);

    memset((void *)&entry, 0, sizeof(HashEntry));
    entry.key = (void *)key;
    entry.ad = *ad;

    /* Hash the key */
    bucket = ((thiz->hash)(key)) % (thiz->buckets);

    /* Search for the data in the bucket */
    IF_ERROR_RETURN(dlist_get_by_value((thiz->table)[bucket], (void *)&entry, &index));

    /* Return that the data was not found */
    return FUNC_OK;
}

#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

