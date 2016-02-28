// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/list/pop_back.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/optional/optional.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::pop_back<VAL(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::pop_back<NUM(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::pop_back<VEC(M)>>), (BOOL(M > 0))); \
    ASSERT((metal::is_just_t<metal::pop_back<PAIR(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::pop_back<LIST(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::pop_back<MAP(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::pop_back<ARG(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::pop_back<LBD(M)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::pop_back<FUN(M)>>), (FALSE)); \
    ASSERT((metal::pop_back_t<LBD(M)>), (LBD(M))); \
    ASSERT((metal::pop_back_t<SEQ()<VALS(N) COMMA(N) VAL(M)>>), (VEC(N))); \
/**/

GEN(MATRIX)
