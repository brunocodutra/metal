// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/lambda/quote.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/list/list.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::quote>, VAL(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::quote>, NUM(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::quote>, PAIR(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::quote>, LIST(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::quote>, MAP(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::quote>, LBD(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::quote>, LBD(_)>), (TRUE)); \
    ASSERT((metal::invoke<metal::quote<VAL(M)> COMMA(N) VALS(N)>), (VAL(M))); \
    ASSERT((metal::invoke<metal::quote<NUM(M)> COMMA(N) VALS(N)>), (NUM(M))); \
    ASSERT((metal::invoke<metal::quote<PAIR(M)> COMMA(N) VALS(N)>), (PAIR(M))); \
    ASSERT((metal::invoke<metal::quote<LIST(M)> COMMA(N) VALS(N)>), (LIST(M))); \
    ASSERT((metal::invoke<metal::quote<MAP(M)> COMMA(N) VALS(N)>), (MAP(M))); \
    ASSERT((metal::invoke<metal::quote<LBD(M)> COMMA(N) VALS(N)>), (LBD(M))); \
    ASSERT((metal::invoke<metal::quote<LBD(_)> COMMA(N) VALS(N)>), (LBD(_))); \
/**/

GEN(MATRIX)
