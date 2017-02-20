// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, VALUE(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, VALUE(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, VALUE(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, VALUE(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, VALUE(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, VALUE(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, NUMBER(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, NUMBER(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, NUMBER(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, NUMBER(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, NUMBER(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, NUMBER(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, PAIR(M) COMMA(N) VALUES(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, PAIR(M) COMMA(N) NUMBERS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, PAIR(M) COMMA(N) PAIRS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, PAIR(M) COMMA(N) LISTS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, PAIR(M) COMMA(N) MAPS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, PAIR(M) COMMA(N) LAMBDAS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, LIST(M) COMMA(N) VALUES(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, LIST(M) COMMA(N) NUMBERS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, LIST(M) COMMA(N) PAIRS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, LIST(M) COMMA(N) LISTS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, LIST(M) COMMA(N) MAPS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, LIST(M) COMMA(N) LAMBDAS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, MAP(M) COMMA(N) VALUES(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, MAP(M) COMMA(N) NUMBERS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, MAP(M) COMMA(N) PAIRS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, MAP(M) COMMA(N) LISTS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, MAP(M) COMMA(N) MAPS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, MAP(M) COMMA(N) LAMBDAS(N)>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, LAMBDA(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, LAMBDA(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, LAMBDA(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, LAMBDA(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, LAMBDA(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, LAMBDA(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, LAMBDA(_) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, LAMBDA(_) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, LAMBDA(_) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, LAMBDA(_) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, LAMBDA(_) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::append>, LAMBDA(_) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::append<PAIR(M), VALUES(INC(N))>), (metal::list<NUMBER(M), VALUE(M), VALUES(INC(N))>)); \
    CHECK((metal::append<LIST(M), VALUES(INC(N))>), (metal::list<VALUES(M) COMMA(M) VALUES(INC(N))>)); \
    CHECK((metal::append<MAP(M), VALUES(INC(N))>), (metal::list<PAIRS(M) COMMA(M) VALUES(INC(N))>)); \
/**/

GEN(MATRIX)
