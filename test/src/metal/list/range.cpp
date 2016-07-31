// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/range.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, VAL(M), VAL(0), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, VAL(M), NUM(0), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, VAL(M), PAIR(0), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, VAL(M), LIST(0), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, VAL(M), MAP(0), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, VAL(M), LBD(0), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, NUM(M), VAL(0), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, NUM(M), NUM(0), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, NUM(M), PAIR(0), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, NUM(M), LIST(0), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, NUM(M), MAP(0), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, NUM(M), LBD(0), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, PAIR(M), VAL(0), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, PAIR(M), NUM(0), NUM(N)>), (BOOL(N < 3))); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, PAIR(M), PAIR(0), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, PAIR(M), LIST(0), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, PAIR(M), MAP(0), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, PAIR(M), LBD(0), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LIST(M), VAL(0), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LIST(M), NUM(0), NUM(N)>), (BOOL(M >= N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LIST(M), PAIR(0), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LIST(M), LIST(0), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LIST(M), MAP(0), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LIST(M), LBD(0), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, MAP(M), VAL(0), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, MAP(M), NUM(0), NUM(N)>), (BOOL(M >= N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, MAP(M), PAIR(0), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, MAP(M), LIST(0), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, MAP(M), MAP(0), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, MAP(M), LBD(0), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LBD(M), VAL(0), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LBD(M), NUM(0), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LBD(M), PAIR(0), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LBD(M), LIST(0), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LBD(M), MAP(0), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LBD(M), LBD(0), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LBD(_), VAL(0), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LBD(_), NUM(0), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LBD(_), PAIR(0), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LBD(_), LIST(0), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LBD(_), MAP(0), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LBD(_), LBD(0), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LIST(INF), NUM(M), NUM(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, MAP(INF), NUM(M), NUM(N)>), (TRUE)); \
    CHECK((metal::range<LIST(M), NUM(0), NUM(M)>), (LIST(M))); \
    CHECK((metal::range<LIST(M), NUM(M), NUM(0)>), (metal::list<RENUM(M, VAL)>)); \
    CHECK((metal::range<LIST(INF), NUM(M), NUM(INC(M))>), (metal::list<VAL(M)>)); \
    CHECK((metal::range<LIST(INF), NUM(INC(M)), NUM(M)>), (metal::list<VAL(M)>)); \
/**/

GEN(MATRIX)
