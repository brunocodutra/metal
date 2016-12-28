// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define ENTRY(M, N, ...) EXPR(_)<__VA_ARGS__, ENUM(N, VALUE FIX(M))>

#define FOLD_KWD() FOLD_IMPL
#define FOLD_IMPL(M, _, ARG, MACRO, ...) \
    IF(_)(HEAD, TAIL)( \
        DEFER(FOLD_KWD)()( \
            INC(M), DEC(_), ARG, MACRO, DEFER(MACRO)(M, ARG, __VA_ARGS__) \
        ), \
        __VA_ARGS__ \
    ) \
/**/

#define FOLD(M, ARG, MACRO, ...) FOLD_IMPL(0, M, ARG, MACRO, __VA_ARGS__)

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, VALUE(M), VALUE(N), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, VALUE(M), VALUE(N), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, VALUE(M), VALUE(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, VALUE(M), VALUE(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, VALUE(M), VALUE(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, VALUE(M), VALUE(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, VALUE(M), VALUE(N), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, NUMBER(M), NUMBER(N), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, NUMBER(M), NUMBER(N), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, NUMBER(M), NUMBER(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, NUMBER(M), NUMBER(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, NUMBER(M), NUMBER(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, NUMBER(M), NUMBER(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, NUMBER(M), NUMBER(N), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, PAIR(M), PAIR(N), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, PAIR(M), PAIR(N), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, PAIR(M), PAIR(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, PAIR(M), PAIR(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, PAIR(M), PAIR(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, PAIR(M), PAIR(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, PAIR(M), PAIR(N), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LIST(M), LIST(N), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LIST(M), LIST(N), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LIST(M), LIST(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LIST(M), LIST(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LIST(M), LIST(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LIST(M), LIST(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LIST(M), LIST(N), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, MAP(M), MAP(N), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, MAP(M), MAP(N), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, MAP(M), MAP(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, MAP(M), MAP(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, MAP(M), MAP(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, MAP(M), MAP(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, MAP(M), MAP(N), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(M), LAMBDA(N), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(M), LAMBDA(N), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(M), LAMBDA(N), PAIR(N)>), (BOOL(M == 2))); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(M), LAMBDA(N), LIST(N)>), (BOOL(M == 2 || !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(M), LAMBDA(N), MAP(N)>), (BOOL(M == 2 || !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(M), LAMBDA(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(M), LAMBDA(N), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(_), LAMBDA(N), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(_), LAMBDA(N), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(_), LAMBDA(N), PAIR(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(_), LAMBDA(N), LIST(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(_), LAMBDA(N), MAP(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(_), LAMBDA(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(_), LAMBDA(N), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::accumulate<LAMBDA(_), VALUE(N), ENUM(INC(N), LIST FIX(M))>), (FOLD(M, INC(N), ENTRY, VALUE(N)))); \
    CHECK((metal::accumulate<LAMBDA(2), NUMBER(2), metal::list<TAGSX20(M) COMMA(AND(M, N)) TAGSX20(N)>>), (NUMBER(2))); \
/**/

GEN(MATRIX)

