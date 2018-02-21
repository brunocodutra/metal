// Copyright Bruno Dutra 2015-2018
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::always>, VALUE(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::always>, NUMBER(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::always>, PAIR(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::always>, LIST(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::always>, MAP(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::always>, LAMBDA(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::always>, LAMBDA(_)>), (TRUE)); \
    CHECK((metal::invoke<metal::always<VALUE(M)> COMMA(N) VALUES(N)>), (VALUE(M))); \
    CHECK((metal::invoke<metal::always<NUMBER(M)> COMMA(N) VALUES(N)>), (NUMBER(M))); \
    CHECK((metal::invoke<metal::always<PAIR(M)> COMMA(N) VALUES(N)>), (PAIR(M))); \
    CHECK((metal::invoke<metal::always<LIST(M)> COMMA(N) VALUES(N)>), (LIST(M))); \
    CHECK((metal::invoke<metal::always<MAP(M)> COMMA(N) VALUES(N)>), (MAP(M))); \
    CHECK((metal::invoke<metal::always<LAMBDA(M)> COMMA(N) VALUES(N)>), (LAMBDA(M))); \
    CHECK((metal::invoke<metal::always<LAMBDA(_)> COMMA(N) VALUES(N)>), (LAMBDA(_))); \
/**/

GEN(MATRIX)
