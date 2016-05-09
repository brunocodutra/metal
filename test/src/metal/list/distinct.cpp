// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/distinct.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<FUNC(metal::distinct), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::distinct), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::distinct), PAIR(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::distinct), LIST(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::distinct), VEC(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::distinct), MAP(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::distinct), LBD(M)>), (FALSE)); \
    ASSERT((metal::distinct<PAIR(M)>), (TRUE)); \
    ASSERT((metal::distinct<LIST(M)>), (TRUE)); \
    ASSERT((metal::distinct<VEC(M)>), (TRUE)); \
    ASSERT((metal::distinct<MAP(M)>), (TRUE)); \
    ASSERT((metal::distinct<SEQ()<VAL(M), VALS(INC(M))>>), (FALSE)); \
    ASSERT((metal::distinct<SEQ(M)<ENUM(M, VAL(N) BAR)>>), (BOOL(M < 2))); \
/**/

GEN(MATRIX)

