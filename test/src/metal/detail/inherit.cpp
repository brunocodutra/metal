// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/detail/inherit.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((std::is_base_of<NUM(M), metal::detail::inherit<NUMS(N)>>::type), (BOOL(M < N))); \
    ASSERT((std::is_base_of<NUM(M), metal::detail::inherit<NUMS(N) COMMA(N) NUMS(N)>>::type), (BOOL(M < N))); \
/**/

GEN(MATRIX)
