// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, VALUE(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, VALUE(M), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, VALUE(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, VALUE(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, VALUE(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, VALUE(M), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, VALUE(M), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, NUMBER(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, NUMBER(M), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, NUMBER(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, NUMBER(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, NUMBER(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, NUMBER(M), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, NUMBER(M), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, PAIR(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, PAIR(M), NUMBER(N)>), (BOOL(N < 2))); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, PAIR(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, PAIR(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, PAIR(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, PAIR(M), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, PAIR(M), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, LIST(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, LIST(M), NUMBER(N)>), (BOOL(M > N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, LIST(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, LIST(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, LIST(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, LIST(M), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, LIST(M), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, MAP(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, MAP(M), NUMBER(N)>), (BOOL(M > N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, MAP(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, MAP(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, MAP(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, MAP(M), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, MAP(M), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, LAMBDA(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, LAMBDA(M), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, LAMBDA(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, LAMBDA(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, LAMBDA(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, LAMBDA(M), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, LAMBDA(M), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, LAMBDA(_), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, LAMBDA(_), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, LAMBDA(_), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, LAMBDA(_), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, LAMBDA(_), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, LAMBDA(_), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::at>, LAMBDA(_), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::at<PAIR(M), NUMBER(0)>), (NUMBER(M))); \
    CHECK((metal::at<PAIR(M), NUMBER(1)>), (VALUE(M))); \
    CHECK((metal::at<LIST(INF), NUMBER(M)>), (VALUE(M))); \
    CHECK((metal::at<MAP(INF), NUMBER(M)>), (PAIR(M))); \
/**/

GEN(MATRIX)

