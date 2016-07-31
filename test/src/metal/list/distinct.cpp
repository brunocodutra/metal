// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/distinct.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct>, VAL(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct>, NUM(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct>, PAIR(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct>, LIST(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct>, MAP(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct>, LBD(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::distinct>, LBD(_)>), (FALSE)); \
    CHECK((metal::distinct<PAIR(M)>), (TRUE)); \
    CHECK((metal::distinct<LIST(M)>), (TRUE)); \
    CHECK((metal::distinct<MAP(M)>), (TRUE)); \
    CHECK((metal::distinct<metal::list<VALS(M) COMMA(AND(M, N)) VALS(N)>>), (BOOL(!M || !N))); \
    CHECK((metal::distinct<metal::list<ENUM(M, VAL FIX(N))>>), (BOOL(M < 2))); \
/**/

GEN(MATRIX)

