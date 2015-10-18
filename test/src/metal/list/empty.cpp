// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/list/empty.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/optional/optional.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::empty<VAL(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::empty<NUM(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::empty<PAIR(M)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::empty<LIST(M)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::empty<MAP(M)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::empty<ARG(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::empty<LBD(M)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::empty<FUN(M)>>), (FALSE)); \
    ASSERT((metal::empty_t<PAIR(M)>), (FALSE)); \
    ASSERT((metal::empty_t<LIST(M)>), (BOOL(!M))); \
    ASSERT((metal::empty_t<MAP(M)>), (BOOL(!M))); \
    ASSERT((metal::empty_t<LBD(M)>), (FALSE)); \
    ASSERT((metal::empty_t<SEQ()<VAL(M), VALS(INC(M))>>), (FALSE)); \
    ASSERT((metal::empty_t<SEQ(M)<ENUM(M, VAL(N) BAR)>>), (BOOL(!M))); \
    ASSERT((metal::empty_t<SEQ()< \
        VALS(INC(M)), NUMS(INC(M)), PAIRS(INC(M)), LISTS(INC(M)), \
        MAPS(INC(M)), ARGS(INC(M)), LBDS(INC(M)), FUNS(INC(M))>>), (FALSE)); \
/**/

GEN(MATRIX)

