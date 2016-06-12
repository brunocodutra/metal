// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/number/equal_to.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, VAL(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, VAL(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, VAL(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, VAL(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, VAL(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, VAL(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, VAL(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, VAL(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, NUM(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, NUM(M), NUM(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, NUM(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, NUM(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, NUM(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, NUM(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, NUM(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, NUM(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, PAIR(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, PAIR(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, PAIR(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, PAIR(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, PAIR(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, PAIR(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, PAIR(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, PAIR(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, VECT(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, VECT(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, VECT(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, VECT(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, VECT(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, VECT(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, VECT(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, VECT(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, LIST(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, LIST(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, LIST(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, LIST(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, LIST(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, LIST(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, LIST(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, LIST(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, MAP(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, MAP(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, MAP(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, MAP(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, MAP(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, MAP(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, MAP(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, MAP(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, LBD(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, LBD(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, LBD(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, LBD(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, LBD(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, LBD(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, LBD(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, LBD(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, LBD(_), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, LBD(_), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, LBD(_), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, LBD(_), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, LBD(_), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, LBD(_), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, LBD(_), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::equal_to>, LBD(_), LBD(_)>), (FALSE)); \
    ASSERT((metal::equal_to<NUM(M), NUM(N)>), (BOOL(M == N))); \
/**/

GEN(MATRIX)

