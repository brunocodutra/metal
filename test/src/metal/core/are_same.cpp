// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/core/are_same.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::are_same<VALS(M)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::are_same<NUMS(M)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::are_same<PAIRS(M)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::are_same<LISTS(M)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::are_same<MAPS(M)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::are_same<ARGS(M)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::are_same<LBDS(M)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::are_same<FUNS(M)>>), (TRUE)); \
    ASSERT((metal::are_same_t<PAIRS(M)>), (BOOL(M < 2))); \
    ASSERT((metal::are_same_t<LISTS(M)>), (BOOL(M < 2))); \
    ASSERT((metal::are_same_t<MAPS(M)>), (BOOL(M < 2))); \
    ASSERT((metal::are_same_t<LBDS(M)>), (BOOL(M < 2))); \
    ASSERT((metal::are_same_t<VAL(M), VALS(INC(M))>), (BOOL(!M))); \
    ASSERT((metal::are_same_t<ENUM(M, VAL(N) BAR)>), (TRUE)); \
    ASSERT((metal::are_same_t< \
        VALS(INC(M)), NUMS(INC(M)), PAIRS(INC(M)), LISTS(INC(M)), \
        MAPS(INC(M)), ARGS(INC(M)), LBDS(INC(M)), FUNS(INC(M))>), (FALSE)); \
/**/

GEN(MATRIX)

