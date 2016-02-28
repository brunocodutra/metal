// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/list/count.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/number/number.hpp>
#include <metal/optional/optional.hpp>

#include "test.hpp"

#define COUNT(...) metal::number<std::ptrdiff_t, (__VA_ARGS__)>

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::count<VAL(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::count<NUM(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::count<PAIR(M), VAL(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::count<LIST(M), VAL(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::count<MAP(M), VAL(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::count<ARG(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::is_just_t<metal::count<LBD(M), VAL(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::count<FUN(M), VAL(N)>>), (FALSE)); \
    ASSERT((metal::count_t<PAIR(M), VAL(N)>), (COUNT(M == N))); \
    ASSERT((metal::count_t<PAIR(M), NUM(N)>), (COUNT(M == N))); \
    ASSERT((metal::count_t<LIST(M), VAL(N)>), (COUNT(M > N))); \
    ASSERT((metal::count_t<MAP(M), PAIR(N)>), (COUNT(M > N))); \
    ASSERT((metal::count_t<LBD(M), NA(N)>), (COUNT(CMPL(M)))); \
    ASSERT((metal::count_t<LBD(M), ARG(N)>), (COUNT(M > N))); \
    ASSERT((metal::count_t<SEQ()<VAL(M), VALS(INC(M))>, VAL(N)>), (COUNT((M >= N) + (M == N)))); \
    ASSERT((metal::count_t<SEQ(M)<ENUM(M, VAL(N) BAR)>, VAL(N)>), (COUNT(M))); \
    ASSERT((metal::count_t<SEQ()< \
        VALS(INC(M)), NUMS(INC(M)), PAIRS(INC(M)), LISTS(INC(M)), \
        MAPS(INC(M)), ARGS(INC(M)), LBDS(INC(M)), FUNS(INC(M))>, MAP(N)>), (COUNT((M >= N) + !N))); \
/**/

GEN(MATRIX)

