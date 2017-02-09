// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, VALUE(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, VALUE(M), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, VALUE(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, VALUE(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, VALUE(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, VALUE(M), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, VALUE(M), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, NUMBER(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, NUMBER(M), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, NUMBER(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, NUMBER(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, NUMBER(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, NUMBER(M), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, NUMBER(M), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, PAIR(M), VALUE(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, PAIR(M), NUMBER(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, PAIR(M), PAIR(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, PAIR(M), LIST(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, PAIR(M), MAP(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, PAIR(M), LAMBDA(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, PAIR(M), LAMBDA(_)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, LIST(M), VALUE(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, LIST(M), NUMBER(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, LIST(M), PAIR(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, LIST(M), LIST(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, LIST(M), MAP(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, LIST(M), LAMBDA(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, LIST(M), LAMBDA(_)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, MAP(M), VALUE(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, MAP(M), NUMBER(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, MAP(M), PAIR(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, MAP(M), LIST(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, MAP(M), MAP(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, MAP(M), LAMBDA(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, MAP(M), LAMBDA(_)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, LAMBDA(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, LAMBDA(M), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, LAMBDA(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, LAMBDA(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, LAMBDA(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, LAMBDA(M), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, LAMBDA(M), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, LAMBDA(_), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, LAMBDA(_), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, LAMBDA(_), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, LAMBDA(_), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, LAMBDA(_), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, LAMBDA(_), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count>, LAMBDA(_), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::count<PAIR(M), VALUE(N)>), (metal::number<M == N>)); \
    CHECK((metal::count<PAIR(M), NUMBER(N)>), (metal::number<M == N>)); \
    CHECK((metal::count<LIST(M), VALUE(N)>), (metal::number<(M > N)>)); \
    CHECK((metal::count<MAP(M), PAIR(N)>), (metal::number<(M > N)>)); \
    CHECK((metal::count<metal::list<VALUES(M) COMMA(M) VALUE(N)>, VALUE(N)>), (metal::number<1 + (M > N)>)); \
    CHECK((metal::count<metal::list<ENUM(M, VALUE FIX(N))>, VALUE(N)>), (metal::number<M>)); \
/**/

GEN(MATRIX)

