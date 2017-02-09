// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) VALUES(M) COMMA(AND(M, N)) VALUES(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) VALUES(M) COMMA(AND(M, N)) NUMBERS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) VALUES(M) COMMA(AND(M, N)) PAIRS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) VALUES(M) COMMA(AND(M, N)) LISTS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) VALUES(M) COMMA(AND(M, N)) MAPS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) VALUES(M) COMMA(AND(M, N)) LAMBDAS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) NUMBERS(M) COMMA(AND(M, N)) VALUES(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) NUMBERS(M) COMMA(AND(M, N)) NUMBERS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) NUMBERS(M) COMMA(AND(M, N)) PAIRS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) NUMBERS(M) COMMA(AND(M, N)) LISTS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) NUMBERS(M) COMMA(AND(M, N)) MAPS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) NUMBERS(M) COMMA(AND(M, N)) LAMBDAS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) PAIRS(M) COMMA(AND(M, N)) VALUES(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) PAIRS(M) COMMA(AND(M, N)) NUMBERS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) PAIRS(M) COMMA(AND(M, N)) PAIRS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) PAIRS(M) COMMA(AND(M, N)) LISTS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) PAIRS(M) COMMA(AND(M, N)) MAPS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) PAIRS(M) COMMA(AND(M, N)) LAMBDAS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) LISTS(M) COMMA(AND(M, N)) VALUES(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) LISTS(M) COMMA(AND(M, N)) NUMBERS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) LISTS(M) COMMA(AND(M, N)) PAIRS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) LISTS(M) COMMA(AND(M, N)) LISTS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) LISTS(M) COMMA(AND(M, N)) MAPS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) LISTS(M) COMMA(AND(M, N)) LAMBDAS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) MAPS(M) COMMA(AND(M, N)) VALUES(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) MAPS(M) COMMA(AND(M, N)) NUMBERS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) MAPS(M) COMMA(AND(M, N)) PAIRS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) MAPS(M) COMMA(AND(M, N)) LISTS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) MAPS(M) COMMA(AND(M, N)) MAPS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) MAPS(M) COMMA(AND(M, N)) LAMBDAS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) LAMBDAS(M) COMMA(AND(M, N)) VALUES(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) LAMBDAS(M) COMMA(AND(M, N)) NUMBERS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) LAMBDAS(M) COMMA(AND(M, N)) PAIRS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) LAMBDAS(M) COMMA(AND(M, N)) LISTS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) LAMBDAS(M) COMMA(AND(M, N)) MAPS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) LAMBDAS(M) COMMA(AND(M, N)) LAMBDAS(N)>), (TRUE)); \
    CHECK((metal::same<VALUES(M) COMMA(AND(M, N)) VALUES(N)>), (BOOL(M < 2 && N < 2))); \
    CHECK((metal::same<ENUM(M, VALUE FIX(N))>), (TRUE)); \
/**/

GEN(MATRIX)

