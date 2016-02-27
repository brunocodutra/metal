// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/lambda/invoke.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/optional/optional.hpp>

#include "test.hpp"

template<typename val>
using identity = val;

#define MATRIX(M, N) \
    using CAT(opt, M) = EXPR(M)<VALS(M)>; \
    using CAT(optval, M) = CAT(opt, M)::type; \
    using CAT(rec, M) = EXPR(M)<ENUM(M, rec)>; \
    using CAT(recval, M) = EXPR(M)<ENUM(M, recval)>::type; \
    ASSERT((metal::is_just_t<metal::invoke<VAL(M) COMMA(N) VALS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::invoke<NUM(M) COMMA(N) VALS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::invoke<PAIR(M) COMMA(N) VALS(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::invoke<LIST(M) COMMA(N) VALS(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::invoke<MAP(M) COMMA(N) VALS(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::invoke<ARG(M) COMMA(N) VALS(N)>>), (BOOL(M < N))); \
    ASSERT((metal::is_just_t<metal::invoke<CAT(opt, M) COMMA(N) VALS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::invoke<CAT(rec, M) COMMA(N) VALS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::invoke<LBD(M) COMMA(N) VALS(N)>>), (BOOL(M <= N))); \
    ASSERT((metal::is_just_t<metal::invoke<FUN() COMMA(N) VALS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::invoke<FUN(M) COMMA(N) VALS(N)>>), (BOOL(M == N))); \
    ASSERT((metal::is_just_t<metal::invoke<EXPR(INC(M))<LBDS(M) COMMA(M) FUN(M)> COMMA(N) VALS(N)>>), (BOOL(M == N))); \
    ASSERT((metal::is_just_t<metal::invoke<metal::invoke<ARGS(INC(M))>, FUN(M) COMMA(N) VALS(N)>>), (BOOL(M <= N))); \
    ASSERT((metal::is_just_t<metal::invoke<metal::lambda<identity>, VAL(N)>>), (FALSE)); \
    ASSERT((metal::invoke_t<VAL(M) COMMA(N) VALS(N)>), (VAL(M))); \
    ASSERT((metal::invoke_t<NUM(M) COMMA(N) VALS(N)>), (NUM(M))); \
    ASSERT((metal::invoke_t<ARG(M), VALS(INC(M))>), (VAL(M))); \
    ASSERT((metal::invoke_t<CAT(opt, M) COMMA(N) VALS(N)>), (CAT(optval, M))); \
    ASSERT((metal::invoke_t<CAT(rec, M) COMMA(N) VALS(N)>), (CAT(recval, M))); \
    ASSERT((metal::invoke_t<LBD(M) COMMA(M) VALS(M)>), (CAT(optval, M))); \
    ASSERT((metal::invoke_t<FUN() COMMA(M) VALS(M)>), (EXPR()<VALS(M)>::type)); \
    ASSERT((metal::invoke_t<FUN(M) COMMA(M) VALS(M)>), (CAT(optval, M))); \
    ASSERT((metal::invoke_t<EXPR(INC(M))<LBDS(M) COMMA(M) FUN(M)> COMMA(M) VALS(M)>), (EXPR(INC(M))<ENUM(INC(M), optval)>::type)); \
    ASSERT((metal::invoke_t<metal::invoke<ARGS(INC(M))>, FUN(M) COMMA(M) VALS(M)>), (CAT(optval, M))); \
/**/

GEN(MATRIX)
