// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/size.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::size>, VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::size>, NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::size>, PAIR(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::size>, LIST(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::size>, MAP(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::size>, LBD(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::size>, LBD(_)>), (FALSE)); \
    ASSERT((metal::size<PAIR(M)>), (SIZE_T(2))); \
    ASSERT((metal::size<LIST(M)>), (SIZE_T(M))); \
    ASSERT((metal::size<MAP(M)>), (SIZE_T(M))); \
    ASSERT((metal::size<metal::list<VALS(M) COMMA(AND(M, N)) VALS(N)>>), (SIZE_T(M + N))); \
    ASSERT((metal::size<metal::list<ENUM(M, VAL FIX(N))>>), (SIZE_T(M))); \
/**/

GEN(MATRIX)

