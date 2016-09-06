// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/value/distinct.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct> COMMA(OR(M, N)) VALUES(M) COMMA(AND(M, N)) VALUES(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct> COMMA(OR(M, N)) VALUES(M) COMMA(AND(M, N)) NUMBERS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct> COMMA(OR(M, N)) VALUES(M) COMMA(AND(M, N)) PAIRS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct> COMMA(OR(M, N)) VALUES(M) COMMA(AND(M, N)) LISTS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct> COMMA(OR(M, N)) VALUES(M) COMMA(AND(M, N)) MAPS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct> COMMA(OR(M, N)) VALUES(M) COMMA(AND(M, N)) LAMBDAS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct> COMMA(OR(M, N)) NUMBERS(M) COMMA(AND(M, N)) VALUES(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct> COMMA(OR(M, N)) NUMBERS(M) COMMA(AND(M, N)) NUMBERS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct> COMMA(OR(M, N)) NUMBERS(M) COMMA(AND(M, N)) PAIRS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct> COMMA(OR(M, N)) NUMBERS(M) COMMA(AND(M, N)) LISTS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct> COMMA(OR(M, N)) NUMBERS(M) COMMA(AND(M, N)) MAPS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct> COMMA(OR(M, N)) NUMBERS(M) COMMA(AND(M, N)) LAMBDAS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct> COMMA(OR(M, N)) PAIRS(M) COMMA(AND(M, N)) VALUES(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct> COMMA(OR(M, N)) PAIRS(M) COMMA(AND(M, N)) NUMBERS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct> COMMA(OR(M, N)) PAIRS(M) COMMA(AND(M, N)) PAIRS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct> COMMA(OR(M, N)) PAIRS(M) COMMA(AND(M, N)) LISTS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct> COMMA(OR(M, N)) PAIRS(M) COMMA(AND(M, N)) MAPS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct> COMMA(OR(M, N)) PAIRS(M) COMMA(AND(M, N)) LAMBDAS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct> COMMA(OR(M, N)) LISTS(M) COMMA(AND(M, N)) VALUES(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct> COMMA(OR(M, N)) LISTS(M) COMMA(AND(M, N)) NUMBERS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct> COMMA(OR(M, N)) LISTS(M) COMMA(AND(M, N)) PAIRS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct> COMMA(OR(M, N)) LISTS(M) COMMA(AND(M, N)) LISTS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct> COMMA(OR(M, N)) LISTS(M) COMMA(AND(M, N)) MAPS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct> COMMA(OR(M, N)) LISTS(M) COMMA(AND(M, N)) LAMBDAS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct> COMMA(OR(M, N)) MAPS(M) COMMA(AND(M, N)) VALUES(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct> COMMA(OR(M, N)) MAPS(M) COMMA(AND(M, N)) NUMBERS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct> COMMA(OR(M, N)) MAPS(M) COMMA(AND(M, N)) PAIRS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct> COMMA(OR(M, N)) MAPS(M) COMMA(AND(M, N)) LISTS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct> COMMA(OR(M, N)) MAPS(M) COMMA(AND(M, N)) MAPS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct> COMMA(OR(M, N)) MAPS(M) COMMA(AND(M, N)) LAMBDAS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct> COMMA(OR(M, N)) LAMBDAS(M) COMMA(AND(M, N)) VALUES(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct> COMMA(OR(M, N)) LAMBDAS(M) COMMA(AND(M, N)) NUMBERS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct> COMMA(OR(M, N)) LAMBDAS(M) COMMA(AND(M, N)) PAIRS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct> COMMA(OR(M, N)) LAMBDAS(M) COMMA(AND(M, N)) LISTS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct> COMMA(OR(M, N)) LAMBDAS(M) COMMA(AND(M, N)) MAPS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct> COMMA(OR(M, N)) LAMBDAS(M) COMMA(AND(M, N)) LAMBDAS(N)>), (TRUE)); \
    CHECK((metal::distinct<VALUES(M) COMMA(AND(M, N)) VALUES(N)>), (BOOL(!M || !N))); \
    CHECK((metal::distinct<ENUM(M, VALUE FIX(N))>), (BOOL(M < 2))); \
/**/

GEN(MATRIX)

