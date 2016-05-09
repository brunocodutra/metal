// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/map/order.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<FUNC(metal::order), VAL(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::order), PAIR(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::order), LIST(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::order), MAP(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::order), MAP(M), NUM(N)>), (BOOL(M > N))); \
    ASSERT((metal::is_invocable<FUNC(metal::order), SEQ()<PAIRS(M)>, NUM(N)>), (BOOL(M > N))); \
    ASSERT((metal::is_invocable<FUNC(metal::order), SEQ()<PAIR(M) COMMA(N) PAIRS(N)>, NUM(N)>), (BOOL(M == N))); \
    ASSERT((metal::is_invocable<FUNC(metal::order), SEQ(INC(N))<PAIRS(N) COMMA(N) SEQ()<NUM(M), MAP(M)>>, NUM(N)>), (BOOL(M == N))); \
    ASSERT((metal::order<MAP(INC(N)), NUM(N)>), (metal::size_t<N>)); \
    ASSERT((metal::order<SEQ()<PAIRS(INC(N))>, NUM(N)>), (metal::size_t<N>)); \
    ASSERT((metal::order<SEQ(INC(N))<PAIRS(N) COMMA(N) SEQ()<NUM(N), MAP(N)>>, NUM(N)>), (metal::size_t<N>)); \
/**/

GEN(MATRIX)
