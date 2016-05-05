// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/map/at_key.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::at_key<VAL(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::at_key<PAIR(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::at_key<LIST(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::at_key<LBD(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::at_key<MAP(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::at_key<MAP(M), NUM(N)>>), (BOOL(M > N))); \
    ASSERT((metal::is_just_t<metal::at_key<SEQ()<PAIRS(M)>, NUM(N)>>), (BOOL(M > N))); \
    ASSERT((metal::is_just_t<metal::at_key<SEQ()<PAIR(M) COMMA(N) PAIRS(N)>, NUM(N)>>), (BOOL(M == N))); \
    ASSERT((metal::is_just_t<metal::at_key<SEQ(INC(N))<PAIRS(N) COMMA(N) SEQ()<NUM(M), MAP(M)>>, NUM(N)>>), (BOOL(M == N))); \
    ASSERT((metal::at_key_t<MAP(INC(N)), NUM(N)>), (VAL(N))); \
    ASSERT((metal::at_key_t<SEQ()<PAIRS(INC(N))>, NUM(N)>), (VAL(N))); \
    ASSERT((metal::at_key_t<SEQ(INC(N))<PAIRS(N) COMMA(N) SEQ()<NUM(N), MAP(N)>>, NUM(N)>), (MAP(N))); \
/**/

GEN(MATRIX)
