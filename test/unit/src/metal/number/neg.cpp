// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::neg>, VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::neg>, NUMBER(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::neg>, PAIR(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::neg>, LIST(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::neg>, MAP(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::neg>, LAMBDA(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::neg>, LAMBDA(_)>), (FALSE)); \
    CHECK((metal::neg<NUMBER(M)>), (metal::number<-M>)); \
/**/

GEN(MATRIX)

