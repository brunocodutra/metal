// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/optional/optional.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define MATRIX(_, N) \
    ASSERT((metal::is_just_t<metal::optional<VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::optional<NUM(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::optional<LBD(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::optional<FUN(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::optional<EXPR()<VAL(N)>>>), (TRUE)); \
    ASSERT((metal::optional<NUM(N)>::type), (NUM(N))); \
    ASSERT((metal::optional<LBD(N)>::type), (LBD(N)::type)); \
    ASSERT((metal::optional<EXPR()<VAL(N)>>::type), (EXPR()<VAL(N)>::type)); \
/**/

GEN(MATRIX)
