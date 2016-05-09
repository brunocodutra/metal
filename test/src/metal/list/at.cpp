// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/at.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<FUNC(metal::at), VAL(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::at), NUM(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::at), PAIR(M), NUM(N)>), (BOOL(N < 2))); \
    ASSERT((metal::is_invocable<FUNC(metal::at), LIST(M), NUM(N)>), (BOOL(M > N))); \
    ASSERT((metal::is_invocable<FUNC(metal::at), MAP(M), NUM(N)>), (BOOL(M > N))); \
    ASSERT((metal::is_invocable<FUNC(metal::at), LBD(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::at), LIST(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::at), LIST(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::at), LIST(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::at), LIST(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::at), LIST(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::at<PAIR(N), NUM(0)>), (NUM(N))); \
    ASSERT((metal::at<PAIR(N), NUM(1)>), (VAL(N))); \
    ASSERT((metal::at<LIST(LIMIT), NUM(N)>), (VAL(N))); \
    ASSERT((metal::at<MAP(LIMIT), NUM(N)>), (PAIR(N))); \
    ASSERT((metal::at<SEQ()<LISTS(M) COMMA(M) MAPS(INC(N))>, NUM(M)>), (MAP(0))); \
/**/

GEN(MATRIX)

