// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/list.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::list> COMMA(N) VALS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::list> COMMA(N) NUMS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::list> COMMA(N) PAIRS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::list> COMMA(N) VECTS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::list> COMMA(N) LISTS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::list> COMMA(N) LISTS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::list> COMMA(N) MAPS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::list> COMMA(N) LBDS(N)>), (TRUE)); \
    ASSERT((metal::is_list<VAL(N)>), (FALSE)); \
    ASSERT((metal::is_list<NUM(N)>), (FALSE)); \
    ASSERT((metal::is_list<PAIR(N)>), (TRUE)); \
    ASSERT((metal::is_list<VECT(N)>), (TRUE)); \
    ASSERT((metal::is_list<LIST(N)>), (TRUE)); \
    ASSERT((metal::is_list<MAP(N)>), (TRUE)); \
    ASSERT((metal::is_list<LBD(N)>), (FALSE)); \
    ASSERT((metal::is_list<LBD(_)>), (FALSE)); \
/**/

GEN(MATRIX)

