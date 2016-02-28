// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/list/front.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/optional/optional.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::front<VAL(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::front<NUM(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::front<PAIR(M)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::front<LIST(M)>>), (BOOL(M > 0))); \
    ASSERT((metal::is_just_t<metal::front<MAP(M)>>), (BOOL(M > 0))); \
    ASSERT((metal::is_just_t<metal::front<ARG(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::front<LBD(M)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::front<FUN(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::front<SEQ()<VAL(M) COMMA(N) VALS(N)>>>), (TRUE)); \
    ASSERT((metal::front_t<PAIR(M)>), (NUM(M))); \
    ASSERT((metal::front_t<LIST(INC(M))>), (VAL(0))); \
    ASSERT((metal::front_t<MAP(INC(M))>), (PAIR(0))); \
    ASSERT((metal::front_t<LBD(0)>), (NA())); \
    ASSERT((metal::front_t<LBD(INC(M))>), (ARG(0))); \
    ASSERT((metal::front_t<SEQ()<VAL(M) COMMA(N) VALS(N)>>), (VAL(M))); \
    ASSERT((metal::front_t<SEQ()< \
        VALS(INC(M)), NUMS(INC(M)), PAIRS(INC(M)), LISTS(INC(M)), \
        MAPS(INC(M)), ARGS(INC(M)), LBDS(INC(M)), FUNS(INC(M))>>), (VAL(0))); \
/**/

GEN(MATRIX)

