// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/number/arithmetic.hpp>
#include <metal/number/comparison/equal_to.hpp>
#include <metal/optional/optional.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    using CAT(triangle, N) = metal::div_t<metal::mul_t<NUM(N), metal::inc_t<NUM(N)>>, NUM(2)>; \
    ASSERT((metal::is_just_t<metal::neg<VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::inc<VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::dec<VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::add<VALS(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::sub<VALS(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::mul<VALS(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::div<VALS(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::mod<VALS(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::pow<VALS(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::add<NUMS(M) COMMA(M) VALS(INC(N))>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::sub<NUMS(M) COMMA(M) VALS(INC(N))>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::mul<NUMS(M) COMMA(M) VALS(INC(N))>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::div<NUMS(M) COMMA(M) VALS(INC(N))>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::mod<NUMS(M) COMMA(M) VALS(INC(N))>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::pow<NUMS(M) COMMA(M) VALS(INC(N))>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::neg<NUM(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::inc<NUM(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::dec<NUM(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::add<NUMS(N)>>), (BOOL(N > 0))); \
    ASSERT((metal::is_just_t<metal::sub<NUMS(N)>>), (BOOL(N > 0))); \
    ASSERT((metal::is_just_t<metal::mul<NUMS(N)>>), (BOOL(N > 0))); \
    ASSERT((metal::is_just_t<metal::div<NUMS(N)>>), (BOOL(N > 0))); \
    ASSERT((metal::is_just_t<metal::mod<NUMS(N)>>), (BOOL(N > 0))); \
    ASSERT((metal::is_just_t<metal::pow<NUMS(N)>>), (BOOL(N > 0))); \
    ASSERT((metal::is_just_t<metal::div<NUMS(M) COMMA(AND(M, N)) NUMS(N)>>), (BOOL(!M ^ !N))); \
    ASSERT((metal::is_just_t<metal::mod<NUMS(M) COMMA(AND(M, N)) NUMS(N)>>), (BOOL(!M ^ !N))); \
    ASSERT((metal::is_just_t<metal::pow<NUMS(M) COMMA(AND(M, N)) NUMS(N)>>), (BOOL(M || N))); \
    ASSERT((metal::is_just_t<metal::pow<NUMS(M) COMMA(M) metal::integer<-N>>>), (BOOL(!M || !N))); \
    ASSERT((metal::equal_to_t<metal::neg_t<metal::neg_t<NUM(N)>>, NUM(N)>), (TRUE)); \
    ASSERT((metal::equal_to_t<metal::inc_t<NUM(N)>, NUM(INC(N))>), (TRUE)); \
    ASSERT((metal::equal_to_t<metal::dec_t<NUM(INC(N))>, NUM(N)>), (TRUE)); \
    ASSERT((metal::equal_to_t<metal::inc_t<metal::dec_t<NUM(N)>>, NUM(N)>), (TRUE)); \
    ASSERT((metal::equal_to_t<metal::dec_t<metal::inc_t<NUM(N)>>, NUM(N)>), (TRUE)); \
    ASSERT((metal::equal_to_t<metal::add_t<NUMS(INC(N))>, CAT(triangle, N)>), (TRUE)); \
    ASSERT((metal::equal_to_t<metal::sub_t<CAT(triangle, N), NUMS(INC(N))>, NUM(0)>), (TRUE)); \
    ASSERT((metal::equal_to_t<metal::add_t<NUM(0) COMMA(N) ENUM(N, NUM(M) BAR)>, metal::mul_t<NUM(M), NUM(N)>>), (TRUE)); \
    ASSERT((metal::equal_to_t<metal::sub_t<metal::mul_t<NUM(M), NUM(N)> COMMA(N) ENUM(N, NUM(M) BAR)>, NUM(0)>), (TRUE)); \
    ASSERT((metal::equal_to_t<metal::mul_t<NUMS(INC(N))>, NUM(0)>), (TRUE)); \
    ASSERT((metal::equal_to_t<metal::div_t<NUMS(INC(N))>, NUM(0)>), (TRUE)); \
    ASSERT((metal::equal_to_t<metal::mod_t<NUMS(INC(N))>, NUM(0)>), (TRUE)); \
    ASSERT((metal::equal_to_t<metal::pow_t<NUMS(INC(N))>, NUM(0)>), (TRUE)); \
    ASSERT((metal::equal_to_t<metal::add_t<metal::mul_t<metal::div_t<NUM(M), NUM(INC(N))>, NUM(INC(N))>, metal::mod_t<NUM(M), NUM(INC(N))>>, NUM(M)>), (TRUE)); \
    ASSERT((metal::equal_to_t<metal::pow_t<NUM(0) COMMA(N) NUMS(N)>, metal::integer<!!N>>), (TRUE)); \
    ASSERT((metal::equal_to_t<metal::pow_t<NUM(1) COMMA(N) NUMS(N)>, NUM(1)>), (TRUE)); \
    ASSERT((metal::equal_to_t<metal::pow_t<NUM(2), NUM(N)>, metal::integer<1 << N>>), (TRUE)); \
/**/

GEN(MATRIX)
