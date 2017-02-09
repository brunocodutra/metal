// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::abs>, VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::abs>, NUMBER(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::abs>, PAIR(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::abs>, LIST(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::abs>, MAP(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::abs>, LAMBDA(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::abs>, LAMBDA(_)>), (FALSE)); \
    CHECK((metal::abs<NUMBER(M)>), (metal::number<M>)); \
    CHECK((metal::abs<metal::number<-M>>), (metal::number<M>)); \
/**/

GEN(MATRIX)

