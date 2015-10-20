// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/map/has_key.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/optional/optional.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::has_key<VAL(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::has_key<PAIR(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::has_key<LIST(M), VAL(N)>>), (BOOL(!M))); \
    ASSERT((metal::is_just_t<metal::has_key<LBD(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::has_key<MAP(M), VAL(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::has_key<MAP(M), NUM(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::has_key<SEQ()<PAIRS(M)>, NUM(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::has_key<SEQ()<PAIR(M) COMMA(N) PAIRS(N)>, NUM(N)>>), (BOOL(M >= N))); \
    ASSERT((metal::is_just_t<metal::has_key<SEQ(INC(N))<PAIRS(N) COMMA(N) SEQ()<NUM(M), MAP(M)>>, NUM(N)>>), (BOOL(M >= N))); \
    ASSERT((metal::has_key_t<MAP(M), NUM(N)>), (BOOL(M > N))); \
    ASSERT((metal::has_key_t<MAP(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::has_key_t<SEQ()<PAIRS(M)>, NUM(N)>), (BOOL(M > N))); \
    ASSERT((metal::has_key_t<SEQ(INC(N))<PAIRS(N) COMMA(N) SEQ()<NUM(N), MAP(N)>>, NUM(N)>), (TRUE)); \
/**/

GEN(MATRIX)
