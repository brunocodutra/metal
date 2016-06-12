// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/clear.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::clear>, VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::clear>, NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::clear>, PAIR(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::clear>, VECT(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::clear>, LIST(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::clear>, MAP(M)>), (BOOL(!M))); \
    ASSERT((metal::is_invocable<test::lambda<metal::clear>, LBD(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::clear>, LBD(_)>), (FALSE)); \
    ASSERT((metal::clear<VECT(M)>), (VECT(0))); \
    ASSERT((metal::clear<LIST(M)>), (LIST(0))); \
/**/

GEN(MATRIX)

