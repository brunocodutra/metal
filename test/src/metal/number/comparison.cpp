// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/number/equal_to.hpp>
#include <metal/number/greater.hpp>
#include <metal/number/less.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<FUNC(metal::equal_to), VAL(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::greater), VAL(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::less), VAL(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::equal_to), NUM(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::greater), NUM(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::less), NUM(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::equal_to), NUM(M), NUM(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::greater), NUM(M), NUM(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::less), NUM(M), NUM(N)>), (TRUE)); \
    ASSERT((metal::equal_to<NUM(M), NUM(N)>), (BOOL(M == N))); \
    ASSERT((metal::greater<NUM(M), NUM(N)>), (BOOL(M > N))); \
    ASSERT((metal::less<NUM(M), NUM(N)>), (BOOL(M < N))); \
/**/

GEN(MATRIX)
