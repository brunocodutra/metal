// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/all.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/pair/pair.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, VAL(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, VAL(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, VAL(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, VAL(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, VAL(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, VAL(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, VAL(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, NUM(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, NUM(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, NUM(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, NUM(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, NUM(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, NUM(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, NUM(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, NUM(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, PAIR(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, PAIR(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, PAIR(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, PAIR(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, PAIR(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, PAIR(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, PAIR(M), LBD(N)>), (BOOL(N == 1))); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, PAIR(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, VECT(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, VECT(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, VECT(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, VECT(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, VECT(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, VECT(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, VECT(M), LBD(N)>), (BOOL(N == 1))); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, VECT(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, LIST(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, LIST(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, LIST(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, LIST(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, LIST(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, LIST(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, LIST(M), LBD(N)>), (BOOL(!M || N == 1))); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, LIST(M), LBD(_)>), (BOOL(!M))); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, MAP(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, MAP(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, MAP(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, MAP(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, MAP(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, MAP(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, MAP(M), LBD(N)>), (BOOL(!M || N == 1))); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, MAP(M), LBD(_)>), (BOOL(!M))); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, LBD(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, LBD(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, LBD(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, LBD(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, LBD(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, LBD(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, LBD(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, LBD(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, LBD(_), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, LBD(_), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, LBD(_), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, LBD(_), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, LBD(_), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, LBD(_), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, LBD(_), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::all>, LBD(_), LBD(_)>), (FALSE)); \
    ASSERT((metal::all<PAIR(M), test::lambda<metal::is_number>>), (FALSE)); \
    ASSERT((metal::all<VECT(M), test::lambda<metal::is_number>>), (FALSE)); \
    ASSERT((metal::all<LIST(M), test::lambda<metal::is_number>>), (BOOL(!M))); \
    ASSERT((metal::all<MAP(M), test::lambda<metal::is_number>>), (BOOL(!M))); \
    ASSERT((metal::all<PAIR(M), test::lambda<metal::is_pair>>), (FALSE)); \
    ASSERT((metal::all<VECT(M), test::lambda<metal::is_pair>>), (FALSE)); \
    ASSERT((metal::all<LIST(M), test::lambda<metal::is_pair>>), (BOOL(!M))); \
    ASSERT((metal::all<MAP(M), test::lambda<metal::is_pair>>), (TRUE)); \
    ASSERT((metal::all<PAIR(M), test::lambda<metal::is_lambda>>), (FALSE)); \
    ASSERT((metal::all<VECT(M), test::lambda<metal::is_lambda>>), (FALSE)); \
    ASSERT((metal::all<LIST(M), test::lambda<metal::is_lambda>>), (BOOL(!M))); \
    ASSERT((metal::all<MAP(M), test::lambda<metal::is_lambda>>), (BOOL(!M))); \
/**/

GEN(MATRIX)

