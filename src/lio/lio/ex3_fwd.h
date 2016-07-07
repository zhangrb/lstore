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

#ifndef ACCRE_LIO_EX3_FWD_H_INCLUDED
#define ACCRE_LIO_EX3_FWD_H_INCLUDED

#include <ibp/ibp.h>
#include <inttypes.h>

#ifdef __cplusplus
extern "C" {
#endif

// Typedefs
typedef struct lio_exnode_t lio_exnode_t;
typedef struct lio_inspect_args_t lio_inspect_args_t;
typedef struct lio_rid_inspect_tweak_t lio_rid_inspect_tweak_t;
typedef struct lio_segment_errors_t lio_segment_errors_t;
typedef struct lio_segment_fn_t lio_segment_fn_t;
typedef struct lio_segment_rw_hints_t lio_segment_rw_hints_t;
typedef struct lio_segment_t lio_segment_t;
typedef lio_segment_t *(*lio_segment_create_fn_t)(void *arg);
typedef struct lio_ex_header_t lio_ex_header_t;
typedef struct lio_exnode_exchange_t lio_exnode_exchange_t;
typedef struct lio_lio_exnode_text_t lio_lio_exnode_text_t;
typedef int64_t ex_off_t;
typedef uint64_t ex_id_t;
typedef ibp_tbx_iovec_t ex_tbx_iovec_t;
typedef void segment_priv_t;

#ifdef __cplusplus
}
#endif

#endif /* ^ ACCRE_LIO_EX3_ABSTRACT_H_INCLUDED ^ */ 
