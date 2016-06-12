// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/number/min.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, VAL(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, VAL(M) COMMA(N) NUMS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, VAL(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, VAL(M) COMMA(N) VECTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, VAL(M) COMMA(N) LISTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, VAL(M) COMMA(N) MAPS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, VAL(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, NUM(M) COMMA(N) VALS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, NUM(M) COMMA(N) NUMS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, NUM(M) COMMA(N) PAIRS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, NUM(M) COMMA(N) VECTS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, NUM(M) COMMA(N) LISTS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, NUM(M) COMMA(N) MAPS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, NUM(M) COMMA(N) LBDS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, PAIR(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, PAIR(M) COMMA(N) NUMS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, PAIR(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, PAIR(M) COMMA(N) VECTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, PAIR(M) COMMA(N) LISTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, PAIR(M) COMMA(N) MAPS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, PAIR(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, VECT(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, VECT(M) COMMA(N) NUMS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, VECT(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, VECT(M) COMMA(N) VECTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, VECT(M) COMMA(N) LISTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, VECT(M) COMMA(N) MAPS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, VECT(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, LIST(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, LIST(M) COMMA(N) NUMS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, LIST(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, LIST(M) COMMA(N) VECTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, LIST(M) COMMA(N) LISTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, LIST(M) COMMA(N) MAPS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, LIST(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, MAP(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, MAP(M) COMMA(N) NUMS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, MAP(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, MAP(M) COMMA(N) VECTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, MAP(M) COMMA(N) LISTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, MAP(M) COMMA(N) MAPS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, MAP(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, LBD(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, LBD(M) COMMA(N) NUMS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, LBD(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, LBD(M) COMMA(N) VECTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, LBD(M) COMMA(N) LISTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, LBD(M) COMMA(N) MAPS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, LBD(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, LBD(_) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, LBD(_) COMMA(N) NUMS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, LBD(_) COMMA(N) PAIRS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, LBD(_) COMMA(N) VECTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, LBD(_) COMMA(N) LISTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, LBD(_) COMMA(N) MAPS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::min>, LBD(_) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::min<NUM(M) COMMA(N) NUMS(N)>), (NUMBER(N ? 0 : M, test::value_type<NUM(M) COMMA(N) ENUM(N, NUM)>))); \
/**/

GEN(MATRIX)
