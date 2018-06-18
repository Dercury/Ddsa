#include "clist.h"
#include "page.h"

#ifdef __cpluspluc
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

int replace_page(CListElmt **current)
{
    /* Circle through the list of pages until one is found to replace */
    while (0 != ((Page *)(*current)->data)->reference)
    {
        ((Page *)(*current)->data)->reference = 0;
        *current = CLIST_NEXT(*current);
    }

    return ((Page *)(*current)->data)->number;
}

#ifdef __cpluspluc
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */
