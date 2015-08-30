// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/list/contains.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define _boilerplate(M, N) \
    _assert((metal::is_just_t<metal::contains<_val(M), _val(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::contains<_num(M), _val(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::contains<_pair(M), _val(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::contains<_list(M), _val(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::contains<_map(M), _val(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::contains<_arg(M), _val(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::contains<_lbd(M), _val(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::contains<_lambda(M), _val(N)>>), (_false)); \
    _assert((metal::contains_t<_pair(M), _val(N)>), (_bool(M == N))); \
    _assert((metal::contains_t<_pair(M), _num(N)>), (_bool(M == N))); \
    _assert((metal::contains_t<_list(M), _val(N)>), (_bool(M > N))); \
    _assert((metal::contains_t<_map(M), _pair(N)>), (_bool(M > N))); \
    _assert((metal::contains_t<_lbd(M), _arg(N)>), (_bool(M > N))); \
    _assert((metal::contains_t<_seq()<_val(M), _vals(_inc(M))>, _val(N)>), (_bool(M >= N))); \
    _assert((metal::contains_t<_seq(M)<_enum(M, _map(N) _bar)>, _map(N)>), (_bool(M > 0))); \
    _assert((metal::contains_t<_seq()< \
        _vals(_inc(M)), _nums(_inc(M)), _pairs(_inc(M)), _lists(_inc(M)), \
        _maps(_inc(M)), _args(_inc(M)), _lbds(_inc(M))>, _map(N)>), (_bool(M >= N))); \
/**/

_gen(_boilerplate)

