// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/optional/extract.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::from_maybe<VAL(M), VAL(N)>), (VAL(N))); \
    ASSERT((metal::from_maybe<NUM(M), VAL(N)>), (NUM(M))); \
    ASSERT((metal::from_maybe<PAIR(M), VAL(N)>), (VAL(N))); \
    ASSERT((metal::from_maybe<LIST(M), VAL(N)>), (VAL(N))); \
    ASSERT((metal::from_maybe<MAP(M), VAL(N)>), (VAL(N))); \
    ASSERT((metal::from_maybe<ARG(M), VAL(N)>), (VAL(N))); \
    ASSERT((metal::from_maybe<LBD(M), VAL(N)>), (LBD(M)::type)); \
    ASSERT((metal::from_maybe<FUN(M), VAL(N)>), (VAL(N))); \
    ASSERT((metal::from_just<NUM(N)>), (NUM(N))); \
    ASSERT((metal::from_just<LBD(N)>), (LBD(N)::type)); \
/**/

GEN(MATRIX)
