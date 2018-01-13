// Copyright Bruno Dutra 2015-2018
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define SEQ1(M) metal::list<VALUE(M)>
#define CART1(M) metal::list<ENUM(M, SEQ1)>

#define SEQ2(N, M) metal::list<VALUE(M), VALUE(N)>
#define CART2_IMPL(M, N) ENUM(N, SEQ2, M)
#define CART2(M, N) metal::list<ENUM(M, CART2_IMPL, N)>

#define CART(...) CAT(CART, LENGTH(__VA_ARGS__))(__VA_ARGS__)

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::cartesian> COMMA(M) VALUES(M)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::cartesian> COMMA(M) NUMBERS(M)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::cartesian> COMMA(M) PAIRS(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cartesian> COMMA(M) LISTS(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cartesian> COMMA(M) MAPS(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::cartesian> COMMA(M) LAMBDAS(M)>), (BOOL(!M))); \
    CHECK((metal::cartesian<>), (metal::list<metal::list<>>)); \
    CHECK((metal::cartesian<LIST(M)>), (CART(M))); \
    CHECK((metal::cartesian<LIST(INC(M)), LIST(INC(N))>), (CART(INC(M), INC(N)))); \
/**/

GEN(MATRIX)
