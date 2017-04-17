// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, VALUE(M), VALUE(0), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, VALUE(M), NUMBER(0), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, VALUE(M), PAIR(0), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, VALUE(M), LIST(0), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, VALUE(M), MAP(0), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, VALUE(M), LAMBDA(0), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, NUMBER(M), VALUE(0), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, NUMBER(M), NUMBER(0), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, NUMBER(M), PAIR(0), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, NUMBER(M), LIST(0), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, NUMBER(M), MAP(0), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, NUMBER(M), LAMBDA(0), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, PAIR(M), VALUE(0), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, PAIR(M), NUMBER(0), NUMBER(N)>), (BOOL(N < 3))); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, PAIR(M), PAIR(0), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, PAIR(M), LIST(0), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, PAIR(M), MAP(0), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, PAIR(M), LAMBDA(0), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LIST(M), VALUE(0), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LIST(M), NUMBER(0), NUMBER(N)>), (BOOL(M >= N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LIST(M), PAIR(0), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LIST(M), LIST(0), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LIST(M), MAP(0), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LIST(M), LAMBDA(0), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, MAP(M), VALUE(0), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, MAP(M), NUMBER(0), NUMBER(N)>), (BOOL(M >= N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, MAP(M), PAIR(0), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, MAP(M), LIST(0), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, MAP(M), MAP(0), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, MAP(M), LAMBDA(0), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LAMBDA(M), VALUE(0), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LAMBDA(M), NUMBER(0), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LAMBDA(M), PAIR(0), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LAMBDA(M), LIST(0), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LAMBDA(M), MAP(0), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LAMBDA(M), LAMBDA(0), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LAMBDA(_), VALUE(0), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LAMBDA(_), NUMBER(0), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LAMBDA(_), PAIR(0), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LAMBDA(_), LIST(0), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LAMBDA(_), MAP(0), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LAMBDA(_), LAMBDA(0), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LIST(INF), metal::number<-M>, NUMBER(N)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LIST(INF), NUMBER(M), metal::number<-N>>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::range>, LIST(INF), NUMBER(M), NUMBER(N)>), (TRUE)); \
    CHECK((metal::range<LIST(M), NUMBER(0), NUMBER(M)>), (LIST(M))); \
    CHECK((metal::range<LIST(M), NUMBER(M), NUMBER(0)>), (metal::list<RENUM(M, VALUE)>)); \
    CHECK((metal::range<LIST(INF), NUMBER(M), NUMBER(INC(M))>), (metal::list<VALUE(M)>)); \
    CHECK((metal::range<LIST(INF), NUMBER(INC(M)), NUMBER(M)>), (metal::list<VALUE(M)>)); \
/**/

GEN(MATRIX)
