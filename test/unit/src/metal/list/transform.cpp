// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, VALUE(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, VALUE(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, VALUE(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, VALUE(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, VALUE(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, VALUE(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, NUMBER(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, NUMBER(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, NUMBER(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, NUMBER(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, NUMBER(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, NUMBER(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, PAIR(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, PAIR(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, PAIR(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, PAIR(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, PAIR(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, PAIR(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LIST(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LIST(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LIST(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LIST(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LIST(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LIST(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, MAP(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, MAP(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, MAP(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, MAP(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, MAP(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, MAP(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LAMBDA(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LAMBDA(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LAMBDA(M) COMMA(N) PAIRS(N)>), (BOOL(M == N && N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LAMBDA(M) COMMA(N) LISTS(N)>), (BOOL(N == 1))); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LAMBDA(M) COMMA(N) MAPS(N)>), (BOOL(N == 1))); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LAMBDA(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LAMBDA(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LAMBDA(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LAMBDA(_) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LAMBDA(_) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LAMBDA(_) COMMA(N) PAIRS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LAMBDA(_) COMMA(N) LISTS(N)>), (BOOL(N == 1))); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LAMBDA(_) COMMA(N) MAPS(N)>), (BOOL(N == 1))); \
    CHECK((metal::is_invocable<metal::lambda<metal::transform>, LAMBDA(_) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::transform<LAMBDA(INC(M)), PAIRS(INC(M))>), (metal::list<EXPR(INC(M))<NUMBERS(INC(M))>, EXPR(INC(M))<VALUES(INC(M))>>)); \
    CHECK((metal::transform<LAMBDA(INC(M)), ENUM(INC(M), LIST FIX(N))>), (metal::list<ENUM(N, NUMBER FIX(INC(M)))>)); \
    CHECK((metal::transform<LAMBDA(_), PAIRS(INC(M))>), (metal::list<EXPR(_)<NUMBERS(INC(M))>, EXPR(_)<VALUES(INC(M))>>)); \
/**/

GEN(MATRIX)
