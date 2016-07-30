// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/fold.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, VAL(M), VAL(N), VAL(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, VAL(M), VAL(N), NUM(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, VAL(M), VAL(N), PAIR(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, VAL(M), VAL(N), VECT(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, VAL(M), VAL(N), LIST(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, VAL(M), VAL(N), MAP(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, VAL(M), VAL(N), LBD(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, VAL(M), VAL(N), LBD(_), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, NUM(M), NUM(N), VAL(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, NUM(M), NUM(N), NUM(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, NUM(M), NUM(N), PAIR(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, NUM(M), NUM(N), VECT(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, NUM(M), NUM(N), LIST(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, NUM(M), NUM(N), MAP(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, NUM(M), NUM(N), LBD(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, NUM(M), NUM(N), LBD(_), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, PAIR(M), PAIR(N), VAL(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, PAIR(M), PAIR(N), NUM(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, PAIR(M), PAIR(N), PAIR(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, PAIR(M), PAIR(N), VECT(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, PAIR(M), PAIR(N), LIST(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, PAIR(M), PAIR(N), MAP(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, PAIR(M), PAIR(N), LBD(N), NUM(0), NUM(M)>), (BOOL(!M || (M < 3 && N == 2)))); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, PAIR(M), PAIR(N), LBD(_), NUM(0), NUM(M)>), (BOOL(M < 3))); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, VECT(M), VECT(N), VAL(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, VECT(M), VECT(N), NUM(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, VECT(M), VECT(N), PAIR(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, VECT(M), VECT(N), VECT(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, VECT(M), VECT(N), LIST(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, VECT(M), VECT(N), MAP(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, VECT(M), VECT(N), LBD(N), NUM(0), NUM(M)>), (BOOL(!M || N == 2))); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, VECT(M), VECT(N), LBD(_), NUM(0), NUM(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, LIST(M), LIST(N), VAL(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, LIST(M), LIST(N), NUM(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, LIST(M), LIST(N), PAIR(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, LIST(M), LIST(N), VECT(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, LIST(M), LIST(N), LIST(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, LIST(M), LIST(N), MAP(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, LIST(M), LIST(N), LBD(N), NUM(0), NUM(M)>), (BOOL(!M || N == 2))); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, LIST(M), LIST(N), LBD(_), NUM(0), NUM(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, MAP(M), MAP(N), VAL(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, MAP(M), MAP(N), NUM(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, MAP(M), MAP(N), PAIR(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, MAP(M), MAP(N), VECT(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, MAP(M), MAP(N), LIST(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, MAP(M), MAP(N), MAP(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, MAP(M), MAP(N), LBD(N), NUM(0), NUM(M)>), (BOOL(!M || N == 2))); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, MAP(M), MAP(N), LBD(_), NUM(0), NUM(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, LBD(M), LBD(N), VAL(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, LBD(M), LBD(N), NUM(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, LBD(M), LBD(N), PAIR(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, LBD(M), LBD(N), VECT(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, LBD(M), LBD(N), LIST(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, LBD(M), LBD(N), MAP(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, LBD(M), LBD(N), LBD(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, LBD(M), LBD(N), LBD(_), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, LBD(_), LBD(N), VAL(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, LBD(_), LBD(N), NUM(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, LBD(_), LBD(N), PAIR(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, LBD(_), LBD(N), VECT(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, LBD(_), LBD(N), LIST(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, LBD(_), LBD(N), MAP(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, LBD(_), LBD(N), LBD(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, LBD(_), LBD(N), LBD(_), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, PAIR(M), VAL(N), LBD(_), NUM(M), NUM(N)>), (BOOL(M < 3 && N < 3))); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, VECT(M), VAL(N), LBD(_), NUM(M), NUM(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, LIST(M), VAL(N), LBD(_), NUM(M), NUM(N)>), (BOOL(M >= N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::fold>, MAP(M), VAL(N), LBD(_), NUM(M), NUM(N)>), (BOOL(M >= N))); \
    ASSERT((metal::fold<LIST(M), VAL(N), LBD(_), NUM(0), NUM(M)>), (metal::fold<LIST(M), VAL(N), LBD(_)>)); \
    ASSERT((metal::fold<LIST(INF), VAL(N), LBD(_), NUM(M), NUM(N)>), (metal::fold<test::list<RENUM(INF, VAL)>, VAL(N), LBD(_), NUM(CMPL(M)), NUM(CMPL(N))>)); \
    ASSERT((metal::fold<VECT(M), VAL(N), LBD(2), NUM(M), NUM(N)>), (std::conditional_t<M == N, VAL(N), NUM(2)>)); \
/**/

GEN(MATRIX)

