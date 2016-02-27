// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/number/comparison.hpp>
#include <metal/optional/optional.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::equal_to<VAL(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::greater<VAL(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::less<VAL(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::equal_to<NUM(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::greater<NUM(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::less<NUM(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::equal_to_t<NUM(M), NUM(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::greater<NUM(M), NUM(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::less<NUM(M), NUM(N)>>), (TRUE)); \
    ASSERT((metal::equal_to_t<NUM(M), NUM(N)>), (BOOL(M == N))); \
    ASSERT((metal::greater_t<NUM(M), NUM(N)>), (BOOL(M > N))); \
    ASSERT((metal::less_t<NUM(M), NUM(N)>), (BOOL(M < N))); \
/**/

GEN(MATRIX)
