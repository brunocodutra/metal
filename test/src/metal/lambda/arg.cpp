// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/lambda/arg.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::arg<INC(M)>), (CAT(metal::_, INC(M)))); \
    ASSERT((metal::is_lambda<metal::arg<INC(M)>>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::arg<INC(M)> COMMA(N) VALS(N)>), (BOOL(M < N))); \
    ASSERT((metal::invoke<metal::arg<INC(M)>, VALS(INC(M))>), (VAL(M))); \
/**/

GEN(MATRIX)
