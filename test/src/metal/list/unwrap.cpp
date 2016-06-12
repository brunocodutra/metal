// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/unwrap.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lambda.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::unwrap>, VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::unwrap>, NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::unwrap>, PAIR(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::unwrap>, VECT(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::unwrap>, LIST(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::unwrap>, MAP(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::unwrap>, LBD(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::unwrap>, LBD(_)>), (FALSE)); \
    ASSERT((metal::unwrap<PAIR(M)>), (metal::lambda<test::pair>)); \
    ASSERT((metal::unwrap<VECT(M)>), (metal::lambda<test::vect>)); \
    ASSERT((metal::unwrap<LIST(M)>), (metal::lambda<test::list>)); \
    ASSERT((metal::unwrap<MAP(INC(M))>), (metal::lambda<CAT(test::map, INC(M))>)); \
/**/

GEN(MATRIX)

