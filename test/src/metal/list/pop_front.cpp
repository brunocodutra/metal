// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/pop_front.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, VAL(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, VAL(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, VAL(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, VAL(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, VAL(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, VAL(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, VAL(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, NUM(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, NUM(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, NUM(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, NUM(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, NUM(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, NUM(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, NUM(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, PAIR(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, PAIR(M), NUM(N)>), (BOOL(N < 3))); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, PAIR(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, PAIR(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, PAIR(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, PAIR(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, PAIR(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, LIST(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, LIST(M), NUM(N)>), (BOOL(M >= N))); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, LIST(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, LIST(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, LIST(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, LIST(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, LIST(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, MAP(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, MAP(M), NUM(N)>), (BOOL(M >= N))); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, MAP(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, MAP(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, MAP(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, MAP(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, MAP(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, LBD(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, LBD(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, LBD(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, LBD(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, LBD(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, LBD(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::pop_front>, LBD(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::pop_front<metal::list<VALS(M) COMMA(AND(M, N)) VALS(N)>, NUM(M)>), (LIST(N))); \
/**/

GEN(MATRIX)
