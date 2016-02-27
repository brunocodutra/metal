// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/list/size.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/number/number.hpp>
#include <metal/optional/optional.hpp>

#include "test.hpp"

#define SIZE(...) metal::number<std::size_t, (__VA_ARGS__)>

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::size<VAL(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::size<NUM(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::size<PAIR(M)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::size<LIST(M)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::size<MAP(M)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::size<ARG(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::size<LBD(M)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::size<FUN(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::size<SEQ()<VALS(M) COMMA(AND(M, N)) VALS(N)>>>), (TRUE)); \
    ASSERT((metal::size_t<PAIR(M)>), (SIZE(2))); \
    ASSERT((metal::size_t<LIST(M)>), (SIZE(M))); \
    ASSERT((metal::size_t<MAP(M)>), (SIZE(M))); \
    ASSERT((metal::size_t<LBD(M)>), (SIZE(LIMIT))); \
    ASSERT((metal::size_t<SEQ()<VALS(M) COMMA(AND(M, N)) VALS(N)>>), (SIZE(M + N))); \
    ASSERT((metal::size_t<SEQ(M)<ENUM(M, VAL(N) BAR)>>), (SIZE(M))); \
    ASSERT((metal::size_t<SEQ()< \
        VALS(M) COMMA(M) NUMS(M) COMMA(M) PAIRS(M) COMMA(M) LISTS(M) COMMA(AND(M, N)) \
        MAPS(N) COMMA(N) ARGS(N) COMMA(N) LBDS(N) COMMA(N) FUNS(N)>>), (SIZE(4*(M + N)))); \
/**/

GEN(MATRIX)

