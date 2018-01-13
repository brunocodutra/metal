// Copyright Bruno Dutra 2015-2018
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, VALUE(M), VALUE(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, VALUE(M), NUMBER(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, VALUE(M), PAIR(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, VALUE(M), LIST(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, VALUE(M), MAP(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, VALUE(M), LAMBDA(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, VALUE(M), LAMBDA(_), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, NUMBER(M), VALUE(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, NUMBER(M), NUMBER(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, NUMBER(M), PAIR(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, NUMBER(M), LIST(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, NUMBER(M), MAP(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, NUMBER(M), LAMBDA(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, NUMBER(M), LAMBDA(_), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, PAIR(M), VALUE(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, PAIR(M), NUMBER(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, PAIR(M), PAIR(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, PAIR(M), LIST(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, PAIR(M), MAP(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, PAIR(M), LAMBDA(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, PAIR(M), LAMBDA(_), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, LIST(M), VALUE(N), VALUE(M)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, LIST(M), NUMBER(N), VALUE(M)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, LIST(M), PAIR(N), VALUE(M)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, LIST(M), LIST(N), VALUE(M)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, LIST(M), MAP(N), VALUE(M)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, LIST(M), LAMBDA(N), VALUE(M)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, LIST(M), LAMBDA(_), VALUE(M)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, MAP(M), VALUE(N), VALUE(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, MAP(M), NUMBER(N), VALUE(M)>), (BOOL(M <= N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, MAP(M), PAIR(N), VALUE(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, MAP(M), LIST(N), VALUE(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, MAP(M), MAP(N), VALUE(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, MAP(M), LAMBDA(N), VALUE(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, MAP(M), LAMBDA(_), VALUE(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, LAMBDA(M), VALUE(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, LAMBDA(M), NUMBER(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, LAMBDA(M), PAIR(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, LAMBDA(M), LIST(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, LAMBDA(M), MAP(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, LAMBDA(M), LAMBDA(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, LAMBDA(M), LAMBDA(_), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, LAMBDA(_), VALUE(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, LAMBDA(_), NUMBER(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, LAMBDA(_), PAIR(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, LAMBDA(_), LIST(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, LAMBDA(_), MAP(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, LAMBDA(_), LAMBDA(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::insert_key>, LAMBDA(_), LAMBDA(_), VALUE(M)>), (FALSE)); \
    CHECK((metal::insert_key<MAP(M), NUMBER(M), VALUE(N)>), (metal::list<PAIRS(M) COMMA(M) metal::pair<NUMBER(M), VALUE(N)>>)); \
/**/

GEN(MATRIX)

