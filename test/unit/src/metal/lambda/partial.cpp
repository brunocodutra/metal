// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, VALUE(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, VALUE(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, VALUE(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, VALUE(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, VALUE(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, VALUE(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, NUMBER(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, NUMBER(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, NUMBER(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, NUMBER(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, NUMBER(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, NUMBER(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, PAIR(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, PAIR(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, PAIR(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, PAIR(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, PAIR(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, PAIR(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, LIST(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, LIST(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, LIST(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, LIST(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, LIST(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, LIST(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, MAP(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, MAP(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, MAP(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, MAP(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, MAP(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, MAP(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, LAMBDA(M) COMMA(N) VALUES(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, LAMBDA(M) COMMA(N) NUMBERS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, LAMBDA(M) COMMA(N) PAIRS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, LAMBDA(M) COMMA(N) LISTS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, LAMBDA(M) COMMA(N) MAPS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, LAMBDA(M) COMMA(N) LAMBDAS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, LAMBDA(_) COMMA(N) VALUES(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, LAMBDA(_) COMMA(N) NUMBERS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, LAMBDA(_) COMMA(N) PAIRS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, LAMBDA(_) COMMA(N) LISTS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, LAMBDA(_) COMMA(N) MAPS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::partial>, LAMBDA(_) COMMA(N) LAMBDAS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::partial<LAMBDA(M) COMMA(N) ENUM(N, LAMBDA FIX(M))> COMMA(N) VALUES(N)>), (BOOL(M == 2*N))); \
    CHECK((metal::invoke<metal::partial<LAMBDA(_) COMMA(M) ENUM(M, LAMBDA FIX(N))> COMMA(CMPL(M)) VALUES(CMPL(M))>), (EXPR(_)<ENUM(M, LAMBDA FIX(N)) COMMA(AND(M, CMPL(M))) VALUES(CMPL(M))>)); \
/**/

GEN(MATRIX)
