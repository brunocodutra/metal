// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/list/same.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/optional/optional.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::same<VAL(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::same<NUM(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::same<PAIR(M)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::same<LIST(M)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::same<MAP(M)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::same<ARG(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::same<LBD(M)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::same<FUN(M)>>), (FALSE)); \
    ASSERT((metal::same_t<PAIR(M)>), (FALSE)); \
    ASSERT((metal::same_t<LIST(M)>), (BOOL(M < 2))); \
    ASSERT((metal::same_t<MAP(M)>), (BOOL(M < 2))); \
    ASSERT((metal::same_t<LBD(M)>), (BOOL(!M))); \
    ASSERT((metal::same_t<SEQ()<VAL(M), VALS(INC(M))>>), (BOOL(!M))); \
    ASSERT((metal::same_t<SEQ(M)<ENUM(M, VAL(N) BAR)>>), (TRUE)); \
    ASSERT((metal::same_t<SEQ()< \
        VALS(INC(M)), NUMS(INC(M)), PAIRS(INC(M)), LISTS(INC(M)), \
        MAPS(INC(M)), ARGS(INC(M)), LBDS(INC(M)), FUNS(INC(M))>>), (FALSE)); \
/**/

GEN(MATRIX)

