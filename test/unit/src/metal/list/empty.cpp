// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::empty>, VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::empty>, NUMBER(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::empty>, PAIR(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::empty>, LIST(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::empty>, MAP(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::empty>, LAMBDA(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::empty>, LAMBDA(_)>), (FALSE)); \
    CHECK((metal::empty<PAIR(M)>), (FALSE)); \
    CHECK((metal::empty<LIST(M)>), (BOOL(!M))); \
    CHECK((metal::empty<MAP(M)>), (BOOL(!M))); \
    CHECK((metal::empty<metal::list<VALUES(M) COMMA(AND(M, N)) VALUES(N)>>), (BOOL(!M && !N))); \
    CHECK((metal::empty<metal::list<ENUM(M, VALUE FIX(N))>>), (BOOL(!M))); \
/**/

GEN(MATRIX)

