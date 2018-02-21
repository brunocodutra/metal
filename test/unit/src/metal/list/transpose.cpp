// Copyright Bruno Dutra 2015-2018
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define SEQ(N, ...) metal::list<FWD(N, __VA_ARGS__)>

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::transpose>, VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transpose>, NUMBER(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transpose>, PAIR(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transpose>, LIST(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transpose>, MAP(M)>), (BOOL(M > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::transpose>, LAMBDA(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::transpose>, LAMBDA(_)>), (FALSE)); \
    CHECK((metal::transpose<MAP(INC(M))>), (metal::list<metal::list<NUMBERS(INC(M))>, metal::list<VALUES(INC(M))>>)); \
    CHECK((metal::transpose<metal::list<ENUM(INC(M), LIST FIX(N))>>), (metal::list<ENUM(N, SEQ, RENUM(INC(M), VALUE NIL))>)); \

/**/

GEN(MATRIX)
