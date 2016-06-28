/*
Copyright 2016 Vanderbilt University

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

/** \file
* Autogenerated public API
*/

#ifndef ACCRE_LIO_RESOURCE_SERVICE_ABSTRACT_H_INCLUDED
#define ACCRE_LIO_RESOURCE_SERVICE_ABSTRACT_H_INCLUDED

#include <apr_thread_cond.h>
#include <apr_thread_mutex.h>
#include <gop/mq.h>
#include <lio/visibility.h>
#include <lio/ds.h>
#include <lio/ex3_fwd.h>

#ifdef __cplusplus
extern "C" {
#endif

// Typedefs
typedef struct resource_service_fn_t resource_service_fn_t;
typedef struct rid_change_entry_t rid_change_entry_t;
typedef struct rs_hints_t rs_hints_t;
typedef struct rs_mapping_notify_t rs_mapping_notify_t;
typedef struct rs_request_t rs_request_t;
typedef struct rs_space_t rs_space_t;
// FIXME:leaky
typedef struct rsq_base_ele_t rsq_base_ele_t;
typedef struct rsq_base_t rsq_base_t;
typedef struct rs_remote_client_priv_t rs_remote_client_priv_t;
typedef struct rs_remote_server_priv_t rs_remote_server_priv_t;
typedef struct rs_simple_priv_t rs_simple_priv_t;
typedef struct rss_check_entry_t rss_check_entry_t;
typedef struct rss_rid_entry_t rss_rid_entry_t;

// Functions

// Preprocessor constants
// FIXME: leaky
#define RSQ_BASE_OP_KV      1
#define RSQ_BASE_OP_NOT     2
#define RSQ_BASE_OP_AND     3

#define RSQ_BASE_KV_EXACT   1
#define RSQ_BASE_KV_ANY     3

// Preprocessor macros
#define rs_get_rid_config(rs) (rs)->get_rid_config(rs)
#define rs_query_add(rs, q, op, key, kop, val, vop) (rs)->query_add(rs, q, op, key, kop, val, vop)
#define rs_query_append(rs, q, qappend) (rs)->query_append(rs, q, qappend)
#define rs_query_destroy(rs, q) (rs)->query_destroy(rs, q)
#define rs_query_new(rs) (rs)->query_new(rs)
#define rs_query_parse(rs, value) (rs)->query_parse(rs, value)
#define rs_query_print(rs, q) (rs)->query_print(rs, q)
#define rs_register_mapping_updates(rs, notify) (rs)->register_mapping_updates(rs, notify)
#define rs_unregister_mapping_updates(rs, notify) (rs)->unregister_mapping_updates(rs, notify)

// Exported types. To be obscured
struct rs_mapping_notify_t {
    apr_thread_mutex_t *lock;
    apr_thread_cond_t *cond;
    int map_version;
    int status_version;
};

typedef void rs_query_t;
struct resource_service_fn_t {
    void *priv;
    char *type;
    char *(*get_rid_value)(resource_service_fn_t *arg, char *rid_key, char *key);
    char *(*get_rid_config)(resource_service_fn_t *arg);
    void (*translate_cap_set)(resource_service_fn_t *arg, char *rid_key, data_cap_set_t *cap);
    void (*register_mapping_updates)(resource_service_fn_t *arg, rs_mapping_notify_t *map_version);
    void (*unregister_mapping_updates)(resource_service_fn_t *arg, rs_mapping_notify_t *map_version);
    int  (*query_add)(resource_service_fn_t *arg, rs_query_t **q, int op, char *key, int key_op, char *val, int val_op);
    void (*query_append)(resource_service_fn_t *arg, rs_query_t *q, rs_query_t *qappend);
    rs_query_t *(*query_dup)(resource_service_fn_t *arg, rs_query_t *q);
    rs_query_t *(*query_new)(resource_service_fn_t *arg);
    void (*query_destroy)(resource_service_fn_t *arg, rs_query_t *q);
    op_generic_t *(*data_request)(resource_service_fn_t *arg, data_attr_t *da, rs_query_t *q, data_cap_set_t **caps, rs_request_t *req, int req_size, rs_hints_t *hints_list, int fixed_size, int n_rid, int ignore_fixed_err, int timeout);
    rs_query_t *(*query_parse)(resource_service_fn_t *arg, char *value);
    char *(*query_print)(resource_service_fn_t *arg, rs_query_t *q);
    void (*destroy_service)(resource_service_fn_t *rs);
};

struct rid_change_entry_t {
    char *rid_key;      //** RID key
    char *ds_key;       //** Data service key
    int state;          //** Tweaking state
    ex_off_t delta;     //** How much to change the space by in bytes.  Negative means remove and postive means add space to the RID
    ex_off_t tolerance; //** Tolerance in bytes.  When abs(delta)<tolerance we stop tweaking the RID
};

#ifdef __cplusplus
}
#endif

#endif /* ^ ACCRE_LIO_RESOURCE_SERVICE_ABSTRACT_H_INCLUDED ^ */ 
