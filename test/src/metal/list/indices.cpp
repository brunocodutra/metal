// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/indices.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::indices>, VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::indices>, NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::indices>, PAIR(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::indices>, LIST(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::indices>, MAP(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::indices>, LBD(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::indices>, LBD(_)>), (FALSE)); \
    ASSERT((metal::indices<PAIR(M)>), (metal::list<ENUM(2, SIZE_T)>)); \
    ASSERT((metal::indices<LIST(M)>), (metal::list<ENUM(M, SIZE_T)>)); \
    ASSERT((metal::indices<MAP(M)>), (metal::list<ENUM(M, SIZE_T)>)); \
/**/

GEN(MATRIX)

