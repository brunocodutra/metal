// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/number/cast.hpp>
#include <metal/number/number.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, VAL(M), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, VAL(M), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, VAL(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, VAL(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, VAL(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, VAL(M), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, VAL(M), LBD(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, NUM(M), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, NUM(M), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, NUM(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, NUM(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, NUM(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, NUM(M), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, NUM(M), LBD(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, PAIR(M), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, PAIR(M), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, PAIR(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, PAIR(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, PAIR(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, PAIR(M), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, PAIR(M), LBD(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, LIST(M), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, LIST(M), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, LIST(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, LIST(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, LIST(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, LIST(M), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, LIST(M), LBD(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, MAP(M), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, MAP(M), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, MAP(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, MAP(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, MAP(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, MAP(M), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, MAP(M), LBD(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, LBD(M), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, LBD(M), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, LBD(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, LBD(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, LBD(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, LBD(M), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, LBD(M), LBD(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, LBD(_), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, LBD(_), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, LBD(_), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, LBD(_), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, LBD(_), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, LBD(_), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, LBD(_), LBD(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, NUM(M), bool>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, test::num<std::int16_t, -M>, std::uint16_t>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, test::num<std::uint16_t, -M>, std::int16_t>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::cast>, test::num<std::uint16_t, -M>, std::int64_t>), (TRUE)); \
    CHECK((metal::cast<NUM(M), bool>), (metal::bool_<IF(M)(true, false)>)); \
    CHECK((metal::cast<NUM(M), int>), (metal::int_<M>)); \
/**/

GEN(MATRIX)

