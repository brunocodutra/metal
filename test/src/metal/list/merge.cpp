// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/merge.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/less.hpp>
#include <metal/number/greater.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, VAL(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, VAL(M) COMMA(N) NUMS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, VAL(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, VAL(M) COMMA(N) VECTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, VAL(M) COMMA(N) LISTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, VAL(M) COMMA(N) MAPS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, VAL(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, NUM(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, NUM(M) COMMA(N) NUMS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, NUM(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, NUM(M) COMMA(N) VECTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, NUM(M) COMMA(N) LISTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, NUM(M) COMMA(N) MAPS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, NUM(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, PAIR(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, PAIR(M) COMMA(N) NUMS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, PAIR(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, PAIR(M) COMMA(N) VECTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, PAIR(M) COMMA(N) LISTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, PAIR(M) COMMA(N) MAPS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, PAIR(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, VECT(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, VECT(M) COMMA(N) NUMS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, VECT(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, VECT(M) COMMA(N) VECTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, VECT(M) COMMA(N) LISTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, VECT(M) COMMA(N) MAPS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, VECT(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, LIST(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, LIST(M) COMMA(N) NUMS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, LIST(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, LIST(M) COMMA(N) VECTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, LIST(M) COMMA(N) LISTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, LIST(M) COMMA(N) MAPS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, LIST(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, MAP(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, MAP(M) COMMA(N) NUMS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, MAP(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, MAP(M) COMMA(N) VECTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, MAP(M) COMMA(N) LISTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, MAP(M) COMMA(N) MAPS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, MAP(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, LBD(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, LBD(M) COMMA(N) NUMS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, LBD(M) COMMA(N) PAIRS(N)>), (BOOL(N == 1))); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, LBD(M) COMMA(N) VECTS(N)>), (BOOL((N == 1) || (M == 2 && N > 1)))); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, LBD(M) COMMA(N) LISTS(N)>), (BOOL((N > 0 && N <= 2) || (M == 2 && N)))); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, LBD(M) COMMA(N) MAPS(N)>), (BOOL(N == 1))); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, LBD(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, LBD(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, LBD(M) COMMA(N) NUMS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, LBD(_) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, LBD(_) COMMA(N) NUMS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, LBD(_) COMMA(N) PAIRS(N)>), (BOOL(N == 1))); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, LBD(_) COMMA(N) VECTS(N)>), (BOOL(N == 1))); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, LBD(_) COMMA(N) LISTS(N)>), (BOOL(N > 0 && N <= 2))); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, LBD(_) COMMA(N) MAPS(N)>), (BOOL(N == 1))); \
    ASSERT((metal::is_invocable<test::lambda<metal::merge>, LBD(_) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::merge<test::lambda<metal::less>, RENUM(INC(M), REST, test::list<NUMS(INF)>)>), (test::list<ENUM(INF, FWD, RENUM(INC(M), NUM NIL))>)); \
/**/

GEN(MATRIX)
