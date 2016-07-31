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
    CHECK((metal::is_invocable<metal::lambda<metal::first>, VAL(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::first>, NUM(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::first>, PAIR(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::first>, LIST(M)>), (BOOL(M == 2))); \
    CHECK((metal::is_invocable<metal::lambda<metal::first>, MAP(M)>), (BOOL(M == 2))); \
    CHECK((metal::is_invocable<metal::lambda<metal::first>, LBD(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::first>, LBD(_)>), (FALSE)); \
    CHECK((metal::first<PAIR(M)>), (NUM(M))); \
/**/

GEN(MATRIX)

