// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/list.hpp>
#include <metal/lambda/lambda.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::flatten_t<metal::transform_t<LIST(M), metal::lambda<metal::list>>>), (LIST(M))); \
    ASSERT((metal::flatten_t<metal::reduce_t<LIST(M), metal::lambda<metal::list>>>), (metal::list<VALS(M)>)); \
    ASSERT((metal::slice_t<LIST(M), metal::size_t<LIST(M)>, metal::size_t<LIST(M)>>), (LIST(M))); \
/**/

GEN(MATRIX)
