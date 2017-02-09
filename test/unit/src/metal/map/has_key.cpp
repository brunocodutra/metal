// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, VALUE(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, VALUE(M), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, VALUE(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, VALUE(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, VALUE(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, VALUE(M), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, VALUE(M), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, NUMBER(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, NUMBER(M), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, NUMBER(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, NUMBER(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, NUMBER(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, NUMBER(M), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, NUMBER(M), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, PAIR(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, PAIR(M), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, PAIR(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, PAIR(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, PAIR(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, PAIR(M), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, PAIR(M), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LIST(M), VALUE(N)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LIST(M), NUMBER(N)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LIST(M), PAIR(N)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LIST(M), LIST(N)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LIST(M), MAP(N)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LIST(M), LAMBDA(N)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LIST(M), LAMBDA(_)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, MAP(M), VALUE(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, MAP(M), NUMBER(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, MAP(M), PAIR(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, MAP(M), LIST(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, MAP(M), MAP(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, MAP(M), LAMBDA(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, MAP(M), LAMBDA(_)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LAMBDA(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LAMBDA(M), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LAMBDA(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LAMBDA(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LAMBDA(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LAMBDA(M), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LAMBDA(M), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LAMBDA(_), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LAMBDA(_), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LAMBDA(_), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LAMBDA(_), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LAMBDA(_), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LAMBDA(_), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::has_key>, LAMBDA(_), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::has_key<MAP(M), NUMBER(N)>), (BOOL(M > N))); \
    CHECK((metal::has_key<MAP(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::has_key<metal::list<PAIRS(N) COMMA(N) metal::list<NUMBER(N), LAMBDA(N)>>, NUMBER(N)>), (TRUE)); \
/**/

GEN(MATRIX)
