// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, VALUE(M), VALUE(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, VALUE(M), NUMBER(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, VALUE(M), PAIR(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, VALUE(M), LIST(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, VALUE(M), MAP(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, VALUE(M), LAMBDA(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, VALUE(M), LAMBDA(_), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, NUMBER(M), VALUE(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, NUMBER(M), NUMBER(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, NUMBER(M), PAIR(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, NUMBER(M), LIST(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, NUMBER(M), MAP(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, NUMBER(M), LAMBDA(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, NUMBER(M), LAMBDA(_), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, PAIR(M), VALUE(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, PAIR(M), NUMBER(N), VALUES(INC(N))>), (BOOL(N < 3))); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, PAIR(M), PAIR(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, PAIR(M), LIST(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, PAIR(M), MAP(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, PAIR(M), LAMBDA(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, PAIR(M), LAMBDA(_), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LIST(M), VALUE(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LIST(M), NUMBER(N), VALUES(INC(N))>), (BOOL(M >= N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LIST(M), PAIR(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LIST(M), LIST(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LIST(M), MAP(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LIST(M), LAMBDA(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LIST(M), LAMBDA(_), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, MAP(M), VALUE(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, MAP(M), NUMBER(N), VALUES(INC(N))>), (BOOL(M >= N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, MAP(M), PAIR(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, MAP(M), LIST(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, MAP(M), MAP(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, MAP(M), LAMBDA(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, MAP(M), LAMBDA(_), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LAMBDA(M), VALUE(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LAMBDA(M), NUMBER(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LAMBDA(M), PAIR(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LAMBDA(M), LIST(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LAMBDA(M), MAP(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LAMBDA(M), LAMBDA(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LAMBDA(M), LAMBDA(_), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LAMBDA(_), VALUE(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LAMBDA(_), NUMBER(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LAMBDA(_), PAIR(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LAMBDA(_), LIST(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LAMBDA(_), MAP(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LAMBDA(_), LAMBDA(N), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert>, LAMBDA(_), LAMBDA(_), VALUES(INC(N))>), (FALSE)); \
    CHECK((metal::insert<metal::list<VALUES(M) COMMA(AND(M, CMPL(M))) VALUES(CMPL(M))>, NUMBER(M), NUMBERS(INC(N))>), (metal::list<VALUES(M) COMMA(M) NUMBERS(INC(N)) COMMA(CMPL(M)) VALUES(CMPL(M))>)); \
/**/

GEN(MATRIX)

