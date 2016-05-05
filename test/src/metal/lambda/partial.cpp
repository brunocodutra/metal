// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/lambda/partial.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::partial<VAL(M) COMMA(N) VALS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::partial<NUM(M) COMMA(N) VALS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::partial<PAIR(M) COMMA(N) VALS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::partial<LIST(M) COMMA(N) VALS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::partial<MAP(M) COMMA(N) VALS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::partial<ARG(M) COMMA(N) VALS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::partial<LBD(M) COMMA(N) VALS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::partial<FUN() COMMA(N) VALS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::partial<FUN(M) COMMA(N) VALS(N)>>), (TRUE)); \
    ASSERT((metal::invoke_t<metal::partial_t<VAL(M) COMMA(M) VALS(M)> COMMA(N) NUMS(N)>), (VAL(M))); \
    ASSERT((metal::invoke_t<metal::partial_t<NUM(M) COMMA(M) VALS(M)> COMMA(N) NUMS(N)>), (NUM(M))); \
    ASSERT((metal::invoke_t<metal::partial_t<LBD(LIMIT) COMMA(M) VALS(M)> COMMA(CMPL(M)) NUMS(CMPL(M))>), (EXPR(LIMIT)<VALS(M) COMMA(AND(M, CMPL(M))) NUMS(CMPL(M))>::type)); \
    ASSERT((metal::invoke_t<metal::partial_t<FUN(LIMIT) COMMA(M) VALS(M)> COMMA(CMPL(M)) NUMS(CMPL(M))>), (EXPR(LIMIT)<VALS(M) COMMA(AND(M, CMPL(M))) NUMS(CMPL(M))>::type)); \
    ASSERT((metal::invoke_t<metal::partial_t<VAL(M) COMMA(M) ARGS(M)> COMMA(N) NUMS(N)>), (VAL(M))); \
    ASSERT((metal::invoke_t<metal::partial_t<NUM(M) COMMA(M) ARGS(M)> COMMA(N) NUMS(N)>), (NUM(M))); \
    ASSERT((metal::invoke_t<metal::partial_t<LBD(LIMIT) COMMA(M) ARGS(M)> COMMA(CMPL(M)) NUMS(CMPL(M))>), (EXPR(LIMIT)<ARGS(M) COMMA(AND(M, CMPL(M))) NUMS(CMPL(M))>::type)); \
    ASSERT((metal::invoke_t<metal::partial_t<FUN(LIMIT) COMMA(M) ARGS(M)> COMMA(CMPL(M)) NUMS(CMPL(M))>), (EXPR(LIMIT)<ARGS(M) COMMA(AND(M, CMPL(M))) NUMS(CMPL(M))>::type)); \
    ASSERT((metal::invoke_t<metal::partial_t<FUN(), LBD(M)> COMMA(N) NUMS(N)>), (EXPR()<LBD(M) COMMA(N) NUMS(N)>::type)); \
    ASSERT((metal::invoke_t<metal::partial_t<FUN(), FUN(M)> COMMA(N) NUMS(N)>), (EXPR()<FUN(M) COMMA(N) NUMS(N)>::type)); \
/**/

GEN(MATRIX)
