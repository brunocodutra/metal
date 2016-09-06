// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/lambda/arg.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/list/list.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::arg<INC(M)>), (CAT(metal::_, INC(M)))); \
    CHECK((metal::is_lambda<metal::arg<INC(M)>>), (TRUE)); \
    CHECK((metal::is_invocable<metal::arg<INC(M)> COMMA(N) VALUES(N)>), (BOOL(M < N))); \
    CHECK((metal::invoke<metal::arg<INC(M)>, VALUES(INC(M))>), (VALUE(M))); \
/**/

GEN(MATRIX)
