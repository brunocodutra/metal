// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/same.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<metal::lambda<metal::same>, VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::same>, NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::same>, PAIR(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::same>, LIST(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::same>, MAP(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::same>, LBD(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::same>, LBD(_)>), (FALSE)); \
    ASSERT((metal::same<PAIR(M)>), (FALSE)); \
    ASSERT((metal::same<LIST(M)>), (BOOL(M < 2))); \
    ASSERT((metal::same<MAP(M)>), (BOOL(M < 2))); \
    ASSERT((metal::same<metal::list<VALS(M) COMMA(AND(M, N)) VALS(N)>>), (BOOL(M < 2 && N < 2))); \
    ASSERT((metal::same<metal::list<ENUM(M, VAL FIX(N))>>), (TRUE)); \
/**/

GEN(MATRIX)

