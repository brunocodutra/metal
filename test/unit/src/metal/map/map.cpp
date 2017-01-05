// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::map> COMMA(N) VALUES(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::map> COMMA(N) NUMBERS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::map> COMMA(N) PAIRS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::map> COMMA(N) LISTS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::map> COMMA(N) MAPS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::map> COMMA(N) LAMBDAS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::map>, PAIR(M) COMMA(N) PAIRS(N)>), (BOOL(M >= N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_map>, VALUE(M)>), (BOOL(M == 2))); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_map>, NUMBER(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_map>, PAIR(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_map>, LIST(M)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_map>, MAP(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_map>, LAMBDA(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_map>, LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_map<VALUE(N)>), (FALSE)); \
    CHECK((metal::is_map<NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_map<PAIR(N)>), (FALSE)); \
    CHECK((metal::is_map<LIST(N)>), (BOOL(!N))); \
    CHECK((metal::is_map<MAP(N)>), (TRUE)); \
    CHECK((metal::is_map<LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_map<LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_map<metal::list<PAIR(N) COMMA(M) PAIRS(M)>>), (BOOL(N >= M))); \
    CHECK((metal::as_map<VALUE(2)>), (metal::map<>)); \
/**/

GEN(MATRIX)
