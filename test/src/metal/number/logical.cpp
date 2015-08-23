// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/number/logical.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define _boilerplate(M, N) \
    _assert((metal::is_just_t<metal::not_<_val(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::and_<_vals(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::or_<_vals(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::and_<_nums(M) _comma(M) _vals(_inc(N))>>), (_false)); \
    _assert((metal::is_just_t<metal::or_<_nums(M) _comma(M) _vals(_inc(N))>>), (_false)); \
    _assert((metal::is_just_t<metal::not_<_num(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::and_<_nums(N)>>), (_bool(N > 0))); \
    _assert((metal::is_just_t<metal::or_<_nums(N)>>), (_bool(N > 0))); \
    _assert((metal::and_t<_nums(_inc(N))>), (_false)); \
    _assert((metal::and_t<_enum(_inc(N), _cat(num, M) _bar)>), (_bool(M > 0))); \
    _assert((metal::and_t<_enum(_inc(N), _cat(num, M) _bar), _enum(_inc(M), _cat(num, N) _bar)>), (_bool(M && N))); \
    _assert((metal::or_t<_nums(_inc(N))>), (_bool(N > 0))); \
    _assert((metal::or_t<_enum(_inc(N), _cat(num, M) _bar)>), (_bool(M > 0))); \
    _assert((metal::or_t<_enum(_inc(N), _cat(num, M) _bar), _enum(_inc(M), _cat(num, N) _bar)>), (_bool(M || N))); \
/**/

_gen(_boilerplate)
