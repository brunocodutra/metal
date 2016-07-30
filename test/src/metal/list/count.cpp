// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/count.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, VAL(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, VAL(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, VAL(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, VAL(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, VAL(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, VAL(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, VAL(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, NUM(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, NUM(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, NUM(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, NUM(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, NUM(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, NUM(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, NUM(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, PAIR(M), VAL(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, PAIR(M), NUM(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, PAIR(M), PAIR(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, PAIR(M), LIST(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, PAIR(M), MAP(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, PAIR(M), LBD(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, PAIR(M), LBD(_)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, LIST(M), VAL(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, LIST(M), NUM(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, LIST(M), PAIR(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, LIST(M), LIST(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, LIST(M), MAP(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, LIST(M), LBD(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, LIST(M), LBD(_)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, MAP(M), VAL(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, MAP(M), NUM(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, MAP(M), PAIR(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, MAP(M), LIST(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, MAP(M), MAP(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, MAP(M), LBD(N)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, MAP(M), LBD(_)>), (TRUE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, LBD(M), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, LBD(M), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, LBD(M), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, LBD(M), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, LBD(M), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, LBD(M), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, LBD(M), LBD(_)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, LBD(_), VAL(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, LBD(_), NUM(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, LBD(_), PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, LBD(_), LIST(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, LBD(_), MAP(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, LBD(_), LBD(N)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::count>, LBD(_), LBD(_)>), (FALSE)); \
    ASSERT((metal::count<PAIR(M), VAL(N)>), (PTRDIFF_T(M == N))); \
    ASSERT((metal::count<PAIR(M), INT(N)>), (PTRDIFF_T(M == N))); \
    ASSERT((metal::count<LIST(M), VAL(N)>), (PTRDIFF_T((M > N)))); \
    ASSERT((metal::count<MAP(M), PAIR(N)>), (PTRDIFF_T((M > N)))); \
    ASSERT((metal::count<metal::list<VALS(M) COMMA(M) VAL(N)>, VAL(N)>), (PTRDIFF_T(1 + (M > N)))); \
    ASSERT((metal::count<metal::list<ENUM(M, VAL FIX(N))>, VAL(N)>), (PTRDIFF_T(M))); \
/**/

GEN(MATRIX)

