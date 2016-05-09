// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/front.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<FUNC(metal::front), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::front), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::front), PAIR(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::front), LIST(M)>), (BOOL(M > 0))); \
    ASSERT((metal::is_invocable<FUNC(metal::front), MAP(M)>), (BOOL(M > 0))); \
    ASSERT((metal::is_invocable<FUNC(metal::front), LBD(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::front), SEQ()<VAL(M) COMMA(N) VALS(N)>>), (TRUE)); \
    ASSERT((metal::front<PAIR(M)>), (NUM(M))); \
    ASSERT((metal::front<LIST(INC(M))>), (VAL(0))); \
    ASSERT((metal::front<MAP(INC(M))>), (PAIR(0))); \
    ASSERT((metal::front<SEQ()<VAL(M) COMMA(N) VALS(N)>>), (VAL(M))); \
/**/

GEN(MATRIX)

