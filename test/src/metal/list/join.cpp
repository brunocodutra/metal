// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/list/join.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/optional/optional.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::join<VALS(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::join<NUMS(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::join<VEC(M) COMMA(N) VALS(N)>>), (BOOL(!N))); \
    ASSERT((metal::is_just_t<metal::join<VEC(M) COMMA(N) VECS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::join<PAIR(M) COMMA(N) PAIRS(N)>>), (BOOL(!N))); \
    ASSERT((metal::is_just_t<metal::join<LIST(M) COMMA(N) LISTS(N)>>), (BOOL(!N || (!M && N == 1)))); \
    ASSERT((metal::is_just_t<metal::join<MAP(M) COMMA(N) MAPS(N)>>), (BOOL(!N || (!M && N == 1)))); \
    ASSERT((metal::is_just_t<metal::join<ARGS(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::join<LBD(M) COMMA(N) LBDS(N)>>), (BOOL(!N))); \
    ASSERT((metal::is_just_t<metal::join<FUNS(M)>>), (FALSE)); \
    ASSERT((metal::join_t<VEC(INC(M)) COMMA(N) VECS(N)>), (SEQ()<VALS(INC(M)) ENUM(N, LIFT(VALS))>)); \
/**/

GEN(MATRIX)
