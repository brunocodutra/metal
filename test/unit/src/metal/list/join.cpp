// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, VALUE(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, VALUE(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, VALUE(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, VALUE(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, VALUE(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, VALUE(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, NUMBER(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, NUMBER(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, NUMBER(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, NUMBER(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, NUMBER(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, NUMBER(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, PAIR(M) COMMA(N) VALUES(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, PAIR(M) COMMA(N) NUMBERS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, PAIR(M) COMMA(N) PAIRS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, PAIR(M) COMMA(N) LISTS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, PAIR(M) COMMA(N) MAPS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, PAIR(M) COMMA(N) LAMBDAS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, LIST(M) COMMA(N) VALUES(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, LIST(M) COMMA(N) NUMBERS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, LIST(M) COMMA(N) PAIRS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, LIST(M) COMMA(N) LISTS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, LIST(M) COMMA(N) MAPS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, LIST(M) COMMA(N) LAMBDAS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, MAP(M) COMMA(N) VALUES(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, MAP(M) COMMA(N) NUMBERS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, MAP(M) COMMA(N) PAIRS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, MAP(M) COMMA(N) LISTS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, MAP(M) COMMA(N) MAPS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, MAP(M) COMMA(N) LAMBDAS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, LAMBDA(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, LAMBDA(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, LAMBDA(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, LAMBDA(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, LAMBDA(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, LAMBDA(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, LAMBDA(_) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, LAMBDA(_) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, LAMBDA(_) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, LAMBDA(_) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, LAMBDA(_) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, LAMBDA(_) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::join<PAIRS(M) COMMA(AND(M, N)) PAIRS(N)>), (metal::list<ENUM(M, FWD, NUMBER, VALUE) COMMA(AND(M, N)) ENUM(N, FWD, NUMBER, VALUE)>)); \
    CHECK((metal::join<PAIR(M) COMMA(N) LISTS(N)>), (metal::list<NUMBER(M), VALUE(M) ENUM(N, VALUES)>)); \
    CHECK((metal::join<PAIR(M) COMMA(N) MAPS(N)>), (metal::list<NUMBER(M), VALUE(M) ENUM(N, PAIRS)>)); \
    CHECK((metal::join<ENUM(M, LIST FIX(INC(N))) COMMA(M) ENUM(INC(N), LIST FIX(0))>), (metal::list<ENUM(M, VALUES FIX(INC(N)))>)); \
/**/

GEN(MATRIX)
