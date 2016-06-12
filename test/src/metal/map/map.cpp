// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/map/map.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::map> COMMA(N) VALS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::map> COMMA(N) NUMS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::map> COMMA(N) PAIRS(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::map> COMMA(N) VECTS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::map> COMMA(N) LISTS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::map> COMMA(N) MAPS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::map> COMMA(N) LBDS(N)>), (BOOL(!N))); \
    ASSERT((metal::is_invocable<test::lambda<metal::map>, PAIR(M) COMMA(N) PAIRS(N)>), (BOOL(M >= N))); \
    ASSERT((metal::is_map<VAL(N)>), (FALSE)); \
    ASSERT((metal::is_map<NUM(N)>), (FALSE)); \
    ASSERT((metal::is_map<PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_map<VECT(N)>), (FALSE)); \
    ASSERT((metal::is_map<LIST(N)>), (BOOL(!N))); \
    ASSERT((metal::is_map<MAP(N)>), (TRUE)); \
    ASSERT((metal::is_map<LBD(N)>), (FALSE)); \
    ASSERT((metal::is_map<LBD(_)>), (FALSE)); \
    ASSERT((metal::is_map<test::vect<PAIR(N) COMMA(M) PAIRS(M)>>), (BOOL(M + 1 == INF && N >= M))); \
    ASSERT((metal::is_map<test::list<PAIR(N) COMMA(M) PAIRS(M)>>), (BOOL(N >= M))); \
/**/

GEN(MATRIX)
