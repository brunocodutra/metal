// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/lambda/apply.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    using CAT(opt, M) = EXPR(M)<VALS(M)>; \
    using CAT(optval, M) = CAT(opt, M)::type; \
    using CAT(rec, M) = EXPR(M)<ENUM(M, rec)>; \
    using CAT(recval, M) = EXPR(M)<ENUM(M, recval)>::type; \
    ASSERT((metal::is_just_t<metal::apply<VAL(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::apply<NUM(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::apply<PAIR(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::apply<LIST(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::apply<MAP(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::apply<ARG(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::apply<CAT(opt, M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::apply<CAT(rec, M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::apply<LBD(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::apply<FUN(), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::apply<FUN(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::apply<VAL(M), SEQ(N)<VALS(N)>>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::apply<NUM(M), SEQ(N)<VALS(N)>>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::apply<PAIR(M), SEQ(N)<VALS(N)>>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::apply<LIST(M), SEQ(N)<VALS(N)>>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::apply<MAP(M), SEQ(N)<VALS(N)>>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::apply<ARG(M), SEQ(N)<VALS(N)>>>), (BOOL(M < N))); \
    ASSERT((metal::is_just_t<metal::apply<CAT(opt, M), SEQ(N)<VALS(N)>>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::apply<CAT(rec, M), SEQ(N)<VALS(N)>>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::apply<LBD(M), SEQ(N)<VALS(N)>>>), (BOOL(M <= N))); \
    ASSERT((metal::is_just_t<metal::apply<FUN(), SEQ(N)<VALS(N)>>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::apply<FUN(M), SEQ(N)<VALS(N)>>>), (BOOL(M == N))); \
    ASSERT((metal::is_just_t<metal::apply<EXPR(INC(M))<LBDS(M) COMMA(M) FUN(M)>, SEQ(N)<VALS(N)>>>), (BOOL(M == N))); \
    ASSERT((metal::is_just_t<metal::apply<metal::apply<ARG(0), ARG(1)>, SEQ()<LBD(M), SEQ(N)<VALS(N)>>>>), (BOOL(M <= N))); \
    ASSERT((metal::is_just_t<metal::apply<metal::lambda<metal::apply>, SEQ()<FUN(M), SEQ(N)<VALS(N)>>>>), (BOOL(M == N))); \
    ASSERT((metal::apply_t<VAL(M), SEQ(N)<VALS(N)>>), (VAL(M))); \
    ASSERT((metal::apply_t<NUM(M), SEQ(N)<VALS(N)>>), (NUM(M))); \
    ASSERT((metal::apply_t<ARG(M), SEQ()<VALS(INC(M))>>), (VAL(M))); \
    ASSERT((metal::apply_t<CAT(opt, M), SEQ(N)<VALS(N)>>), (CAT(optval, M))); \
    ASSERT((metal::apply_t<CAT(rec, M), SEQ(N)<VALS(N)>>), (CAT(recval, M))); \
    ASSERT((metal::apply_t<LBD(M), SEQ(M)<VALS(M)>>), (CAT(optval, M))); \
    ASSERT((metal::apply_t<FUN(), SEQ(M)<VALS(M)>>), (EXPR()<VALS(M)>::type)); \
    ASSERT((metal::apply_t<FUN(M), SEQ(M)<VALS(M)>>), (CAT(optval, M))); \
    ASSERT((metal::apply_t<EXPR(INC(M))<LBDS(M) COMMA(M) FUN(M)>, SEQ(M)<VALS(M)>>), (EXPR(INC(M))<ENUM(INC(M), optval)>::type)); \
    ASSERT((metal::apply_t<metal::apply<ARG(0), ARG(1)>, SEQ()<LBD(M), SEQ(M)<VALS(M)>>>), (CAT(optval, M))); \
    ASSERT((metal::apply_t<metal::lambda<metal::apply>, SEQ()<FUN(M), SEQ(M)<VALS(M)>>>), (CAT(optval, M))); \
/**/

GEN(MATRIX)
