// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/lambda/quote.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::quote_t<VAL(N)>::type), (VAL(N))); \
    ASSERT((metal::quote_t<NUM(N)>::type), (NUM(N))); \
    ASSERT((metal::quote_t<PAIR(N)>::type), (PAIR(N))); \
    ASSERT((metal::quote_t<LIST(N)>::type), (LIST(N))); \
    ASSERT((metal::quote_t<MAP(N)>::type), (MAP(N))); \
    ASSERT((metal::quote_t<ARG(N)>::type), (ARG(N))); \
    ASSERT((metal::quote_t<LBD(N)>::type), (LBD(N))); \
    ASSERT((metal::quote_t<FUN(N)>::type), (FUN(N))); \
    ASSERT((metal::invoke_t<metal::quote_t<VAL(M)> COMMA(N) VALS(N)>), (VAL(M))); \
    ASSERT((metal::invoke_t<metal::quote_t<NUM(M)> COMMA(N) VALS(N)>), (NUM(M))); \
    ASSERT((metal::invoke_t<metal::quote_t<PAIR(M)> COMMA(N) VALS(N)>), (PAIR(M))); \
    ASSERT((metal::invoke_t<metal::quote_t<LIST(M)> COMMA(N) VALS(N)>), (LIST(M))); \
    ASSERT((metal::invoke_t<metal::quote_t<MAP(M)> COMMA(N) VALS(N)>), (MAP(M))); \
    ASSERT((metal::invoke_t<metal::quote_t<ARG(M)> COMMA(N) VALS(N)>), (ARG(M))); \
    ASSERT((metal::invoke_t<metal::quote_t<LBD(M)> COMMA(N) VALS(N)>), (LBD(M))); \
    ASSERT((metal::invoke_t<metal::quote_t<FUN(M)> COMMA(N) VALS(N)>), (FUN(M))); \
/**/

GEN(MATRIX)
