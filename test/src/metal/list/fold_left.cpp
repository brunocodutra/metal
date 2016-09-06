// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/fold_left.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>
#include <metal/number/enumerate.hpp>

#include "test.hpp"

#define TAB(N, ...) EXPR(_)<__VA_ARGS__, VALUE(N)>

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, VALUE(M), VALUE(N), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, VALUE(M), VALUE(N), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, VALUE(M), VALUE(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, VALUE(M), VALUE(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, VALUE(M), VALUE(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, VALUE(M), VALUE(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, VALUE(M), VALUE(N), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, NUMBER(M), NUMBER(N), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, NUMBER(M), NUMBER(N), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, NUMBER(M), NUMBER(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, NUMBER(M), NUMBER(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, NUMBER(M), NUMBER(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, NUMBER(M), NUMBER(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, NUMBER(M), NUMBER(N), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, PAIR(M), PAIR(N), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, PAIR(M), PAIR(N), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, PAIR(M), PAIR(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, PAIR(M), PAIR(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, PAIR(M), PAIR(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, PAIR(M), PAIR(N), LAMBDA(N)>), (BOOL(N == 2))); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, PAIR(M), PAIR(N), LAMBDA(_)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LIST(M), LIST(N), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LIST(M), LIST(N), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LIST(M), LIST(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LIST(M), LIST(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LIST(M), LIST(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LIST(M), LIST(N), LAMBDA(N)>), (BOOL(!M || N == 2))); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LIST(M), LIST(N), LAMBDA(_)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, MAP(M), MAP(N), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, MAP(M), MAP(N), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, MAP(M), MAP(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, MAP(M), MAP(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, MAP(M), MAP(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, MAP(M), MAP(N), LAMBDA(N)>), (BOOL(!M || N == 2))); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, MAP(M), MAP(N), LAMBDA(_)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LAMBDA(M), LAMBDA(N), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LAMBDA(M), LAMBDA(N), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LAMBDA(M), LAMBDA(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LAMBDA(M), LAMBDA(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LAMBDA(M), LAMBDA(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LAMBDA(M), LAMBDA(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LAMBDA(M), LAMBDA(N), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LAMBDA(_), LAMBDA(N), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LAMBDA(_), LAMBDA(N), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LAMBDA(_), LAMBDA(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LAMBDA(_), LAMBDA(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LAMBDA(_), LAMBDA(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LAMBDA(_), LAMBDA(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LAMBDA(_), LAMBDA(N), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::fold_left<LIST(M), VALUE(N), LAMBDA(_)>), (FOLD(M, TAB, VALUE(N)))); \
    CHECK((metal::fold_left<metal::enumerate<NUMBER(0), metal::number<100*M>, NUMBER(N)>, NUMBER(2), LAMBDA(2)>), (NUMBER(2))); \
/**/

GEN(MATRIX)

