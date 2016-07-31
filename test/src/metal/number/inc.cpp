// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/number/inc.hpp>
#include <metal/number/number.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::inc>, VAL(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::inc>, NUM(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::inc>, PAIR(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::inc>, LIST(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::inc>, MAP(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::inc>, LBD(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::inc>, LBD(_)>), (FALSE)); \
    CHECK((metal::inc<NUM(M)>), (test::num<test::value_type<NUM(M)>, M + 1>)); \
/**/

GEN(MATRIX)

