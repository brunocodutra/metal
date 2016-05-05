// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/lambda/lift.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/optional/optional.hpp>

#include "test.hpp"

#define LIFT_(_, ...) metal::lift_t<__VA_ARGS__>
#define LIFT(N, ...) RECURSE(N, LIFT_, __VA_ARGS__)

#define QUOTE_(_, ...) metal::quote_t<__VA_ARGS__>
#define QUOTE(N, ...) RECURSE(N, QUOTE_, __VA_ARGS__)

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::invoke<LIFT(M, VAL(N)), QUOTE(N, VAL(N))>>), (BOOL(M <= N))); \
    ASSERT((metal::is_just_t<metal::invoke<LIFT(M, NUM(N)), QUOTE(N, VAL(N))>>), (BOOL(M <= N))); \
    ASSERT((metal::is_just_t<metal::invoke<LIFT(M, PAIR(N)), QUOTE(N, VAL(N))>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::invoke<LIFT(M, LIST(N)), QUOTE(N, VAL(N))>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::invoke<LIFT(M, MAP(N)), QUOTE(N, VAL(N))>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::invoke<LIFT(M, LBD(N)) COMMA(N) ENUM(N, QUOTE(N, VAL(N)) BAR)>>), (BOOL(!N || M <= N))); \
    ASSERT((metal::is_just_t<metal::invoke<LIFT(M, FUN(N)) COMMA(N) ENUM(N, QUOTE(N, VAL(N)) BAR)>>), (BOOL(!N || M <= N))); \
    ASSERT((metal::invoke_t<LIFT(M, VAL(N)), QUOTE(M, VAL(N))>), (VAL(N))); \
    ASSERT((metal::invoke_t<LIFT(M, NUM(N)), QUOTE(M, VAL(N))>), (NUM(N))); \
    ASSERT((metal::invoke_t<LIFT(M, LBD(N)) COMMA(N) ENUM(N, QUOTE(M, VAL(N)) BAR)>), (EXPR(N)<ENUM(N, VAL(N) BAR)>::type)); \
    ASSERT((metal::invoke_t<LIFT(M, FUN(INC(N))), ENUM(INC(N), QUOTE(M, VAL(N)) BAR)>), (EXPR(INC(N))<ENUM(INC(N), VAL(N) BAR)>::type)); \
/**/

GEN(MATRIX)
