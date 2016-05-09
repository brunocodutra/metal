// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/number/enumerate.hpp>
#include <metal/number/number.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/list/list.hpp>

#include "test.hpp"

#define NUMBER(N, TYPE, A, B) COMMA(N) metal::number<TYPE, A*N + B>

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<FUNC(metal::enumerate), NUM(M), NUM(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::enumerate), NUM(M), NUM(N), NUM(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::enumerate), NUM(M), NUM(N), PAIR(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::enumerate), NUM(M), NUM(N), LIST(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::enumerate), NUM(M), NUM(N), MAP(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::enumerate), NUM(M), NUM(N), LBD(M)>), (FALSE)); \
    ASSERT((metal::enumerate<NUM(M), NUM(N)>), (metal::list<REPEAT(N, NUMBER, NUM(M)::value_type, 1, M)>)); \
    ASSERT((metal::enumerate<NUM(M), NUM(N), NUM(M)>), (metal::list<REPEAT(N, NUMBER, NUM(M)::value_type, M, M)>)); \
    ASSERT((metal::enumerate<NUM(M), metal::int_<-N>, metal::int_<-M>>), (metal::list<REPEAT(N, NUMBER, NUM(M)::value_type, M, M)>)); \
    ASSERT((metal::enumerate<metal::int_<-M>, NUM(N)>), (metal::list<REPEAT(N, NUMBER, int, 1, -M)>)); \
    ASSERT((metal::enumerate<metal::int_<-M>, NUM(N), NUM(M)>), (metal::list<REPEAT(N, NUMBER, int, M, -M)>)); \
    ASSERT((metal::enumerate<metal::int_<-M>, metal::int_<-N>>), (metal::list<REPEAT(N, NUMBER, int, -1, -M)>)); \
    ASSERT((metal::enumerate<metal::int_<-M>, metal::int_<-N>, NUM(M)>), (metal::list<REPEAT(N, NUMBER, int, -M, -M)>)); \
    ASSERT((metal::enumerate<metal::int_<-M>, NUM(N), metal::int_<-M>>), (metal::list<REPEAT(N, NUMBER, int, -M, -M)>)); \
    ASSERT((metal::enumerate<metal::int_<-M>, metal::int_<-N>, metal::int_<-M>>), (metal::list<REPEAT(N, NUMBER, int, M, -M)>)); \
/**/

GEN(MATRIX)
