// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/reverse.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::reverse>, VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reverse>, NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reverse>, PAIR(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reverse>, LIST(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reverse>, MAP(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reverse>, LBD(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reverse>, LBD(_)>), (FALSE)); \
    ASSERT((metal::reverse<PAIR(M)>), (metal::list<VAL(M), NUM(M)>)); \
    ASSERT((metal::reverse<LIST(M)>), (metal::list<RENUM(M, VAL)>)); \
    ASSERT((metal::reverse<MAP(M)>), (metal::list<RENUM(M, PAIR)>)); \
/**/

GEN(MATRIX)

