// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/replace.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, VAL(M), VAL(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, VAL(M), NUM(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, VAL(M), PAIR(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, VAL(M), LIST(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, VAL(M), MAP(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, VAL(M), LBD(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, VAL(M), LBD(_), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, NUM(M), VAL(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, NUM(M), NUM(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, NUM(M), PAIR(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, NUM(M), LIST(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, NUM(M), MAP(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, NUM(M), LBD(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, NUM(M), LBD(_), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, PAIR(M), VAL(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, PAIR(M), NUM(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, PAIR(M), PAIR(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, PAIR(M), LIST(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, PAIR(M), MAP(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, PAIR(M), LBD(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, PAIR(M), LBD(_), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LIST(M), VAL(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LIST(M), NUM(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LIST(M), PAIR(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LIST(M), LIST(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LIST(M), MAP(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LIST(M), LBD(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LIST(M), LBD(_), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, MAP(M), VAL(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, MAP(M), NUM(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, MAP(M), PAIR(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, MAP(M), LIST(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, MAP(M), MAP(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, MAP(M), LBD(N), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, MAP(M), LBD(_), VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LBD(M), VAL(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LBD(M), NUM(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LBD(M), PAIR(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LBD(M), LIST(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LBD(M), MAP(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LBD(M), LBD(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LBD(M), LBD(_), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LBD(_), VAL(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LBD(_), NUM(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LBD(_), PAIR(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LBD(_), LIST(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LBD(_), MAP(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LBD(_), LBD(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::replace>, LBD(_), LBD(_), VAL(M)>), (FALSE)); \
    ASSERT((metal::replace<PAIR(M), VAL(N), NUM(N)>), (metal::list<NUM(M), std::conditional_t<M == N, NUM(N), VAL(M)>>)); \
    ASSERT((metal::replace<PAIR(M), INT(N), VAL(N)>), (metal::list<std::conditional_t<M == N, VAL(N), NUM(M)>, VAL(M)>)); \
    ASSERT((metal::replace<metal::list<VALS(M) COMMA(AND(M, CMPL(M))) ENUM(CMPL(M), NUM FIX(N))>, NUM(N), VAL(N)>), (metal::list<VALS(M) COMMA(AND(M, CMPL(M))) ENUM(CMPL(M), VAL FIX(N))>)); \
/**/

GEN(MATRIX)

