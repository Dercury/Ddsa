#ifndef PAGE_H
#define PAGE_H

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/* Define a structure for information about pages */
typedef struct tagPage
{
    int number;
    int reference;
} Page;

/* Public Interface */
int replace_page(CListElmt **current);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif /* PAGE_H */

