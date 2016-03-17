// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/lambda/lambda.hpp>
#include <metal/optional/optional.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::lambda<EXPR()>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::lambda<EXPR(M)>>), (TRUE)); \
    ASSERT((metal::lambda<EXPR()>::type), (metal::lambda<EXPR()>)); \
    ASSERT((metal::lambda<EXPR(M)>::type), (metal::lambda<EXPR(M)>)); \
/**/

GEN(MATRIX)
