// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/list/list.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define _boilerplate(M, N) \
    _assert((metal::is_just_t<metal::list<_vals(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::list<_nums(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::list<_pairs(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::list<_pair(M) _comma(N) _pairs(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::list<_lists(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::list<_maps(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::list<_args(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::list<_lbds(N)>>), (_true)); \
    _assert((metal::is_list_t<_val(N)>), (_false)); \
    _assert((metal::is_list_t<_num(N)>), (_false)); \
    _assert((metal::is_list_t<_pair(N)>), (_true)); \
    _assert((metal::is_list_t<_list(N)>), (_true)); \
    _assert((metal::is_list_t<_map(N)>), (_true)); \
    _assert((metal::is_list_t<_arg(N)>), (_false)); \
    _assert((metal::is_list_t<_lbd(N)>), (_true)); \
    _assert((metal::is_list_t<_lambda(N)>), (_false)); \
/**/

_gen(_boilerplate)

