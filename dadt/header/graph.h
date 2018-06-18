/******************************************************************************/
/**
 * @file          graph.h
 * @brief         graph.h
 * @version       0.0.1
 * @author        Dercury
 * @date          2015-5-24
 */
/******************************************************************************/
#ifndef GRAPH_H
#define GRAPH_H

/******************************************************************************/
#include "bool.h"
#include "func_rtn.h"
#include "func_ptr.h"
#include <stdlib.h>

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
struct tagGraph;
typedef struct tagGraph Graph;

/******************************************************************************/
/**
 * @func          Graph* graph_create(FreeFunc vertex_free, CmpFunc vertex_cmp)
 * @brief         graph_create
 * @param[in]     FreeFunc vertex_free:
 * @param[in]     CmpFunc vertex_cmp:
 * @return        Graph*:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern Graph* graph_create(FreeFunc vertex_free, CmpFunc vertex_cmp);

/******************************************************************************/
/**
 * @func          FuncRtn graph_destroy(Graph** thiz)
 * @brief         graph_destroy
 * @param[in/out] Graph** thiz:
 * @return        FuncRtn:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn graph_destroy(Graph** thiz);

/******************************************************************************/
/**
 * @func          size_t graph_get_vertex_num(const Graph* thiz)
 * @brief         graph_get_vertex_num
 * @param[in]     Graph* thiz:
 * @return        size_t:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern size_t graph_get_vertex_num(const Graph* thiz);
/******************************************************************************/
/**
 * @func          size_t graph_get_edge_num(const Graph* thiz)
 * @brief         graph_get_edge_num
 * @param[in]     Graph* thiz:
 * @return        size_t:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern size_t graph_get_edge_num(const Graph* thiz);

/******************************************************************************/
/**
 * @func          FreeFunc graph_get_free_func(const Graph* thiz)
 * @brief         graph_get_free_func
 * @param[in]     Graph* thiz:
 * @return        FreeFunc:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FreeFunc graph_get_free_func(const Graph* thiz);
/******************************************************************************/
/**
 * @func          void graph_set_free_func(Graph* thiz, FreeFunc vertex_free)
 * @brief         graph_set_free_func
 * @param[in/out] Graph* thiz:
 * @param[in]     FreeFunc vertex_free:
 * @return        void:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern void graph_set_free_func(Graph* thiz, FreeFunc vertex_free);

/******************************************************************************/
/**
 * @func          CmpFunc graph_get_cmp_func(const Graph* thiz)
 * @brief         graph_get_cmp_func
 * @param[in]     Graph* thiz:
 * @return        CmpFunc:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern CmpFunc graph_get_cmp_func(const Graph* thiz);
/******************************************************************************/
/**
 * @func          void graph_set_cmp_func(Graph* thiz, CmpFunc vertex_cmp)
 * @brief         graph_set_cmp_func
 * @param[in/out] Graph* thiz:
 * @param[in]     CmpFunc vertex_cmp:
 * @return        void:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern void graph_set_cmp_func(Graph* thiz, CmpFunc vertex_cmp);

/******************************************************************************/
/**
 * @func          FuncRtn graph_insert_vertex(Graph* thiz, const void* vertex)
 * @brief         graph_insert_vertex
 * @param[in/out] Graph* thiz:
 * @param[in]     void* vertex:
 * @return        FuncRtn:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn graph_insert_vertex(Graph* thiz, const void* vertex);
/******************************************************************************/
/**
 * @func          FuncRtn graph_remove_vertex(Graph* thiz, void** vertex)
 * @brief         graph_remove_vertex
 * @param[in/out] Graph* thiz:
 * @param[in/out] void** vertex:
 * @return        FuncRtn:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn graph_remove_vertex(Graph* thiz, Bool free_flag, void** vertex);

/******************************************************************************/
/**
 * @func          FuncRtn graph_insert_edge(Graph* thiz, const void* vertex1, const void* vertex2)
 * @brief         graph_insert_edge
 * @param[in/out] Graph* thiz:
 * @param[in]     void* vertex1:
 * @param[in]     void* vertex2:
 * @return        FuncRtn:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn graph_insert_edge(Graph* thiz, const void* vertex1, const void* vertex2);
/******************************************************************************/
/**
 * @func          FuncRtn graph_remove_edge(Graph* thiz, const void* vertex1, void** vertex2)
 * @brief         graph_remove_edge
 * @param[in/out] Graph* thiz:
 * @param[in]     void* vertex1:
 * @param[in/out] void** vertex2:
 * @return        FuncRtn:
 * @complexity    O(?)
 * @notes         nothing
 */
/******************************************************************************/
extern FuncRtn graph_remove_edge(Graph* thiz, const void* vertex1, void** vertex2);

/******************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif // __cplusplus
#endif // __cplusplus

/******************************************************************************/
#endif // GRAPH_H

