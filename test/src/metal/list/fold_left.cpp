// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/fold_left.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>
#include <metal/number/enumerate.hpp>

#include "test.hpp"

#define TAB(N, ...) EXPR(_)<__VA_ARGS__, VAL(N)>

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, VAL(M), VAL(N), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, VAL(M), VAL(N), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, VAL(M), VAL(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, VAL(M), VAL(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, VAL(M), VAL(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, VAL(M), VAL(N), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, VAL(M), VAL(N), LBD(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, NUM(M), NUM(N), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, NUM(M), NUM(N), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, NUM(M), NUM(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, NUM(M), NUM(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, NUM(M), NUM(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, NUM(M), NUM(N), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, NUM(M), NUM(N), LBD(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, PAIR(M), PAIR(N), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, PAIR(M), PAIR(N), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, PAIR(M), PAIR(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, PAIR(M), PAIR(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, PAIR(M), PAIR(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, PAIR(M), PAIR(N), LBD(N)>), (BOOL(N == 2))); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, PAIR(M), PAIR(N), LBD(_)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LIST(M), LIST(N), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LIST(M), LIST(N), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LIST(M), LIST(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LIST(M), LIST(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LIST(M), LIST(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LIST(M), LIST(N), LBD(N)>), (BOOL(!M || N == 2))); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LIST(M), LIST(N), LBD(_)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, MAP(M), MAP(N), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, MAP(M), MAP(N), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, MAP(M), MAP(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, MAP(M), MAP(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, MAP(M), MAP(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, MAP(M), MAP(N), LBD(N)>), (BOOL(!M || N == 2))); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, MAP(M), MAP(N), LBD(_)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LBD(M), LBD(N), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LBD(M), LBD(N), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LBD(M), LBD(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LBD(M), LBD(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LBD(M), LBD(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LBD(M), LBD(N), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LBD(M), LBD(N), LBD(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LBD(_), LBD(N), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LBD(_), LBD(N), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LBD(_), LBD(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LBD(_), LBD(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LBD(_), LBD(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LBD(_), LBD(N), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::fold_left>, LBD(_), LBD(N), LBD(_)>), (FALSE)); \
    CHECK((metal::fold_left<LIST(M), VAL(N), LBD(_)>), (FOLD(M, TAB, VAL(N)))); \
    CHECK((metal::fold_left<metal::enumerate<NUM(0), metal::number<100*M>, NUM(N)>, NUM(2), LBD(2)>), (NUM(2))); \
/**/

GEN(MATRIX)

