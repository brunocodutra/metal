// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::not_<metal::not_<NUM(N)>>), (BOOL(!!N))); \
    ASSERT((metal::not_<metal::and_<NUM(M), NUM(N)>>), (metal::or_<metal::not_<NUM(M)>, metal::not_<NUM(N)>>)); \
    ASSERT((metal::not_<metal::or_<NUM(M), NUM(N)>>), (metal::and_<metal::not_<NUM(M)>, metal::not_<NUM(N)>>)); \
    ASSERT((metal::neg<metal::neg<NUM(N)>>), (NUM(N))); \
    ASSERT((metal::inc<metal::dec<NUM(N)>>), (NUM(N))); \
    ASSERT((metal::dec<metal::inc<NUM(N)>>), (NUM(N))); \
    ASSERT((metal::equal_to<metal::add<NUM(0) COMMA(N) ENUM(N, NUM FIX(M))>, metal::mul<NUM(M), NUM(N)>>), (TRUE)); \
    ASSERT((metal::equal_to<metal::mul<NUM(1) COMMA(N) ENUM(N, NUM FIX(M))>, metal::pow<NUM(M), NUM(N)>>), (TRUE)); \
    ASSERT((metal::equal_to<metal::add<NUMS(INC(N))>, metal::div<metal::mul<NUM(N), metal::inc<NUM(N)>>, NUM(2)>>), (TRUE)); \
    ASSERT((metal::equal_to<metal::sub<NUM(M), metal::mul<metal::div<NUM(M), NUM(INC(N))>, NUM(INC(N))>>, metal::mod<NUM(M), NUM(INC(N))>>), (TRUE)); \
    ASSERT((metal::equal_to<metal::mod<metal::pow<NUM(INC(M)), NUM(INC(N))>, NUM(INC(M))>, NUM(0)>), (TRUE)); \
    ASSERT((metal::equal_to<NUM(M), NUM(N)>), (metal::not_<metal::or_<metal::less<NUM(M), NUM(N)>, metal::greater<NUM(M), NUM(N)>>>)); \
    ASSERT((metal::less<NUM(M), NUM(N)>), (metal::greater<NUM(N), NUM(M)>)); \
    ASSERT((metal::if_<NUM(M), BOOL(!!N), FALSE>), (metal::and_<NUM(M), NUM(N)>)); \
    ASSERT((metal::if_<NUM(M), TRUE, BOOL(!!N)>), (metal::or_<NUM(M), NUM(N)>)); \
/**/

GEN(MATRIX)
