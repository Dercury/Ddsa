#ifndef COVER_H
#define COVER_H

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/* Define a structure for subsets identified by a key */
typedef struct tagKSet
{
    void    *key;
    Set     set;
} KSet;

/* Public Interface */
int cover(Set *members, Set *subsets, Set *covering);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* COVER_H */
