// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/number/sub.hpp>
#include <metal/number/number.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, VAL(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, VAL(M) COMMA(N) NUMS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, VAL(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, VAL(M) COMMA(N) LISTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, VAL(M) COMMA(N) MAPS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, VAL(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, NUM(M) COMMA(N) VALS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, NUM(M) COMMA(N) NUMS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, NUM(M) COMMA(N) PAIRS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, NUM(M) COMMA(N) LISTS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, NUM(M) COMMA(N) MAPS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, NUM(M) COMMA(N) LBDS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, PAIR(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, PAIR(M) COMMA(N) NUMS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, PAIR(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, PAIR(M) COMMA(N) LISTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, PAIR(M) COMMA(N) MAPS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, PAIR(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, LIST(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, LIST(M) COMMA(N) NUMS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, LIST(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, LIST(M) COMMA(N) LISTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, LIST(M) COMMA(N) MAPS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, LIST(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, MAP(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, MAP(M) COMMA(N) NUMS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, MAP(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, MAP(M) COMMA(N) LISTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, MAP(M) COMMA(N) MAPS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, MAP(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, LBD(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, LBD(M) COMMA(N) NUMS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, LBD(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, LBD(M) COMMA(N) LISTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, LBD(M) COMMA(N) MAPS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, LBD(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, LBD(_) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, LBD(_) COMMA(N) NUMS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, LBD(_) COMMA(N) PAIRS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, LBD(_) COMMA(N) LISTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, LBD(_) COMMA(N) MAPS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::sub>, LBD(_) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::sub<NUM(M) COMMA(N) NUMS(N)>), (test::num<test::value_type<NUM(M) COMMA(N) ENUM(N, NUM) COMMA(N) IF(NOT(N))( , INT(0))>, N*(1 - N)/2 + M>)); \
/**/

GEN(MATRIX)
