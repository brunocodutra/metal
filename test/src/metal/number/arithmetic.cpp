// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/number/add.hpp>
#include <metal/number/dec.hpp>
#include <metal/number/div.hpp>
#include <metal/number/inc.hpp>
#include <metal/number/max.hpp>
#include <metal/number/min.hpp>
#include <metal/number/mod.hpp>
#include <metal/number/mul.hpp>
#include <metal/number/neg.hpp>
#include <metal/number/pow.hpp>
#include <metal/number/sub.hpp>
#include <metal/number/equal_to.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    using CAT(triangle, N) = metal::div<metal::mul<NUM(N), metal::inc<NUM(N)>>, NUM(2)>; \
    ASSERT((metal::is_invocable<FUNC(metal::neg), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::inc), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::dec), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::add) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::sub) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::mul) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::div) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::mod) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::pow) COMMA(N) VALS(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::add) COMMA(M) NUMS(M), VALS(INC(N))>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::sub) COMMA(M) NUMS(M), VALS(INC(N))>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::mul) COMMA(M) NUMS(M), VALS(INC(N))>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::div) COMMA(M) NUMS(M), VALS(INC(N))>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::mod) COMMA(M) NUMS(M), VALS(INC(N))>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::pow) COMMA(M) NUMS(M), VALS(INC(N))>), (FALSE)); \
    ASSERT((metal::is_invocable<FUNC(metal::neg), NUM(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::inc), NUM(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::dec), NUM(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<FUNC(metal::add) COMMA(N) NUMS(N)>), (BOOL(N > 0))); \
    ASSERT((metal::is_invocable<FUNC(metal::sub) COMMA(N) NUMS(N)>), (BOOL(N > 0))); \
    ASSERT((metal::is_invocable<FUNC(metal::mul) COMMA(N) NUMS(N)>), (BOOL(N > 0))); \
    ASSERT((metal::is_invocable<FUNC(metal::div) COMMA(N) NUMS(N)>), (BOOL(N > 0))); \
    ASSERT((metal::is_invocable<FUNC(metal::mod) COMMA(N) NUMS(N)>), (BOOL(N > 0))); \
    ASSERT((metal::is_invocable<FUNC(metal::pow) COMMA(N) NUMS(N)>), (BOOL(N > 0))); \
    ASSERT((metal::is_invocable<FUNC(metal::div) COMMA(M) NUMS(M) COMMA(N) NUMS(N)>), (BOOL(!M ^ !N))); \
    ASSERT((metal::is_invocable<FUNC(metal::mod) COMMA(M) NUMS(M) COMMA(N) NUMS(N)>), (BOOL(!M ^ !N))); \
    ASSERT((metal::is_invocable<FUNC(metal::pow) COMMA(M) NUMS(M) COMMA(N) NUMS(N)>), (BOOL(M || N))); \
    ASSERT((metal::is_invocable<FUNC(metal::pow) COMMA(M) NUMS(M), metal::int_<-N>>), (BOOL(!M || !N))); \
    ASSERT((metal::equal_to<metal::neg<metal::neg<NUM(N)>>, NUM(N)>), (TRUE)); \
    ASSERT((metal::equal_to<metal::inc<NUM(N)>, NUM(INC(N))>), (TRUE)); \
    ASSERT((metal::equal_to<metal::dec<NUM(INC(N))>, NUM(N)>), (TRUE)); \
    ASSERT((metal::equal_to<metal::inc<metal::dec<NUM(N)>>, NUM(N)>), (TRUE)); \
    ASSERT((metal::equal_to<metal::dec<metal::inc<NUM(N)>>, NUM(N)>), (TRUE)); \
    ASSERT((metal::equal_to<metal::add<NUMS(INC(N))>, CAT(triangle, N)>), (TRUE)); \
    ASSERT((metal::equal_to<metal::sub<CAT(triangle, N), NUMS(INC(N))>, NUM(0)>), (TRUE)); \
    ASSERT((metal::equal_to<metal::add<NUM(0) COMMA(N) ENUM(N, NUM(M) BAR)>, metal::mul<NUM(M), NUM(N)>>), (TRUE)); \
    ASSERT((metal::equal_to<metal::sub<metal::mul<NUM(M), NUM(N)> COMMA(N) ENUM(N, NUM(M) BAR)>, NUM(0)>), (TRUE)); \
    ASSERT((metal::equal_to<metal::mul<NUMS(INC(N))>, NUM(0)>), (TRUE)); \
    ASSERT((metal::equal_to<metal::div<NUMS(INC(N))>, NUM(0)>), (TRUE)); \
    ASSERT((metal::equal_to<metal::mod<NUMS(INC(N))>, NUM(0)>), (TRUE)); \
    ASSERT((metal::equal_to<metal::pow<NUMS(INC(N))>, NUM(0)>), (TRUE)); \
    ASSERT((metal::equal_to<metal::add<metal::mul<metal::div<NUM(M), NUM(INC(N))>, NUM(INC(N))>, metal::mod<NUM(M), NUM(INC(N))>>, NUM(M)>), (TRUE)); \
    ASSERT((metal::equal_to<metal::pow<NUM(0) COMMA(N) NUMS(N)>, metal::int_<!!N>>), (TRUE)); \
    ASSERT((metal::equal_to<metal::pow<NUM(1) COMMA(N) NUMS(N)>, NUM(1)>), (TRUE)); \
    ASSERT((metal::equal_to<metal::pow<NUM(2), NUM(N)>, metal::int_<1 << N>>), (TRUE)); \
/**/

GEN(MATRIX)
