// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/lambda/bind.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/optional/optional.hpp>

#include "test.hpp"

template<typename x>
using unptr = typename std::remove_pointer<x>::type;

#define MATRIX(M, N) \
    ASSERT((metal::is_just_t<metal::bind<VAL(M) COMMA(N) VALS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::bind<NUM(M) COMMA(N) VALS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::bind<PAIR(M) COMMA(N) VALS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::bind<LIST(M) COMMA(N) VALS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::bind<MAP(M) COMMA(N) VALS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::bind<ARG(M) COMMA(N) VALS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::bind<LBD(M) COMMA(N) VALS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::bind<FUN() COMMA(N) VALS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::bind<FUN(M) COMMA(N) VALS(N)>>), (TRUE)); \
    ASSERT((metal::is_just_t<metal::bind<metal::lambda<unptr> COMMA(N) ARGS(N)>>), (TRUE)); \
    ASSERT((metal::invoke_t<metal::bind_t<VAL(M) COMMA(M) VALS(M)> COMMA(N) NUMS(N)>), (VAL(M))); \
    ASSERT((metal::invoke_t<metal::bind_t<NUM(M) COMMA(M) VALS(M)> COMMA(N) NUMS(N)>), (NUM(M))); \
    ASSERT((metal::invoke_t<metal::bind_t<LBD(M) COMMA(M) VALS(M)> COMMA(N) NUMS(N)>), (EXPR(M)<VALS(M)>::type)); \
    ASSERT((metal::invoke_t<metal::bind_t<FUN(M) COMMA(M) VALS(M)> COMMA(N) NUMS(N)>), (EXPR(M)<VALS(M)>::type)); \
    ASSERT((metal::invoke_t<metal::bind_t<VAL(M) COMMA(M) ARGS(M)> COMMA(M) NUMS(M)>), (VAL(M))); \
    ASSERT((metal::invoke_t<metal::bind_t<NUM(M) COMMA(M) ARGS(M)> COMMA(M) NUMS(M)>), (NUM(M))); \
    ASSERT((metal::invoke_t<metal::bind_t<LBD(M) COMMA(M) ARGS(M)> COMMA(M) NUMS(M)>), (EXPR(M)<NUMS(M)>::type)); \
    ASSERT((metal::invoke_t<metal::bind_t<FUN(M) COMMA(M) ARGS(M)> COMMA(M) NUMS(M)>), (EXPR(M)<NUMS(M)>::type)); \
    ASSERT((metal::invoke_t<metal::bind_t<VAL(M) COMMA(M) ENUM(M, ARG(N) BAR)>, NUMS(INC(N))>), (VAL(M))); \
    ASSERT((metal::invoke_t<metal::bind_t<NUM(M) COMMA(M) ENUM(M, ARG(N) BAR)>, NUMS(INC(N))>), (NUM(M))); \
    ASSERT((metal::invoke_t<metal::bind_t<LBD(M) COMMA(M) ENUM(M, ARG(N) BAR)>, NUMS(INC(N))>), (EXPR(M)<ENUM(M, NUM(N) BAR)>::type)); \
    ASSERT((metal::invoke_t<metal::bind_t<FUN(M) COMMA(M) ENUM(M, ARG(N) BAR)>, NUMS(INC(N))>), (EXPR(M)<ENUM(M, NUM(N) BAR)>::type)); \
    ASSERT((metal::invoke_t<metal::bind_t<FUN(), LBD(N)> COMMA(N) NUMS(N)>), (EXPR()<EXPR(N)<NUMS(N)>::type>::type)); \
    ASSERT((metal::invoke_t<metal::bind_t<FUN(), FUN(N)> COMMA(N) NUMS(N)>), (EXPR()<EXPR(N)<NUMS(N)>::type>::type)); \
    ASSERT((metal::invoke_t<metal::bind_t<metal::lambda<unptr>, ARG(N)> COMMA(N) VALS(N), NUM(M)*>), (NUM(M))); \
/**/

GEN(MATRIX)
