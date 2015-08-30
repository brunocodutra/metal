// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/map/map.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define _boilerplate(M, N) \
    _assert((metal::is_just_t<metal::map<_vals(N)>>), (_bool(!N))); \
    _assert((metal::is_just_t<metal::map<_nums(N)>>), (_bool(!N))); \
    _assert((metal::is_just_t<metal::map<_pairs(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::map<_pair(M) _comma(N) _pairs(N)>>), (_bool(M >= N))); \
    _assert((metal::is_just_t<metal::map<_lists(N)>>), (_bool(!N))); \
    _assert((metal::is_just_t<metal::map<_maps(N)>>), (_bool(!N))); \
    _assert((metal::is_just_t<metal::map<_args(N)>>), (_bool(!N))); \
    _assert((metal::is_just_t<metal::map<_lbds(N)>>), (_bool(!N))); \
    _assert((metal::is_map_t<_val(N)>), (_false)); \
    _assert((metal::is_map_t<_num(N)>), (_false)); \
    _assert((metal::is_map_t<_pair(N)>), (_false)); \
    _assert((metal::is_map_t<_list(N)>), (_bool(!N))); \
    _assert((metal::is_map_t<_map(N)>), (_true)); \
    _assert((metal::is_map_t<_arg(N)>), (_false)); \
    _assert((metal::is_map_t<_lbd(N)>), (_bool(!N))); \
/**/

_gen(_boilerplate)
