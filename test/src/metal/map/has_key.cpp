// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/map/has_key.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, VAL(M), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, VAL(M), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, VAL(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, VAL(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, VAL(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, VAL(M), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, VAL(M), LBD(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, NUM(M), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, NUM(M), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, NUM(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, NUM(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, NUM(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, NUM(M), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, NUM(M), LBD(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, PAIR(M), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, PAIR(M), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, PAIR(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, PAIR(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, PAIR(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, PAIR(M), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, PAIR(M), LBD(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LIST(M), VAL(N)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LIST(M), NUM(N)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LIST(M), PAIR(N)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LIST(M), LIST(N)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LIST(M), MAP(N)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LIST(M), LBD(N)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LIST(M), LBD(_)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, MAP(M), VAL(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, MAP(M), NUM(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, MAP(M), PAIR(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, MAP(M), LIST(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, MAP(M), MAP(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, MAP(M), LBD(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, MAP(M), LBD(_)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LBD(M), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LBD(M), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LBD(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LBD(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LBD(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LBD(M), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LBD(M), LBD(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LBD(_), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LBD(_), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LBD(_), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LBD(_), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LBD(_), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LBD(_), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LBD(_), LBD(_)>), (FALSE)); \
    CHECK((metal::has_key<MAP(M), NUM(N)>), (BOOL(M > N))); \
    CHECK((metal::has_key<MAP(M), VAL(N)>), (FALSE)); \
    CHECK((metal::has_key<metal::list<PAIRS(N) COMMA(N) metal::list<NUM(N), LBD(N)>>, NUM(N)>), (TRUE)); \
/**/

GEN(MATRIX)
