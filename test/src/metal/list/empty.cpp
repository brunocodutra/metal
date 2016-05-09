// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/empty.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<FUNC(metal::empty), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::empty), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::empty), PAIR(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::empty), LIST(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::empty), MAP(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::empty), LBD(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::empty), SEQ()<VALS(M) COMMA(AND(M, N)) VALS(N)>>), (TRUE)); \
    ASSERT((metal::empty<PAIR(M)>), (FALSE)); \
    ASSERT((metal::empty<LIST(M)>), (BOOL(!M))); \
    ASSERT((metal::empty<MAP(M)>), (BOOL(!M))); \
    ASSERT((metal::empty<SEQ()<VALS(M) COMMA(AND(M, N)) VALS(N)>>), (BOOL(!M && !N))); \
    ASSERT((metal::empty<SEQ(M)<ENUM(M, VAL(N) BAR)>>), (BOOL(!M))); \
/**/

GEN(MATRIX)

