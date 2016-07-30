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
    ASSERT((metal::is_invocable<metal::lambda<metal::value>, VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::value>, NUM(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::value>, PAIR(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::value>, LIST(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::value>, MAP(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::value>, LBD(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::value>, LBD(_)>), (TRUE)); \
    ASSERT((metal::is_value<VAL(N)>), (TRUE)); \
    ASSERT((metal::is_value<NUM(N)>), (TRUE)); \
    ASSERT((metal::is_value<PAIR(N)>), (TRUE)); \
    ASSERT((metal::is_value<LIST(N)>), (TRUE)); \
    ASSERT((metal::is_value<MAP(N)>), (TRUE)); \
    ASSERT((metal::is_value<LBD(N)>), (TRUE)); \
    ASSERT((metal::is_value<LBD(_)>), (TRUE)); \
/**/

GEN(MATRIX)
