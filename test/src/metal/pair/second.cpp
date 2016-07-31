// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/pair/second.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::second>, VAL(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::second>, NUM(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::second>, PAIR(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::second>, LIST(M)>), (BOOL(M == 2))); \
    CHECK((metal::is_invocable<metal::lambda<metal::second>, MAP(M)>), (BOOL(M == 2))); \
    CHECK((metal::is_invocable<metal::lambda<metal::second>, LBD(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::second>, LBD(_)>), (FALSE)); \
    CHECK((metal::second<PAIR(M)>), (VAL(M))); \
/**/

GEN(MATRIX)

