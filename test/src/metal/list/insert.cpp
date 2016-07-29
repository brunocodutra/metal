// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/insert.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, VAL(M), VAL(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, VAL(M), NUM(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, VAL(M), PAIR(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, VAL(M), LIST(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, VAL(M), MAP(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, VAL(M), LBD(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, VAL(M), LBD(_), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, NUM(M), VAL(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, NUM(M), NUM(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, NUM(M), PAIR(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, NUM(M), LIST(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, NUM(M), MAP(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, NUM(M), LBD(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, NUM(M), LBD(_), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, PAIR(M), VAL(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, PAIR(M), NUM(N), VAL(M)>), (BOOL(N < 3))); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, PAIR(M), PAIR(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, PAIR(M), LIST(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, PAIR(M), MAP(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, PAIR(M), LBD(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, PAIR(M), LBD(_), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, LIST(M), VAL(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, LIST(M), NUM(N), VAL(M)>), (BOOL(M >= N))); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, LIST(M), PAIR(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, LIST(M), LIST(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, LIST(M), MAP(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, LIST(M), LBD(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, LIST(M), LBD(_), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, MAP(M), VAL(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, MAP(M), NUM(N), VAL(M)>), (BOOL(M >= N))); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, MAP(M), PAIR(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, MAP(M), LIST(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, MAP(M), MAP(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, MAP(M), LBD(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, MAP(M), LBD(_), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, LBD(M), VAL(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, LBD(M), NUM(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, LBD(M), PAIR(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, LBD(M), LIST(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, LBD(M), MAP(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, LBD(M), LBD(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, LBD(M), LBD(_), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, LBD(_), VAL(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, LBD(_), NUM(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, LBD(_), PAIR(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, LBD(_), LIST(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, LBD(_), MAP(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, LBD(_), LBD(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::insert>, LBD(_), LBD(_), VAL(M)>), (FALSE)); \
    ASSERT((metal::insert<metal::list<VALS(M) COMMA(AND(M, CMPL(M))) VALS(CMPL(M))>, NUM(M), NUM(N)>), (metal::list<VALS(M) COMMA(M) NUM(N) COMMA(CMPL(M)) VALS(CMPL(M))>)); \
/**/

GEN(MATRIX)

