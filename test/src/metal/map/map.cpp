// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/map/map.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/optional/optional.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::map<VALS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::map<NUMS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::map<PAIRS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::map<PAIR(M) COMMA(N) PAIRS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::map<LISTS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::map<MAPS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::map<ARGS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::map<LBDS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::map<FUNS(N)>>), (TRUE)); \
    ASSERT((metal::map<VALS(N)>::type), (metal::map<VALS(N)>)); \
    ASSERT((metal::map<NUMS(N)>::type), (metal::map<NUMS(N)>)); \
    ASSERT((metal::map<PAIRS(N)>::type), (metal::map<PAIRS(N)>)); \
    ASSERT((metal::map<PAIR(M) COMMA(N) PAIRS(N)>::type), (metal::map<PAIR(M) COMMA(N) PAIRS(N)>)); \
    ASSERT((metal::map<LISTS(N)>::type), (metal::map<LISTS(N)>)); \
    ASSERT((metal::map<MAPS(N)>::type), (metal::map<MAPS(N)>)); \
    ASSERT((metal::map<ARGS(N)>::type), (metal::map<ARGS(N)>)); \
    ASSERT((metal::map<LBDS(N)>::type), (metal::map<LBDS(N)>)); \
    ASSERT((metal::map<FUNS(N)>::type), (metal::map<FUNS(N)>)); \
    ASSERT((metal::is_map_t<VAL(N)>), (FALSE)); \
    ASSERT((metal::is_map_t<NUM(N)>), (FALSE)); \
    ASSERT((metal::is_map_t<PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_map_t<LIST(N)>), (BOOL(!N))); \
    ASSERT((metal::is_map_t<MAP(N)>), (TRUE)); \
    ASSERT((metal::is_map_t<ARG(N)>), (FALSE)); \
    ASSERT((metal::is_map_t<LBD(N)>), (FALSE)); \
    ASSERT((metal::is_map_t<FUN(N)>), (FALSE)); \
    ASSERT((metal::is_map_t<metal::map<VALS(N)>>), (BOOL(!N))); \
    ASSERT((metal::is_map_t<metal::map<NUMS(N)>>), (BOOL(!N))); \
    ASSERT((metal::is_map_t<metal::map<PAIRS(N)>>), (TRUE)); \
    ASSERT((metal::is_map_t<metal::map<PAIR(M) COMMA(N) PAIRS(N)>>), (BOOL(M >= N))); \
    ASSERT((metal::is_map_t<metal::map<LISTS(N)>>), (BOOL(!N))); \
    ASSERT((metal::is_map_t<metal::map<MAPS(N)>>), (BOOL(!N))); \
    ASSERT((metal::is_map_t<metal::map<ARGS(N)>>), (BOOL(!N))); \
    ASSERT((metal::is_map_t<metal::map<LBDS(N)>>), (BOOL(!N))); \
    ASSERT((metal::is_map_t<metal::map<FUNS(N)>>), (BOOL(!N))); \
/**/

GEN(MATRIX)
