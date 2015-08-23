// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/number/arithmetic.hpp>
#include <metal/number/number.hpp>
#include <metal/number/comparison/equal_to.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define _boilerplate(M, N) \
    _assert((metal::is_just_t<metal::neg<_val(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::inc<_val(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::dec<_val(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::add<_vals(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::sub<_vals(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::mul<_vals(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::div<_vals(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::add<_nums(M) _comma(M) _vals(_inc(N))>>), (_false)); \
    _assert((metal::is_just_t<metal::sub<_nums(M) _comma(M) _vals(_inc(N))>>), (_false)); \
    _assert((metal::is_just_t<metal::mul<_nums(M) _comma(M) _vals(_inc(N))>>), (_false)); \
    _assert((metal::is_just_t<metal::div<_nums(M) _comma(M) _vals(_inc(N))>>), (_false)); \
    _assert((metal::is_just_t<metal::neg<_num(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::inc<_num(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::dec<_num(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::add<_nums(N)>>), (_bool(N > 0))); \
    _assert((metal::is_just_t<metal::sub<_nums(N)>>), (_bool(N > 0))); \
    _assert((metal::is_just_t<metal::mul<_nums(N)>>), (_bool(N > 0))); \
    _assert((metal::is_just_t<metal::div<_nums(N)>>), (_bool(N > 0))); \
    _assert((metal::equal_to_t<metal::neg_t<metal::neg_t<_num(N)>>, _num(N)>), (_true)); \
    _assert((metal::equal_to_t<metal::inc_t<_num(N)>, _num(_inc(N))>), (_true)); \
    _assert((metal::equal_to_t<metal::dec_t<_num(_inc(N))>, _num(N)>), (_true)); \
    _assert((metal::equal_to_t<metal::inc_t<metal::dec_t<_num(N)>>, _num(N)>), (_true)); \
    _assert((metal::equal_to_t<metal::dec_t<metal::inc_t<_num(N)>>, _num(N)>), (_true)); \
    using _cat(triangle, N) = metal::div_t<metal::mul_t<_num(N), _num(_inc(N))>, num2>; \
    _assert((metal::equal_to_t<metal::add_t<_nums(_inc(N))>, _cat(triangle, N)>), (_true)); \
    _assert((metal::equal_to_t<metal::sub_t<_cat(triangle, N), _nums(_inc(N))>, num0>), (_true)); \
    _assert((metal::equal_to_t<metal::add_t<num0 _comma(N) _enum(N, _cat(num, M) _bar)>, metal::mul_t<_num(M), _num(N)>>), (_true)); \
    _assert((metal::equal_to_t<metal::sub_t<metal::mul_t<_num(M), _num(N)> _comma(N) _enum(N, _cat(num, M) _bar)>, num0>), (_true)); \
    _assert((metal::equal_to_t<metal::mul_t<_nums(_inc(N))>, num0>), (_true)); \
    _assert((metal::equal_to_t<metal::div_t<_nums(_inc(N))>, num0>), (_true)); \
    _assert((metal::equal_to_t<metal::div_t<metal::mul_t<_enum(_inc(N), _cat(num, _inc(M)) _bar)>, _enum(_inc(N), _cat(num, _inc(M)) _bar)>, num1>), (_true)); \
/**/

_gen(_boilerplate)
