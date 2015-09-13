// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/list/at.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::at<VAL(M), NUM(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::at<NUM(M), NUM(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::at<PAIR(M), NUM(N)>>), (BOOL(N < 2))); \
    ASSERT((metal::is_just_t<metal::at<LIST(M), NUM(N)>>), (BOOL(M > N))); \
    ASSERT((metal::is_just_t<metal::at<MAP(M), NUM(N)>>), (BOOL(M > N))); \
    ASSERT((metal::is_just_t<metal::at<ARG(M), NUM(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::at<LBD(M), NUM(N)>>), (BOOL(M > N))); \
    ASSERT((metal::is_just_t<metal::at<FUN(M), NUM(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::at<LIST(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::at<LIST(M), PAIR(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::at<LIST(M), LIST(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::at<LIST(M), MAP(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::at<LIST(M), ARG(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::at<LIST(M), LBD(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::at<LIST(M), FUN(N)>>), (FALSE)); \
    ASSERT((metal::at_t<PAIR(N), NUM(0)>), (NUM(N))); \
    ASSERT((metal::at_t<PAIR(N), NUM(1)>), (VAL(N))); \
    ASSERT((metal::at_t<LIST(LIMIT), NUM(N)>), (VAL(N))); \
    ASSERT((metal::at_t<MAP(LIMIT), NUM(N)>), (PAIR(N))); \
    ASSERT((metal::at_t<LBD(LIMIT), NUM(N)>), (ARG(N))); \
    ASSERT((metal::at_t<SEQ()<LISTS(M) COMMA(M) MAPS(INC(N))>, NUM(M)>), (MAP(0))); \
    ASSERT((metal::at_t<SEQ()< \
        VALS(LIMIT), NUMS(INC(M)), PAIRS(INC(M)), LISTS(INC(M)), \
        MAPS(INC(M)), ARGS(INC(M)), LBDS(INC(M)), FUNS(INC(M))>, NUM(N)>), (VAL(N))); \
/**/

GEN(MATRIX)

