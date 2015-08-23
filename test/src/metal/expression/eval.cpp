// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/expression/eval.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define _boilerplate(M, N) \
    _assert((metal::is_just_t<metal::eval<_seq(M) _comma(N) _vals(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::eval<_expr(M) _comma(N) _vals(N)>>), (_bool(M == N))); \
    _assert((metal::is_just_t<metal::eval<expr _comma(N) _vals(N)>>), (_true)); \
    _assert((metal::eval_t<_expr(N) _comma(N) _vals(N)>), (_expr(N)<_vals(N)>::type)); \
    _assert((metal::eval_t<expr _comma(N) _vals(N)>), (expr<_vals(N)>::type)); \
/**/

_gen(_boilerplate)
