// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/value/value.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::value>, VAL(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::value>, NUM(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::value>, PAIR(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::value>, LIST(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::value>, MAP(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::value>, LBD(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::value>, LBD(_)>), (TRUE)); \
    CHECK((metal::is_value<VAL(N)>), (TRUE)); \
    CHECK((metal::is_value<NUM(N)>), (TRUE)); \
    CHECK((metal::is_value<PAIR(N)>), (TRUE)); \
    CHECK((metal::is_value<LIST(N)>), (TRUE)); \
    CHECK((metal::is_value<MAP(N)>), (TRUE)); \
    CHECK((metal::is_value<LBD(N)>), (TRUE)); \
    CHECK((metal::is_value<LBD(_)>), (TRUE)); \
/**/

GEN(MATRIX)
