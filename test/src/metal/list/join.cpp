// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/join.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<FUNC(metal::join) COMMA(M) VALS(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::join) COMMA(M) NUMS(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::join), VEC(M) COMMA(N) VALS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<FUNC(metal::join), VEC(M) COMMA(N) VECS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::join), PAIR(M) COMMA(N) PAIRS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<FUNC(metal::join), LIST(M) COMMA(N) LISTS(N)>), (BOOL(!N || (!M && N == 1)))); \
    ASSERT((metal::is_invocable<FUNC(metal::join), MAP(M) COMMA(N) MAPS(N)>), (BOOL(!N || (!M && N == 1)))); \
    ASSERT((metal::is_invocable<FUNC(metal::join) COMMA(M) LBDS(M)>), (FALSE)); \
    ASSERT((metal::join<VEC(INC(M)) COMMA(N) VECS(N)>), (SEQ()<VALS(INC(M)) ENUM(N, ADAPT(VALS))>)); \
/**/

GEN(MATRIX)
