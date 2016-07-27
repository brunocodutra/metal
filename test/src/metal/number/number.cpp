// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_number<VAL(M)>), (FALSE)); \
    ASSERT((metal::is_number<NUM(M)>), (TRUE)); \
    ASSERT((metal::is_number<PAIR(M)>), (FALSE)); \
    ASSERT((metal::is_number<VECT(M)>), (FALSE)); \
    ASSERT((metal::is_number<LIST(M)>), (FALSE)); \
    ASSERT((metal::is_number<MAP(M)>), (FALSE)); \
    ASSERT((metal::is_number<LBD(M)>), (FALSE)); \
    ASSERT((metal::is_number<LBD(_)>), (FALSE)); \
    ASSERT((metal::is_number<metal::size_t<M>>), (TRUE)); \
    ASSERT((metal::is_number<metal::int_<M>>), (TRUE)); \
    ASSERT((metal::is_number<metal::char_<M>>), (TRUE)); \
    ASSERT((metal::is_number<metal::size_t<M>>), (TRUE)); \
    ASSERT((metal::is_number<metal::ptrdiff_t<M>>), (TRUE)); \
    ASSERT((metal::is_number<metal::bool_<!M>>), (TRUE)); \
    ASSERT((metal::is_number<metal::false_>), (TRUE)); \
    ASSERT((metal::is_number<metal::true_>), (TRUE)); \
/**/

GEN(MATRIX)
