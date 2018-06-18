#include <stdio.h>
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#include <stdlib.h>
#include <string.h>

#include "dlist.h"

static DListRet print_int(void * data)
{
    printf("%d ", (int)data);
    return DLIST_RET_OK;
}

static DListRet int_max(void * ctx, void * data)
{
    int * result = ctx;
    if (*result < (int)data)
    {
        *result = (int)data;
    }
    return DLIST_RET_OK;
}

static DListRet int_sum(void * ctx, void * data)
{
    long long * result = ctx;
    *result += (int)data;
    return DLIST_RET_OK;
}

static DListRet str_uppcase(void * data)
{
    char * result = data;
    while ('\0' != *result)
    {
        if('a' <= *result && 'z' >= *result)
        {
            *result = *result - 'a' + 'A';
        }
        result++;
    }
    return DLIST_RET_OK;
}

int main(int argc, char ** argv)
{
    DListRet ret = DLIST_RET_OK;
    DList list;

    ret = dlist_print(list, print_int);
    return 0;
}

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */
