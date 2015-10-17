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
    ASSERT((metal::eval<VAL(M), VAL(N)>), (VAL(N))); \
    ASSERT((metal::eval<NUM(M), VAL(N)>), (NUM(M))); \
    ASSERT((metal::eval<PAIR(M), VAL(N)>), (VAL(N))); \
    ASSERT((metal::eval<LIST(M), VAL(N)>), (VAL(N))); \
    ASSERT((metal::eval<MAP(M), VAL(N)>), (VAL(N))); \
    ASSERT((metal::eval<ARG(M), VAL(N)>), (VAL(N))); \
    ASSERT((metal::eval<LBD(M), VAL(N)>), (LBD(M)::type)); \
    ASSERT((metal::eval<FUN(M), VAL(N)>), (VAL(N))); \
/**/

GEN(MATRIX)
