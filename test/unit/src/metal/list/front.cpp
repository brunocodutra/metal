// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::front>, VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::front>, NUMBER(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::front>, PAIR(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::front>, LIST(M)>), (BOOL(M > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::front>, MAP(M)>), (BOOL(M > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::front>, LAMBDA(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::front>, LAMBDA(_)>), (FALSE)); \
    CHECK((metal::front<PAIR(M)>), (NUMBER(M))); \
    CHECK((metal::front<LIST(INC(M))>), (VALUE(0))); \
    CHECK((metal::front<MAP(INC(M))>), (PAIR(0))); \
/**/

GEN(MATRIX)

