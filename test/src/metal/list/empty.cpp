// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/empty.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::empty>, VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::empty>, NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::empty>, PAIR(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::empty>, VECT(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::empty>, LIST(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::empty>, MAP(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::empty>, LBD(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::empty>, LBD(_)>), (FALSE)); \
    ASSERT((metal::empty<PAIR(M)>), (FALSE)); \
    ASSERT((metal::empty<VECT(M)>), (FALSE)); \
    ASSERT((metal::empty<LIST(M)>), (BOOL(!M))); \
    ASSERT((metal::empty<MAP(M)>), (BOOL(!M))); \
    ASSERT((metal::empty<test::list<VALS(M) COMMA(AND(M, N)) VALS(N)>>), (BOOL(!M && !N))); \
    ASSERT((metal::empty<test::list<ENUM(M, VAL FIX(N))>>), (BOOL(!M))); \
/**/

GEN(MATRIX)

