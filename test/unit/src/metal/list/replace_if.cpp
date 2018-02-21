// Copyright Bruno Dutra 2015-2018
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, VALUE(M), VALUE(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, VALUE(M), NUMBER(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, VALUE(M), PAIR(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, VALUE(M), LIST(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, VALUE(M), MAP(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, VALUE(M), LAMBDA(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, VALUE(M), LAMBDA(_) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, NUMBER(M), VALUE(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, NUMBER(M), NUMBER(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, NUMBER(M), PAIR(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, NUMBER(M), LIST(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, NUMBER(M), MAP(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, NUMBER(M), LAMBDA(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, NUMBER(M), LAMBDA(_) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, PAIR(M), VALUE(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, PAIR(M), NUMBER(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, PAIR(M), PAIR(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, PAIR(M), LIST(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, PAIR(M), MAP(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, PAIR(M), LAMBDA(N) COMMA(M) VALUES(M)>), (BOOL(N == 1))); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, PAIR(M), LAMBDA(_) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LIST(M), VALUE(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LIST(M), NUMBER(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LIST(M), PAIR(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LIST(M), LIST(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LIST(M), MAP(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LIST(M), LAMBDA(N) COMMA(M) VALUES(M)>), (BOOL(!M || N == 1))); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LIST(M), LAMBDA(_) COMMA(M) VALUES(M)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, MAP(M), VALUE(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, MAP(M), NUMBER(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, MAP(M), PAIR(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, MAP(M), LIST(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, MAP(M), MAP(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, MAP(M), LAMBDA(N) COMMA(M) VALUES(M)>), (BOOL(!M || N == 1))); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, MAP(M), LAMBDA(_) COMMA(M) VALUES(M)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LAMBDA(M), VALUE(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LAMBDA(M), NUMBER(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LAMBDA(M), PAIR(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LAMBDA(M), LIST(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LAMBDA(M), MAP(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LAMBDA(M), LAMBDA(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LAMBDA(M), LAMBDA(_) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LAMBDA(_), VALUE(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LAMBDA(_), NUMBER(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LAMBDA(_), PAIR(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LAMBDA(_), LIST(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LAMBDA(_), MAP(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LAMBDA(_), LAMBDA(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LAMBDA(_), LAMBDA(_) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::replace_if<metal::list<ENUM(M, FWD, NUMBER, PAIR, LAMBDA)>, metal::lambda<metal::is_number>, VALUE(N)>), (metal::list<ENUM(M, FWD, VALUE(N) NIL, PAIR, LAMBDA)>)); \
    CHECK((metal::replace_if<metal::list<ENUM(M, FWD, NUMBER, PAIR, LAMBDA)>, metal::lambda<metal::is_pair>, VALUE(N)>), (metal::list<ENUM(M, FWD, NUMBER, VALUE(N) NIL, LAMBDA)>)); \
    CHECK((metal::replace_if<metal::list<ENUM(M, FWD, NUMBER, PAIR, LAMBDA)>, metal::lambda<metal::is_lambda>, VALUE(N)>), (metal::list<ENUM(M, FWD, NUMBER, PAIR, VALUE(N) NIL)>)); \
/**/

GEN(MATRIX)
