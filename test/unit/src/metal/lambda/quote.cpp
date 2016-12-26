// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::quote>, VALUE(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::quote>, NUMBER(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::quote>, PAIR(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::quote>, LIST(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::quote>, MAP(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::quote>, LAMBDA(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::quote>, LAMBDA(_)>), (TRUE)); \
    CHECK((metal::invoke<metal::quote<VALUE(M)> COMMA(N) VALUES(N)>), (VALUE(M))); \
    CHECK((metal::invoke<metal::quote<NUMBER(M)> COMMA(N) VALUES(N)>), (NUMBER(M))); \
    CHECK((metal::invoke<metal::quote<PAIR(M)> COMMA(N) VALUES(N)>), (PAIR(M))); \
    CHECK((metal::invoke<metal::quote<LIST(M)> COMMA(N) VALUES(N)>), (LIST(M))); \
    CHECK((metal::invoke<metal::quote<MAP(M)> COMMA(N) VALUES(N)>), (MAP(M))); \
    CHECK((metal::invoke<metal::quote<LAMBDA(M)> COMMA(N) VALUES(N)>), (LAMBDA(M))); \
    CHECK((metal::invoke<metal::quote<LAMBDA(_)> COMMA(N) VALUES(N)>), (LAMBDA(_))); \
/**/

GEN(MATRIX)
