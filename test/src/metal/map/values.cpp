// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/map/values.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::values>, VAL(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::values>, NUM(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::values>, PAIR(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::values>, LIST(M)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::values>, MAP(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::values>, LBD(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::values>, LBD(_)>), (FALSE)); \
    CHECK((metal::values<MAP(M)>), (metal::list<VALS(M)>)); \
/**/

GEN(MATRIX)

