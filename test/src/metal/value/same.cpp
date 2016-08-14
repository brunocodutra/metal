// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/value/same.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) VALS(M) COMMA(AND(M, N)) VALS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) VALS(M) COMMA(AND(M, N)) NUMS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) VALS(M) COMMA(AND(M, N)) PAIRS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) VALS(M) COMMA(AND(M, N)) LISTS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) VALS(M) COMMA(AND(M, N)) MAPS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) VALS(M) COMMA(AND(M, N)) LBDS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) NUMS(M) COMMA(AND(M, N)) VALS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) NUMS(M) COMMA(AND(M, N)) NUMS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) NUMS(M) COMMA(AND(M, N)) PAIRS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) NUMS(M) COMMA(AND(M, N)) LISTS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) NUMS(M) COMMA(AND(M, N)) MAPS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) NUMS(M) COMMA(AND(M, N)) LBDS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) PAIRS(M) COMMA(AND(M, N)) VALS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) PAIRS(M) COMMA(AND(M, N)) NUMS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) PAIRS(M) COMMA(AND(M, N)) PAIRS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) PAIRS(M) COMMA(AND(M, N)) LISTS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) PAIRS(M) COMMA(AND(M, N)) MAPS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) PAIRS(M) COMMA(AND(M, N)) LBDS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) LISTS(M) COMMA(AND(M, N)) VALS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) LISTS(M) COMMA(AND(M, N)) NUMS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) LISTS(M) COMMA(AND(M, N)) PAIRS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) LISTS(M) COMMA(AND(M, N)) LISTS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) LISTS(M) COMMA(AND(M, N)) MAPS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) LISTS(M) COMMA(AND(M, N)) LBDS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) MAPS(M) COMMA(AND(M, N)) VALS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) MAPS(M) COMMA(AND(M, N)) NUMS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) MAPS(M) COMMA(AND(M, N)) PAIRS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) MAPS(M) COMMA(AND(M, N)) LISTS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) MAPS(M) COMMA(AND(M, N)) MAPS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) MAPS(M) COMMA(AND(M, N)) LBDS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) LBDS(M) COMMA(AND(M, N)) VALS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) LBDS(M) COMMA(AND(M, N)) NUMS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) LBDS(M) COMMA(AND(M, N)) PAIRS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) LBDS(M) COMMA(AND(M, N)) LISTS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) LBDS(M) COMMA(AND(M, N)) MAPS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::same> COMMA(OR(M, N)) LBDS(M) COMMA(AND(M, N)) LBDS(N)>), (TRUE)); \
    CHECK((metal::same<VALS(M) COMMA(AND(M, N)) VALS(N)>), (BOOL(M < 2 && N < 2))); \
    CHECK((metal::same<ENUM(M, VAL FIX(N))>), (TRUE)); \
/**/

GEN(MATRIX)

