// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/optional/optional.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/list/size.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(_, N) \
    ASSERT((metal::is_just_t<VAL(N)>), (FALSE)); \
    ASSERT((metal::is_just_t<NUM(N)>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::optional<VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::optional<NUM(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::optional<LBD(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::optional<FUN(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::optional<EXPR()<VAL(N)>>>), (TRUE)); \
    ASSERT((metal::just<>), (metal::nothing)); \
    ASSERT((metal::just<VAL(N)>::type), (VAL(N))); \
    ASSERT((metal::size_t<metal::just<>>), (metal::number<std::size_t, 0>)); \
    ASSERT((metal::size_t<metal::just<VAL(N)>>), (metal::number<std::size_t, 1>)); \
    ASSERT((metal::optional<NUM(N)>::type), (NUM(N))); \
    ASSERT((metal::optional<LBD(N)>::type), (LBD(N)::type)); \
    ASSERT((metal::optional<EXPR()<VAL(N)>>::type), (EXPR()<VAL(N)>::type)); \
/**/

GEN(MATRIX)
