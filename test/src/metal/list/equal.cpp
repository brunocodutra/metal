// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/equal.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<FUNC(metal::equal), VAL(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::equal), NUM(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::equal), VEC(M), LIST(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::equal), PAIR(M), LIST(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::equal), LIST(M), LIST(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::equal), MAP(M), LIST(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::equal), LBD(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::equal<VEC(M), LIST(N)>), (BOOL(M == N))); \
    ASSERT((metal::equal<PAIR(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::equal<LIST(M), LIST(N)>), (BOOL(M == N))); \
    ASSERT((metal::equal<MAP(M), LIST(N)>), (BOOL(!M && !N))); \
/**/

GEN(MATRIX)

