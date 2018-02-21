// Copyright Bruno Dutra 2015-2018
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define ENTRY(M, N, ...) EXPR(_)<__VA_ARGS__, ENUM(N, VALUE FIX(M))>

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, VALUE(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, VALUE(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, VALUE(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, VALUE(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, VALUE(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, VALUE(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, NUMBER(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, NUMBER(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, NUMBER(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, NUMBER(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, NUMBER(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, NUMBER(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, PAIR(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, PAIR(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, PAIR(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, PAIR(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, PAIR(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, PAIR(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LIST(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LIST(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LIST(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LIST(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LIST(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LIST(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, MAP(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, MAP(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, MAP(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, MAP(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, MAP(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, MAP(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LAMBDA(M) COMMA(N) VALUES(N)>), (BOOL(N == 1 || (M == 2 && N)))); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LAMBDA(M) COMMA(N) NUMBERS(N)>), (BOOL(N == 1 || (M == 2 && N)))); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LAMBDA(M) COMMA(N) PAIRS(N)>), (BOOL(N == 1 || (M == 2 && N)))); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LAMBDA(M) COMMA(N) LISTS(N)>), (BOOL(N == 1 || (M == 2 && N)))); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LAMBDA(M) COMMA(N) MAPS(N)>), (BOOL(N == 1 || (M == 2 && N)))); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LAMBDA(M) COMMA(N) LAMBDAS(N)>), (BOOL(N == 1 || (M == 2 && N)))); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LAMBDA(_) COMMA(N) VALUES(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LAMBDA(_) COMMA(N) NUMBERS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LAMBDA(_) COMMA(N) PAIRS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LAMBDA(_) COMMA(N) LISTS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LAMBDA(_) COMMA(N) MAPS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LAMBDA(_) COMMA(N) LAMBDAS(N)>), (BOOL(N > 0))); \
    CHECK((metal::fold_left<LAMBDA(_), VALUE(M) COMMA(N) VALUES(N)>), (FOLD_LEFT(N, 1, ENTRY, VALUE(M)))); \
    CHECK((metal::fold_left<LAMBDA(2), NUMBER(2) COMMA(M) TAGSX20(M) COMMA(N) TAGSX20(N)>), (NUMBER(2))); \
/**/

GEN(MATRIX)

