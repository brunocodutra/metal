// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/optional/conditional.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::conditional<VALS(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::conditional<NUMS(N)>>), (BOOL(N > 2))); \
    ASSERT((metal::conditional_t<ENUM(M, NUM(0) BAR) COMMA(M) NUM(INC(N)), EXPR()<VAL(N)>>), (EXPR()<VAL(N)>::type)); \
    ASSERT((metal::conditional_t<NUM(INC(N)), EXPR()<VAL(N)> COMMA(M) VALS(M)>), (EXPR()<VAL(N)>::type)); \
/**/

GEN(MATRIX)





