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
    ASSERT((metal::is_invocable<metal::lambda<metal::back>, VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::back>, NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::back>, PAIR(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::back>, LIST(M)>), (BOOL(M > 0))); \
    ASSERT((metal::is_invocable<metal::lambda<metal::back>, MAP(M)>), (BOOL(M > 0))); \
    ASSERT((metal::is_invocable<metal::lambda<metal::back>, LBD(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::back>, LBD(_)>), (FALSE)); \
    ASSERT((metal::back<PAIR(M)>), (VAL(M))); \
    ASSERT((metal::back<LIST(INC(M))>), (VAL(M))); \
    ASSERT((metal::back<MAP(INC(M))>), (PAIR(M))); \
/**/

GEN(MATRIX)

