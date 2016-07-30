// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/push_front.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, VAL(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, VAL(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, VAL(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, VAL(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, VAL(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, VAL(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, VAL(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, NUM(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, NUM(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, NUM(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, NUM(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, NUM(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, NUM(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, NUM(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, PAIR(M), VAL(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, PAIR(M), NUM(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, PAIR(M), PAIR(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, PAIR(M), LIST(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, PAIR(M), MAP(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, PAIR(M), LBD(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, PAIR(M), LBD(_)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, LIST(M), VAL(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, LIST(M), NUM(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, LIST(M), PAIR(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, LIST(M), LIST(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, LIST(M), MAP(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, LIST(M), LBD(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, LIST(M), LBD(_)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, MAP(M), VAL(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, MAP(M), NUM(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, MAP(M), PAIR(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, MAP(M), LIST(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, MAP(M), MAP(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, MAP(M), LBD(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, MAP(M), LBD(_)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, LBD(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, LBD(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, LBD(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, LBD(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, LBD(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, LBD(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, LBD(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, LBD(_), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, LBD(_), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, LBD(_), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, LBD(_), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, LBD(_), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, LBD(_), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_front>, LBD(_), LBD(_)>), (FALSE)); \
    ASSERT((metal::push_front<PAIR(M), VAL(N)>), (metal::list<VAL(N), NUM(M), VAL(M)>)); \
    ASSERT((metal::push_front<LIST(M), VAL(N)>), (metal::list<VAL(N) COMMA(M) VALS(M)>)); \
    ASSERT((metal::push_front<MAP(M), VAL(N)>), (metal::list<VAL(N) COMMA(M) PAIRS(M)>)); \
/**/

GEN(MATRIX)
