// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/take.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, VAL(M), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, VAL(M), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, VAL(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, VAL(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, VAL(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, VAL(M), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, VAL(M), LBD(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, NUM(M), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, NUM(M), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, NUM(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, NUM(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, NUM(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, NUM(M), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, NUM(M), LBD(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, PAIR(M), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, PAIR(M), NUM(N)>), (BOOL(N < 3))); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, PAIR(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, PAIR(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, PAIR(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, PAIR(M), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, PAIR(M), LBD(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LIST(M), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LIST(M), NUM(N)>), (BOOL(M >= N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LIST(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LIST(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LIST(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LIST(M), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LIST(M), LBD(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, MAP(M), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, MAP(M), NUM(N)>), (BOOL(M >= N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, MAP(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, MAP(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, MAP(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, MAP(M), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, MAP(M), LBD(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LBD(M), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LBD(M), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LBD(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LBD(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LBD(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LBD(M), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LBD(M), LBD(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LBD(_), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LBD(_), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LBD(_), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LBD(_), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LBD(_), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LBD(_), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LBD(_), LBD(_)>), (FALSE)); \
    CHECK((metal::take<metal::list<VALS(M) COMMA(AND(M, N)) VALS(N)>, NUM(M)>), (LIST(M))); \
/**/

GEN(MATRIX)
