// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/splice.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, VAL(M), VAL(N), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, VAL(M), NUM(N), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, VAL(M), PAIR(N), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, VAL(M), VECT(N), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, VAL(M), LIST(N), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, VAL(M), MAP(N), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, VAL(M), LBD(N), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, VAL(M), LBD(_), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, NUM(M), VAL(N), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, NUM(M), NUM(N), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, NUM(M), PAIR(N), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, NUM(M), VECT(N), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, NUM(M), LIST(N), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, NUM(M), MAP(N), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, NUM(M), LBD(N), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, NUM(M), LBD(_), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, PAIR(M), VAL(N), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, PAIR(M), NUM(N), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, PAIR(M), PAIR(N), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, PAIR(M), VECT(N), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, PAIR(M), LIST(N), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, PAIR(M), MAP(N), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, PAIR(M), LBD(N), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, PAIR(M), LBD(_), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, VECT(M), VAL(N), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, VECT(M), NUM(N), VECT(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, VECT(M), PAIR(N), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, VECT(M), VECT(N), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, VECT(M), LIST(N), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, VECT(M), MAP(N), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, VECT(M), LBD(N), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, VECT(M), LBD(_), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, LIST(M), VAL(N), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, LIST(M), NUM(N), LIST(N)>), (BOOL(M >= N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, LIST(M), PAIR(N), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, LIST(M), VECT(N), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, LIST(M), LIST(N), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, LIST(M), MAP(N), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, LIST(M), LBD(N), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, LIST(M), LBD(_), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, MAP(M), VAL(N), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, MAP(M), NUM(N), MAP(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, MAP(M), PAIR(N), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, MAP(M), VECT(N), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, MAP(M), LIST(N), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, MAP(M), MAP(N), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, MAP(M), LBD(N), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, MAP(M), LBD(_), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, LBD(M), VAL(N), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, LBD(M), NUM(N), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, LBD(M), PAIR(N), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, LBD(M), VECT(N), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, LBD(M), LIST(N), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, LBD(M), MAP(N), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, LBD(M), LBD(N), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, LBD(M), LBD(_), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, LBD(_), VAL(N), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, LBD(_), NUM(N), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, LBD(_), PAIR(N), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, LBD(_), VECT(N), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, LBD(_), LIST(N), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, LBD(_), MAP(N), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, LBD(_), LBD(N), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::splice>, LBD(_), LBD(_), LBD(N)>), (FALSE)); \
    ASSERT((metal::splice<VECT(M), NUM(M), LIST(INC(N))>), (test::vect<VALS(M) COMMA(M) VALS(INC(N)) COMMA(CMPL(M)) ENUM(CMPL(M), NA)>)); \
    ASSERT((metal::splice<LIST(INC(M)), NUM(INC(M)), VECT(N)>), (test::list<VALS(INC(M)) COMMA(N) VALS(N) COMMA(CMPL(N)) ENUM(CMPL(N), NA)>)); \
/**/

GEN(MATRIX)

