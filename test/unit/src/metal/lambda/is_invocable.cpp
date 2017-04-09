// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<VALUE(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<VALUE(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<VALUE(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<VALUE(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<VALUE(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<VALUE(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<NUMBER(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<NUMBER(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<NUMBER(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<NUMBER(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<NUMBER(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<NUMBER(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<PAIR(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<PAIR(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<PAIR(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<PAIR(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<PAIR(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<PAIR(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<MAP(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<MAP(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<MAP(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<MAP(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<MAP(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<MAP(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<LAMBDA(M) COMMA(N) VALUES(N)>), (BOOL(M == N))); \
    CHECK((metal::is_invocable<LAMBDA(M) COMMA(N) NUMBERS(N)>), (BOOL(M == N))); \
    CHECK((metal::is_invocable<LAMBDA(M) COMMA(N) PAIRS(N)>), (BOOL(M == N))); \
    CHECK((metal::is_invocable<LAMBDA(M) COMMA(N) LISTS(N)>), (BOOL(M == N))); \
    CHECK((metal::is_invocable<LAMBDA(M) COMMA(N) MAPS(N)>), (BOOL(M == N))); \
    CHECK((metal::is_invocable<LAMBDA(M) COMMA(N) LAMBDAS(N)>), (BOOL(M == N))); \
    CHECK((metal::is_invocable<LAMBDA(_) COMMA(N) VALUES(N)>), (TRUE)); \
    CHECK((metal::is_invocable<LAMBDA(_) COMMA(N) NUMBERS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<LAMBDA(_) COMMA(N) PAIRS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<LAMBDA(_) COMMA(N) LISTS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<LAMBDA(_) COMMA(N) MAPS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<LAMBDA(_) COMMA(N) LAMBDAS(N)>), (TRUE)); \
/**/

GEN(MATRIX)
