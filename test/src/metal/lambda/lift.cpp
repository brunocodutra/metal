// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/lambda/lift.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/optional/optional.hpp>

#include "test.hpp"

#define LIFT_T(_, ...) metal::lift_t<__VA_ARGS__>
#define QUOTE_T(_, ...) metal::quote_t<__VA_ARGS__>
#define BOX(N) RECURSE(N, QUOTE_T, VAL(N))

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::invoke<RECURSE(M, LIFT_T, VAL(N)), BOX(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::invoke<RECURSE(M, LIFT_T, NUM(N)), BOX(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::invoke<RECURSE(M, LIFT_T, PAIR(N)), BOX(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::invoke<RECURSE(M, LIFT_T, LIST(N)), BOX(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::invoke<RECURSE(M, LIFT_T, MAP(N)), BOX(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::invoke<RECURSE(M, LIFT_T, ARG(N)), ENUM(LIMIT, LIFT(BOX))>>), (BOOL(M <= N))); \
    ASSERT((metal::is_just_t<metal::invoke<RECURSE(M, LIFT_T, LBD(N)) COMMA(N) ENUM(N, BOX(N) BAR) COMMA(CMPL(N)) VALS(CMPL(N))>>), (BOOL(!N || M <= N))); \
    ASSERT((metal::is_just_t<metal::invoke<RECURSE(M, LIFT_T, FUN(INC(N))), ENUM(INC(N), BOX(N) BAR)>>), (BOOL(M <= N))); \
    ASSERT((metal::is_just_t<metal::invoke<RECURSE(M, LIFT_T, metal::lambda<SEQ(INC(N)>)), ENUM(INC(N), BOX(N) BAR)>>), (FALSE)); \
    ASSERT((metal::invoke_t<RECURSE(M, LIFT_T, VAL(N)), BOX(N)>), (VAL(N))); \
    ASSERT((metal::invoke_t<RECURSE(M, LIFT_T, NUM(N)), BOX(N)>), (NUM(N))); \
    ASSERT((metal::invoke_t<RECURSE(M, LIFT_T, ARG(N)) COMMA(N) ENUM(N, LIFT(VAL)), BOX(M) COMMA(CMPL(N)) VALS(CMPL(N))>), (VAL(M))); \
    ASSERT((metal::invoke_t<RECURSE(M, LIFT_T, LBD(N)) COMMA(N) ENUM(N, BOX(M) BAR) COMMA(CMPL(N)) VALS(CMPL(N))>), (EXPR(N)<ENUM(N, VAL(M) BAR)>::type)); \
    ASSERT((metal::invoke_t<RECURSE(M, LIFT_T, FUN(INC(N))), ENUM(INC(N), BOX(M) BAR)>), (EXPR(INC(N))<ENUM(INC(N), VAL(M) BAR)>::type)); \
/**/

GEN(MATRIX)
