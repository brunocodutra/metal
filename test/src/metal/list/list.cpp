// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/list/list.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::list<VALS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::list<NUMS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::list<PAIRS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::list<PAIR(M) COMMA(N) PAIRS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::list<LISTS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::list<MAPS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::list<ARGS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::list<LBDS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::list<FUNS(N)>>), (TRUE)); \
    ASSERT((metal::is_list_t<VAL(N)>), (FALSE)); \
    ASSERT((metal::is_list_t<NUM(N)>), (FALSE)); \
    ASSERT((metal::is_list_t<PAIR(N)>), (TRUE)); \
    ASSERT((metal::is_list_t<LIST(N)>), (TRUE)); \
    ASSERT((metal::is_list_t<MAP(N)>), (TRUE)); \
    ASSERT((metal::is_list_t<ARG(N)>), (FALSE)); \
    ASSERT((metal::is_list_t<LBD(N)>), (TRUE)); \
    ASSERT((metal::is_list_t<FUN(N)>), (FALSE)); \
/**/

GEN(MATRIX)

