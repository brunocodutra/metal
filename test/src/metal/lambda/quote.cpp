// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/lambda/quote.hpp>
#include <metal/lambda/apply.hpp>

#include "test.hpp"

#define MATRIX(_, N) \
    ASSERT((metal::quote_t<VAL(N)>::type), (VAL(N))); \
    ASSERT((metal::quote_t<NUM(N)>::type), (NUM(N))); \
    ASSERT((metal::quote_t<PAIR(N)>::type), (PAIR(N))); \
    ASSERT((metal::quote_t<LIST(N)>::type), (LIST(N))); \
    ASSERT((metal::quote_t<MAP(N)>::type), (MAP(N))); \
    ASSERT((metal::quote_t<ARG(N)>::type), (ARG(N))); \
    ASSERT((metal::quote_t<LBD(N)>::type), (LBD(N))); \
    ASSERT((metal::quote_t<FUN(N)>::type), (FUN(N))); \
    ASSERT((metal::apply_t<metal::quote_t<VAL(N)>>), (VAL(N))); \
    ASSERT((metal::apply_t<metal::quote_t<NUM(N)>>), (NUM(N))); \
    ASSERT((metal::apply_t<metal::quote_t<PAIR(N)>>), (PAIR(N))); \
    ASSERT((metal::apply_t<metal::quote_t<LIST(N)>>), (LIST(N))); \
    ASSERT((metal::apply_t<metal::quote_t<MAP(N)>>), (MAP(N))); \
    ASSERT((metal::apply_t<metal::quote_t<ARG(N)>>), (ARG(N))); \
    ASSERT((metal::apply_t<metal::quote_t<LBD(N)>>), (LBD(N))); \
    ASSERT((metal::apply_t<metal::quote_t<FUN(N)>>), (FUN(N))); \
/**/

GEN(MATRIX)
