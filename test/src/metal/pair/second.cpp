// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/pair/second.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::second>, VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::second>, NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::second>, PAIR(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::second>, LIST(M)>), (BOOL(M == 2))); \
    ASSERT((metal::is_invocable<test::lambda<metal::second>, MAP(M)>), (BOOL(M == 2))); \
    ASSERT((metal::is_invocable<test::lambda<metal::second>, LBD(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::second>, LBD(_)>), (FALSE)); \
    ASSERT((metal::second<PAIR(M)>), (VAL(M))); \
/**/

GEN(MATRIX)

