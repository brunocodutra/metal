// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::size>, VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::size>, NUMBER(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::size>, PAIR(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::size>, LIST(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::size>, MAP(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::size>, LAMBDA(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::size>, LAMBDA(_)>), (FALSE)); \
    CHECK((metal::size<PAIR(M)>), (metal::number<2>)); \
    CHECK((metal::size<LIST(M)>), (metal::number<M>)); \
    CHECK((metal::size<MAP(M)>), (metal::number<M>)); \
    CHECK((metal::size<metal::list<VALUES(M) COMMA(AND(M, N)) VALUES(N)>>), (metal::number<M + N>)); \
    CHECK((metal::size<metal::list<ENUM(M, VALUE FIX(N))>>), (metal::number<M>)); \
/**/

GEN(MATRIX)

