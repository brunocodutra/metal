// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/reverse.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>
#include <metal/number/enumerate.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::reverse>, VAL(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::reverse>, NUM(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::reverse>, PAIR(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::reverse>, LIST(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::reverse>, MAP(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::reverse>, LBD(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::reverse>, LBD(_)>), (FALSE)); \
    CHECK((metal::reverse<PAIR(M)>), (metal::list<VAL(M), NUM(M)>)); \
    CHECK((metal::reverse<LIST(M)>), (metal::list<RENUM(M, VAL)>)); \
    CHECK((metal::reverse<MAP(M)>), (metal::list<RENUM(M, PAIR)>)); \
    CHECK((metal::reverse<metal::enumerate<NUM(0), metal::number<100*M>, NUM(N)>>), (metal::enumerate<metal::number<(100*M - 1)*N>, metal::number<-100*M>, NUM(N)>)); \
/**/

GEN(MATRIX)

