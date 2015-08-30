// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/list/at.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define _boilerplate(M, N) \
    _assert((metal::is_just_t<metal::at<_val(M), _num(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::at<_num(M), _num(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::at<_pair(M), _num(N)>>), (_bool(N < 2))); \
    _assert((metal::is_just_t<metal::at<_list(M), _num(N)>>), (_bool(M > N))); \
    _assert((metal::is_just_t<metal::at<_map(M), _num(N)>>), (_bool(M > N))); \
    _assert((metal::is_just_t<metal::at<_arg(M), _num(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::at<_lbd(M), _num(N)>>), (_bool(M > N))); \
    _assert((metal::is_just_t<metal::at<_lambda(M), _num(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::at<_list(M), _val(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::at<_list(M), _pair(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::at<_list(M), _list(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::at<_list(M), _map(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::at<_list(M), _arg(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::at<_list(M), _lbd(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::at<_list(M), _lambda(N)>>), (_false)); \
    _assert((metal::at_t<_pair(N), _num(0)>), (_num(N))); \
    _assert((metal::at_t<_pair(N), _num(1)>), (_val(N))); \
    _assert((metal::at_t<_list(_limit), _num(N)>), (_val(N))); \
    _assert((metal::at_t<_map(_limit), _num(N)>), (_pair(N))); \
    _assert((metal::at_t<_lbd(_limit), _num(N)>), (_arg(N))); \
    _assert((metal::at_t<_seq()<_lists(M) _comma(M) _maps(_inc(N))>, _num(M)>), (_map(0))); \
/**/

_gen(_boilerplate)

