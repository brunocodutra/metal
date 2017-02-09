// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, VALUE(M), VALUE(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, VALUE(M), NUMBER(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, VALUE(M), PAIR(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, VALUE(M), LIST(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, VALUE(M), MAP(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, VALUE(M), LAMBDA(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, VALUE(M), LAMBDA(_)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, NUMBER(M), VALUE(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, NUMBER(M), NUMBER(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, NUMBER(M), PAIR(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, NUMBER(M), LIST(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, NUMBER(M), MAP(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, NUMBER(M), LAMBDA(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, NUMBER(M), LAMBDA(_)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, PAIR(M), VALUE(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, PAIR(M), NUMBER(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, PAIR(M), PAIR(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, PAIR(M), LIST(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, PAIR(M), MAP(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, PAIR(M), LAMBDA(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, PAIR(M), LAMBDA(_)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LIST(M), VALUE(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LIST(M), NUMBER(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LIST(M), PAIR(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LIST(M), LIST(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LIST(M), MAP(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LIST(M), LAMBDA(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LIST(M), LAMBDA(_)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, MAP(M), VALUE(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, MAP(M), NUMBER(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, MAP(M), PAIR(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, MAP(M), LIST(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, MAP(M), MAP(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, MAP(M), LAMBDA(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, MAP(M), LAMBDA(_)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LAMBDA(M), VALUE(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LAMBDA(M), NUMBER(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LAMBDA(M), PAIR(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LAMBDA(M), LIST(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LAMBDA(M), MAP(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LAMBDA(M), LAMBDA(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LAMBDA(M), LAMBDA(_)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LAMBDA(_), NUMBER(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LAMBDA(_), PAIR(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LAMBDA(_), LIST(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LAMBDA(_), MAP(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LAMBDA(_), LAMBDA(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LAMBDA(_), LAMBDA(_)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_pair>, VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_pair>, NUMBER(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_pair>, PAIR(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_pair>, LIST(M)>), (BOOL(M == 2))); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_pair>, MAP(M)>), (BOOL(M == 2))); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_pair>, LAMBDA(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_pair>, LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_pair<VALUE(N)>), (FALSE)); \
    CHECK((metal::is_pair<NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_pair<PAIR(N)>), (TRUE)); \
    CHECK((metal::is_pair<LIST(N)>), (BOOL(N == 2))); \
    CHECK((metal::is_pair<MAP(N)>), (BOOL(N == 2))); \
    CHECK((metal::is_pair<LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_pair<LAMBDA(_)>), (FALSE)); \
/**/

GEN(MATRIX)
