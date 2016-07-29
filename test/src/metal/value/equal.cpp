// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/value/equal.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, VAL(M), VAL(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, VAL(M), NUM(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, VAL(M), PAIR(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, VAL(M), LIST(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, VAL(M), MAP(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, VAL(M), LBD(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, VAL(M), LBD(_)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, NUM(M), VAL(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, NUM(M), NUM(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, NUM(M), PAIR(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, NUM(M), LIST(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, NUM(M), MAP(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, NUM(M), LBD(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, NUM(M), LBD(_)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, PAIR(M), VAL(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, PAIR(M), NUM(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, PAIR(M), PAIR(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, PAIR(M), LIST(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, PAIR(M), MAP(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, PAIR(M), LBD(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, PAIR(M), LBD(_)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, LIST(M), VAL(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, LIST(M), NUM(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, LIST(M), PAIR(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, LIST(M), LIST(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, LIST(M), MAP(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, LIST(M), LBD(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, LIST(M), LBD(_)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, MAP(M), VAL(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, MAP(M), NUM(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, MAP(M), PAIR(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, MAP(M), LIST(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, MAP(M), MAP(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, MAP(M), LBD(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, MAP(M), LBD(_)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, LBD(M), VAL(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, LBD(M), NUM(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, LBD(M), PAIR(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, LBD(M), LIST(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, LBD(M), MAP(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, LBD(M), LBD(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, LBD(M), LBD(_)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, LBD(_), VAL(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, LBD(_), NUM(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, LBD(_), PAIR(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, LBD(_), LIST(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, LBD(_), MAP(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, LBD(_), LBD(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::equal>, LBD(_), LBD(_)>), (TRUE)); \
    ASSERT((metal::equal<VAL(M), VAL(N)>), (BOOL(M == N))); \
    ASSERT((metal::equal<NUM(M), INT(N)>), (BOOL(M == N))); \
    ASSERT((metal::equal<PAIR(M), metal::list<INT(N), VAL(N)>>), (BOOL(M == N))); \
    ASSERT((metal::equal<PAIR(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::equal<PAIR(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::equal<LIST(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::equal<LIST(M), LIST(N)>), (BOOL(M == N))); \
    ASSERT((metal::equal<LIST(N), MAP(M)>), (BOOL(!M && !N))); \
    ASSERT((metal::equal<MAP(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::equal<MAP(M), LIST(N)>), (BOOL(!M && !N))); \
    ASSERT((metal::equal<MAP(M), MAP(N)>), (BOOL(M == N))); \
    ASSERT((metal::equal<LBD(M), LBD(N)>), (BOOL(M == N))); \
    ASSERT((metal::equal<LBD(M), metal::lambda<EXPR(N)>>), (BOOL(M == N))); \
/**/

GEN(MATRIX)

