// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/replace_if.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>
#include <metal/pair/pair.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, VALUE(M), VALUE(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, VALUE(M), NUMBER(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, VALUE(M), PAIR(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, VALUE(M), LIST(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, VALUE(M), MAP(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, VALUE(M), LAMBDA(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, VALUE(M), LAMBDA(_), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, NUMBER(M), VALUE(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, NUMBER(M), NUMBER(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, NUMBER(M), PAIR(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, NUMBER(M), LIST(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, NUMBER(M), MAP(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, NUMBER(M), LAMBDA(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, NUMBER(M), LAMBDA(_), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, PAIR(M), VALUE(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, PAIR(M), NUMBER(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, PAIR(M), PAIR(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, PAIR(M), LIST(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, PAIR(M), MAP(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, PAIR(M), LAMBDA(N), VALUE(M)>), (BOOL(N == 1))); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, PAIR(M), LAMBDA(_), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LIST(M), VALUE(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LIST(M), NUMBER(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LIST(M), PAIR(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LIST(M), LIST(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LIST(M), MAP(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LIST(M), LAMBDA(N), VALUE(M)>), (BOOL(!M || N == 1))); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LIST(M), LAMBDA(_), VALUE(M)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, MAP(M), VALUE(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, MAP(M), NUMBER(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, MAP(M), PAIR(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, MAP(M), LIST(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, MAP(M), MAP(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, MAP(M), LAMBDA(N), VALUE(M)>), (BOOL(!M || N == 1))); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, MAP(M), LAMBDA(_), VALUE(M)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LAMBDA(M), VALUE(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LAMBDA(M), NUMBER(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LAMBDA(M), PAIR(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LAMBDA(M), LIST(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LAMBDA(M), MAP(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LAMBDA(M), LAMBDA(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LAMBDA(M), LAMBDA(_), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LAMBDA(_), VALUE(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LAMBDA(_), NUMBER(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LAMBDA(_), PAIR(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LAMBDA(_), LIST(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LAMBDA(_), MAP(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LAMBDA(_), LAMBDA(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace_if>, LAMBDA(_), LAMBDA(_), VALUE(M)>), (FALSE)); \
    CHECK((metal::replace_if<PAIR(M), metal::lambda<metal::is_number>, VALUE(N)>), (metal::list<VALUE(N), VALUE(M)>)); \
    CHECK((metal::replace_if<LIST(M), metal::lambda<metal::is_number>, VALUE(N)>), (LIST(M))); \
    CHECK((metal::replace_if<MAP(M), metal::lambda<metal::is_number>, VALUE(N)>), (MAP(M))); \
    CHECK((metal::replace_if<PAIR(M), metal::lambda<metal::is_pair>, VALUE(N)>), (PAIR(M))); \
    CHECK((metal::replace_if<LIST(M), metal::lambda<metal::is_pair>, VALUE(N)>), (LIST(M))); \
    CHECK((metal::replace_if<MAP(M), metal::lambda<metal::is_pair>, VALUE(N)>), (metal::list<ENUM(M, VALUE FIX(N))>)); \
    CHECK((metal::replace_if<PAIR(M), metal::lambda<metal::is_lambda>, VALUE(N)>), (PAIR(M))); \
    CHECK((metal::replace_if<LIST(M), metal::lambda<metal::is_lambda>, VALUE(N)>), (LIST(M))); \
    CHECK((metal::replace_if<MAP(M), metal::lambda<metal::is_lambda>, VALUE(N)>), (MAP(M))); \
    CHECK((metal::replace_if<metal::list<ENUM(M, FWD, NUMBER, PAIR, LAMBDA)>, metal::lambda<metal::is_number>, VALUE(N)>), (metal::list<ENUM(M, FWD, VALUE(N) NIL, PAIR, LAMBDA)>)); \
    CHECK((metal::replace_if<metal::list<ENUM(M, FWD, NUMBER, PAIR, LAMBDA)>, metal::lambda<metal::is_pair>, VALUE(N)>), (metal::list<ENUM(M, FWD, NUMBER, VALUE(N) NIL, LAMBDA)>)); \
    CHECK((metal::replace_if<metal::list<ENUM(M, FWD, NUMBER, PAIR, LAMBDA)>, metal::lambda<metal::is_lambda>, VALUE(N)>), (metal::list<ENUM(M, FWD, NUMBER, PAIR, VALUE(N) NIL)>)); \
/**/

GEN(MATRIX)
