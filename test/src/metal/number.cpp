// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/number.hpp>
#include <metal/list/apply.hpp>
#include <metal/lambda/lambda.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::equal_to_t<metal::pow_t<NUM(M), NUM(INC(N))>, metal::apply_t<metal::lambda<metal::mul>, metal::enumerate_t<NUM(M), NUM(INC(N)), NUM(0)>>>), (TRUE)); \
    ASSERT((metal::equal_to_t<metal::div_t<metal::add_t<metal::mul_t<NUM(LIMIT), NUM(2), NUM(M)>, metal::mul_t<NUM(LIMIT), NUM(DEC(LIMIT)), NUM(N)>>, NUM(2)>, metal::apply_t<metal::lambda<metal::add>, metal::enumerate_t<NUM(M), NUM(LIMIT), NUM(N)>>>), (TRUE)); \
/**/

GEN(MATRIX)
