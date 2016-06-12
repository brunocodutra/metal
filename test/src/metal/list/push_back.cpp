// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/push_back.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, VAL(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, VAL(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, VAL(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, VAL(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, VAL(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, VAL(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, VAL(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, VAL(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, NUM(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, NUM(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, NUM(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, NUM(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, NUM(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, NUM(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, NUM(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, NUM(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, PAIR(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, PAIR(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, PAIR(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, PAIR(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, PAIR(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, PAIR(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, PAIR(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, PAIR(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, VECT(M), VAL(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, VECT(M), NUM(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, VECT(M), PAIR(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, VECT(M), VECT(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, VECT(M), LIST(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, VECT(M), MAP(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, VECT(M), LBD(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, VECT(M), LBD(_)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, LIST(M), VAL(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, LIST(M), NUM(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, LIST(M), PAIR(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, LIST(M), VECT(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, LIST(M), LIST(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, LIST(M), MAP(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, LIST(M), LBD(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, LIST(M), LBD(_)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, MAP(M), VAL(N)>), (BOOL(!M))); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, MAP(M), NUM(N)>), (BOOL(!M))); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, MAP(M), PAIR(N)>), (BOOL(!M))); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, MAP(M), VECT(N)>), (BOOL(!M))); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, MAP(M), LIST(N)>), (BOOL(!M))); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, MAP(M), MAP(N)>), (BOOL(!M))); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, MAP(M), LBD(N)>), (BOOL(!M))); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, MAP(M), LBD(_)>), (BOOL(!M))); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, LBD(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, LBD(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, LBD(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, LBD(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, LBD(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, LBD(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, LBD(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, LBD(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, LBD(_), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, LBD(_), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, LBD(_), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, LBD(_), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, LBD(_), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, LBD(_), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, LBD(_), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::push_back>, LBD(_), LBD(_)>), (FALSE)); \
    ASSERT((metal::push_back<VECT(M), VAL(N)>), (test::vect<VALS(M) COMMA(AND(M, CMPL(M))) NAS(CMPL(M)), VAL(N)>)); \
    ASSERT((metal::push_back<LIST(M), VAL(N)>), (test::list<VALS(M) COMMA(M) VAL(N)>)); \
/**/

GEN(MATRIX)
