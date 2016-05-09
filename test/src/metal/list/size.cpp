// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/size.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define SIZE(...) metal::size_t<(__VA_ARGS__)>

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<FUNC(metal::size), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::size), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::size), PAIR(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::size), LIST(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::size), MAP(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::size), LBD(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::size), SEQ()<VALS(M) COMMA(AND(M, N)) VALS(N)>>), (TRUE)); \
    ASSERT((metal::size<PAIR(M)>), (SIZE(2))); \
    ASSERT((metal::size<LIST(M)>), (SIZE(M))); \
    ASSERT((metal::size<MAP(M)>), (SIZE(M))); \
    ASSERT((metal::size<SEQ()<VALS(M) COMMA(AND(M, N)) VALS(N)>>), (SIZE(M + N))); \
    ASSERT((metal::size<SEQ(M)<ENUM(M, VAL(N) BAR)>>), (SIZE(M))); \
/**/

GEN(MATRIX)

