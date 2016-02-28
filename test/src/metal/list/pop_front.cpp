// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/list/pop_front.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/optional/optional.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::pop_front<VAL(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::pop_front<NUM(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::pop_front<VEC(M)>>), (BOOL(M > 0))); \
    ASSERT((metal::is_just_t<metal::pop_front<PAIR(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::pop_front<LIST(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::pop_front<MAP(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::pop_front<ARG(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::pop_front<LBD(M)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::pop_front<FUN(M)>>), (FALSE)); \
    ASSERT((metal::pop_front_t<LBD(0)>), (LBD(0))); \
    ASSERT((metal::pop_front_t<SEQ()<VAL(M) COMMA(N) VALS(N)>>), (VEC(N))); \
/**/

GEN(MATRIX)
