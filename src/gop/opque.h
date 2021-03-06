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

//*************************************************************
// opque.h - Header defining I/O structs and operations for
//     collections of oplists
//*************************************************************

#ifndef __OPQUE_H_
#define __OPQUE_H_

#include <apr_hash.h>
#include <apr_thread_cond.h>
#include <apr_thread_mutex.h>
#include <gop/types.h>
#include <tbx/atomic_counter.h>
#include <tbx/network.h>
#include <tbx/pigeon_coop.h>
#include <tbx/stack.h>

#include "callback.h"
#include "gop.h"
#include "gop/visibility.h"
#include "gop/opque.h"

#ifdef __cplusplus
extern "C" {
#endif

// Types

// Functions
void opque_set_failure_mode(gop_opque_t *q, int value);
int opque_get_failure_mode(gop_opque_t *q);
gop_op_status_t opque_completion_status(gop_opque_t *q);
void opque_set_arg(gop_opque_t *q, void *arg);
void *opque_get_arg(gop_opque_t *q);
void init_opque(gop_opque_t *que);
int internal_gop_opque_add(gop_opque_t *que, gop_op_generic_t *gop, int dolock);


#ifdef __cplusplus
}
#endif


#endif

