// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/number/enumerate.hpp>
#include <metal/number/number.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define ENTRY(N, A, B) metal::number<A*N + B>

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, VALUE(M), VALUE(N), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, VALUE(M), NUMBER(N), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, VALUE(M), PAIR(N), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, VALUE(M), LIST(N), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, VALUE(M), MAP(N), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, VALUE(M), LAMBDA(N), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, VALUE(M), LAMBDA(_), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, NUMBER(M), VALUE(N), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, NUMBER(M), NUMBER(N), NUMBER(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, NUMBER(M), PAIR(N), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, NUMBER(M), LIST(N), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, NUMBER(M), MAP(N), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, NUMBER(M), LAMBDA(N), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, NUMBER(M), LAMBDA(_), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, PAIR(M), VALUE(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, PAIR(M), NUMBER(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, PAIR(M), PAIR(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, PAIR(M), LIST(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, PAIR(M), MAP(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, PAIR(M), LAMBDA(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, PAIR(M), LAMBDA(_), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LIST(M), VALUE(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LIST(M), NUMBER(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LIST(M), PAIR(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LIST(M), LIST(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LIST(M), MAP(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LIST(M), LAMBDA(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LIST(M), LAMBDA(_), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, MAP(M), VALUE(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, MAP(M), NUMBER(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, MAP(M), PAIR(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, MAP(M), LIST(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, MAP(M), MAP(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, MAP(M), LAMBDA(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, MAP(M), LAMBDA(_), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LAMBDA(M), VALUE(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LAMBDA(M), NUMBER(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LAMBDA(M), PAIR(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LAMBDA(M), LIST(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LAMBDA(M), MAP(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LAMBDA(M), LAMBDA(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LAMBDA(M), LAMBDA(_), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LAMBDA(_), VALUE(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LAMBDA(_), NUMBER(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LAMBDA(_), PAIR(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LAMBDA(_), LIST(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LAMBDA(_), MAP(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LAMBDA(_), LAMBDA(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LAMBDA(_), LAMBDA(_), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::enumerate<NUMBER(M), NUMBER(N)>), (metal::list<ENUM(N, ENTRY, 1, M)>)); \
    CHECK((metal::enumerate<NUMBER(M), NUMBER(N), NUMBER(M)>), (metal::list<ENUM(N, ENTRY, M, M)>)); \
    CHECK((metal::enumerate<NUMBER(M), metal::number<-N>, metal::number<-M>>), (metal::list<ENUM(N, ENTRY, M, M)>)); \
    CHECK((metal::enumerate<metal::number<-M>, NUMBER(N)>), (metal::list<ENUM(N, ENTRY, 1, -M)>)); \
    CHECK((metal::enumerate<metal::number<-M>, NUMBER(N), NUMBER(M)>), (metal::list<ENUM(N, ENTRY, M, -M)>)); \
    CHECK((metal::enumerate<metal::number<-M>, metal::number<-N>>), (metal::list<ENUM(N, ENTRY, -1, -M)>)); \
    CHECK((metal::enumerate<metal::number<-M>, metal::number<-N>, NUMBER(M)>), (metal::list<ENUM(N, ENTRY, -M, -M)>)); \
    CHECK((metal::enumerate<metal::number<-M>, NUMBER(N), metal::number<-M>>), (metal::list<ENUM(N, ENTRY, -M, -M)>)); \
    CHECK((metal::enumerate<metal::number<-M>, metal::number<-N>, metal::number<-M>>), (metal::list<ENUM(N, ENTRY, M, -M)>)); \
/**/

GEN(MATRIX)
