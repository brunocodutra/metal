// Copyright Bruno Dutra 2015-2018
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, VALUE(INC(M)) COMMA(N) ENUM(N, VALUE FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, VALUE(INC(M)) COMMA(N) ENUM(N, NUMBER FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, VALUE(INC(M)) COMMA(N) ENUM(N, PAIR FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, VALUE(INC(M)) COMMA(N) ENUM(N, LIST FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, VALUE(INC(M)) COMMA(N) ENUM(N, MAP FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, VALUE(INC(M)) COMMA(N) ENUM(N, LAMBDA FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, NUMBER(INC(M)) COMMA(N) ENUM(N, VALUE FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, NUMBER(INC(M)) COMMA(N) ENUM(N, NUMBER FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, NUMBER(INC(M)) COMMA(N) ENUM(N, PAIR FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, NUMBER(INC(M)) COMMA(N) ENUM(N, LIST FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, NUMBER(INC(M)) COMMA(N) ENUM(N, MAP FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, NUMBER(INC(M)) COMMA(N) ENUM(N, LAMBDA FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, PAIR(INC(M)) COMMA(N) ENUM(N, VALUE FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, PAIR(INC(M)) COMMA(N) ENUM(N, NUMBER FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, PAIR(INC(M)) COMMA(N) ENUM(N, PAIR FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, PAIR(INC(M)) COMMA(N) ENUM(N, LIST FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, PAIR(INC(M)) COMMA(N) ENUM(N, MAP FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, PAIR(INC(M)) COMMA(N) ENUM(N, LAMBDA FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LIST(INC(M)) COMMA(N) ENUM(N, VALUE FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LIST(INC(M)) COMMA(N) ENUM(N, NUMBER FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LIST(INC(M)) COMMA(N) ENUM(N, PAIR FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LIST(INC(M)) COMMA(N) ENUM(N, LIST FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LIST(INC(M)) COMMA(N) ENUM(N, MAP FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LIST(INC(M)) COMMA(N) ENUM(N, LAMBDA FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, MAP(INC(M)) COMMA(N) ENUM(N, VALUE FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, MAP(INC(M)) COMMA(N) ENUM(N, NUMBER FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, MAP(INC(M)) COMMA(N) ENUM(N, PAIR FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, MAP(INC(M)) COMMA(N) ENUM(N, LIST FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, MAP(INC(M)) COMMA(N) ENUM(N, MAP FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, MAP(INC(M)) COMMA(N) ENUM(N, LAMBDA FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LAMBDA(INC(M)) COMMA(N) ENUM(N, VALUE FIX(M)), LIST(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LAMBDA(INC(M)) COMMA(N) ENUM(N, NUMBER FIX(M)), LIST(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LAMBDA(INC(M)) COMMA(N) ENUM(N, PAIR FIX(M)), LIST(N)>), (BOOL((M == 2 && M == N) || !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LAMBDA(INC(M)) COMMA(N) ENUM(N, LIST FIX(M)), LIST(N)>), (BOOL(!N || M == N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LAMBDA(INC(M)) COMMA(N) ENUM(N, MAP FIX(M)), LIST(N)>), (BOOL(!N || M == N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LAMBDA(INC(M)) COMMA(N) ENUM(N, LAMBDA FIX(M)), LIST(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LAMBDA(_) COMMA(N) ENUM(N, VALUE FIX(M)), LIST(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LAMBDA(_) COMMA(N) ENUM(N, NUMBER FIX(M)), LIST(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LAMBDA(_) COMMA(N) ENUM(N, PAIR FIX(M)), LIST(N)>), (BOOL(N == 2 || !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LAMBDA(_) COMMA(N) ENUM(N, LIST FIX(M)), LIST(N)>), (BOOL(!N || M == N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LAMBDA(_) COMMA(N) ENUM(N, MAP FIX(M)), LIST(N)>), (BOOL(!N || M == N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LAMBDA(_) COMMA(N) ENUM(N, LAMBDA FIX(M)), LIST(N)>), (BOOL(!N))); \
    CHECK((metal::transform<LAMBDA(INC(M)), PAIRS(INC(M))>), (metal::list<EXPR(INC(M))<NUMBERS(INC(M))>, EXPR(INC(M))<VALUES(INC(M))>>)); \
    CHECK((metal::transform<LAMBDA(INC(M)), ENUM(INC(M), LIST FIX(N))>), (metal::list<ENUM(N, NUMBER FIX(INC(M)))>)); \
    CHECK((metal::transform<LAMBDA(_), PAIRS(INC(M))>), (metal::list<EXPR(_)<NUMBERS(INC(M))>, EXPR(_)<VALUES(INC(M))>>)); \
/**/

GEN(MATRIX)
