// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/list/equal.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::equal<VAL(M), LIST(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::equal<NUM(M), LIST(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::equal<VEC(M), LIST(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::equal<PAIR(M), LIST(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::equal<LIST(M), LIST(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::equal<MAP(M), LIST(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::equal<ARG(M), LIST(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::equal<LBD(M), LIST(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::equal<FUN(M), LIST(N)>>), (FALSE)); \
    ASSERT((metal::equal_t<VEC(M), LIST(N)>), (BOOL(M == N))); \
    ASSERT((metal::equal_t<PAIR(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::equal_t<LIST(M), LIST(N)>), (BOOL(M == N))); \
    ASSERT((metal::equal_t<MAP(M), LIST(N)>), (BOOL(!M && !N))); \
    ASSERT((metal::equal_t<LBD(M), LIST(N)>), (FALSE)); \
/**/

GEN(MATRIX)

