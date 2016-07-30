// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/copy.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, VAL(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, VAL(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, VAL(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, VAL(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, VAL(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, VAL(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, VAL(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, NUM(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, NUM(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, NUM(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, NUM(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, NUM(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, NUM(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, NUM(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, PAIR(M), VAL(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, PAIR(M), NUM(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, PAIR(M), PAIR(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, PAIR(M), LIST(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, PAIR(M), MAP(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, PAIR(M), LBD(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, PAIR(M), LBD(_)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, LIST(M), VAL(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, LIST(M), NUM(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, LIST(M), PAIR(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, LIST(M), LIST(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, LIST(M), MAP(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, LIST(M), LBD(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, LIST(M), LBD(_)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, MAP(M), VAL(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, MAP(M), NUM(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, MAP(M), PAIR(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, MAP(M), LIST(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, MAP(M), MAP(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, MAP(M), LBD(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, MAP(M), LBD(_)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, LBD(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, LBD(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, LBD(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, LBD(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, LBD(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, LBD(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, LBD(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, LBD(_), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, LBD(_), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, LBD(_), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, LBD(_), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, LBD(_), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, LBD(_), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::copy>, LBD(_), LBD(_)>), (FALSE)); \
    ASSERT((metal::copy<PAIR(M), VAL(N)>), (std::conditional_t<M == N, metal::list<VAL(M)>, metal::list<>>)); \
    ASSERT((metal::copy<PAIR(M), INT(N)>), (std::conditional_t<M == N, metal::list<NUM(M)>, metal::list<>>)); \
    ASSERT((metal::copy<metal::list<VALS(M) COMMA(AND(M, N)) ENUM(N, VAL FIX(M))>, VAL(M)>), (metal::list<ENUM(N, VAL FIX(M))>)); \
/**/

GEN(MATRIX)

