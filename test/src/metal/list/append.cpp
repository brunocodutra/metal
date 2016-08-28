// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/append.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, VAL(M) COMMA(N) VALS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, VAL(M) COMMA(N) NUMS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, VAL(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, VAL(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, VAL(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, VAL(M) COMMA(N) LBDS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, NUM(M) COMMA(N) VALS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, NUM(M) COMMA(N) NUMS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, NUM(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, NUM(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, NUM(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, NUM(M) COMMA(N) LBDS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, PAIR(M) COMMA(N) VALS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, PAIR(M) COMMA(N) NUMS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, PAIR(M) COMMA(N) PAIRS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, PAIR(M) COMMA(N) LISTS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, PAIR(M) COMMA(N) MAPS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, PAIR(M) COMMA(N) LBDS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, LIST(M) COMMA(N) VALS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, LIST(M) COMMA(N) NUMS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, LIST(M) COMMA(N) PAIRS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, LIST(M) COMMA(N) LISTS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, LIST(M) COMMA(N) MAPS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, LIST(M) COMMA(N) LBDS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, MAP(M) COMMA(N) VALS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, MAP(M) COMMA(N) NUMS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, MAP(M) COMMA(N) PAIRS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, MAP(M) COMMA(N) LISTS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, MAP(M) COMMA(N) MAPS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, MAP(M) COMMA(N) LBDS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, LBD(M) COMMA(N) VALS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, LBD(M) COMMA(N) NUMS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, LBD(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, LBD(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, LBD(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, LBD(M) COMMA(N) LBDS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, LBD(_) COMMA(N) VALS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, LBD(_) COMMA(N) NUMS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, LBD(_) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, LBD(_) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, LBD(_) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, LBD(_) COMMA(N) LBDS(N)>), (FALSE)); \
    CHECK((metal::append<PAIR(M), VALS(INC(N))>), (metal::list<NUM(M), VAL(M), VALS(INC(N))>)); \
    CHECK((metal::append<LIST(M), VALS(INC(N))>), (metal::list<VALS(M) COMMA(M) VALS(INC(N))>)); \
    CHECK((metal::append<MAP(M), VALS(INC(N))>), (metal::list<PAIRS(M) COMMA(M) VALS(INC(N))>)); \
/**/

GEN(MATRIX)
