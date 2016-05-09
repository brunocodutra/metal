// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/pair/pair.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<FUNC(metal::pair), VAL(M), VAL(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::pair), NUM(M), NUM(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::pair), PAIR(M), PAIR(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::pair), LIST(M), LIST(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::pair), MAP(M), MAP(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::pair), LBD(M), LBD(N)>), (TRUE)); \
    ASSERT((metal::is_pair<VAL(N)>), (FALSE)); \
    ASSERT((metal::is_pair<NUM(N)>), (FALSE)); \
    ASSERT((metal::is_pair<PAIR(N)>), (TRUE)); \
    ASSERT((metal::is_pair<LIST(N)>), (BOOL(N == 2))); \
    ASSERT((metal::is_pair<MAP(N)>), (BOOL(N == 2))); \
    ASSERT((metal::is_pair<LBD(N)>), (FALSE)); \
/**/

GEN(MATRIX)
