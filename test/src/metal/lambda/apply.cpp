// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/lambda/apply.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define _boilerplate(M, N) \
    using _cat(opt, M) = _expr(M)<_vals(M)>; \
    using _cat(optval, M) = _cat(opt, M)::type; \
    using _cat(rec, M) = _expr(M)<_enum(M, rec)>; \
    using _cat(recval, M) = _expr(M)<_enum(M, recval)>::type; \
    _assert((metal::is_just_t<metal::apply<_val(M) _comma(N) _vals(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::apply<_num(M) _comma(N) _vals(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::apply<_pair(M) _comma(N) _vals(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::apply<_list(M) _comma(N) _vals(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::apply<_map(M) _comma(N) _vals(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::apply<_arg(M) _comma(N) _vals(N)>>), (_bool(M < N))); \
    _assert((metal::is_just_t<metal::apply<_cat(opt, M) _comma(N) _vals(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::apply<_cat(rec, M) _comma(N) _vals(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::apply<_lbd() _comma(N) _vals(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::apply<_lambda() _comma(N) _vals(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::apply<_lbd(M) _comma(N) _vals(N)>>), (_bool(M <= N))); \
    _assert((metal::is_just_t<metal::apply<_lambda(M) _comma(N) _vals(N)>>), (_bool(M == N))); \
    _assert((metal::is_just_t<metal::apply<_expr(_inc(M))<_lbds(M) _comma(M) _lambda(M)> _comma(N) _vals(N)>>), (_bool(M == N))); \
    _assert((metal::is_just_t<metal::apply<metal::apply<_args(_inc(M))>, _lbd(M) _comma(N) _vals(N)>>), (_bool(M <= N))); \
    _assert((metal::is_just_t<metal::apply<metal::lambda<metal::apply>, _lambda(M) _comma(N) _vals(N)>>), (_bool(M == N))); \
    _assert((metal::apply_t<_val(M) _comma(N) _vals(N)>), (_val(M))); \
    _assert((metal::apply_t<_num(M) _comma(N) _vals(N)>), (_num(M))); \
    _assert((metal::apply_t<_arg(M), _vals(_inc(M))>), (_val(M))); \
    _assert((metal::apply_t<_cat(opt, M) _comma(N) _vals(N)>), (_cat(optval, M))); \
    _assert((metal::apply_t<_cat(rec, M) _comma(N) _vals(N)>), (_cat(recval, M))); \
    _assert((metal::apply_t<_lbd() _comma(M) _vals(M)>), (_expr()<_vals(M)>::type)); \
    _assert((metal::apply_t<_lambda() _comma(M) _vals(M)>), (_expr()<_vals(M)>::type)); \
    _assert((metal::apply_t<_lbd(M) _comma(M) _vals(M)>), (_cat(optval, M))); \
    _assert((metal::apply_t<_lambda(M) _comma(M) _vals(M)>), (_cat(optval, M))); \
    _assert((metal::apply_t<_expr(_inc(M))<_lbds(M) _comma(M) _lambda(M)> _comma(M) _vals(M)>), (_expr(_inc(M))<_enum(_inc(M), optval)>::type)); \
    _assert((metal::apply_t<metal::apply<_args(_inc(M))>, _lbd(M) _comma(M) _vals(M)>), (_cat(optval, M))); \
    _assert((metal::apply_t<metal::lambda<metal::apply>, _lambda(M) _comma(M) _vals(M)>), (_cat(optval, M))); \
/**/

_gen(_boilerplate)
