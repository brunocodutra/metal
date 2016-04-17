// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/lambda/lift.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/optional/optional.hpp>

#include "test.hpp"

#define LIFT_T_(_, ...) metal::lift_t<__VA_ARGS__>
#define LIFT_T(N, ...) RECURSE(N, LIFT_T_, __VA_ARGS__)

#define QUOTE_T_(_, ...) metal::quote_t<__VA_ARGS__>
#define QUOTE_T(N, ...) RECURSE(N, QUOTE_T_, __VA_ARGS__)

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::invoke<LIFT_T(M, VAL(N)), QUOTE_T(N, VAL(N))>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::invoke<LIFT_T(M, NUM(N)), QUOTE_T(N, VAL(N))>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::invoke<LIFT_T(M, PAIR(N)), QUOTE_T(N, VAL(N))>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::invoke<LIFT_T(M, LIST(N)), QUOTE_T(N, VAL(N))>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::invoke<LIFT_T(M, MAP(N)), QUOTE_T(N, VAL(N))>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::invoke<LIFT_T(M, ARG(N)), ENUM(LIMIT, QUOTE_T(N, VAL(N)) BAR)>>), (BOOL(M <= N))); \
    ASSERT((metal::is_just_t<metal::invoke<LIFT_T(M, LBD(N)) COMMA(N) ENUM(N, QUOTE_T(N, VAL(N)) BAR) COMMA(CMPL(N)) VALS(CMPL(N))>>), (BOOL(!N || M <= N))); \
    ASSERT((metal::is_just_t<metal::invoke<LIFT_T(M, FUN(INC(N))), ENUM(INC(N), QUOTE_T(N, VAL(N)) BAR)>>), (BOOL(M <= N))); \
    ASSERT((metal::is_just_t<metal::invoke<LIFT_T(M, metal::lambda<SEQ(INC(N))>), ENUM(INC(N), QUOTE_T(N, VAL(N)) BAR)>>), (FALSE)); \
    ASSERT((metal::invoke_t<LIFT_T(M, VAL(N)), QUOTE_T(N, VAL(N))>), (VAL(N))); \
    ASSERT((metal::invoke_t<LIFT_T(M, NUM(N)), QUOTE_T(N, VAL(N))>), (NUM(N))); \
    ASSERT((metal::invoke_t<LIFT_T(M, ARG(N)) COMMA(N) ENUM(N, LIFT(VAL)), QUOTE_T(M, VAL(N)) COMMA(CMPL(N)) VALS(CMPL(N))>), (VAL(N))); \
    ASSERT((metal::invoke_t<LIFT_T(M, LBD(N)) COMMA(N) ENUM(N, QUOTE_T(M, VAL(N)) BAR) COMMA(CMPL(N)) VALS(CMPL(N))>), (EXPR(N)<ENUM(N, VAL(N) BAR)>::type)); \
    ASSERT((metal::invoke_t<LIFT_T(M, FUN(INC(N))), ENUM(INC(N), QUOTE_T(M, VAL(N)) BAR)>), (EXPR(INC(N))<ENUM(INC(N), VAL(N) BAR)>::type)); \
/**/

GEN(MATRIX)
