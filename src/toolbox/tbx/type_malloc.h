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

#pragma once
#ifndef ACCRE_TYPE_MALLOC_H_INCLUDED
#define ACCRE_TYPE_MALLOC_H_INCLUDED

#include <assert.h>
#include <stdlib.h>
#include "tbx/toolbox_visibility.h"

// Preprocessor macros
#define tbx_type_malloc_clear(var, type, count) \
            tbx_type_malloc(var, type, count); tbx_type_memclear(var, type, count)
#define tbx_type_malloc(var, type, count) \
            var = (type *)malloc(sizeof(type)*(count)); assert(var != NULL)
#define tbx_type_realloc(var, type, count) \
            var = (type *)realloc(var, sizeof(type)*(count)); assert(var != NULL)
#define tbx_type_memclear(var, type, count) \
            memset(var, 0, sizeof(type)*(count))

#endif