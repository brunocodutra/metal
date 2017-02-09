// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::value>, VALUE(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::value>, NUMBER(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::value>, PAIR(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::value>, LIST(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::value>, MAP(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::value>, LAMBDA(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::value>, LAMBDA(_)>), (TRUE)); \
    CHECK((metal::is_value<VALUE(N)>), (TRUE)); \
    CHECK((metal::is_value<NUMBER(N)>), (TRUE)); \
    CHECK((metal::is_value<PAIR(N)>), (TRUE)); \
    CHECK((metal::is_value<LIST(N)>), (TRUE)); \
    CHECK((metal::is_value<MAP(N)>), (TRUE)); \
    CHECK((metal::is_value<LAMBDA(N)>), (TRUE)); \
    CHECK((metal::is_value<LAMBDA(_)>), (TRUE)); \
    CHECK((metal::value<>), (metal::nil)); \
/**/

GEN(MATRIX)
