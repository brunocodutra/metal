// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/number/number.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_number_t<VAL(M)>), (FALSE)); \
    ASSERT((metal::is_number_t<NUM(M)>), (TRUE)); \
    ASSERT((metal::is_number_t<PAIR(M)>), (FALSE)); \
    ASSERT((metal::is_number_t<LIST(M)>), (FALSE)); \
    ASSERT((metal::is_number_t<MAP(M)>), (FALSE)); \
    ASSERT((metal::is_number_t<ARG(M)>), (FALSE)); \
    ASSERT((metal::is_number_t<LBD(M)>), (FALSE)); \
    ASSERT((metal::is_number_t<FUN(M)>), (FALSE)); \
    ASSERT((metal::is_number_t<metal::number<std::size_t, 0>>), (TRUE)); \
    ASSERT((metal::is_number_t<metal::integer<0>>), (TRUE)); \
    ASSERT((metal::is_number_t<metal::boolean<0>>), (TRUE)); \
/**/

GEN(MATRIX)
