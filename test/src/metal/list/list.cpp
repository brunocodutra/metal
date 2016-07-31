// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::list> COMMA(N) VALS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::list> COMMA(N) NUMS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::list> COMMA(N) PAIRS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::list> COMMA(N) LISTS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::list> COMMA(N) LISTS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::list> COMMA(N) MAPS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::list> COMMA(N) LBDS(N)>), (TRUE)); \
    CHECK((metal::is_list<VAL(N)>), (FALSE)); \
    CHECK((metal::is_list<NUM(N)>), (FALSE)); \
    CHECK((metal::is_list<PAIR(N)>), (TRUE)); \
    CHECK((metal::is_list<LIST(N)>), (TRUE)); \
    CHECK((metal::is_list<MAP(N)>), (TRUE)); \
    CHECK((metal::is_list<LBD(N)>), (FALSE)); \
    CHECK((metal::is_list<LBD(_)>), (FALSE)); \
/**/

GEN(MATRIX)

