// Copyright Bruno Dutra 2015-2018
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, VALUE(M), VALUE(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, VALUE(M), NUMBER(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, VALUE(M), PAIR(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, VALUE(M), LIST(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, VALUE(M), MAP(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, VALUE(M), LAMBDA(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, VALUE(M), LAMBDA(_) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, NUMBER(M), VALUE(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, NUMBER(M), NUMBER(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, NUMBER(M), PAIR(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, NUMBER(M), LIST(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, NUMBER(M), MAP(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, NUMBER(M), LAMBDA(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, NUMBER(M), LAMBDA(_) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, PAIR(M), VALUE(N) COMMA(M) VALUES(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, PAIR(M), NUMBER(N) COMMA(M) VALUES(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, PAIR(M), PAIR(N) COMMA(M) VALUES(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, PAIR(M), LIST(N) COMMA(M) VALUES(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, PAIR(M), MAP(N) COMMA(M) VALUES(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, PAIR(M), LAMBDA(N) COMMA(M) VALUES(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, PAIR(M), LAMBDA(_) COMMA(M) VALUES(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LIST(M), VALUE(N) COMMA(M) VALUES(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LIST(M), NUMBER(N) COMMA(M) VALUES(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LIST(M), PAIR(N) COMMA(M) VALUES(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LIST(M), LIST(N) COMMA(M) VALUES(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LIST(M), MAP(N) COMMA(M) VALUES(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LIST(M), LAMBDA(N) COMMA(M) VALUES(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LIST(M), LAMBDA(_) COMMA(M) VALUES(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, MAP(M), VALUE(N) COMMA(M) VALUES(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, MAP(M), NUMBER(N) COMMA(M) VALUES(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, MAP(M), PAIR(N) COMMA(M) VALUES(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, MAP(M), LIST(N) COMMA(M) VALUES(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, MAP(M), MAP(N) COMMA(M) VALUES(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, MAP(M), LAMBDA(N) COMMA(M) VALUES(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, MAP(M), LAMBDA(_) COMMA(M) VALUES(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LAMBDA(M), VALUE(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LAMBDA(M), NUMBER(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LAMBDA(M), PAIR(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LAMBDA(M), LIST(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LAMBDA(M), MAP(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LAMBDA(M), LAMBDA(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LAMBDA(M), LAMBDA(_) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LAMBDA(_), VALUE(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LAMBDA(_), NUMBER(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LAMBDA(_), PAIR(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LAMBDA(_), LIST(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LAMBDA(_), MAP(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LAMBDA(_), LAMBDA(N) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LAMBDA(_), LAMBDA(_) COMMA(M) VALUES(M)>), (FALSE)); \
    CHECK((metal::replace<PAIR(M), VALUE(N), NUMBER(N)>), (metal::list<NUMBER(M), metal::if_<BOOL(M == N), NUMBER(N), VALUE(M)>>)); \
    CHECK((metal::replace<PAIR(M), NUMBER(N), VALUE(N)>), (metal::list<metal::if_<BOOL(M == N), VALUE(N), NUMBER(M)>, VALUE(M)>)); \
    CHECK((metal::replace<metal::list<VALUES(M) COMMA(AND(M, CMPL(M))) ENUM(CMPL(M), NUMBER FIX(N))>, NUMBER(N), VALUE(N)>), (metal::list<VALUES(M) COMMA(AND(M, CMPL(M))) ENUM(CMPL(M), VALUE FIX(N))>)); \
/**/

GEN(MATRIX)

