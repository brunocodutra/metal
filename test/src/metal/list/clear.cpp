// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/clear.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<FUNC(metal::clear), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::clear), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::clear), VEC(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::clear), PAIR(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::clear), LBD(M)>), (FALSE)); \
    ASSERT((metal::clear<VEC(M)>), (VEC(0))); \
    ASSERT((metal::clear<LIST(0)>), (LIST(0))); \
    ASSERT((metal::clear<MAP(0)>), (MAP(0))); \
/**/

GEN(MATRIX)

