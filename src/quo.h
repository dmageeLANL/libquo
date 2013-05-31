/**
 * Copyright (c) 2013      Los Alamos National Security, LLC.
 *                         All rights reserved.
 */

#ifndef QUO_H_INCLUDED
#define QUO_H_INCLUDED

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

struct quo_t;
typedef struct quo_t quo_t;

enum {
    QUO_SUCCESS,
    QUO_ERR,
    QUO_ERR_SYS,
    QUO_ERR_OOR,
    QUO_ERR_INVLD_ARG,
    QUO_ERR_CALL_BEFORE_INIT,
    QUO_ERR_TOPO,
    QUO_ERR_MPI,
    QUO_ERR_NOT_SUPPORTED,
    QUO_ERR_POP
};

typedef enum {
    QUO_MACHINE,
    QUO_NODE,
    QUO_SOCKET,
    QUO_CORE,
    QUO_PU
} quo_obj_type_t;

/* ////////////////////////////////////////////////////////////////////////// */
/* ////////////////////////////////////////////////////////////////////////// */
/* quo api */
/* ////////////////////////////////////////////////////////////////////////// */
/* ////////////////////////////////////////////////////////////////////////// */

/**
 * this routine can be called before quo_init.
 */
int
quo_version(int *version,
            int *subversion);

/* 1st call */
int
quo_construct(quo_t **q);

/* 2nd call */
int
quo_init(quo_t *q);

/* 2nd-to-last call */
int
quo_finalize(quo_t *q);

/* last call - call before MPI_Finalize */
int
quo_destruct(quo_t *q);

/**
 */
int
quo_initialized(const quo_t *q,
                int *out_initialized);

int
quo_node_topo_stringify(const quo_t *q,
                        char **out_str);

int
quo_nsockets(const quo_t *q,
             int *out_nsockets);

int
quo_ncores(const quo_t *q,
           int *out_ncores);

int
quo_npus(const quo_t *q,
         int *out_npus);

int
quo_bound(const quo_t *q,
          bool *bound);

int
quo_stringify_cbind(const quo_t *q,
                    char **cbind_str);

int
quo_nnodes(const quo_t *q,
           int *out_nodes);

int
quo_nnoderanks(const quo_t *q,
               int *out_nnoderanks);

int
quo_noderank(const quo_t *q,
             int *out_noderank);

int
quo_rebind(quo_t *q,
           quo_obj_type_t type,
           unsigned obj_index);

int
quo_bind_push(quo_t *q,
              quo_obj_type_t type,
              unsigned obj_index);
int
quo_bind_pop(quo_t *q);

#ifdef __cplusplus
}
#endif

#endif
