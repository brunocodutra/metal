// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::mod> COMMA(M) VALUES(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::mod> COMMA(M) VALUES(M) COMMA(N) NUMBERS(N)>), (BOOL(!M && N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::mod> COMMA(M) VALUES(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::mod> COMMA(M) VALUES(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::mod> COMMA(M) VALUES(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::mod> COMMA(M) VALUES(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::mod> COMMA(M) NUMBERS(M) COMMA(N) VALUES(N)>), (BOOL(M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::mod> COMMA(M) NUMBERS(M) COMMA(N) NUMBERS(N)>), (BOOL((M && !N) || (!M && N)))); \
    CHECK((metal::is_invocable<metal::lambda<metal::mod> COMMA(M) NUMBERS(M) COMMA(N) PAIRS(N)>), (BOOL(M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::mod> COMMA(M) NUMBERS(M) COMMA(N) LISTS(N)>), (BOOL(M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::mod> COMMA(M) NUMBERS(M) COMMA(N) MAPS(N)>), (BOOL(M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::mod> COMMA(M) NUMBERS(M) COMMA(N) LAMBDAS(N)>), (BOOL(M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::mod> COMMA(M) PAIRS(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::mod> COMMA(M) PAIRS(M) COMMA(N) NUMBERS(N)>), (BOOL(!M && N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::mod> COMMA(M) PAIRS(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::mod> COMMA(M) PAIRS(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::mod> COMMA(M) PAIRS(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::mod> COMMA(M) PAIRS(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::mod> COMMA(M) LISTS(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::mod> COMMA(M) LISTS(M) COMMA(N) NUMBERS(N)>), (BOOL(!M && N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::mod> COMMA(M) LISTS(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::mod> COMMA(M) LISTS(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::mod> COMMA(M) LISTS(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::mod> COMMA(M) LISTS(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::mod> COMMA(M) MAPS(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::mod> COMMA(M) MAPS(M) COMMA(N) NUMBERS(N)>), (BOOL(!M && N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::mod> COMMA(M) MAPS(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::mod> COMMA(M) MAPS(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::mod> COMMA(M) MAPS(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::mod> COMMA(M) MAPS(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::mod> COMMA(M) LAMBDAS(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::mod> COMMA(M) LAMBDAS(M) COMMA(N) NUMBERS(N)>), (BOOL(!M && N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::mod> COMMA(M) LAMBDAS(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::mod> COMMA(M) LAMBDAS(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::mod> COMMA(M) LAMBDAS(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::mod> COMMA(M) LAMBDAS(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::mod<NUMBER(M) COMMA(N) ENUM(N, NUMBER LIFT(INC))>), (NUMBER(IF(N)(0, M)))); \
/**/

GEN(MATRIX)
