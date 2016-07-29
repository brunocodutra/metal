// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/pair/first.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<metal::lambda<metal::first>, VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::first>, NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::first>, PAIR(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::first>, LIST(M)>), (BOOL(M == 2))); \
    ASSERT((metal::is_invocable<metal::lambda<metal::first>, MAP(M)>), (BOOL(M == 2))); \
    ASSERT((metal::is_invocable<metal::lambda<metal::first>, LBD(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::first>, LBD(_)>), (FALSE)); \
    ASSERT((metal::first<PAIR(M)>), (NUM(M))); \
/**/

GEN(MATRIX)

