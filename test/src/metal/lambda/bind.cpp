// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/lambda/bind.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define ARG(N) metal::arg<INC(N)>
#define ARGS(N) ENUM(N, ADAPT(ARG))

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<FUNC(metal::bind), VAL(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::bind), NUM(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::bind), PAIR(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::bind), LIST(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::bind), MAP(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::bind), LBD(M) COMMA(N) LBDS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::bind), LBD() COMMA(N) LBDS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::bind), LBD(M), VAL(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::bind), LBD(), VAL(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::invoke<metal::bind<LBD(M) COMMA(M) ARGS(M)> COMMA(M) NUMS(M)>), (EXPR(M)<NUMS(M)>)); \
    ASSERT((metal::invoke<metal::bind<LBD(M) COMMA(M) ENUM(M, ARG(N) BAR)>, NUMS(INC(N))>), (EXPR(M)<ENUM(M, NUM(N) BAR)>)); \
    ASSERT((metal::invoke<metal::bind<LBD(), LBD(N)> COMMA(N) NUMS(N)>), (EXPR()<EXPR(N)<NUMS(N)>>)); \
/**/

GEN(MATRIX)
