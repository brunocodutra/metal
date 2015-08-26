// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/lambda/apply.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define _boilerplate(M, N) \
    using _cat(opt, M) = _expr(M)<_vals(M)>; \
    using _cat(r, M) = _cat(opt, M)::type; \
    _assert((metal::is_just_t<metal::apply<_val(M) _comma(N) _vals(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::apply<_num(M) _comma(N) _vals(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::apply<_pair(M) _comma(N) _vals(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::apply<_list(M) _comma(N) _vals(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::apply<_map(M) _comma(N) _vals(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::apply<_arg(M) _comma(N) _vals(N)>>), (_bool(M < N))); \
    _assert((metal::is_just_t<metal::apply<lbd _comma(N) _vals(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::apply<_lbd(M) _comma(N) _vals(N)>>), (_bool(M <= N))); \
    _assert((metal::is_just_t<metal::apply<_cat(opt, M) _comma(N) _vals(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::apply<expr<metal::_0> _comma(N) _vals(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::apply<expr<metal::_0 _comma(M) _args(M)> _comma(N) _vals(N)>>), (_bool(M <= N))); \
    _assert((metal::is_just_t<metal::apply<_expr(_inc(M))<_enum(_inc(M), metal::_0 _bar)> _comma(N) _vals(N)>>), (_bool(N == 1))); \
    _assert((metal::is_just_t<metal::apply<_expr(M)<_lbds(M)> _comma(N) _vals(N)>>), (_bool(M <= N + 1))); \
    _assert((metal::is_just_t<metal::apply<metal::apply<_args(_inc(M))>, _lbd(M) _comma(N) _vals(N)>>), (_bool(M <= N))); \
    _assert((metal::apply_t<_val(M) _comma(N) _vals(N)>), (_val(M))); \
    _assert((metal::apply_t<_num(M) _comma(N) _vals(N)>), (_num(M))); \
    _assert((metal::apply_t<_arg(M), _vals(_inc(M))>), (_val(M))); \
    _assert((metal::apply_t<lbd _comma(M) _vals(M)>), (expr<_vals(M)>::type)); \
    _assert((metal::apply_t<_lbd(M) _comma(M) _vals(M)>), (_cat(r, M))); \
    _assert((metal::apply_t<_cat(opt, M) _comma(N) _vals(N)>), (_cat(r, M))); \
    _assert((metal::apply_t<expr<metal::_0> _comma(M) _vals(M)>), (expr<_vals(M)>::type)); \
    _assert((metal::apply_t<expr<metal::_0 _comma(M) _args(M)> _comma(M) _vals(M)>), (expr<_vals(M) _comma(M) _vals(M)>::type)); \
    _assert((metal::apply_t<_expr(_inc(M))<_enum(_inc(M), metal::_0 _bar)>, _val(N)>), (_expr(_inc(M))<_enum(_inc(M), _val(N) _bar)>::type)); \
    _assert((metal::apply_t<_expr(M)<_lbds(M)> _comma(M) _vals(M)>), (_expr(M)<_enum(M, r)>::type)); \
    _assert((metal::apply_t<_expr(M)<_lbds(M)> _comma(M) _vals(M)>), (metal::apply_t<_expr(M)<_enum(M, opt)>>)); \
    _assert((metal::apply_t<metal::apply<_args(_inc(M))>, _lbd(M) _comma(M) _vals(M)>), (_cat(r, M))); \
/**/

_gen(_boilerplate)
