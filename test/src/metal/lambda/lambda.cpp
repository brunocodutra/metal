// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/lambda/lambda.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::lambda<SEQ()>::call<VALS(N)>), (SEQ()<VALS(N)>)); \
    ASSERT((metal::lambda<SEQ(M)>::call<VALS(M)>), (SEQ(M)<VALS(M)>)); \
    ASSERT((metal::lambda<EXPR()>::call<VALS(N)>::type), (EXPR()<VALS(N)>::type)); \
    ASSERT((metal::lambda<EXPR(M)>::call<VALS(M)>::type), (EXPR(M)<VALS(M)>::type)); \
/**/

GEN(MATRIX)
