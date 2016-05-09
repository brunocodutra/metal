// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/pop_front.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<FUNC(metal::pop_front), VAL(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::pop_front), NUM(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::pop_front), VEC(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::pop_front), PAIR(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::pop_front), LBD(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::pop_front), VAL(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::pop_front), NUM(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::pop_front), VEC(M), NUM(N)>), (BOOL(M >= N))); \
    ASSERT((metal::is_invocable<FUNC(metal::pop_front), PAIR(M), NUM(N)>), (BOOL(N == 0))); \
    ASSERT((metal::is_invocable<FUNC(metal::pop_front), LBD(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::pop_front<SEQ()<VALS(M) COMMA(AND(M, N)) VALS(N)>, NUM(M)>), (VEC(N))); \
/**/

GEN(MATRIX)
