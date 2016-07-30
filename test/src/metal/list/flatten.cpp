// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/flatten.hpp>
#include <metal/list/join.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::flatten>, VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::flatten>, NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::flatten>, PAIR(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::flatten>, LIST(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::flatten>, MAP(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::flatten>, LBD(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::flatten>, LBD(_)>), (FALSE)); \
    ASSERT((metal::flatten<PAIR(M)>), (PAIR(M))); \
    ASSERT((metal::flatten<LIST(M)>), (LIST(M))); \
    ASSERT((metal::flatten<MAP(M)>), (metal::list<ENUM(M, FWD, NUM, VAL)>)); \
/**/

GEN(MATRIX)
