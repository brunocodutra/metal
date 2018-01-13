// Copyright Bruno Dutra 2015-2018
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::add> COMMA(M) VALUES(M) COMMA(N) VALUES(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add> COMMA(M) VALUES(M) COMMA(N) NUMBERS(N)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add> COMMA(M) VALUES(M) COMMA(N) PAIRS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add> COMMA(M) VALUES(M) COMMA(N) LISTS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add> COMMA(M) VALUES(M) COMMA(N) MAPS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add> COMMA(M) VALUES(M) COMMA(N) LAMBDAS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add> COMMA(M) NUMBERS(M) COMMA(N) VALUES(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add> COMMA(M) NUMBERS(M) COMMA(N) NUMBERS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add> COMMA(M) NUMBERS(M) COMMA(N) PAIRS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add> COMMA(M) NUMBERS(M) COMMA(N) LISTS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add> COMMA(M) NUMBERS(M) COMMA(N) MAPS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add> COMMA(M) NUMBERS(M) COMMA(N) LAMBDAS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add> COMMA(M) PAIRS(M) COMMA(N) VALUES(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add> COMMA(M) PAIRS(M) COMMA(N) NUMBERS(N)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add> COMMA(M) PAIRS(M) COMMA(N) PAIRS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add> COMMA(M) PAIRS(M) COMMA(N) LISTS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add> COMMA(M) PAIRS(M) COMMA(N) MAPS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add> COMMA(M) PAIRS(M) COMMA(N) LAMBDAS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add> COMMA(M) LISTS(M) COMMA(N) VALUES(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add> COMMA(M) LISTS(M) COMMA(N) NUMBERS(N)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add> COMMA(M) LISTS(M) COMMA(N) PAIRS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add> COMMA(M) LISTS(M) COMMA(N) LISTS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add> COMMA(M) LISTS(M) COMMA(N) MAPS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add> COMMA(M) LISTS(M) COMMA(N) LAMBDAS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add> COMMA(M) MAPS(M) COMMA(N) VALUES(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add> COMMA(M) MAPS(M) COMMA(N) NUMBERS(N)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add> COMMA(M) MAPS(M) COMMA(N) PAIRS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add> COMMA(M) MAPS(M) COMMA(N) LISTS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add> COMMA(M) MAPS(M) COMMA(N) MAPS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add> COMMA(M) MAPS(M) COMMA(N) LAMBDAS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add> COMMA(M) LAMBDAS(M) COMMA(N) VALUES(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add> COMMA(M) LAMBDAS(M) COMMA(N) NUMBERS(N)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add> COMMA(M) LAMBDAS(M) COMMA(N) PAIRS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add> COMMA(M) LAMBDAS(M) COMMA(N) LISTS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add> COMMA(M) LAMBDAS(M) COMMA(N) MAPS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add> COMMA(M) LAMBDAS(M) COMMA(N) LAMBDAS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::add<NUMBERS(M) COMMA(AND(M, N)) NUMBERS(N)>), (NUMBER(M*(M - 1)/2 + N*(N - 1)/2))); \
/**/

GEN(MATRIX)
