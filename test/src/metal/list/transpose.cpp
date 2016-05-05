// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/list/transpose.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define FORWARD(N, M, ...) COMMA(N) M(__VA_ARGS__)

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::transpose<VAL(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::transpose<NUM(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::transpose<PAIR(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::transpose<LIST(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::transpose<MAP(M)>>), (BOOL(M > 0))); \
    ASSERT((metal::is_just_t<metal::transpose<ARG(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::transpose<LBD(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::transpose<FUN(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::transpose<SEQ()<LISTS(N)>>>), (BOOL(N == 1))); \
    ASSERT((metal::is_just_t<metal::transpose<SEQ(M)<REPEAT(M, FORWARD, LIST, N)>>>), (BOOL(M > 0))); \
    ASSERT((metal::is_just_t<metal::transpose<SEQ()<REPEAT(M, FORWARD, LIST, N) COMMA(M) VEC(N)>>>), (BOOL(!M || !N))); \
    ASSERT((metal::is_just_t<metal::transpose<SEQ()<REPEAT(M, FORWARD, LIST, N) COMMA(M) VAL(N)>>>), (FALSE)); \
    ASSERT((metal::transpose_t<SEQ(INC(M))<REPEAT(INC(M), FORWARD, LIST, 0)>>), (LIST(0))); \
    ASSERT((metal::transpose_t<metal::transpose_t<MAP(INC(M))>>), (MAP(INC(M)))); \
    ASSERT((metal::transpose_t<metal::transpose_t<SEQ(INC(M))<REPEAT(INC(M), FORWARD, MAP, INC(N))>>>), (SEQ(INC(M))<REPEAT(INC(M), FORWARD, MAP, INC(N))>)); \
/**/

GEN(MATRIX)
