// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/slice.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, VAL(M), VAL(M), VAL(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, VAL(M), NUM(M), NUM(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, VAL(M), PAIR(M), PAIR(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, VAL(M), VECT(M), VECT(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, VAL(M), LIST(M), LIST(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, VAL(M), MAP(M), MAP(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, VAL(M), LBD(M), LBD(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, VAL(M), LBD(M), LBD(_), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, NUM(M), VAL(M), VAL(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, NUM(M), NUM(M), NUM(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, NUM(M), PAIR(M), PAIR(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, NUM(M), VECT(M), VECT(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, NUM(M), LIST(M), LIST(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, NUM(M), MAP(M), MAP(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, NUM(M), LBD(M), LBD(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, NUM(M), LBD(M), LBD(_), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, PAIR(M), VAL(M), VAL(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, PAIR(M), NUM(M), NUM(N), NUM(1)>), (BOOL(!M && N == 2))); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, PAIR(M), PAIR(M), PAIR(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, PAIR(M), VECT(M), VECT(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, PAIR(M), LIST(M), LIST(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, PAIR(M), MAP(M), MAP(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, PAIR(M), LBD(M), LBD(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, PAIR(M), LBD(M), LBD(_), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, VECT(M), VAL(M), VAL(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, VECT(M), NUM(M), NUM(N), NUM(1)>), (BOOL(N <= CMPL(M)))); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, VECT(M), PAIR(M), PAIR(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, VECT(M), VECT(M), VECT(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, VECT(M), LIST(M), LIST(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, VECT(M), MAP(M), MAP(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, VECT(M), LBD(M), LBD(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, VECT(M), LBD(M), LBD(_), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, LIST(M), VAL(M), VAL(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, LIST(M), NUM(M), NUM(N), NUM(1)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, LIST(M), PAIR(M), PAIR(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, LIST(M), VECT(M), VECT(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, LIST(M), LIST(M), LIST(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, LIST(M), MAP(M), MAP(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, LIST(M), LBD(M), LBD(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, LIST(M), LBD(M), LBD(_), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, MAP(M), VAL(M), VAL(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, MAP(M), NUM(M), NUM(N), NUM(1)>), (BOOL(!M && !N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, MAP(M), PAIR(M), PAIR(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, MAP(M), VECT(M), VECT(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, MAP(M), LIST(M), LIST(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, MAP(M), MAP(M), MAP(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, MAP(M), LBD(M), LBD(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, MAP(M), LBD(M), LBD(_), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, LBD(M), VAL(M), VAL(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, LBD(M), NUM(M), NUM(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, LBD(M), PAIR(M), PAIR(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, LBD(M), VECT(M), VECT(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, LBD(M), LIST(M), LIST(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, LBD(M), MAP(M), MAP(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, LBD(M), LBD(M), LBD(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, LBD(M), LBD(M), LBD(_), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, LBD(_), VAL(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, LBD(_), NUM(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, LBD(_), PAIR(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, LBD(_), VECT(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, LBD(_), LIST(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, LBD(_), MAP(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, LBD(_), LBD(N), NUM(1)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::slice>, LBD(_), LBD(_), NUM(1)>), (FALSE)); \
    ASSERT((metal::slice<PAIR(M), NUM(0), NUM(2)>), (PAIR(M))); \
    ASSERT((metal::slice<VECT(M), NUM(0), NUM(N)>), (std::conditional_t<(M > N), VECT(N), VECT(M)>)); \
    ASSERT((metal::slice<LIST(INF), NUM(M), NUM(CMPL(M))>), (metal::slice<LIST(INF), NUM(M), NUM(CMPL(M)), NUM(1)>)); \
    ASSERT((metal::slice<LIST(INF), NUM(0), NUM(M)>), (LIST(M))); \
    ASSERT((metal::slice<LIST(INF), NUM(M), NUM(N), NUM(0)>), (test::list<ENUM(N, VAL FIX(M))>)); \
    ASSERT((metal::slice<LIST(INF), NUM(M), NUM(M), INT(-1)>), (test::list<RENUM(M, VAL LIFT(INC))>)); \
    ASSERT((metal::slice<MAP(M), NUM(0), NUM(M)>), (MAP(M))); \
/**/

GEN(MATRIX)
