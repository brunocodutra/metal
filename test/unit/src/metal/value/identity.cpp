// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::identity>, VALUE(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::identity>, NUMBER(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::identity>, PAIR(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::identity>, LIST(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::identity>, MAP(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::identity>, LAMBDA(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::identity>, LAMBDA(_)>), (TRUE)); \
    CHECK((metal::identity<VALUE(N)>), (VALUE(N))); \
    CHECK((metal::identity<NUMBER(N)>), (NUMBER(N))); \
    CHECK((metal::identity<PAIR(N)>), (PAIR(N))); \
    CHECK((metal::identity<LIST(N)>), (LIST(N))); \
    CHECK((metal::identity<MAP(N)>), (MAP(N))); \
    CHECK((metal::identity<LAMBDA(N)>), (LAMBDA(N))); \
    CHECK((metal::identity<LAMBDA(_)>), (LAMBDA(_))); \
/**/

GEN(MATRIX)
