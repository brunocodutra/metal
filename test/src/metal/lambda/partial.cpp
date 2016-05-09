// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/lambda/partial.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define ARG(N) metal::arg<INC(N)>
#define ARGS(N) ENUM(N, ADAPT(ARG))

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<FUNC(metal::partial), VAL(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::partial), NUM(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::partial), PAIR(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::partial), LIST(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::partial), MAP(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::partial), LBD(M) COMMA(N) VALS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::partial), LBD() COMMA(N) VALS(N)>), (TRUE)); \
    ASSERT((metal::invoke<metal::partial<LBD(LIMIT) COMMA(M) VALS(M)> COMMA(CMPL(M)) NUMS(CMPL(M))>), (EXPR(LIMIT)<VALS(M) COMMA(AND(M, CMPL(M))) NUMS(CMPL(M))>)); \
    ASSERT((metal::invoke<metal::partial<LBD(LIMIT) COMMA(M) ARGS(M)> COMMA(CMPL(M)) NUMS(CMPL(M))>), (EXPR(LIMIT)<ARGS(M) COMMA(AND(M, CMPL(M))) NUMS(CMPL(M))>)); \
    ASSERT((metal::invoke<metal::partial<LBD(), LBD(M)> COMMA(N) NUMS(N)>), (EXPR()<LBD(M) COMMA(N) NUMS(N)>)); \
    ASSERT((metal::invoke<metal::partial<LBD(), LBD(M)> COMMA(N) NUMS(N)>), (EXPR()<LBD(M) COMMA(N) NUMS(N)>)); \
/**/

GEN(MATRIX)
