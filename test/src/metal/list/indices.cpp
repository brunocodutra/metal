// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/indices.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::indices>, VAL(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::indices>, NUM(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::indices>, PAIR(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::indices>, LIST(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::indices>, MAP(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::indices>, LBD(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::indices>, LBD(_)>), (FALSE)); \
    CHECK((metal::indices<PAIR(M)>), (metal::list<NUMS(2)>)); \
    CHECK((metal::indices<LIST(M)>), (metal::list<NUMS(M)>)); \
    CHECK((metal::indices<MAP(M)>), (metal::list<NUMS(M)>)); \
/**/

GEN(MATRIX)

