// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::back>, VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::back>, NUMBER(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::back>, PAIR(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::back>, LIST(M)>), (BOOL(M > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::back>, MAP(M)>), (BOOL(M > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::back>, LAMBDA(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::back>, LAMBDA(_)>), (FALSE)); \
    CHECK((metal::back<PAIR(M)>), (VALUE(M))); \
    CHECK((metal::back<LIST(INC(M))>), (VALUE(M))); \
    CHECK((metal::back<MAP(INC(M))>), (PAIR(M))); \
/**/

GEN(MATRIX)

