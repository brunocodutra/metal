// Copyright Bruno Dutra 2015-2018
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, VALUE(M), VALUE(0), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, VALUE(M), NUMBER(0), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, VALUE(M), PAIR(0), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, VALUE(M), LIST(0), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, VALUE(M), MAP(0), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, VALUE(M), LAMBDA(0), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, NUMBER(M), VALUE(0), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, NUMBER(M), NUMBER(0), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, NUMBER(M), PAIR(0), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, NUMBER(M), LIST(0), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, NUMBER(M), MAP(0), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, NUMBER(M), LAMBDA(0), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, PAIR(M), VALUE(0), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, PAIR(M), NUMBER(0), NUMBER(N)>), (BOOL(N < 3))); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, PAIR(M), PAIR(0), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, PAIR(M), LIST(0), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, PAIR(M), MAP(0), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, PAIR(M), LAMBDA(0), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, LIST(M), VALUE(0), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, LIST(M), NUMBER(0), NUMBER(N)>), (BOOL(M >= N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, LIST(M), PAIR(0), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, LIST(M), LIST(0), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, LIST(M), MAP(0), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, LIST(M), LAMBDA(0), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, MAP(M), VALUE(0), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, MAP(M), NUMBER(0), NUMBER(N)>), (BOOL(M >= N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, MAP(M), PAIR(0), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, MAP(M), LIST(0), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, MAP(M), MAP(0), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, MAP(M), LAMBDA(0), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, LAMBDA(M), VALUE(0), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, LAMBDA(M), NUMBER(0), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, LAMBDA(M), PAIR(0), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, LAMBDA(M), LIST(0), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, LAMBDA(M), MAP(0), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, LAMBDA(M), LAMBDA(0), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, LAMBDA(_), VALUE(0), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, LAMBDA(_), NUMBER(0), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, LAMBDA(_), PAIR(0), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, LAMBDA(_), LIST(0), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, LAMBDA(_), MAP(0), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::erase>, LAMBDA(_), LAMBDA(0), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::erase<LIST(INF), NUMBER(M)>), (metal::erase<LIST(INF), NUMBER(M), NUMBER(INC(M))>)); \
    CHECK((metal::erase<LIST(INF), NUMBER(M), NUMBER(N)>), (metal::erase<LIST(INF), NUMBER(N), NUMBER(M)>)); \
    CHECK((metal::erase<LIST(M), NUMBER(0), NUMBER(M)>), (LIST(0))); \
    CHECK((metal::erase<LIST(INF), NUMBER(INF), NUMBER(M)>), (LIST(M))); \
/**/

GEN(MATRIX)
