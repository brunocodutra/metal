// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/lambda/bind.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/list/list.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, VAL(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, VAL(M) COMMA(N) NUMS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, VAL(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, VAL(M) COMMA(N) LISTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, VAL(M) COMMA(N) MAPS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, VAL(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, NUM(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, NUM(M) COMMA(N) NUMS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, NUM(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, NUM(M) COMMA(N) LISTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, NUM(M) COMMA(N) MAPS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, NUM(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, PAIR(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, PAIR(M) COMMA(N) NUMS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, PAIR(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, PAIR(M) COMMA(N) LISTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, PAIR(M) COMMA(N) MAPS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, PAIR(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, LIST(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, LIST(M) COMMA(N) NUMS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, LIST(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, LIST(M) COMMA(N) LISTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, LIST(M) COMMA(N) MAPS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, LIST(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, MAP(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, MAP(M) COMMA(N) NUMS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, MAP(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, MAP(M) COMMA(N) LISTS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, MAP(M) COMMA(N) MAPS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, MAP(M) COMMA(N) LBDS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, LBD(M) COMMA(N) VALS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, LBD(M) COMMA(N) NUMS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, LBD(M) COMMA(N) PAIRS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, LBD(M) COMMA(N) LISTS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, LBD(M) COMMA(N) MAPS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, LBD(M) COMMA(N) LBDS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, LBD(_) COMMA(N) VALS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, LBD(_) COMMA(N) NUMS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, LBD(_) COMMA(N) PAIRS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, LBD(_) COMMA(N) LISTS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, LBD(_) COMMA(N) MAPS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::bind>, LBD(_) COMMA(N) LBDS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::bind<LBD(M) COMMA(N) ENUM(N, LBD FIX(M))> COMMA(N) VALS(N)>), (BOOL(M == N))); \
    ASSERT((metal::invoke<metal::bind<LBD(M) COMMA(M) ENUM(M, LBD FIX(N))> COMMA(N) VALS(N)>), (EXPR(M)<ENUM(M, NUM FIX(N))>)); \
    ASSERT((metal::invoke<metal::bind<LBD(_) COMMA(M) ENUM(M, LBD FIX(N))> COMMA(N) VALS(N)>), (EXPR(_)<ENUM(M, NUM FIX(N))>)); \
/**/

GEN(MATRIX)
