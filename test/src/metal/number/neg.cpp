// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/number/neg.hpp>
#include <metal/number/number.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::neg>, VAL(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::neg>, NUM(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::neg>, PAIR(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::neg>, LIST(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::neg>, MAP(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::neg>, LBD(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::neg>, LBD(_)>), (FALSE)); \
    CHECK((metal::neg<NUM(M)>), (test::num<test::value_type<NUM(M)>, -M>)); \
/**/

GEN(MATRIX)

