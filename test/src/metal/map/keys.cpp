// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/map/keys.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<metal::lambda<metal::keys>, VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::keys>, NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::keys>, PAIR(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::keys>, LIST(M)>), (BOOL(!M))); \
    ASSERT((metal::is_invocable<metal::lambda<metal::keys>, MAP(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::keys>, LBD(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::keys>, LBD(_)>), (FALSE)); \
    ASSERT((metal::keys<MAP(M)>), (metal::list<NUMS(M)>)); \
/**/

GEN(MATRIX)

