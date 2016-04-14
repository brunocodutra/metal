// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/list/distinct.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/optional/optional.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::distinct<VAL(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::distinct<NUM(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::distinct<PAIR(M)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::distinct<LIST(M)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::distinct<MAP(M)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::distinct<ARG(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::distinct<LBD(M)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::distinct<FUN(M)>>), (FALSE)); \
    ASSERT((metal::distinct_t<PAIR(M)>), (TRUE)); \
    ASSERT((metal::distinct_t<LIST(M)>), (TRUE)); \
    ASSERT((metal::distinct_t<MAP(M)>), (TRUE)); \
    ASSERT((metal::distinct_t<LBD(M)>), (BOOL(CMPL(M) < 2))); \
    ASSERT((metal::distinct_t<SEQ()<VAL(M), VALS(INC(M))>>), (FALSE)); \
    ASSERT((metal::distinct_t<SEQ(M)<ENUM(M, VAL(N) BAR)>>), (BOOL(M < 2))); \
    ASSERT((metal::distinct_t<SEQ()< \
        VALS(INC(M)), NUMS(INC(M)), PAIRS(INC(M)), LISTS(INC(M)), \
        MAPS(INC(M)), ARGS(INC(M)), LBDS(INC(M)), FUNS(INC(M))>>), (FALSE)); \
/**/

GEN(MATRIX)

