// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/core/voider.hpp>
#include <metal/optional/optional.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::voider<VALS(N)>>), (TRUE)); \
    ASSERT((metal::voider_t<VALS(N)>), (void)); \
/**/

GEN(MATRIX)
