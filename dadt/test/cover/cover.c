#include <stdlib.h>

#include "list.h"
#include "set.h"
#include "cover.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

int cover(Set *members, Set *subsets, Set *covering)
{
    Set         inersection;
    KSet        *subset;
    ListNode    *member, *max_member;
    void        *data;
    int         max_size;

    /* Initialize the covering */
    set_init(covering, subsets->match, NULL);

    /* Continue while there are noncovered members and candidate subsets */
    while (0 < SET_SIZE(members) && 0 < SET_SIZE(subsets))
    {
        /* Find the subset that covers the most members */
        max_size = 0;
        for (member = LIST_HEAD(subsets); NULL != member; member = LIST_NEXT(member))
        {
            if (0 != set_intersect(&intersection, &((KSet *)LIST_DATA(member))->set, members))
            {
                return -1;
            }
            if (SET_SIZE(&intersection) > max_size)
            {
                max_member = member;
                max_size = SET_SIZE(&intersection);
            }

            set_destroy(&intersecton);
        }
        /* A covering is not possible if there was no intersection */
        if (0 == max_size)
        {
            return 1;
        }

        /* Insert the selected subset into the covering */
        subset = (KSet *)LIST_DATA(max_member);
        if (0 != set_insert(covering, subset))
        {
            return -1;
        }

        /* Remove each covered member from the set of noncovered members */
        for (member = LIST_HEAD(&((KSet *)LIST_DATA(max_member))->set); NULL != member; member = LIST_NEXT(member))
        {
            data = LIST_DATA(member);
            if (0 == set_remove(members, (void **)&data) && NULL != members->destroy)
            {
                members->destroy(data);
            }
        }

        /* Remove the subset from the set of candidate subsets */
        if (0 != set_remove(subsets, (void **)&subsets))
        {
            return -1;
        }
    }
    /* No covering is possible if there are still noncovered members */
    if (0 < SET_SIZE(members))
    {
        return -1;
    }

    return 0;
}

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

