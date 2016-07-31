// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/size.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::size>, VAL(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::size>, NUM(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::size>, PAIR(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::size>, LIST(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::size>, MAP(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::size>, LBD(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::size>, LBD(_)>), (FALSE)); \
    CHECK((metal::size<PAIR(M)>), (SIZE_T(2))); \
    CHECK((metal::size<LIST(M)>), (SIZE_T(M))); \
    CHECK((metal::size<MAP(M)>), (SIZE_T(M))); \
    CHECK((metal::size<metal::list<VALS(M) COMMA(AND(M, N)) VALS(N)>>), (SIZE_T(M + N))); \
    CHECK((metal::size<metal::list<ENUM(M, VAL FIX(N))>>), (SIZE_T(M))); \
/**/

GEN(MATRIX)

