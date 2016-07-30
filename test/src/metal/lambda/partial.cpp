// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/lambda/partial.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/list/list.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, VAL(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, VAL(M) COMMA(N) NUMS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, VAL(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, VAL(M) COMMA(N) LISTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, VAL(M) COMMA(N) MAPS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, VAL(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, NUM(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, NUM(M) COMMA(N) NUMS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, NUM(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, NUM(M) COMMA(N) LISTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, NUM(M) COMMA(N) MAPS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, NUM(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, PAIR(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, PAIR(M) COMMA(N) NUMS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, PAIR(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, PAIR(M) COMMA(N) LISTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, PAIR(M) COMMA(N) MAPS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, PAIR(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, LIST(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, LIST(M) COMMA(N) NUMS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, LIST(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, LIST(M) COMMA(N) LISTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, LIST(M) COMMA(N) MAPS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, LIST(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, MAP(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, MAP(M) COMMA(N) NUMS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, MAP(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, MAP(M) COMMA(N) LISTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, MAP(M) COMMA(N) MAPS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, MAP(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, LBD(M) COMMA(N) VALS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, LBD(M) COMMA(N) NUMS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, LBD(M) COMMA(N) PAIRS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, LBD(M) COMMA(N) LISTS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, LBD(M) COMMA(N) MAPS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, LBD(M) COMMA(N) LBDS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, LBD(_) COMMA(N) VALS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, LBD(_) COMMA(N) NUMS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, LBD(_) COMMA(N) PAIRS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, LBD(_) COMMA(N) LISTS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, LBD(_) COMMA(N) MAPS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partial>, LBD(_) COMMA(N) LBDS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::partial<LBD(M) COMMA(N) ENUM(N, LBD FIX(M))> COMMA(N) VALS(N)>), (BOOL(M == 2*N))); \
    ASSERT((metal::invoke<metal::partial<LBD(_) COMMA(M) ENUM(M, LBD FIX(N))> COMMA(CMPL(M)) VALS(CMPL(M))>), (EXPR(_)<ENUM(M, LBD FIX(N)) COMMA(AND(M, CMPL(M))) VALS(CMPL(M))>)); \
/**/

GEN(MATRIX)
