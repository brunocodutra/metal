// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, VALUE(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, VALUE(M), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, VALUE(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, VALUE(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, VALUE(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, VALUE(M), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, VALUE(M), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, NUMBER(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, NUMBER(M), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, NUMBER(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, NUMBER(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, NUMBER(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, NUMBER(M), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, NUMBER(M), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, PAIR(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, PAIR(M), NUMBER(N)>), (BOOL(N < 3))); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, PAIR(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, PAIR(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, PAIR(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, PAIR(M), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, PAIR(M), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LIST(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LIST(M), NUMBER(N)>), (BOOL(M >= N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LIST(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LIST(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LIST(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LIST(M), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LIST(M), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, MAP(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, MAP(M), NUMBER(N)>), (BOOL(M >= N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, MAP(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, MAP(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, MAP(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, MAP(M), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, MAP(M), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LAMBDA(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LAMBDA(M), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LAMBDA(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LAMBDA(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LAMBDA(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LAMBDA(M), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LAMBDA(M), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LAMBDA(_), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LAMBDA(_), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LAMBDA(_), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LAMBDA(_), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LAMBDA(_), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LAMBDA(_), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::take>, LAMBDA(_), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::take<metal::list<VALUES(M) COMMA(AND(M, N)) VALUES(N)>, NUMBER(M)>), (LIST(M))); \
/**/

GEN(MATRIX)
