// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/list/push_back.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::push_back<VAL(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::push_back<NUM(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::push_back<VEC(M), VAL(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::push_back<PAIR(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::push_back<LIST(INC(M)), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::push_back<MAP(INC(M)), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::push_back<ARG(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::push_back<LBD(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::push_back<FUN(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::push_back_t<VEC(M), VAL(N)>), (SEQ()<VALS(M) COMMA(M) VAL(N)>)); \
/**/

GEN(MATRIX)
