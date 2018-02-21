// Copyright Bruno Dutra 2015-2018
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::reverse>, VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::reverse>, NUMBER(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::reverse>, PAIR(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::reverse>, LIST(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::reverse>, MAP(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::reverse>, LAMBDA(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::reverse>, LAMBDA(_)>), (FALSE)); \
    CHECK((metal::reverse<PAIR(M)>), (metal::list<VALUE(M), NUMBER(M)>)); \
    CHECK((metal::reverse<LIST(M)>), (metal::list<RENUM(M, VALUE)>)); \
    CHECK((metal::reverse<MAP(M)>), (metal::list<RENUM(M, PAIR)>)); \
    CHECK((metal::reverse<metal::list<TAGSX20(M) COMMA(AND(M, N)) TAGSX20(N)>>), (metal::list<RENUM(N, FWD, TAGX20) COMMA(AND(M, N)) RENUM(M, FWD, TAGX20)>)); \
/**/

GEN(MATRIX)

