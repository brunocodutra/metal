// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/optional/eval.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/lambda.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::eval<NUM(N)>), (NUM(N))); \
    ASSERT((metal::eval<LBD(N)>), (LBD(N)::type)); \
    ASSERT((metal::eval_or<VAL(M), VAL(N)>), (VAL(N))); \
    ASSERT((metal::eval_or<NUM(M), VAL(N)>), (NUM(M))); \
    ASSERT((metal::eval_or<PAIR(M), VAL(N)>), (VAL(N))); \
    ASSERT((metal::eval_or<LIST(M), VAL(N)>), (VAL(N))); \
    ASSERT((metal::eval_or<MAP(M), VAL(N)>), (VAL(N))); \
    ASSERT((metal::eval_or<ARG(M), VAL(N)>), (VAL(N))); \
    ASSERT((metal::eval_or<LBD(M), VAL(N)>), (LBD(M)::type)); \
    ASSERT((metal::eval_or<FUN(M), VAL(N)>), (VAL(N))); \
/**/

GEN(MATRIX)
