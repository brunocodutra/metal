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
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, VAL(M), VAL(0), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, VAL(M), NUM(0), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, VAL(M), PAIR(0), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, VAL(M), LIST(0), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, VAL(M), MAP(0), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, VAL(M), LBD(0), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, NUM(M), VAL(0), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, NUM(M), NUM(0), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, NUM(M), PAIR(0), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, NUM(M), LIST(0), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, NUM(M), MAP(0), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, NUM(M), LBD(0), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, PAIR(M), VAL(0), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, PAIR(M), NUM(0), NUM(N)>), (BOOL(N < 3))); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, PAIR(M), PAIR(0), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, PAIR(M), LIST(0), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, PAIR(M), MAP(0), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, PAIR(M), LBD(0), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LIST(M), VAL(0), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LIST(M), NUM(0), NUM(N)>), (BOOL(M >= N))); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LIST(M), PAIR(0), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LIST(M), LIST(0), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LIST(M), MAP(0), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LIST(M), LBD(0), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, MAP(M), VAL(0), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, MAP(M), NUM(0), NUM(N)>), (BOOL(M >= N))); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, MAP(M), PAIR(0), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, MAP(M), LIST(0), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, MAP(M), MAP(0), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, MAP(M), LBD(0), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LBD(M), VAL(0), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LBD(M), NUM(0), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LBD(M), PAIR(0), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LBD(M), LIST(0), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LBD(M), MAP(0), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LBD(M), LBD(0), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LBD(_), VAL(0), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LBD(_), NUM(0), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LBD(_), PAIR(0), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LBD(_), LIST(0), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LBD(_), MAP(0), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::erase>, LBD(_), LBD(0), LBD(N)>), (FALSE)); \
    ASSERT((metal::erase<LIST(INF), NUM(M)>), (metal::erase<LIST(INF), NUM(M), NUM(INC(M))>)); \
    ASSERT((metal::erase<LIST(INF), NUM(M), NUM(N)>), (metal::erase<LIST(INF), NUM(N), NUM(M)>)); \
    ASSERT((metal::erase<LIST(M), NUM(0), NUM(M)>), (LIST(0))); \
    ASSERT((metal::erase<LIST(INF), NUM(INF), NUM(M)>), (LIST(M))); \
/**/

GEN(MATRIX)
