// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/count.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<FUNC(metal::count), VAL(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::count), NUM(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::count), PAIR(M), VAL(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::count), LIST(M), VAL(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::count), MAP(M), VAL(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::count), LBD(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::count<PAIR(M), VAL(N)>), (metal::ptrdiff_t<M == N>)); \
    ASSERT((metal::count<PAIR(M), NUM(N)>), (metal::ptrdiff_t<M == N>)); \
    ASSERT((metal::count<LIST(M), VAL(N)>), (metal::ptrdiff_t<(M > N)>)); \
    ASSERT((metal::count<MAP(M), PAIR(N)>), (metal::ptrdiff_t<(M > N)>)); \
    ASSERT((metal::count<SEQ()<VAL(M), VALS(INC(M))>, VAL(N)>), (metal::ptrdiff_t<(M >= N) + (M == N)>)); \
    ASSERT((metal::count<SEQ(M)<ENUM(M, VAL(N) BAR)>, VAL(N)>), (metal::ptrdiff_t<M>)); \
/**/

GEN(MATRIX)

