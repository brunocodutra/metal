// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/optional/extract.hpp>

#include "test.hpp"

#define _boilerplate(M, N) \
    _assert((metal::from_maybe<_val(M), _val(N)>), (_val(N))); \
    _assert((metal::from_maybe<_num(M), _val(N)>), (_num(M))); \
    _assert((metal::from_maybe<_pair(M), _val(N)>), (_val(N))); \
    _assert((metal::from_maybe<_list(M), _val(N)>), (_val(N))); \
    _assert((metal::from_maybe<_map(M), _val(N)>), (_val(N))); \
    _assert((metal::from_maybe<_arg(M), _val(N)>), (_val(N))); \
    _assert((metal::from_maybe<_lbd(M), _val(N)>), (_lbd(M)::type)); \
    _assert((metal::from_maybe<_lambda(M), _val(N)>), (_val(N))); \
    _assert((metal::from_just<_num(N)>), (_num(N))); \
    _assert((metal::from_just<_lbd(N)>), (_lbd(N)::type)); \
/**/

_gen(_boilerplate)
