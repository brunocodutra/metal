// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, VALUE(M), VALUE(0), VALUE(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, VALUE(M), NUMBER(0), NUMBER(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, VALUE(M), PAIR(0), PAIR(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, VALUE(M), LIST(0), LIST(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, VALUE(M), MAP(0), MAP(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, VALUE(M), LAMBDA(0), LAMBDA(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, VALUE(M), LAMBDA(M), LAMBDA(_), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, NUMBER(M), VALUE(0), VALUE(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, NUMBER(M), NUMBER(0), NUMBER(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, NUMBER(M), PAIR(0), PAIR(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, NUMBER(M), LIST(0), LIST(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, NUMBER(M), MAP(0), MAP(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, NUMBER(M), LAMBDA(0), LAMBDA(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, NUMBER(M), LAMBDA(M), LAMBDA(_), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, PAIR(M), VALUE(0), VALUE(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, PAIR(M), NUMBER(0), NUMBER(N), NUMBER(1)>), (BOOL(N < 3))); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, PAIR(M), PAIR(0), PAIR(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, PAIR(M), LIST(0), LIST(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, PAIR(M), MAP(0), MAP(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, PAIR(M), LAMBDA(0), LAMBDA(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, PAIR(M), LAMBDA(M), LAMBDA(_), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LIST(M), VALUE(0), VALUE(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LIST(M), NUMBER(0), NUMBER(N), NUMBER(1)>), (BOOL(M >= N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LIST(M), PAIR(0), PAIR(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LIST(M), LIST(0), LIST(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LIST(M), MAP(0), MAP(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LIST(M), LAMBDA(0), LAMBDA(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LIST(M), LAMBDA(M), LAMBDA(_), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, MAP(M), VALUE(0), VALUE(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, MAP(M), NUMBER(0), NUMBER(N), NUMBER(1)>), (BOOL(M >= N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, MAP(M), PAIR(0), PAIR(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, MAP(M), LIST(0), LIST(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, MAP(M), MAP(0), MAP(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, MAP(M), LAMBDA(0), LAMBDA(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, MAP(M), LAMBDA(M), LAMBDA(_), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LAMBDA(M), VALUE(0), VALUE(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LAMBDA(M), NUMBER(0), NUMBER(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LAMBDA(M), PAIR(0), PAIR(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LAMBDA(M), LIST(0), LIST(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LAMBDA(M), MAP(0), MAP(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LAMBDA(M), LAMBDA(0), LAMBDA(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LAMBDA(M), LAMBDA(M), LAMBDA(_), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LAMBDA(_), VALUE(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LAMBDA(_), NUMBER(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LAMBDA(_), PAIR(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LAMBDA(_), LIST(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LAMBDA(_), MAP(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LAMBDA(_), LAMBDA(N), NUMBER(1)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LAMBDA(_), LAMBDA(_), NUMBER(1)>), (FALSE)); \
    CHECK((metal::slice<LIST(INF), NUMBER(0), NUMBER(M)>), (LIST(M))); \
    CHECK((metal::slice<LIST(INF), NUMBER(M), NUMBER(N), NUMBER(0)>), (metal::list<ENUM(N, VALUE FIX(M))>)); \
    CHECK((metal::slice<LIST(INF), NUMBER(M), NUMBER(M), NUMBER(-1)>), (metal::list<RENUM(M, VALUE LIFT(INC))>)); \
/**/

GEN(MATRIX)
