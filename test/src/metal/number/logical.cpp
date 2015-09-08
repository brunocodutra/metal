// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/number/logical.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::not_<VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::and_<VALS(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::or_<VALS(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::and_<NUMS(M) COMMA(M) VALS(INC(N))>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::or_<NUMS(M) COMMA(M) VALS(INC(N))>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::not_<NUM(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::and_<NUMS(N)>>), (BOOL(N > 0))); \
    ASSERT((metal::is_just_t<metal::or_<NUMS(N)>>), (BOOL(N > 0))); \
    ASSERT((metal::and_t<NUMS(INC(N))>), (FALSE)); \
    ASSERT((metal::and_t<ENUM(INC(N), NUM(M) BAR)>), (BOOL(M > 0))); \
    ASSERT((metal::and_t<ENUM(INC(N), NUM(M) BAR), ENUM(INC(M), NUM(N) BAR)>), (BOOL(M && N))); \
    ASSERT((metal::or_t<NUMS(INC(N))>), (BOOL(N > 0))); \
    ASSERT((metal::or_t<ENUM(INC(N), NUM(M) BAR)>), (BOOL(M > 0))); \
    ASSERT((metal::or_t<ENUM(INC(N), NUM(M) BAR), ENUM(INC(M), NUM(N) BAR)>), (BOOL(M || N))); \
/**/

GEN(MATRIX)
