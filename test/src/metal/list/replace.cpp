// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/replace.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, VALUE(M), VALUE(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, VALUE(M), NUMBER(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, VALUE(M), PAIR(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, VALUE(M), LIST(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, VALUE(M), MAP(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, VALUE(M), LAMBDA(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, VALUE(M), LAMBDA(_), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, NUMBER(M), VALUE(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, NUMBER(M), NUMBER(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, NUMBER(M), PAIR(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, NUMBER(M), LIST(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, NUMBER(M), MAP(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, NUMBER(M), LAMBDA(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, NUMBER(M), LAMBDA(_), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, PAIR(M), VALUE(N), VALUE(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, PAIR(M), NUMBER(N), VALUE(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, PAIR(M), PAIR(N), VALUE(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, PAIR(M), LIST(N), VALUE(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, PAIR(M), MAP(N), VALUE(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, PAIR(M), LAMBDA(N), VALUE(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, PAIR(M), LAMBDA(_), VALUE(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LIST(M), VALUE(N), VALUE(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LIST(M), NUMBER(N), VALUE(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LIST(M), PAIR(N), VALUE(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LIST(M), LIST(N), VALUE(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LIST(M), MAP(N), VALUE(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LIST(M), LAMBDA(N), VALUE(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LIST(M), LAMBDA(_), VALUE(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, MAP(M), VALUE(N), VALUE(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, MAP(M), NUMBER(N), VALUE(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, MAP(M), PAIR(N), VALUE(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, MAP(M), LIST(N), VALUE(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, MAP(M), MAP(N), VALUE(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, MAP(M), LAMBDA(N), VALUE(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, MAP(M), LAMBDA(_), VALUE(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LAMBDA(M), VALUE(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LAMBDA(M), NUMBER(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LAMBDA(M), PAIR(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LAMBDA(M), LIST(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LAMBDA(M), MAP(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LAMBDA(M), LAMBDA(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LAMBDA(M), LAMBDA(_), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LAMBDA(_), VALUE(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LAMBDA(_), NUMBER(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LAMBDA(_), PAIR(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LAMBDA(_), LIST(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LAMBDA(_), MAP(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LAMBDA(_), LAMBDA(N), VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::replace>, LAMBDA(_), LAMBDA(_), VALUE(M)>), (FALSE)); \
    CHECK((metal::replace<PAIR(M), VALUE(N), NUMBER(N)>), (metal::list<NUMBER(M), std::conditional_t<M == N, NUMBER(N), VALUE(M)>>)); \
    CHECK((metal::replace<PAIR(M), NUMBER(N), VALUE(N)>), (metal::list<std::conditional_t<M == N, VALUE(N), NUMBER(M)>, VALUE(M)>)); \
    CHECK((metal::replace<metal::list<VALUES(M) COMMA(AND(M, CMPL(M))) ENUM(CMPL(M), NUMBER FIX(N))>, NUMBER(N), VALUE(N)>), (metal::list<VALUES(M) COMMA(AND(M, CMPL(M))) ENUM(CMPL(M), VALUE FIX(N))>)); \
/**/

GEN(MATRIX)

