// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/contains.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<FUNC(metal::contains), VAL(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::contains), NUM(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::contains), PAIR(M), VAL(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::contains), LIST(M), VAL(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::contains), MAP(M), VAL(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::contains), LBD(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::contains<PAIR(M), VAL(N)>), (BOOL(M == N))); \
    ASSERT((metal::contains<PAIR(M), NUM(N)>), (BOOL(M == N))); \
    ASSERT((metal::contains<LIST(M), VAL(N)>), (BOOL(M > N))); \
    ASSERT((metal::contains<MAP(M), PAIR(N)>), (BOOL(M > N))); \
    ASSERT((metal::contains<SEQ()<VAL(M), VALS(INC(M))>, VAL(N)>), (BOOL(M >= N))); \
    ASSERT((metal::contains<SEQ(M)<ENUM(M, VAL(N) BAR)>, VAL(N)>), (BOOL(M > 0))); \
/**/

GEN(MATRIX)

