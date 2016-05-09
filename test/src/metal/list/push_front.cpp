// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/push_front.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<FUNC(metal::push_front), VAL(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::push_front), NUM(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::push_front), VEC(M), VAL(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::push_front), PAIR(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::push_front), LIST(INC(M)), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::push_front), MAP(INC(M)), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::push_front), LBD(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::push_front<VEC(M), VAL(N)>), (SEQ()<VAL(N) COMMA(M) VALS(M)>)); \
/**/

GEN(MATRIX)
