// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/slice.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, VAL(M), VAL(0), VAL(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, VAL(M), NUM(0), NUM(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, VAL(M), PAIR(0), PAIR(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, VAL(M), LIST(0), LIST(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, VAL(M), MAP(0), MAP(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, VAL(M), LBD(0), LBD(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, VAL(M), LBD(M), LBD(_), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, NUM(M), VAL(0), VAL(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, NUM(M), NUM(0), NUM(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, NUM(M), PAIR(0), PAIR(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, NUM(M), LIST(0), LIST(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, NUM(M), MAP(0), MAP(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, NUM(M), LBD(0), LBD(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, NUM(M), LBD(M), LBD(_), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, PAIR(M), VAL(0), VAL(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, PAIR(M), NUM(0), NUM(N), NUM(1)>), (BOOL(N < 3))); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, PAIR(M), PAIR(0), PAIR(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, PAIR(M), LIST(0), LIST(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, PAIR(M), MAP(0), MAP(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, PAIR(M), LBD(0), LBD(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, PAIR(M), LBD(M), LBD(_), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LIST(M), VAL(0), VAL(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LIST(M), NUM(0), NUM(N), NUM(1)>), (BOOL(M >= N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LIST(M), PAIR(0), PAIR(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LIST(M), LIST(0), LIST(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LIST(M), MAP(0), MAP(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LIST(M), LBD(0), LBD(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LIST(M), LBD(M), LBD(_), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, MAP(M), VAL(0), VAL(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, MAP(M), NUM(0), NUM(N), NUM(1)>), (BOOL(M >= N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, MAP(M), PAIR(0), PAIR(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, MAP(M), LIST(0), LIST(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, MAP(M), MAP(0), MAP(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, MAP(M), LBD(0), LBD(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, MAP(M), LBD(M), LBD(_), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LBD(M), VAL(0), VAL(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LBD(M), NUM(0), NUM(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LBD(M), PAIR(0), PAIR(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LBD(M), LIST(0), LIST(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LBD(M), MAP(0), MAP(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LBD(M), LBD(0), LBD(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LBD(M), LBD(M), LBD(_), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LBD(_), VAL(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LBD(_), NUM(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LBD(_), PAIR(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LBD(_), LIST(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LBD(_), MAP(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LBD(_), LBD(N), NUM(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LBD(_), LBD(_), NUM(1)>), (FALSE)); \
    CHECK((metal::slice<LIST(INF), NUM(0), NUM(M)>), (LIST(M))); \
    CHECK((metal::slice<LIST(INF), NUM(M), NUM(N), NUM(0)>), (metal::list<ENUM(N, VAL FIX(M))>)); \
    CHECK((metal::slice<LIST(INF), NUM(M), NUM(M), INT(-1)>), (metal::list<RENUM(M, VAL LIFT(INC))>)); \
/**/

GEN(MATRIX)
