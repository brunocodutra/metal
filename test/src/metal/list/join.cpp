// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/join.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, VAL(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, VAL(M) COMMA(N) NUMS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, VAL(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, VAL(M) COMMA(N) LISTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, VAL(M) COMMA(N) MAPS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, VAL(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, NUM(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, NUM(M) COMMA(N) NUMS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, NUM(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, NUM(M) COMMA(N) LISTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, NUM(M) COMMA(N) MAPS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, NUM(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, PAIR(M) COMMA(N) VALS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, PAIR(M) COMMA(N) NUMS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, PAIR(M) COMMA(N) PAIRS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, PAIR(M) COMMA(N) LISTS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, PAIR(M) COMMA(N) MAPS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, PAIR(M) COMMA(N) LBDS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, LIST(M) COMMA(N) VALS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, LIST(M) COMMA(N) NUMS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, LIST(M) COMMA(N) PAIRS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, LIST(M) COMMA(N) LISTS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, LIST(M) COMMA(N) MAPS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, LIST(M) COMMA(N) LBDS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, MAP(M) COMMA(N) VALS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, MAP(M) COMMA(N) NUMS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, MAP(M) COMMA(N) PAIRS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, MAP(M) COMMA(N) LISTS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, MAP(M) COMMA(N) MAPS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, MAP(M) COMMA(N) LBDS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, LBD(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, LBD(M) COMMA(N) NUMS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, LBD(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, LBD(M) COMMA(N) LISTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, LBD(M) COMMA(N) MAPS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, LBD(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, LBD(_) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, LBD(_) COMMA(N) NUMS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, LBD(_) COMMA(N) PAIRS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, LBD(_) COMMA(N) LISTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, LBD(_) COMMA(N) MAPS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::join>, LBD(_) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::join<PAIR(M) COMMA(N) PAIRS(N)>), (metal::list<NUM(M), VAL(M) COMMA(N) ENUM(N, FWD, NUM, VAL)>)); \
    ASSERT((metal::join<PAIR(M) COMMA(N) LISTS(N)>), (metal::list<NUM(M), VAL(M) ENUM(N, VALS)>)); \
    ASSERT((metal::join<PAIR(M) COMMA(N) MAPS(N)>), (metal::list<NUM(M), VAL(M) ENUM(N, PAIRS)>)); \
/**/

GEN(MATRIX)
