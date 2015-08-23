// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/lambda/apply.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define _boilerplate(M, N) \
    _assert((metal::is_just_t<metal::apply<_val(M) _comma(N) _vals(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::apply<_num(M) _comma(N) _vals(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::apply<_pair(M) _comma(N) _vals(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::apply<_list(M) _comma(N) _vals(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::apply<_map(M) _comma(N) _vals(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::apply<_arg(M) _comma(N) _vals(N)>>), (_bool(M < N))); \
    _assert((metal::is_just_t<metal::apply<_lbd(M) _comma(N) _vals(N)>>), (_bool(M <= N))); \
    _assert((metal::is_just_t<metal::apply<metal::apply<_args(_inc(M))>, _lbd(M) _comma(N) _vals(N)>>), (_bool(M <= N))); \
    using _cat(opt, N) = _expr(N)<_vals(N)>; \
    using _cat(r, N) = _cat(opt, N)::type; \
    _assert((metal::apply_t<_val(M) _comma(N) _vals(N)>), (_val(M))); \
    _assert((metal::apply_t<_num(M) _comma(N) _vals(N)>), (_num(M))); \
    _assert((metal::apply_t<_arg(N), _vals(_inc(N))>), (_val(N))); \
    _assert((metal::apply_t<_lbd(N) _comma(N) _vals(N)>), (_cat(r, N))); \
    _assert((metal::apply_t<_expr(N)<_lbds(N)> _comma(N) _vals(N)>), (_expr(N)<_enum(N, r)>::type)); \
    _assert((metal::apply_t<_expr(N)<_lbds(N)> _comma(N) _vals(N)>), (metal::apply_t<_expr(N)<_enum(N, opt)>>)); \
    _assert((metal::apply_t<metal::apply<_args(_inc(N))>, _lbd(N) _comma(N) _vals(N)>), (_cat(r, N))); \
/**/

_gen(_boilerplate)
