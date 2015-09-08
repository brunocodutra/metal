// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/list/contains.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::contains<VAL(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::contains<NUM(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::contains<PAIR(M), VAL(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::contains<LIST(M), VAL(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::contains<MAP(M), VAL(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::contains<ARG(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::contains<LBD(M), VAL(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::contains<FUN(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::contains_t<PAIR(M), VAL(N)>), (BOOL(M == N))); \
    ASSERT((metal::contains_t<PAIR(M), NUM(N)>), (BOOL(M == N))); \
    ASSERT((metal::contains_t<LIST(M), VAL(N)>), (BOOL(M > N))); \
    ASSERT((metal::contains_t<MAP(M), PAIR(N)>), (BOOL(M > N))); \
    ASSERT((metal::contains_t<LBD(M), ARG(N)>), (BOOL(M > N))); \
    ASSERT((metal::contains_t<SEQ()<VAL(M), VALS(INC(M))>, VAL(N)>), (BOOL(M >= N))); \
    ASSERT((metal::contains_t<SEQ(M)<ENUM(M, MAP(N) BAR)>, MAP(N)>), (BOOL(M > 0))); \
    ASSERT((metal::contains_t<SEQ()< \
        VALS(INC(M)), NUMS(INC(M)), PAIRS(INC(M)), LISTS(INC(M)), \
        MAPS(INC(M)), ARGS(INC(M)), LBDS(INC(M))>, MAP(N)>), (BOOL(M >= N))); \
/**/

GEN(MATRIX)

