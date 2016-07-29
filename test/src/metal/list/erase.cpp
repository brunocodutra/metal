// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/erase.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, VAL(M), VAL(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, VAL(M), NUM(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, VAL(M), PAIR(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, VAL(M), LIST(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, VAL(M), MAP(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, VAL(M), LBD(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, VAL(M), LBD(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, NUM(M), VAL(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, NUM(M), NUM(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, NUM(M), PAIR(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, NUM(M), LIST(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, NUM(M), MAP(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, NUM(M), LBD(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, NUM(M), LBD(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, PAIR(M), VAL(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, PAIR(M), NUM(M), NUM(N)>), (BOOL(M < 3 && N < 3))); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, PAIR(M), PAIR(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, PAIR(M), LIST(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, PAIR(M), MAP(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, PAIR(M), LBD(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, PAIR(M), LBD(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LIST(M), VAL(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LIST(M), NUM(M), NUM(N)>), (BOOL(M >= N))); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LIST(M), PAIR(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LIST(M), LIST(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LIST(M), MAP(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LIST(M), LBD(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LIST(M), LBD(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, MAP(M), VAL(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, MAP(M), NUM(M), NUM(N)>), (BOOL(M >= N))); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, MAP(M), PAIR(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, MAP(M), LIST(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, MAP(M), MAP(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, MAP(M), LBD(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, MAP(M), LBD(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LBD(M), VAL(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LBD(M), NUM(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LBD(M), PAIR(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LBD(M), LIST(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LBD(M), MAP(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LBD(M), LBD(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LBD(M), LBD(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LBD(_), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LBD(_), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LBD(_), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LBD(_), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LBD(_), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LBD(_), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LBD(_), LBD(_)>), (FALSE)); \
    ASSERT((metal::erase<LIST(INF), NUM(M)>), (metal::erase<LIST(INF), NUM(M), NUM(INC(M))>)); \
    ASSERT((metal::erase<LIST(INF), NUM(M), NUM(N)>), (metal::erase<LIST(INF), NUM(N), NUM(M)>)); \
    ASSERT((metal::erase<LIST(M), NUM(0), NUM(M)>), (LIST(0))); \
    ASSERT((metal::erase<LIST(INF), NUM(INF), NUM(M)>), (LIST(M))); \
/**/

GEN(MATRIX)
