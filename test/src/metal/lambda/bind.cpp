// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/lambda/bind.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    using CAT(opt, M) = EXPR(M)<VALS(M)>; \
    using CAT(rec, M) = EXPR(M)<ENUM(M, rec)>; \
    ASSERT((metal::is_just_t<metal::bind<VAL(M) COMMA(N) VALS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::bind<NUM(M) COMMA(N) VALS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::bind<PAIR(M) COMMA(N) VALS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::bind<LIST(M) COMMA(N) VALS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::bind<MAP(M) COMMA(N) VALS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::bind<ARG(M) COMMA(N) VALS(N)>>), (BOOL(M < N))); \
    ASSERT((metal::is_just_t<metal::bind<CAT(opt, M) COMMA(N) VALS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::bind<CAT(rec, M) COMMA(N) VALS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::bind<FUN() COMMA(N) VALS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::bind<LBD(M) COMMA(N) VALS(N)>>), (BOOL(M <= N))); \
    ASSERT((metal::is_just_t<metal::bind<FUN(M) COMMA(N) VALS(N)>>), (BOOL(M == N))); \
    ASSERT((metal::is_just_t<metal::bind<EXPR(INC(M))<LBDS(M) COMMA(M) FUN(M)> COMMA(N) VALS(N)>>), (BOOL(M == N))); \
    ASSERT((metal::is_just_t<metal::bind<metal::bind<ARGS(INC(M))>, LBD(M) COMMA(N) VALS(N)>>), (BOOL(M <= N))); \
    ASSERT((metal::is_just_t<metal::bind<metal::lambda<metal::bind>, FUN(M) COMMA(N) VALS(N)>>), (TRUE)); \
    ASSERT((metal::bind_t<VAL(M) COMMA(N) VALS(N)>), (VAL(M))); \
    ASSERT((metal::bind_t<NUM(M) COMMA(N) VALS(N)>), (NUM(M))); \
    ASSERT((metal::bind_t<PAIR(M) COMMA(N) VALS(N)>), (PAIR(M))); \
    ASSERT((metal::bind_t<LIST(M) COMMA(N) VALS(N)>), (LIST(M))); \
    ASSERT((metal::bind_t<MAP(M) COMMA(N) VALS(N)>), (MAP(M))); \
    ASSERT((metal::bind_t<ARG(M), VALS(INC(M))>), (VAL(M))); \
    ASSERT((metal::bind_t<CAT(opt, M) COMMA(N) VALS(N)>), (CAT(opt, M))); \
    ASSERT((metal::bind_t<CAT(rec, M) COMMA(N) VALS(N)>), (CAT(rec, M))); \
    ASSERT((metal::bind_t<FUN() COMMA(M) VALS(M)>), (EXPR()<VALS(M)>)); \
    ASSERT((metal::bind_t<LBD(M) COMMA(M) VALS(M)>), (CAT(opt, M))); \
    ASSERT((metal::bind_t<FUN(M) COMMA(M) VALS(M)>), (CAT(opt, M))); \
    ASSERT((metal::bind_t<EXPR(INC(M))<LBDS(M) COMMA(M) FUN(M)> COMMA(M) VALS(M)>), (EXPR(INC(M))<ENUM(INC(M), opt)>)); \
    ASSERT((metal::bind_t<metal::bind<ARGS(INC(M))>, LBD(M) COMMA(M) VALS(M)>), (metal::bind<LBD(M) COMMA(M) VALS(M)>)); \
    ASSERT((metal::bind_t<metal::lambda<metal::bind>, FUN(M) COMMA(M) VALS(M)>), (metal::bind<FUN(M) COMMA(M) VALS(M)>)); \
/**/

GEN(MATRIX)
