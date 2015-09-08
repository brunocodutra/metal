// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/optional/nothing.hpp>

#include "test.hpp"

#define MATRIX(_, N) \
    ASSERT((metal::is_nothing_t<VAL(N)>), (TRUE)); \
    ASSERT((metal::is_nothing_t<NUM(N)>), (FALSE)); \
/**/

GEN(MATRIX)

ASSERT((metal::is_nothing_t<metal::nothing>), (TRUE));
