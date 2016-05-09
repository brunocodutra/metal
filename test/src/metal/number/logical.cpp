// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/number/and.hpp>
#include <metal/number/if.hpp>
#include <metal/number/not.hpp>
#include <metal/number/or.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<FUNC(metal::if_), VAL(N), VAL(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::not_), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::and_) COMMA(N) VALS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<FUNC(metal::and_) COMMA(M) NUMS(M) COMMA(N) VALS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<FUNC(metal::or_) COMMA(N) VALS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<FUNC(metal::or_) COMMA(M) NUMS(M) COMMA(N) VALS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<FUNC(metal::if_), NUM(N), VAL(M), VAL(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::not_), NUM(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::and_) COMMA(N) NUMS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::or_) COMMA(N) NUMS(N)>), (TRUE)); \
    ASSERT((metal::if_<NUM(0), VAL(M), VAL(N)>), (VAL(N))); \
    ASSERT((metal::if_<NUM(INC(N)), VAL(M), VAL(N)>), (VAL(M))); \
    ASSERT((metal::not_<NUM(N)>), (BOOL(!N))); \
    ASSERT((metal::and_<NUMS(N)>), (BOOL(!N))); \
    ASSERT((metal::and_<ENUM(N, NUM(M) BAR)>), (BOOL(!N || M))); \
    ASSERT((metal::and_<ENUM(N, NUM(M) BAR) COMMA(AND(M, N)) ENUM(M, NUM(N) BAR)>), (BOOL((M && N) || (!M && !N)))); \
    ASSERT((metal::or_<NUMS(N)>), (BOOL(N > 1))); \
    ASSERT((metal::or_<ENUM(N, NUM(M) BAR)>), (BOOL(N && M))); \
    ASSERT((metal::or_<ENUM(N, NUM(M) BAR) COMMA(AND(M, N)) ENUM(M, NUM(N) BAR)>), (BOOL(M && N))); \
/**/

GEN(MATRIX)
