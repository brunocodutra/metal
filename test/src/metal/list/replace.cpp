// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/replace.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, VAL(M), VAL(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, VAL(M), NUM(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, VAL(M), PAIR(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, VAL(M), VECT(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, VAL(M), LIST(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, VAL(M), MAP(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, VAL(M), LBD(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, VAL(M), LBD(_), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, NUM(M), VAL(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, NUM(M), NUM(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, NUM(M), PAIR(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, NUM(M), VECT(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, NUM(M), LIST(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, NUM(M), MAP(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, NUM(M), LBD(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, NUM(M), LBD(_), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, PAIR(M), VAL(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, PAIR(M), NUM(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, PAIR(M), PAIR(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, PAIR(M), VECT(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, PAIR(M), LIST(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, PAIR(M), MAP(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, PAIR(M), LBD(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, PAIR(M), LBD(_), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, VECT(M), VAL(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, VECT(M), NUM(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, VECT(M), PAIR(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, VECT(M), VECT(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, VECT(M), LIST(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, VECT(M), MAP(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, VECT(M), LBD(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, VECT(M), LBD(_), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LIST(M), VAL(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LIST(M), NUM(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LIST(M), PAIR(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LIST(M), VECT(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LIST(M), LIST(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LIST(M), MAP(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LIST(M), LBD(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LIST(M), LBD(_), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, MAP(M), VAL(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, MAP(M), NUM(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, MAP(M), PAIR(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, MAP(M), VECT(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, MAP(M), LIST(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, MAP(M), MAP(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, MAP(M), LBD(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, MAP(M), LBD(_), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LBD(M), VAL(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LBD(M), NUM(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LBD(M), PAIR(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LBD(M), VECT(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LBD(M), LIST(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LBD(M), MAP(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LBD(M), LBD(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LBD(M), LBD(_), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LBD(_), VAL(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LBD(_), NUM(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LBD(_), PAIR(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LBD(_), VECT(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LBD(_), LIST(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LBD(_), MAP(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LBD(_), LBD(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LBD(_), LBD(_), VAL(M)>), (FALSE)); \
    ASSERT((metal::replace<PAIR(M), VAL(N), NUM(N)>), (test::pair<NUM(M), std::conditional_t<M == N, NUM(N), VAL(M)>>)); \
    ASSERT((metal::replace<PAIR(M), NUM(N), VAL(N)>), (test::pair<std::conditional_t<M == N, VAL(N), NUM(M)>, VAL(M)>)); \
    ASSERT((metal::replace<VECT(M), NA(), VAL(N)>), (test::vect<VALS(M) COMMA(AND(M, CMPL(M))) ENUM(CMPL(M), VAL FIX(N))>)); \
/**/

GEN(MATRIX)

