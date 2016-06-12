// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/partition.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/pair/pair.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, VAL(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, VAL(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, VAL(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, VAL(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, VAL(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, VAL(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, VAL(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, VAL(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, NUM(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, NUM(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, NUM(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, NUM(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, NUM(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, NUM(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, NUM(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, NUM(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, PAIR(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, PAIR(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, PAIR(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, PAIR(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, PAIR(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, PAIR(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, PAIR(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, PAIR(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, VECT(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, VECT(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, VECT(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, VECT(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, VECT(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, VECT(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, VECT(M), LBD(N)>), (BOOL(N == 1))); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, VECT(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, LIST(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, LIST(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, LIST(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, LIST(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, LIST(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, LIST(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, LIST(M), LBD(N)>), (BOOL(!M || N == 1))); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, LIST(M), LBD(_)>), (BOOL(!M))); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, MAP(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, MAP(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, MAP(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, MAP(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, MAP(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, MAP(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, MAP(M), LBD(N)>), (BOOL(!M))); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, MAP(M), LBD(_)>), (BOOL(!M))); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, LBD(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, LBD(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, LBD(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, LBD(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, LBD(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, LBD(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, LBD(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, LBD(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, LBD(_), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, LBD(_), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, LBD(_), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, LBD(_), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, LBD(_), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, LBD(_), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, LBD(_), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::partition>, LBD(_), LBD(_)>), (FALSE)); \
    ASSERT((metal::partition<VECT(M), test::lambda<metal::is_number>>), (metal::pair<VECT(0), VECT(M)>)); \
    ASSERT((metal::partition<LIST(M), test::lambda<metal::is_number>>), (metal::pair<LIST(0), LIST(M)>)); \
    ASSERT((metal::partition<VECT(M), test::lambda<metal::is_pair>>), (metal::pair<VECT(0), VECT(M)>)); \
    ASSERT((metal::partition<LIST(M), test::lambda<metal::is_pair>>), (metal::pair<LIST(0), LIST(M)>)); \
    ASSERT((metal::partition<VECT(M), test::lambda<metal::is_lambda>>), (metal::pair<VECT(0), VECT(M)>)); \
    ASSERT((metal::partition<LIST(M), test::lambda<metal::is_lambda>>), (metal::pair<LIST(0), LIST(M)>)); \
    ASSERT((metal::partition<test::list<ENUM(M, FWD, NUM, PAIR, LBD)>, test::lambda<metal::is_number>>), (metal::pair<test::list<NUMS(M)>, test::list<ENUM(M, FWD, PAIR, LBD)>>)); \
    ASSERT((metal::partition<test::list<ENUM(M, FWD, NUM, PAIR, LBD)>, test::lambda<metal::is_pair>>), (metal::pair<test::list<PAIRS(M)>, test::list<ENUM(M, FWD, NUM, LBD)>>)); \
    ASSERT((metal::partition<test::list<ENUM(M, FWD, NUM, PAIR, LBD)>, test::lambda<metal::is_lambda>>), (metal::pair<test::list<LBDS(M)>, test::list<ENUM(M, FWD, NUM, PAIR)>>)); \
/**/

GEN(MATRIX)

