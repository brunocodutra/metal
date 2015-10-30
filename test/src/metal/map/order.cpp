// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/map/order.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/optional/optional.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::order<VAL(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::order<PAIR(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::order<LIST(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::order<LBD(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::order<MAP(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::order<MAP(M), NUM(N)>>), (BOOL(M > N))); \
    ASSERT((metal::is_just_t<metal::order<SEQ()<PAIRS(M)>, NUM(N)>>), (BOOL(M > N))); \
    ASSERT((metal::is_just_t<metal::order<SEQ()<PAIR(M) COMMA(N) PAIRS(N)>, NUM(N)>>), (BOOL(M == N))); \
    ASSERT((metal::is_just_t<metal::order<SEQ(INC(N))<PAIRS(N) COMMA(N) SEQ()<NUM(M), MAP(M)>>, NUM(N)>>), (BOOL(M == N))); \
    ASSERT((metal::order_t<MAP(INC(N)), NUM(N)>), (metal::number<std::size_t, N>)); \
    ASSERT((metal::order_t<SEQ()<PAIRS(INC(N))>, NUM(N)>), (metal::number<std::size_t, N>)); \
    ASSERT((metal::order_t<SEQ(INC(N))<PAIRS(N) COMMA(N) SEQ()<NUM(N), MAP(N)>>, NUM(N)>), (metal::number<std::size_t, N>)); \
/**/

GEN(MATRIX)
