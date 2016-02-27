// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/list/back.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/optional/optional.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::back<VAL(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::back<NUM(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::back<PAIR(M)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::back<LIST(M)>>), (BOOL(M > 0))); \
    ASSERT((metal::is_just_t<metal::back<MAP(M)>>), (BOOL(M > 0))); \
    ASSERT((metal::is_just_t<metal::back<ARG(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::back<LBD(M)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::back<FUN(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::back<SEQ()<VALS(M) COMMA(M) VAL(N)>>>), (TRUE)); \
    ASSERT((metal::back_t<PAIR(M)>), (VAL(M))); \
    ASSERT((metal::back_t<LIST(INC(M))>), (VAL(M))); \
    ASSERT((metal::back_t<MAP(INC(M))>), (PAIR(M))); \
    ASSERT((metal::back_t<LBD(LIMIT)>), (ARG(DEC(LIMIT)))); \
    ASSERT((metal::back_t<LBD(M)>), (NA())); \
    ASSERT((metal::back_t<SEQ()<VALS(M) COMMA(M) VAL(N)>>), (VAL(N))); \
    ASSERT((metal::back_t<SEQ()< \
        VALS(INC(M)), NUMS(INC(M)), PAIRS(INC(M)), LISTS(INC(M)), \
        MAPS(INC(M)), ARGS(INC(M)), LBDS(INC(M)), FUNS(INC(M))>>), (FUN(M))); \
/**/

GEN(MATRIX)

