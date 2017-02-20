// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::dec>, VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::dec>, NUMBER(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::dec>, PAIR(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::dec>, LIST(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::dec>, MAP(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::dec>, LAMBDA(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::dec>, LAMBDA(_)>), (FALSE)); \
    CHECK((metal::dec<NUMBER(M)>), (metal::number<M - 1>)); \
/**/

GEN(MATRIX)

