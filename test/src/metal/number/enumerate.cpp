// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/number/enumerate.hpp>
#include <metal/number/number.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/optional/just.hpp>
#include <metal/list/list.hpp>

#include "test.hpp"

#define NUMBER(N, TYPE, A, B) COMMA(N) metal::number<TYPE, A*N + B>

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::enumerate<VAL(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::enumerate<NUM(M)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::enumerate<PAIR(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::enumerate<LIST(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::enumerate<MAP(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::enumerate<ARG(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::enumerate<LBD(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::enumerate<FUN(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::enumerate<NUM(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::enumerate<NUM(M), NUM(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::enumerate<NUM(M), PAIR(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::enumerate<NUM(M), LIST(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::enumerate<NUM(M), MAP(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::enumerate<NUM(M), ARG(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::enumerate<NUM(M), LBD(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::enumerate<NUM(M), FUN(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::enumerate<NUM(M), NUM(N), VAL(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::enumerate<NUM(M), NUM(N), NUM(M)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::enumerate<NUM(M), NUM(N), PAIR(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::enumerate<NUM(M), NUM(N), LIST(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::enumerate<NUM(M), NUM(N), MAP(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::enumerate<NUM(M), NUM(N), ARG(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::enumerate<NUM(M), NUM(N), LBD(M)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::enumerate<NUM(M), NUM(N), FUN(M)>>), (FALSE)); \
    ASSERT((metal::enumerate_t<NUM(M)>), (metal::list<REPEAT(M, NUMBER, NUM(M)::value_type, 1, 0)>)); \
    ASSERT((metal::enumerate_t<NUM(M), NUM(N)>), (metal::list<REPEAT(N, NUMBER, NUM(M)::value_type, 1, M)>)); \
    ASSERT((metal::enumerate_t<NUM(M), NUM(N), NUM(M)>), (metal::list<REPEAT(N, NUMBER, NUM(M)::value_type, M, M)>)); \
    ASSERT((metal::enumerate_t<NUM(M), metal::integer<-N>, metal::integer<-M>>), (metal::list<REPEAT(N, NUMBER, NUM(M)::value_type, M, M)>)); \
    ASSERT((metal::enumerate_t<metal::integer<-M>>), (metal::list<REPEAT(M, NUMBER, int, -1, 0)>)); \
    ASSERT((metal::enumerate_t<metal::integer<-M>, NUM(N)>), (metal::list<REPEAT(N, NUMBER, int, 1, -M)>)); \
    ASSERT((metal::enumerate_t<metal::integer<-M>, NUM(N), NUM(M)>), (metal::list<REPEAT(N, NUMBER, int, M, -M)>)); \
    ASSERT((metal::enumerate_t<metal::integer<-M>, metal::integer<-N>>), (metal::list<REPEAT(N, NUMBER, int, -1, -M)>)); \
    ASSERT((metal::enumerate_t<metal::integer<-M>, metal::integer<-N>, NUM(M)>), (metal::list<REPEAT(N, NUMBER, int, -M, -M)>)); \
    ASSERT((metal::enumerate_t<metal::integer<-M>, NUM(N), metal::integer<-M>>), (metal::list<REPEAT(N, NUMBER, int, -M, -M)>)); \
    ASSERT((metal::enumerate_t<metal::integer<-M>, metal::integer<-N>, metal::integer<-M>>), (metal::list<REPEAT(N, NUMBER, int, M, -M)>)); \
/**/

GEN(MATRIX)
