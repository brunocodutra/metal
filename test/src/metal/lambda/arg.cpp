// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/lambda/arg.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((CAT(metal::_, INC(M))), (metal::arg<INC(M)>)); \
    ASSERT((metal::is_just_t<metal::arg<M COMMA(N) VALS(N)>>), (BOOL(M && M <= N))); \
    ASSERT((metal::is_just_t<metal::arg<M COMMA(N) NUMS(N)>>), (BOOL(M && M <= N))); \
    ASSERT((metal::is_just_t<metal::arg<M COMMA(N) PAIRS(N)>>), (BOOL(M && M <= N))); \
    ASSERT((metal::is_just_t<metal::arg<M COMMA(N) LISTS(N)>>), (BOOL(M && M <= N))); \
    ASSERT((metal::is_just_t<metal::arg<M COMMA(N) MAPS(N)>>), (BOOL(M && M <= N))); \
    ASSERT((metal::is_just_t<metal::arg<M COMMA(N) ARGS(N)>>), (BOOL(M && M <= N))); \
    ASSERT((metal::is_just_t<metal::arg<M COMMA(N) LBDS(N)>>), (BOOL(M && M <= N))); \
    ASSERT((metal::is_just_t<metal::arg<M COMMA(N) FUNS(N)>>), (BOOL(M && M <= N))); \
    ASSERT((metal::arg_t<INC(M), VALS(INC(M))>), (VAL(M))); \
    ASSERT((metal::arg_t<INC(M), NUMS(INC(M))>), (NUM(M))); \
    ASSERT((metal::arg_t<INC(M), PAIRS(INC(M))>), (PAIR(M))); \
    ASSERT((metal::arg_t<INC(M), LISTS(INC(M))>), (LIST(M))); \
    ASSERT((metal::arg_t<INC(M), ARGS(INC(M))>), (ARG(M))); \
    ASSERT((metal::arg_t<INC(M), LBDS(INC(M))>), (LBD(M))); \
    ASSERT((metal::arg_t<INC(M), FUNS(INC(M))>), (FUN(M))); \
/**/

GEN(MATRIX)
