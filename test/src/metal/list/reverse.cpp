// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/reverse.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<test::lambda<metal::reverse>, VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reverse>, NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reverse>, PAIR(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reverse>, VECT(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reverse>, LIST(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reverse>, MAP(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reverse>, LBD(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<test::lambda<metal::reverse>, LBD(_)>), (FALSE)); \
    ASSERT((metal::reverse<PAIR(M)>), (test::pair<VAL(M), NUM(M)>)); \
    ASSERT((metal::reverse<VECT(M)>), (test::vect<NAS(CMPL(M)) COMMA(AND(M, CMPL(M))) RENUM(M, VAL)>)); \
    ASSERT((metal::reverse<LIST(M)>), (test::list<RENUM(M, VAL)>)); \
    ASSERT((metal::reverse<MAP(M)>), (CAT(test::map, M)<RENUM(M, PAIR)>)); \
/**/

GEN(MATRIX)

