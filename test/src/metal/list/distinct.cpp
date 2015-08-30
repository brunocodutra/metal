// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/list/distinct.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define _boilerplate(M, N) \
    _assert((metal::is_just_t<metal::distinct<_val(M)>>), (_false)); \
    _assert((metal::is_just_t<metal::distinct<_num(M)>>), (_false)); \
    _assert((metal::is_just_t<metal::distinct<_pair(M)>>), (_true)); \
    _assert((metal::is_just_t<metal::distinct<_list(M)>>), (_true)); \
    _assert((metal::is_just_t<metal::distinct<_map(M)>>), (_true)); \
    _assert((metal::is_just_t<metal::distinct<_arg(M)>>), (_false)); \
    _assert((metal::is_just_t<metal::distinct<_lbd(M)>>), (_true)); \
    _assert((metal::is_just_t<metal::distinct<_lambda(M)>>), (_false)); \
    _assert((metal::distinct_t<_pair(M)>), (_true)); \
    _assert((metal::distinct_t<_pair(M)>), (_true)); \
    _assert((metal::distinct_t<_list(M)>), (_true)); \
    _assert((metal::distinct_t<_map(M)>), (_true)); \
    _assert((metal::distinct_t<_lbd(M)>), (_true)); \
    _assert((metal::distinct_t<_seq()<_val(M), _vals(_inc(M))>>), (_false)); \
    _assert((metal::distinct_t<_seq(M)<_enum(M, _map(N) _bar)>>), (_bool(M < 2))); \
    _assert((metal::distinct_t<_seq()< \
        _vals(_inc(M)), _nums(_inc(M)), _pairs(_inc(M)), _lists(_inc(M)), \
        _maps(_inc(M)), _args(_inc(M)), _lbds(_inc(M))>>), (_false)); \
/**/

_gen(_boilerplate)

