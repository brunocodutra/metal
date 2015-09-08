// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/core/inherit.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((std::is_base_of<NUM(M), metal::inherit<NUMS(N)>>::type), (BOOL(M < N))); \
    ASSERT((std::is_base_of<NUM(M), metal::inherit<NUMS(N) COMMA(N) NUMS(N)>>::type), (BOOL(M < N))); \
/**/

GEN(MATRIX)
