// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/lambda/apply.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<FUNC(metal::apply), VAL(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::apply), NUM(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::apply), PAIR(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::apply), LIST(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::apply), MAP(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::apply), LBD(), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::apply), LBD(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::apply), VAL(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::apply), NUM(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::apply), PAIR(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::apply), LIST(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::apply), MAP(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::apply), LBD(M), LIST(N)>), (BOOL(M == N))); \
    ASSERT((metal::is_invocable<FUNC(metal::apply), LBD(), LIST(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::apply), FUNC(metal::apply), SEQ()<LBD(M), LIST(N)>>), (BOOL(M == N))); \
    ASSERT((metal::apply<LBD(M), SEQ(M)<VALS(M)>>), (EXPR(M)<VALS(M)>)); \
    ASSERT((metal::apply<LBD(), SEQ(M)<VALS(M)>>), (EXPR()<VALS(M)>)); \
    ASSERT((metal::apply<FUNC(metal::apply), SEQ()<LBD(M), SEQ(M)<VALS(M)>>>), (EXPR(M)<VALS(M)>)); \
/**/

GEN(MATRIX)
