// Copyright Bruno Dutra 2015-2018
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::as_lambda>, VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_lambda>, NUMBER(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_lambda>, PAIR(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_lambda>, LIST(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_lambda>, MAP(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_lambda>, LAMBDA(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_lambda>, LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_lambda<VALUE(N)>), (FALSE)); \
    CHECK((metal::is_lambda<NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_lambda<PAIR(N)>), (FALSE)); \
    CHECK((metal::is_lambda<LIST(N)>), (FALSE)); \
    CHECK((metal::is_lambda<MAP(N)>), (FALSE)); \
    CHECK((metal::is_lambda<LAMBDA(N)>), (TRUE)); \
    CHECK((metal::is_lambda<LAMBDA(_)>), (TRUE)); \
    CHECK((metal::is_lambda<metal::lambda<EXPR(M)>>), (TRUE)); \
    CHECK((metal::is_lambda<metal::lambda<EXPR(N)>>), (TRUE)); \
    CHECK((metal::as_lambda<PAIR(N)>), (metal::lambda<metal::list>)); \
    CHECK((metal::as_lambda<LIST(N)>), (metal::lambda<metal::list>)); \
    CHECK((metal::as_lambda<MAP(N)>), (metal::lambda<metal::list>)); \
/**/

GEN(MATRIX)
