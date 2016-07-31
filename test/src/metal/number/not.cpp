// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/number/not.hpp>
#include <metal/number/number.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::not_>, VAL(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::not_>, NUM(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::not_>, PAIR(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::not_>, LIST(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::not_>, MAP(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::not_>, LBD(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::not_>, LBD(_)>), (FALSE)); \
    CHECK((metal::not_<NUM(M)>), (BOOL(!M))); \
/**/

GEN(MATRIX)

