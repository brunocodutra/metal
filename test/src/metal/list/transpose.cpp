// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/transpose.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define SEQ(N, ...) test::list<FWD(N, __VA_ARGS__)>

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::transpose>, VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::transpose>, NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::transpose>, PAIR(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::transpose>, VECT(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::transpose>, LIST(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::transpose>, MAP(M)>), (BOOL(M > 0))); \
    ASSERT((metal::is_invocable<test::lambda<metal::transpose>, LBD(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::transpose>, LBD(_)>), (FALSE)); \
    ASSERT((metal::transpose<test::list<ENUM(INC(M), LIST FIX(N))>>), (test::list<ENUM(N, SEQ, RENUM(INC(M), VAL NIL))>)); \
    ASSERT((metal::transpose<MAP(INC(M))>), (test::pair<CAT(test::map, INC(M))<NUMS(INC(M))>, CAT(test::map, INC(M))<VALS(INC(M))>>)); \
/**/

GEN(MATRIX)
