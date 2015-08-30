// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/list/count.hpp>
#include <metal/number/number.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define _count(...) metal::number<std::ptrdiff_t, (__VA_ARGS__)>

#define _boilerplate(M, N) \
    _assert((metal::is_just_t<metal::count<_val(M), _val(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::count<_num(M), _val(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::count<_pair(M), _val(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::count<_list(M), _val(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::count<_map(M), _val(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::count<_arg(M), _val(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::count<_lbd(M), _val(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::count<_lambda(M), _val(N)>>), (_false)); \
    _assert((metal::count_t<_pair(M), _val(N)>), (_count(M == N))); \
    _assert((metal::count_t<_pair(M), _num(N)>), (_count(M == N))); \
    _assert((metal::count_t<_list(M), _val(N)>), (_count(M > N))); \
    _assert((metal::count_t<_map(M), _pair(N)>), (_count(M > N))); \
    _assert((metal::count_t<_lbd(M), _arg(N)>), (_count(M > N))); \
    _assert((metal::count_t<_seq()<_val(M), _vals(_inc(M))>, _val(N)>), (_count((M >= N) + (M == N)))); \
    _assert((metal::count_t<_seq(M)<_enum(M, _map(N) _bar)>, _map(N)>), (_count(M))); \
    _assert((metal::count_t<_seq()< \
        _vals(_inc(M)), _nums(_inc(M)), _pairs(_inc(M)), _lists(_inc(M)), \
        _maps(_inc(M)), _args(_inc(M)), _lbds(_inc(M))>, _map(N)>), (_count((M >= N) + !N))); \
/**/

_gen(_boilerplate)

