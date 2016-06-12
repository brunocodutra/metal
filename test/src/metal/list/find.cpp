// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/find.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, VAL(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, VAL(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, VAL(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, VAL(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, VAL(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, VAL(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, VAL(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, VAL(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, NUM(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, NUM(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, NUM(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, NUM(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, NUM(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, NUM(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, NUM(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, NUM(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, PAIR(M), VAL(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, PAIR(M), NUM(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, PAIR(M), PAIR(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, PAIR(M), VECT(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, PAIR(M), LIST(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, PAIR(M), MAP(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, PAIR(M), LBD(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, PAIR(M), LBD(_)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, VECT(M), VAL(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, VECT(M), NUM(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, VECT(M), PAIR(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, VECT(M), VECT(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, VECT(M), LIST(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, VECT(M), MAP(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, VECT(M), LBD(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, VECT(M), LBD(_)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, LIST(M), VAL(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, LIST(M), NUM(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, LIST(M), PAIR(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, LIST(M), VECT(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, LIST(M), LIST(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, LIST(M), MAP(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, LIST(M), LBD(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, LIST(M), LBD(_)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, MAP(M), VAL(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, MAP(M), NUM(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, MAP(M), PAIR(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, MAP(M), VECT(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, MAP(M), LIST(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, MAP(M), MAP(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, MAP(M), LBD(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, MAP(M), LBD(_)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, LBD(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, LBD(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, LBD(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, LBD(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, LBD(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, LBD(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, LBD(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, LBD(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, LBD(_), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, LBD(_), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, LBD(_), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, LBD(_), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, LBD(_), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, LBD(_), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, LBD(_), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::find>, LBD(_), LBD(_)>), (FALSE)); \
    ASSERT((metal::find<PAIR(M), VAL(N)>), (SIZE_T(M == N ? 1 : 2))); \
    ASSERT((metal::find<PAIR(M), NUM(N)>), (SIZE_T(M == N ? 0 : 2))); \
    ASSERT((metal::find<VECT(M), VAL(N)>), (SIZE_T((M > N) ? N : INF))); \
    ASSERT((metal::find<LIST(M), VAL(N)>), (SIZE_T((M > N) ? N : M))); \
    ASSERT((metal::find<MAP(M), PAIR(N)>), (SIZE_T((M > N) ? N : M))); \
    ASSERT((metal::find<test::list<VALS(M) COMMA(M) VAL(N)>, VAL(N)>), (SIZE_T((M > N) ? N : M))); \
    ASSERT((metal::find<test::list<ENUM(M, VAL FIX(N))>, VAL(N)>), (SIZE_T(0))); \
/**/

GEN(MATRIX)

