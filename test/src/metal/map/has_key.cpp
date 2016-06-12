// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/map/has_key.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, VAL(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, VAL(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, VAL(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, VAL(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, VAL(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, VAL(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, VAL(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, VAL(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, NUM(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, NUM(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, NUM(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, NUM(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, NUM(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, NUM(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, NUM(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, NUM(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, PAIR(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, PAIR(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, PAIR(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, PAIR(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, PAIR(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, PAIR(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, PAIR(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, PAIR(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, VECT(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, VECT(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, VECT(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, VECT(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, VECT(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, VECT(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, VECT(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, VECT(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, LIST(M), VAL(N)>), (BOOL(!M))); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, LIST(M), NUM(N)>), (BOOL(!M))); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, LIST(M), PAIR(N)>), (BOOL(!M))); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, LIST(M), VECT(N)>), (BOOL(!M))); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, LIST(M), LIST(N)>), (BOOL(!M))); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, LIST(M), MAP(N)>), (BOOL(!M))); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, LIST(M), LBD(N)>), (BOOL(!M))); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, LIST(M), LBD(_)>), (BOOL(!M))); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, MAP(M), VAL(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, MAP(M), NUM(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, MAP(M), PAIR(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, MAP(M), VECT(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, MAP(M), LIST(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, MAP(M), MAP(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, MAP(M), LBD(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, MAP(M), LBD(_)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, LBD(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, LBD(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, LBD(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, LBD(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, LBD(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, LBD(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, LBD(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, LBD(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, LBD(_), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, LBD(_), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, LBD(_), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, LBD(_), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, LBD(_), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, LBD(_), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, LBD(_), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::has_key>, LBD(_), LBD(_)>), (FALSE)); \
    ASSERT((metal::has_key<MAP(M), NUM(N)>), (BOOL(M > N))); \
    ASSERT((metal::has_key<MAP(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::has_key<test::list<PAIRS(N) COMMA(N) test::list<NUM(N), LBD(N)>>, NUM(N)>), (TRUE)); \
/**/

GEN(MATRIX)
