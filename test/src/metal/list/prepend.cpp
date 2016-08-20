// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/prepend.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, VAL(M) COMMA(N) VALS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, VAL(M) COMMA(N) NUMS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, VAL(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, VAL(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, VAL(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, VAL(M) COMMA(N) LBDS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, NUM(M) COMMA(N) VALS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, NUM(M) COMMA(N) NUMS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, NUM(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, NUM(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, NUM(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, NUM(M) COMMA(N) LBDS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, PAIR(M) COMMA(N) VALS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, PAIR(M) COMMA(N) NUMS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, PAIR(M) COMMA(N) PAIRS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, PAIR(M) COMMA(N) LISTS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, PAIR(M) COMMA(N) MAPS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, PAIR(M) COMMA(N) LBDS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, LIST(M) COMMA(N) VALS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, LIST(M) COMMA(N) NUMS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, LIST(M) COMMA(N) PAIRS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, LIST(M) COMMA(N) LISTS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, LIST(M) COMMA(N) MAPS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, LIST(M) COMMA(N) LBDS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, MAP(M) COMMA(N) VALS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, MAP(M) COMMA(N) NUMS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, MAP(M) COMMA(N) PAIRS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, MAP(M) COMMA(N) LISTS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, MAP(M) COMMA(N) MAPS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, MAP(M) COMMA(N) LBDS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, LBD(M) COMMA(N) VALS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, LBD(M) COMMA(N) NUMS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, LBD(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, LBD(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, LBD(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, LBD(M) COMMA(N) LBDS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, LBD(_) COMMA(N) VALS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, LBD(_) COMMA(N) NUMS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, LBD(_) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, LBD(_) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, LBD(_) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::prepend>, LBD(_) COMMA(N) LBDS(N)>), (FALSE)); \
    CHECK((metal::prepend<PAIR(M), VAL(INC(N))>), (metal::list<VAL(INC(N)), NUM(M), VAL(M)>)); \
    CHECK((metal::prepend<LIST(M), VAL(INC(N))>), (metal::list<VAL(INC(N)) COMMA(M) VALS(M)>)); \
    CHECK((metal::prepend<MAP(M), VAL(INC(N))>), (metal::list<VAL(INC(N)) COMMA(M) PAIRS(M)>)); \
/**/

GEN(MATRIX)
