/******************************************************************************/
/**
 * @file        graph.c
 * @brief
 * @version     0.0.1
 * @author      dercury
 * @date        2015-5-24
 */
/******************************************************************************/

#include "dlist.h"
#include "graph.h"
#include "linkset.h"
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

#if CODE_SEPARATOR("Inner Function", 1)
/******************************************************************************/
typedef enum tagVertexColor
{
    VERTEX_WHITE,
    VERTEX_GRAY,
    VERTEX_BLACK,
} eVertexColor;

/* vertex and set of its adjacent vertexes */
typedef struct tagGraphElmt
{
    void*    vertex;
    LinkSet* adjacent;
} GraphElmt;

struct tagGraph
{
    size_t vertex_count;
    size_t edge_count;
    CmpFunc  vertex_cmp;
    FreeFunc vertex_free;
    DList*   elmts_list;    // a linked-list of graph elements
};

typedef enum tagVertexStatus
{
    NONENTIRY_VERTEX = 0,
    ISOLATED_VERTEX,
    EDGE_VERTEX,
} eVertexStatus;

typedef struct tagVertexContext
{
    void* vertex;
    CmpFunc  vertex_cmp;
    FreeFunc vertex_free;
    eVertexStatus status;
} VertexContext;

/******************************************************************************/
static FuncRtn graph_make_elmt(const void* vertex, GraphElmt** elmt)
{
    IF_ERROR_EXIT(alloc_memory((void**)elmt, sizeof(GraphElmt)));

    (*elmt)->vertex = (void*)vertex;
    (*elmt)->adjacent = linkset_create(NULL, NULL);

    return FUNC_OK;
}

/******************************************************************************/
static void graph_free_elmt(GraphElmt** elmt, Bool free_flag, void* context)
{
    FreeFunc vertex_free = (FreeFunc)context;

    IF_ERROR_PRINT(linkset_destroy(&((*elmt)->adjacent)));
    if (free_flag == TRUE && vertex_free != NULL)
    {
        vertex_free(&((*elmt)->vertex));
    }

    free_memory((void **)elmt);

    return;
}

/******************************************************************************/
static FuncRtn graph_get_elmt(const Graph* thiz, const void* vertex, GraphElmt** elmt, size_t* index)
{
    GraphElmt* temp = NULL;
    size_t list_size = dlist_get_size(thiz->elmts_list);
    size_t i;

    for (i = 0; i < list_size; i++)
    {
        IF_ERROR_RETURN(dlist_get_by_index(thiz->elmts_list, i, (void**)&temp));
        if (thiz->vertex_cmp(vertex, temp->vertex) == 0)
        {
            *elmt = temp;
            *index = i;
            break;
        }
    }

    return ((i < list_size) ? FUNC_OK : FUNC_NOT_EXIST);
}

/******************************************************************************/
static int graph_cmp_elmt(GraphElmt* elmt1, GraphElmt* elmt2, void* context)
{
    CmpFunc vertex_cmp = (CmpFunc)context;

    return vertex_cmp(elmt1->vertex, elmt2->vertex);
}

/******************************************************************************/
static FuncRtn cmp_vertex(void* context, void* data)
{
    GraphElmt* adj_data = (GraphElmt *)data;
    VertexContext* vertex_context = (VertexContext *)context;
    int cmp_rtn = (vertex_context->vertex_cmp)(adj_data->vertex, vertex_context->vertex);

    if (0 == cmp_rtn)
    {
        return FUNC_ALREADY_EXIST;
    }

    return FUNC_OK;
}

/******************************************************************************/
static FuncRtn get_vertex_status(void* context, void* data)
{
    size_t index = 0;
    GraphElmt* adj_data = (GraphElmt *)data;
    VertexContext* vertex_context = (VertexContext *)context;

    switch (vertex_context->status)
    {
    case NONENTIRY_VERTEX:
        if (0 == (vertex_context->vertex_cmp)(adj_data->vertex, vertex_context->vertex))
        {
            vertex_context->status = ISOLATED_VERTEX;
        }
        else
        {
            if(FUNC_OK == dlist_get_by_value(adj_data->adjacent, vertex_context->vertex, &index))
            {
                vertex_context->status = EDGE_VERTEX;
            }
        }
    	break;
    case ISOLATED_VERTEX:
        if(FUNC_OK == dlist_get_by_value(adj_data->adjacent, vertex_context->vertex, &index))
        {
            vertex_context->status = EDGE_VERTEX;
        }
        break;
    case EDGE_VERTEX:
        break;
    }

    return FUNC_OK;
}

/******************************************************************************/
#endif  /* CODE_SEPARATOR("Inner Function", 1) */

#if CODE_SEPARATOR("Outer Function", 1)
/******************************************************************************/
Graph* graph_create(FreeFunc vertex_free, CmpFunc vertex_cmp)
{
    Graph* thiz = NULL;

    IF_ERROR_EXIT(alloc_memory((void **)&thiz, sizeof(Graph)));
    thiz->vertex_count  = 0;
    thiz->edge_count    = 0;
    thiz->vertex_cmp    = vertex_cmp;
    thiz->vertex_free   = vertex_free;
    thiz->elmts_list    = dlist_create(NULL, NULL);

    return thiz;
}

/******************************************************************************/
FuncRtn graph_destroy(Graph** thiz)
{
    DList* list = NULL;
    GraphElmt* data = NULL;

    PARAM_CHECK_NULL_POINTER(thiz);

    list = (*thiz)->elmts_list;

    // Remove and destroy each graph element
    while (dlist_get_size(list) > 0)
    {
        IF_ERROR_RETURN(dlist_remove_head(list, FALSE, (void**)&data));
        graph_free_elmt(&data, TRUE, (*thiz)->vertex_free);
    }

    // Destroy the list of graph elements, which is now empty
    IF_ERROR_RETURN(dlist_destroy(&list));

    free_memory((void **)thiz);

    return FUNC_OK;
}

/******************************************************************************/
size_t graph_get_vertex_num(const Graph* thiz)
{
    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return 0;
    }

    return thiz->vertex_count;
}

/******************************************************************************/
size_t graph_get_edge_num(const Graph* thiz)
{
    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return 0;
    }

    return thiz->edge_count;
}

/******************************************************************************/
FreeFunc graph_get_free_func(const Graph* thiz)
{
    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return NULL;
    }

    return thiz->vertex_free;
}

/******************************************************************************/
void graph_set_free_func(Graph* thiz, FreeFunc vertex_free)
{
    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return;
    }

    thiz->vertex_free = vertex_free;
}

/******************************************************************************/
CmpFunc graph_get_cmp_func(const Graph* thiz)
{
    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return NULL;
    }

    return thiz->vertex_cmp;
}

/******************************************************************************/
void graph_set_cmp_func(Graph* thiz, CmpFunc vertex_cmp)
{
    if (NULL == thiz)
    {
        IF_ERROR_PRINT(FUNC_PARAM_NULL_POINTER);
        return;
    }

    thiz->vertex_cmp = vertex_cmp;

    return;
}

/******************************************************************************/
FuncRtn graph_insert_vertex(Graph* thiz, const void* vertex)
{
    GraphElmt* elmt = NULL;
    size_t index = 0;

    PARAM_CHECK_NULL_POINTER(thiz);

    /* Do not allow the insertion of duplicate vertexes. */
    if (FUNC_OK == graph_get_elmt(thiz, vertex, &elmt, &index))
    {
        printf("Vertex already exist at index=%u!\n", index);
        return FUNC_ALREADY_EXIST;
    }

    // create graph element
    IF_ERROR_RETURN(graph_make_elmt(vertex, &elmt));
    linkset_set_cmp_func(elmt->adjacent, thiz->vertex_cmp);

    // Insert the vertex
    IF_ERROR_RETURN(dlist_append_tail(thiz->elmts_list, elmt));

    /* Adjust the vertex count to account for the inserted vertex */
    thiz->vertex_count++;

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn graph_remove_vertex(Graph* thiz, Bool free_flag, void** vertex)
{
    GraphElmt* elmt = NULL;
    size_t index = 0;

    PARAM_CHECK_NULL_POINTER(thiz);
    PARAM_CHECK_NULL_POINTER(vertex);

    if (FUNC_OK != graph_get_elmt(thiz, *vertex, &elmt, &index))
    {
        return FUNC_NOT_EXIST;
    }

    if (linkset_get_size(elmt->adjacent) > 0)
    {
        printf("Vertex is NOT isolated!\n");
        return FUNC_UNREACHABLE;
    }

    // remove graph element
    IF_ERROR_RETURN(dlist_remove_by_index(thiz->elmts_list, index, FALSE, (void**)&elmt));
    graph_free_elmt(&elmt, free_flag, thiz->vertex_free);

    thiz->vertex_count--;

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn graph_insert_edge(Graph* thiz, const void* vertex1, const void* vertex2)
{
    PARAM_CHECK_NULL_POINTER(thiz);

    return FUNC_OK;
}

/******************************************************************************/
FuncRtn graph_remove_edge(Graph* thiz, const void* vertex1, void** vertex2)
{
    PARAM_CHECK_NULL_POINTER(thiz);

    return FUNC_OK;
}

/******************************************************************************/

#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

