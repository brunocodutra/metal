// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::list> COMMA(N) VALUES(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::list> COMMA(N) NUMBERS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::list> COMMA(N) PAIRS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::list> COMMA(N) LISTS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::list> COMMA(N) MAPS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::list> COMMA(N) LAMBDAS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_list>, VALUE(M)>), (BOOL(M == 4))); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_list>, NUMBER(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_list>, PAIR(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_list>, LIST(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_list>, MAP(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_list>, LAMBDA(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_list>, LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_list<VALUE(N)>), (FALSE)); \
    CHECK((metal::is_list<NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_list<PAIR(N)>), (TRUE)); \
    CHECK((metal::is_list<LIST(N)>), (TRUE)); \
    CHECK((metal::is_list<MAP(N)>), (TRUE)); \
    CHECK((metal::is_list<LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_list<LAMBDA(_)>), (FALSE)); \
    CHECK((metal::as_list<VALUE(4)>), (metal::list<>)); \
/**/

GEN(MATRIX)

