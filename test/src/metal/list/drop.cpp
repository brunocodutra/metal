// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/drop.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, VAL(M), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, VAL(M), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, VAL(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, VAL(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, VAL(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, VAL(M), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, VAL(M), LBD(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, NUM(M), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, NUM(M), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, NUM(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, NUM(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, NUM(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, NUM(M), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, NUM(M), LBD(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, PAIR(M), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, PAIR(M), NUM(N)>), (BOOL(N < 3))); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, PAIR(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, PAIR(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, PAIR(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, PAIR(M), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, PAIR(M), LBD(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, LIST(M), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, LIST(M), NUM(N)>), (BOOL(M >= N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, LIST(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, LIST(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, LIST(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, LIST(M), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, LIST(M), LBD(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, MAP(M), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, MAP(M), NUM(N)>), (BOOL(M >= N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, MAP(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, MAP(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, MAP(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, MAP(M), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, MAP(M), LBD(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, LBD(M), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, LBD(M), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, LBD(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, LBD(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, LBD(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, LBD(M), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::drop>, LBD(M), LBD(_)>), (FALSE)); \
    CHECK((metal::drop<metal::list<VALS(M) COMMA(AND(M, N)) VALS(N)>, NUM(M)>), (LIST(N))); \
/**/

GEN(MATRIX)
