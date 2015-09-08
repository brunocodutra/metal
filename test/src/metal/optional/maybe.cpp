// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/optional/maybe.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define MATRIX(_, N) \
    ASSERT((metal::is_just_t<metal::maybe<VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::maybe<NUM(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::maybe<LBD(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::maybe<FUN(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::maybe<EXPR()<VAL(N)>>>), (TRUE)); \
    ASSERT((metal::maybe<NUM(N)>::type), (NUM(N))); \
    ASSERT((metal::maybe<LBD(N)>::type), (LBD(N)::type)); \
    ASSERT((metal::maybe<EXPR()<VAL(N)>>::type), (EXPR()<VAL(N)>::type)); \
/**/

GEN(MATRIX)
