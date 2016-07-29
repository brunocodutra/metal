// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/number/enumerate.hpp>
#include <metal/number/number.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define ENTRY(N, TYPE, A, B) test::num<TYPE, A*N + B>

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, VAL(M), VAL(N), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, VAL(M), NUM(N), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, VAL(M), PAIR(N), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, VAL(M), LIST(N), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, VAL(M), MAP(N), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, VAL(M), LBD(N), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, VAL(M), LBD(_), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, NUM(M), VAL(N), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, NUM(M), NUM(N), NUM(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, NUM(M), PAIR(N), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, NUM(M), LIST(N), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, NUM(M), MAP(N), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, NUM(M), LBD(N), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, NUM(M), LBD(_), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, PAIR(M), VAL(N), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, PAIR(M), NUM(N), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, PAIR(M), PAIR(N), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, PAIR(M), LIST(N), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, PAIR(M), MAP(N), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, PAIR(M), LBD(N), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, PAIR(M), LBD(_), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, LIST(M), VAL(N), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, LIST(M), NUM(N), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, LIST(M), PAIR(N), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, LIST(M), LIST(N), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, LIST(M), MAP(N), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, LIST(M), LBD(N), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, LIST(M), LBD(_), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, MAP(M), VAL(N), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, MAP(M), NUM(N), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, MAP(M), PAIR(N), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, MAP(M), LIST(N), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, MAP(M), MAP(N), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, MAP(M), LBD(N), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, MAP(M), LBD(_), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, LBD(M), VAL(N), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, LBD(M), NUM(N), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, LBD(M), PAIR(N), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, LBD(M), LIST(N), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, LBD(M), MAP(N), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, LBD(M), LBD(N), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, LBD(M), LBD(_), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, LBD(_), VAL(N), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, LBD(_), NUM(N), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, LBD(_), PAIR(N), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, LBD(_), LIST(N), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, LBD(_), MAP(N), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, LBD(_), LBD(N), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::enumerate>, LBD(_), LBD(_), LBD(N)>), (FALSE)); \
    ASSERT((metal::enumerate<NUM(M), NUM(N)>), (metal::list<ENUM(N, ENTRY, test::value_type<NUM(M)>, 1, M)>)); \
    ASSERT((metal::enumerate<NUM(M), NUM(N), NUM(M)>), (metal::list<ENUM(N, ENTRY, test::value_type<NUM(M)>, M, M)>)); \
    ASSERT((metal::enumerate<NUM(M), INT(-N), INT(-M)>), (metal::list<ENUM(N, ENTRY, test::value_type<NUM(M)>, M, M)>)); \
    ASSERT((metal::enumerate<INT(-M), NUM(N)>), (metal::list<ENUM(N, ENTRY, int, 1, -M)>)); \
    ASSERT((metal::enumerate<INT(-M), NUM(N), NUM(M)>), (metal::list<ENUM(N, ENTRY, int, M, -M)>)); \
    ASSERT((metal::enumerate<INT(-M), INT(-N)>), (metal::list<ENUM(N, ENTRY, int, -1, -M)>)); \
    ASSERT((metal::enumerate<INT(-M), INT(-N), NUM(M)>), (metal::list<ENUM(N, ENTRY, int, -M, -M)>)); \
    ASSERT((metal::enumerate<INT(-M), NUM(N), INT(-M)>), (metal::list<ENUM(N, ENTRY, int, -M, -M)>)); \
    ASSERT((metal::enumerate<INT(-M), INT(-N), INT(-M)>), (metal::list<ENUM(N, ENTRY, int, M, -M)>)); \
/**/

GEN(MATRIX)
