// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/insert.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, VALUE(M), VALUE(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, VALUE(M), NUMBER(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, VALUE(M), PAIR(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, VALUE(M), LIST(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, VALUE(M), MAP(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, VALUE(M), LAMBDA(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, VALUE(M), LAMBDA(_), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, NUMBER(M), VALUE(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, NUMBER(M), NUMBER(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, NUMBER(M), PAIR(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, NUMBER(M), LIST(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, NUMBER(M), MAP(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, NUMBER(M), LAMBDA(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, NUMBER(M), LAMBDA(_), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, PAIR(M), VALUE(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, PAIR(M), NUMBER(N), VALUE(M)>), (BOOL(N < 3))); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, PAIR(M), PAIR(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, PAIR(M), LIST(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, PAIR(M), MAP(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, PAIR(M), LAMBDA(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, PAIR(M), LAMBDA(_), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LIST(M), VALUE(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LIST(M), NUMBER(N), VALUE(M)>), (BOOL(M >= N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LIST(M), PAIR(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LIST(M), LIST(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LIST(M), MAP(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LIST(M), LAMBDA(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LIST(M), LAMBDA(_), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, MAP(M), VALUE(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, MAP(M), NUMBER(N), VALUE(M)>), (BOOL(M >= N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, MAP(M), PAIR(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, MAP(M), LIST(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, MAP(M), MAP(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, MAP(M), LAMBDA(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, MAP(M), LAMBDA(_), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LAMBDA(M), VALUE(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LAMBDA(M), NUMBER(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LAMBDA(M), PAIR(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LAMBDA(M), LIST(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LAMBDA(M), MAP(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LAMBDA(M), LAMBDA(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LAMBDA(M), LAMBDA(_), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LAMBDA(_), VALUE(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LAMBDA(_), NUMBER(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LAMBDA(_), PAIR(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LAMBDA(_), LIST(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LAMBDA(_), MAP(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LAMBDA(_), LAMBDA(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LAMBDA(_), LAMBDA(_), VALUE(M)>), (FALSE)); \
    CHECK((metal::insert<metal::list<VALUES(M) COMMA(AND(M, CMPL(M))) VALUES(CMPL(M))>, NUMBER(M), NUMBER(N)>), (metal::list<VALUES(M) COMMA(M) NUMBER(N) COMMA(CMPL(M)) VALUES(CMPL(M))>)); \
/**/

GEN(MATRIX)

