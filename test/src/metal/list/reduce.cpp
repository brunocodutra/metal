// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/reduce.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, VAL(M), VAL(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, VAL(M), NUM(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, VAL(M), PAIR(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, VAL(M), VECT(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, VAL(M), LIST(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, VAL(M), MAP(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, VAL(M), LBD(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, VAL(M), LBD(_), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, NUM(M), VAL(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, NUM(M), NUM(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, NUM(M), PAIR(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, NUM(M), VECT(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, NUM(M), LIST(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, NUM(M), MAP(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, NUM(M), LBD(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, NUM(M), LBD(_), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, PAIR(M), VAL(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, PAIR(M), NUM(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, PAIR(M), PAIR(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, PAIR(M), VECT(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, PAIR(M), LIST(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, PAIR(M), MAP(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, PAIR(M), LBD(N), NUM(0), NUM(M)>), (BOOL(M == 1 || (M == 2 && N == 2)))); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, PAIR(M), LBD(_), NUM(0), NUM(M)>), (BOOL(M && M < 3))); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, VECT(M), VAL(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, VECT(M), NUM(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, VECT(M), PAIR(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, VECT(M), VECT(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, VECT(M), LIST(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, VECT(M), MAP(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, VECT(M), LBD(N), NUM(0), NUM(M)>), (BOOL(M == 1 || (M && N == 2)))); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, VECT(M), LBD(_), NUM(0), NUM(M)>), (BOOL(M > 0))); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, LIST(M), VAL(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, LIST(M), NUM(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, LIST(M), PAIR(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, LIST(M), VECT(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, LIST(M), LIST(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, LIST(M), MAP(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, LIST(M), LBD(N), NUM(0), NUM(M)>), (BOOL(M == 1 || (M && N == 2)))); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, LIST(M), LBD(_), NUM(0), NUM(M)>), (BOOL(M > 0))); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, MAP(M), VAL(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, MAP(M), NUM(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, MAP(M), PAIR(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, MAP(M), VECT(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, MAP(M), LIST(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, MAP(M), MAP(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, MAP(M), LBD(N), NUM(0), NUM(M)>), (BOOL(M == 1 || (M && N == 2)))); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, MAP(M), LBD(_), NUM(0), NUM(M)>), (BOOL(M > 0))); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, LBD(M), VAL(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, LBD(M), NUM(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, LBD(M), PAIR(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, LBD(M), VECT(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, LBD(M), LIST(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, LBD(M), MAP(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, LBD(M), LBD(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, LBD(M), LBD(_), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, LBD(_), LBD(N), VAL(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, LBD(_), LBD(N), NUM(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, LBD(_), LBD(N), PAIR(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, LBD(_), LBD(N), VECT(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, LBD(_), LBD(N), LIST(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, LBD(_), LBD(N), MAP(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, LBD(_), LBD(N), LBD(N), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, LBD(_), LBD(N), LBD(_), NUM(0), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, PAIR(M), LBD(_), NUM(M), NUM(N)>), (BOOL(M != N && M < 3 && N < 3))); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, VECT(M), LBD(_), NUM(M), NUM(N)>), (BOOL(M != N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, LIST(M), LBD(_), NUM(M), NUM(N)>), (BOOL(M > N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::reduce>, MAP(M), LBD(_), NUM(M), NUM(N)>), (BOOL(M > N))); \
    ASSERT((metal::reduce<LIST(INC(M)), LBD(_), NUM(0), NUM(INC(M))>), (metal::reduce<LIST(INC(M)), LBD(_)>)); \
/**/

GEN(MATRIX)

