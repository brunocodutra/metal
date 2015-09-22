// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/list/join.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::join<VALS(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::join<NUMS(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::join<PAIR(M) COMMA(N) PAIRS(N)>>), (BOOL(!N))); \
    ASSERT((metal::is_just_t<metal::join<LIST(M) COMMA(N) LISTS(N)>>), (BOOL(!M || N < 2))); \
    ASSERT((metal::is_just_t<metal::join<MAP(M) COMMA(N) MAPS(N)>>), (BOOL(!M || N < 2))); \
    ASSERT((metal::is_just_t<metal::join<ARGS(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::join<LBD(M) COMMA(N) LBDS(N)>>), (BOOL(!M || N < 2))); \
    ASSERT((metal::is_just_t<metal::join<FUNS(M)>>), (FALSE)); \
    ASSERT((metal::join_t<SEQ()<VALS(M)>>), (SEQ()<VALS(M)>)); \
    ASSERT((metal::join_t<SEQ()<NUMS(M)>>), (SEQ()<NUMS(M)>)); \
    ASSERT((metal::join_t<SEQ()<>, PAIR(M) COMMA(N) PAIRS(N)>), (SEQ()<NUM(M), VAL(M) COMMA(N) ENUM(N, LIFT(NUM), LIFT(VAL))>)); \
    ASSERT((metal::join_t<SEQ()<VAL(M)>, LIST(M) COMMA(N) LISTS(N)>), (SEQ()<VAL(M) COMMA(M) VALS(M) ENUM(N, LIFT(VALS))>)); \
    ASSERT((metal::join_t<SEQ()<VAL(M)>, MAP(M) COMMA(N) MAPS(N)>), (SEQ()<VAL(M) COMMA(M) PAIRS(M) ENUM(N, LIFT(PAIRS))>)); \
    ASSERT((metal::join_t<SEQ()<ARGS(M)>>), (SEQ()<ARGS(M)>)); \
    ASSERT((metal::join_t<SEQ()<VAL(M)>, LBD(M) COMMA(N) LBDS(N)>), (SEQ()<VAL(M) COMMA(M) ARGS(M) ENUM(N, LIFT(ARGS))>)); \
    ASSERT((metal::join_t<SEQ()<FUNS(M)>>), (SEQ()<FUNS(M)>)); \
/**/

GEN(MATRIX)
