// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/number/neg.hpp>
#include <metal/number/number.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::neg>, VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::neg>, NUM(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::neg>, PAIR(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::neg>, LIST(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::neg>, MAP(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::neg>, LBD(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::neg>, LBD(_)>), (FALSE)); \
    ASSERT((metal::neg<NUM(M)>), (test::num<test::value_type<NUM(M)>, -M>)); \
/**/

GEN(MATRIX)

