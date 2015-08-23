// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/number/comparison.hpp>
#include <metal/number/number.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define _boilerplate(M, N) \
    _assert((metal::is_just_t<metal::equal_to<_val(M), _val(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::greater<_val(M), _val(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::less<_val(M), _val(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::equal_to<_num(M), _val(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::greater<_num(M), _val(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::less<_num(M), _val(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::equal_to_t<_num(M), _num(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::greater<_num(M), _num(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::less<_num(M), _num(N)>>), (_true)); \
    _assert((metal::equal_to_t<_num(M), _num(N)>), (_bool(M == N))); \
    _assert((metal::greater_t<_num(M), _num(N)>), (_bool(M > N))); \
    _assert((metal::less_t<_num(M), _num(N)>), (_bool(M < N))); \
/**/

_gen(_boilerplate)
