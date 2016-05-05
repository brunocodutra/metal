// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/number/logical.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::if_<VAL(M), NUMS(INC(N))>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::not_<VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::and_<VALS(N)>>), (BOOL(!N))); \
    ASSERT((metal::is_just_t<metal::and_<NUMS(M) COMMA(AND(M, N)) VALS(N)>>), (BOOL(!N))); \
    ASSERT((metal::is_just_t<metal::or_<VALS(N)>>), (BOOL(!N))); \
    ASSERT((metal::is_just_t<metal::or_<NUMS(M) COMMA(AND(M, N)) VALS(N)>>), (BOOL(!N))); \
    ASSERT((metal::is_just_t<metal::if_<NUM(M), NUMS(INC(N))>>), (BOOL(M || N))); \
    ASSERT((metal::is_just_t<metal::not_<NUM(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::and_<NUMS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::or_<NUMS(N)>>), (TRUE)); \
    ASSERT((metal::if_t<ENUM(M, NUM(0) BAR) COMMA(M) NUM(INC(N)), VAL(N)>), (VAL(N))); \
    ASSERT((metal::not_t<NUM(N)>), (BOOL(!N))); \
    ASSERT((metal::and_t<NUMS(N)>), (BOOL(!N))); \
    ASSERT((metal::and_t<ENUM(N, NUM(M) BAR)>), (BOOL(!N || M))); \
    ASSERT((metal::and_t<ENUM(N, NUM(M) BAR) COMMA(AND(M, N)) ENUM(M, NUM(N) BAR)>), (BOOL((M && N) || (!M && !N)))); \
    ASSERT((metal::or_t<NUMS(N)>), (BOOL(N > 1))); \
    ASSERT((metal::or_t<ENUM(N, NUM(M) BAR)>), (BOOL(N && M))); \
    ASSERT((metal::or_t<ENUM(N, NUM(M) BAR) COMMA(AND(M, N)) ENUM(M, NUM(N) BAR)>), (BOOL(M && N))); \
/**/

GEN(MATRIX)
