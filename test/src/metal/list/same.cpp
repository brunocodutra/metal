// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/same.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<FUNC(metal::same), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::same), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::same), PAIR(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::same), LIST(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::same), MAP(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::same), LBD(M)>), (FALSE)); \
    ASSERT((metal::same<PAIR(M)>), (FALSE)); \
    ASSERT((metal::same<LIST(M)>), (BOOL(M < 2))); \
    ASSERT((metal::same<MAP(M)>), (BOOL(M < 2))); \
    ASSERT((metal::same<SEQ()<VAL(M), VALS(INC(M))>>), (BOOL(!M))); \
    ASSERT((metal::same<SEQ(M)<ENUM(M, VAL(N) BAR)>>), (TRUE)); \
/**/

GEN(MATRIX)

