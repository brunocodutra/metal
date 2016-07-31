// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/join.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, VAL(M) COMMA(N) VALS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, VAL(M) COMMA(N) NUMS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, VAL(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, VAL(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, VAL(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, VAL(M) COMMA(N) LBDS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, NUM(M) COMMA(N) VALS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, NUM(M) COMMA(N) NUMS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, NUM(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, NUM(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, NUM(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, NUM(M) COMMA(N) LBDS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, PAIR(M) COMMA(N) VALS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, PAIR(M) COMMA(N) NUMS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, PAIR(M) COMMA(N) PAIRS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, PAIR(M) COMMA(N) LISTS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, PAIR(M) COMMA(N) MAPS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, PAIR(M) COMMA(N) LBDS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, LIST(M) COMMA(N) VALS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, LIST(M) COMMA(N) NUMS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, LIST(M) COMMA(N) PAIRS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, LIST(M) COMMA(N) LISTS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, LIST(M) COMMA(N) MAPS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, LIST(M) COMMA(N) LBDS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, MAP(M) COMMA(N) VALS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, MAP(M) COMMA(N) NUMS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, MAP(M) COMMA(N) PAIRS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, MAP(M) COMMA(N) LISTS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, MAP(M) COMMA(N) MAPS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, MAP(M) COMMA(N) LBDS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, LBD(M) COMMA(N) VALS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, LBD(M) COMMA(N) NUMS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, LBD(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, LBD(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, LBD(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, LBD(M) COMMA(N) LBDS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, LBD(_) COMMA(N) VALS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, LBD(_) COMMA(N) NUMS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, LBD(_) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, LBD(_) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, LBD(_) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::join>, LBD(_) COMMA(N) LBDS(N)>), (FALSE)); \
    CHECK((metal::join<PAIR(M) COMMA(N) PAIRS(N)>), (metal::list<NUM(M), VAL(M) COMMA(N) ENUM(N, FWD, NUM, VAL)>)); \
    CHECK((metal::join<PAIR(M) COMMA(N) LISTS(N)>), (metal::list<NUM(M), VAL(M) ENUM(N, VALS)>)); \
    CHECK((metal::join<PAIR(M) COMMA(N) MAPS(N)>), (metal::list<NUM(M), VAL(M) ENUM(N, PAIRS)>)); \
/**/

GEN(MATRIX)
