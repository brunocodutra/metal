// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/copy.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, VAL(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, VAL(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, VAL(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, VAL(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, VAL(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, VAL(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, VAL(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, VAL(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, NUM(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, NUM(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, NUM(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, NUM(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, NUM(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, NUM(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, NUM(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, NUM(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, PAIR(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, PAIR(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, PAIR(M), PAIR(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, PAIR(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, PAIR(M), LIST(N)>), (BOOL(N == 2))); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, PAIR(M), MAP(N)>), (BOOL(N == 2))); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, PAIR(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, PAIR(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, VECT(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, VECT(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, VECT(M), PAIR(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, VECT(M), VECT(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, VECT(M), LIST(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, VECT(M), MAP(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, VECT(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, VECT(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, LIST(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, LIST(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, LIST(M), PAIR(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, LIST(M), VECT(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, LIST(M), LIST(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, LIST(M), MAP(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, LIST(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, LIST(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, MAP(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, MAP(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, MAP(M), PAIR(N)>), (BOOL(!M || M == 2))); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, MAP(M), VECT(N)>), (BOOL(!M))); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, MAP(M), LIST(N)>), (BOOL(!M || M == N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, MAP(M), MAP(N)>), (BOOL(!M || M == N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, MAP(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, MAP(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, LBD(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, LBD(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, LBD(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, LBD(M), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, LBD(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, LBD(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, LBD(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, LBD(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, LBD(_), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, LBD(_), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, LBD(_), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, LBD(_), VECT(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, LBD(_), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, LBD(_), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, LBD(_), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::copy>, LBD(_), LBD(_)>), (FALSE)); \
    ASSERT((metal::copy<PAIR(M), PAIR(N)>), (PAIR(N))); \
    ASSERT((metal::copy<PAIR(M), LIST(2)>), (test::pair<VALS(2)>)); \
    ASSERT((metal::copy<PAIR(M), MAP(2)>), (test::pair<PAIRS(2)>)); \
    ASSERT((metal::copy<VECT(M), PAIR(N)>), (test::vect<NUM(N), VAL(N) COMMA(CMPL(2)) NAS(CMPL(2))>)); \
    ASSERT((metal::copy<VECT(M), VECT(N)>), (VECT(N))); \
    ASSERT((metal::copy<VECT(M), LIST(N)>), (test::vect<VALS(N) COMMA(AND(N, CMPL(N))) NAS(CMPL(N))>)); \
    ASSERT((metal::copy<VECT(M), MAP(N)>), (test::vect<PAIRS(N) COMMA(AND(N, CMPL(N))) NAS(CMPL(N))>)); \
    ASSERT((metal::copy<LIST(M), PAIR(N)>), (test::list<NUM(N), VAL(N)>)); \
    ASSERT((metal::copy<LIST(M), VECT(N)>), (test::list<VALS(N) COMMA(AND(N, CMPL(N))) NAS(CMPL(N))>)); \
    ASSERT((metal::copy<LIST(M), LIST(N)>), (LIST(N))); \
    ASSERT((metal::copy<LIST(M), MAP(N)>), (test::list<PAIRS(N)>)); \
    ASSERT((metal::copy<MAP(2), PAIR(N)>), (CAT(test::map, 2)<NUM(N), VAL(N)>)); \
    ASSERT((metal::copy<MAP(INF), VECT(N)>), (CAT(test::map, INF)<VALS(N) COMMA(AND(N, CMPL(N))) NAS(CMPL(N))>)); \
    ASSERT((metal::copy<MAP(M), LIST(M)>), (CAT(test::map, M)<VALS(M)>)); \
    ASSERT((metal::copy<MAP(M), MAP(M)>), (MAP(M))); \
/**/

GEN(MATRIX)

