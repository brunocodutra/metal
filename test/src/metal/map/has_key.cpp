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
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, VAL(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, VAL(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, VAL(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, VAL(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, VAL(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, VAL(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, VAL(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, NUM(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, NUM(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, NUM(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, NUM(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, NUM(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, NUM(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, NUM(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, PAIR(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, PAIR(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, PAIR(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, PAIR(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, PAIR(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, PAIR(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, PAIR(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, LIST(M), VAL(N)>), (BOOL(!M))); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, LIST(M), NUM(N)>), (BOOL(!M))); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, LIST(M), PAIR(N)>), (BOOL(!M))); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, LIST(M), LIST(N)>), (BOOL(!M))); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, LIST(M), MAP(N)>), (BOOL(!M))); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, LIST(M), LBD(N)>), (BOOL(!M))); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, LIST(M), LBD(_)>), (BOOL(!M))); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, MAP(M), VAL(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, MAP(M), NUM(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, MAP(M), PAIR(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, MAP(M), LIST(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, MAP(M), MAP(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, MAP(M), LBD(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, MAP(M), LBD(_)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, LBD(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, LBD(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, LBD(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, LBD(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, LBD(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, LBD(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, LBD(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, LBD(_), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, LBD(_), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, LBD(_), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, LBD(_), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, LBD(_), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, LBD(_), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::has_key>, LBD(_), LBD(_)>), (FALSE)); \
    ASSERT((metal::has_key<MAP(M), NUM(N)>), (BOOL(M > N))); \
    ASSERT((metal::has_key<MAP(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::has_key<metal::list<PAIRS(N) COMMA(N) metal::list<NUM(N), LBD(N)>>, NUM(N)>), (TRUE)); \
/**/

GEN(MATRIX)
