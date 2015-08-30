// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/map/at_key.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define _boilerplate(M, N) \
    _assert((metal::is_just_t<metal::at_key<_val(M), _val(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::at_key<_pair(M), _val(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::at_key<_list(M), _val(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::at_key<_map(M), _val(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::at_key<_map(M), _num(N)>>), (_bool(M > N))); \
    _assert((metal::is_just_t<metal::at_key<_seq()<_pairs(M)>, _num(N)>>), (_bool(M > N))); \
    _assert((metal::is_just_t<metal::at_key<_seq()<_pair(M) _comma(N) _pairs(N)>, _num(N)>>), (_bool(M == N))); \
    _assert((metal::is_just_t<metal::at_key<_seq(_inc(N))<_pairs(N) _comma(N) _seq()<_num(M), _map(M)>>, _num(N)>>), (_bool(M == N))); \
    _assert((metal::at_key_t<_map(_inc(N)), _num(N)>), (_val(N))); \
    _assert((metal::at_key_t<_seq()<_pairs(_inc(N))>, _num(N)>), (_val(N))); \
    _assert((metal::at_key_t<_seq(_inc(N))<_pairs(N) _comma(N) _seq()<_num(N), _map(N)>>, _num(N)>), (_map(N))); \
/**/

_gen(_boilerplate)
