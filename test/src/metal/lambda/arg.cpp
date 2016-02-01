// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/lambda/arg.hpp>
#include <metal/optional/optional.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::arg<M>>), (FALSE)); \
    ASSERT((CAT(metal::_, INC(M))), (metal::arg<INC(M)>)); \
/**/

GEN(MATRIX)
