// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/map/values.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::values>, VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::values>, NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::values>, PAIR(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::values>, VECT(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::values>, LIST(M)>), (BOOL(!M))); \
    ASSERT((metal::is_invocable<test::lambda<metal::values>, MAP(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::values>, LBD(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::values>, LBD(_)>), (FALSE)); \
    ASSERT((metal::values<MAP(M)>), (CAT(test::map, M)<VALS(M)>)); \
/**/

GEN(MATRIX)

