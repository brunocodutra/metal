// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/pair/pair.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/optional/optional.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::pair<VAL(M), VAL(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::pair<NUM(M), NUM(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::pair<PAIR(M), PAIR(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::pair<LIST(M), LIST(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::pair<MAP(M), MAP(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::pair<ARG(M), ARG(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::pair<LBD(M), LBD(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::pair<FUN(M), FUN(N)>>), (TRUE)); \
    ASSERT((metal::is_pair_t<VAL(N)>), (FALSE)); \
    ASSERT((metal::is_pair_t<NUM(N)>), (FALSE)); \
    ASSERT((metal::is_pair_t<PAIR(N)>), (TRUE)); \
    ASSERT((metal::is_pair_t<LIST(N)>), (BOOL(N == 2))); \
    ASSERT((metal::is_pair_t<MAP(N)>), (BOOL(N == 2))); \
    ASSERT((metal::is_pair_t<ARG(N)>), (FALSE)); \
    ASSERT((metal::is_pair_t<LBD(N)>), (FALSE)); \
    ASSERT((metal::is_pair_t<FUN(N)>), (FALSE)); \
/**/

GEN(MATRIX)
