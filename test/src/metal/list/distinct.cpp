// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/distinct.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::distinct>, VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::distinct>, NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::distinct>, PAIR(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::distinct>, VECT(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::distinct>, LIST(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::distinct>, MAP(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::distinct>, LBD(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::distinct>, LBD(_)>), (FALSE)); \
    ASSERT((metal::distinct<PAIR(M)>), (TRUE)); \
    ASSERT((metal::distinct<VECT(M)>), (BOOL(M + 1 == INF))); \
    ASSERT((metal::distinct<LIST(M)>), (TRUE)); \
    ASSERT((metal::distinct<MAP(M)>), (TRUE)); \
    ASSERT((metal::distinct<test::list<VALS(M) COMMA(AND(M, N)) VALS(N)>>), (BOOL(!M || !N))); \
    ASSERT((metal::distinct<test::list<ENUM(M, VAL FIX(N))>>), (BOOL(M < 2))); \
/**/

GEN(MATRIX)

