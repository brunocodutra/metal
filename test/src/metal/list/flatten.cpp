// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/flatten.hpp>
#include <metal/list/join.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    using CAT(CAT(trunk, N), 0) = SEQ()<VAL(N)>; \
    using CAT(CAT(trunk, N), INC(M)) = metal::join<CAT(CAT(trunk, N), M), CAT(CAT(trunk, N), M)>; \
    using CAT(CAT(tree, N), M) = SEQ()<VAL(N) COMMA(M) ENUM(M, CAT(tree, N))>; \
    ASSERT((metal::is_invocable<FUNC(metal::flatten), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::flatten), NUM(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::flatten), PAIR(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::flatten), LIST(M)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::flatten), MAP(M)>), (BOOL(!M))); \
    ASSERT((metal::is_invocable<FUNC(metal::flatten), LBD(M)>), (FALSE)); \
    ASSERT((metal::flatten<VEC(M)>), (VEC(M))); \
    ASSERT((metal::flatten<PAIR(M)>), (PAIR(M))); \
    ASSERT((metal::flatten<LIST(M)>), (LIST(M))); \
    ASSERT((metal::flatten<SEQ()<LBD(M)>>), (SEQ()<LBD(M)>)); \
    ASSERT((metal::flatten<SEQ()<MAP(M)>>), (SEQ()<ENUM(M, ADAPT(NUM), ADAPT(VAL))>)); \
    ASSERT((metal::flatten<CAT(CAT(tree, N), M)>), (CAT(CAT(trunk, N), M))); \
/**/

GEN(MATRIX)
