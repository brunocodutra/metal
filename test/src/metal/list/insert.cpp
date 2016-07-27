// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/insert.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, VAL(M), VAL(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, VAL(M), NUM(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, VAL(M), PAIR(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, VAL(M), VECT(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, VAL(M), LIST(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, VAL(M), MAP(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, VAL(M), LBD(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, VAL(M), LBD(_), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, NUM(M), VAL(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, NUM(M), NUM(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, NUM(M), PAIR(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, NUM(M), VECT(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, NUM(M), LIST(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, NUM(M), MAP(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, NUM(M), LBD(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, NUM(M), LBD(_), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, PAIR(M), VAL(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, PAIR(M), NUM(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, PAIR(M), PAIR(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, PAIR(M), VECT(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, PAIR(M), LIST(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, PAIR(M), MAP(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, PAIR(M), LBD(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, PAIR(M), LBD(_), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, VECT(M), VAL(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, VECT(M), NUM(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, VECT(M), PAIR(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, VECT(M), VECT(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, VECT(M), LIST(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, VECT(M), MAP(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, VECT(M), LBD(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, VECT(M), LBD(_), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, LIST(M), VAL(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, LIST(M), NUM(N), VAL(M)>), (BOOL(M >= N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, LIST(M), PAIR(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, LIST(M), VECT(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, LIST(M), LIST(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, LIST(M), MAP(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, LIST(M), LBD(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, LIST(M), LBD(_), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, MAP(M), VAL(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, MAP(M), NUM(N), VAL(M)>), (BOOL(!M && !N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, MAP(M), PAIR(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, MAP(M), VECT(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, MAP(M), LIST(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, MAP(M), MAP(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, MAP(M), LBD(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, MAP(M), LBD(_), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, LBD(M), VAL(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, LBD(M), NUM(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, LBD(M), PAIR(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, LBD(M), VECT(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, LBD(M), LIST(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, LBD(M), MAP(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, LBD(M), LBD(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, LBD(M), LBD(_), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, LBD(_), VAL(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, LBD(_), NUM(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, LBD(_), PAIR(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, LBD(_), VECT(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, LBD(_), LIST(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, LBD(_), MAP(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, LBD(_), LBD(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::insert>, LBD(_), LBD(_), VAL(M)>), (FALSE)); \
    ASSERT((metal::insert<VECT(M), NUM(M), VAL(N)>), (test::vect<VALS(M) COMMA(M) VAL(N) COMMA(CMPL(M)) ENUM(CMPL(M), NA)>)); \
    ASSERT((metal::insert<LIST(M), NUM(M), VAL(N)>), (test::list<VALS(M) COMMA(M) VAL(N)>)); \
/**/

GEN(MATRIX)

