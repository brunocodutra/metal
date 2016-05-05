// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/optional/just.hpp>

#include "test.hpp"

#define MATRIX(_, N) \
    ASSERT((metal::just<>), (metal::nothing)); \
    ASSERT((metal::is_just_t<VAL(N)>), (FALSE)); \
    ASSERT((metal::is_just_t<NUM(N)>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::just<>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::just<VAL(N)>>), (TRUE)); \
    ASSERT((metal::just<VAL(N)>::type), (VAL(N))); \
/**/

GEN(MATRIX)
