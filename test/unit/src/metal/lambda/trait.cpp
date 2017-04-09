// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::trait<EXPR(N)>, VALUE(M)>), (BOOL(N == 1))); \
    CHECK((metal::is_invocable<metal::trait<EXPR(N)>, NUMBER(M)>), (BOOL(N == 1))); \
    CHECK((metal::is_invocable<metal::trait<EXPR(N)>, PAIR(M)>), (BOOL(N == 1))); \
    CHECK((metal::is_invocable<metal::trait<EXPR(N)>, LIST(M)>), (BOOL(N == 1))); \
    CHECK((metal::is_invocable<metal::trait<EXPR(N)>, MAP(M)>), (BOOL(N == 1))); \
    CHECK((metal::is_invocable<metal::trait<EXPR(N)>, LAMBDA(M)>), (BOOL(N == 1))); \
    CHECK((metal::is_invocable<metal::trait<EXPR(N)>, LAMBDA(_)>), (BOOL(N == 1))); \
    CHECK((metal::is_invocable<metal::trait<EXPR(_)>, VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::trait<EXPR(_)>, NUMBER(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::trait<EXPR(_)>, PAIR(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::trait<EXPR(_)>, LIST(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::trait<EXPR(_)>, MAP(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::trait<EXPR(_)>, LAMBDA(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::trait<EXPR(_)>, LAMBDA(_)>), (FALSE)); \
    CHECK((metal::invoke<metal::trait<EXPR(1)>, NUMBER(N)>), (NUMBER(1))); \
/**/

GEN(MATRIX)
