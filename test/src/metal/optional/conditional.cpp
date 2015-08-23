// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/optional/conditional.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define _boilerplate(M, N) \
    _assert((metal::is_just_t<metal::conditional<_vals(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::conditional<_nums(N)>>), (_bool(N > 2))); \
    _assert((metal::conditional_t<_enum(M, num0 _bar) _comma(M) _num(_inc(N)), metal::just<_val(N)>>), (_val(N))); \
    _assert((metal::conditional_t<_num(_inc(N)), metal::just<_val(N)> _comma(M) _vals(M)>), (_val(N))); \
/**/

_gen(_boilerplate)





