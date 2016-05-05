// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/list/clear.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::clear<VAL(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::clear<NUM(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::clear<VEC(M)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::clear<PAIR(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::clear<LIST(M)>>), (BOOL(!M))); \
    ASSERT((metal::is_just_t<metal::clear<MAP(M)>>), (BOOL(!M))); \
    ASSERT((metal::is_just_t<metal::clear<ARG(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::clear<LBD(M)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::clear<FUN(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::clear<SEQ()<VALS(M) COMMA(AND(M, N)) VALS(N)>>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::clear<SEQ(M)<ENUM(M, VAL(N) BAR)>>>), (BOOL(!M))); \
    ASSERT((metal::clear_t<VEC(M)>), (VEC(0))); \
    ASSERT((metal::clear_t<LIST(0)>), (LIST(0))); \
    ASSERT((metal::clear_t<MAP(0)>), (MAP(0))); \
    ASSERT((metal::clear_t<LBD(M)>), (LBD(0))); \
/**/

GEN(MATRIX)

