// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::as_number>, VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_number>, NUMBER(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_number>, PAIR(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_number>, LIST(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_number>, MAP(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_number>, LAMBDA(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_number>, LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_number<VALUE(M)>), (FALSE)); \
    CHECK((metal::is_number<NUMBER(M)>), (TRUE)); \
    CHECK((metal::is_number<PAIR(M)>), (FALSE)); \
    CHECK((metal::is_number<LIST(M)>), (FALSE)); \
    CHECK((metal::is_number<MAP(M)>), (FALSE)); \
    CHECK((metal::is_number<LAMBDA(M)>), (FALSE)); \
    CHECK((metal::is_number<LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_number<metal::number<M>>), (TRUE)); \
    CHECK((metal::is_number<metal::number<-M>>), (TRUE)); \
    CHECK((metal::is_number<metal::false_>), (TRUE)); \
    CHECK((metal::is_number<metal::true_>), (TRUE)); \
/**/

GEN(MATRIX)
