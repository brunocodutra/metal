// Copyright Bruno Dutra 2015-2018
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::not_>, VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::not_>, NUMBER(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::not_>, PAIR(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::not_>, LIST(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::not_>, MAP(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::not_>, LAMBDA(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::not_>, LAMBDA(_)>), (FALSE)); \
    CHECK((metal::not_<NUMBER(M)>), (BOOL(!M))); \
/**/

GEN(MATRIX)

