// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/optional/eval.hpp>
#include <metal/lambda/arg.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::eval<NUM(N)>), (NUM(N))); \
    ASSERT((metal::eval<LBD(N)>), (LBD(N)::type)); \
/**/

GEN(MATRIX)
