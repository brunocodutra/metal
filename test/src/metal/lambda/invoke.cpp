// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<VAL(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<NUM(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<PAIR(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<LIST(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<MAP(M) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<LBD(M) COMMA(N) VALS(N)>), (BOOL(M == N))); \
    ASSERT((metal::is_invocable<LBD() COMMA(N) VALS(N)>), (TRUE)); \
    ASSERT((metal::invoke<LBD(M) COMMA(M) VALS(M)>), (EXPR(M)<VALS(M)>)); \
    ASSERT((metal::invoke<LBD() COMMA(M) VALS(M)>), (EXPR()<VALS(M)>)); \
/**/

GEN(MATRIX)
