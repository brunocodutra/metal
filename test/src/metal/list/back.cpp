// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/back.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::back>, VAL(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::back>, NUM(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::back>, PAIR(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::back>, LIST(M)>), (BOOL(M > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::back>, MAP(M)>), (BOOL(M > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::back>, LBD(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::back>, LBD(_)>), (FALSE)); \
    CHECK((metal::back<PAIR(M)>), (VAL(M))); \
    CHECK((metal::back<LIST(INC(M))>), (VAL(M))); \
    CHECK((metal::back<MAP(INC(M))>), (PAIR(M))); \
/**/

GEN(MATRIX)

