// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/count_if.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>
#include <metal/pair/pair.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, VAL(M), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, VAL(M), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, VAL(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, VAL(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, VAL(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, VAL(M), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, VAL(M), LBD(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, NUM(M), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, NUM(M), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, NUM(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, NUM(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, NUM(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, NUM(M), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, NUM(M), LBD(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, PAIR(M), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, PAIR(M), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, PAIR(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, PAIR(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, PAIR(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, PAIR(M), LBD(N)>), (BOOL(N == 1))); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, PAIR(M), LBD(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, LIST(M), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, LIST(M), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, LIST(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, LIST(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, LIST(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, LIST(M), LBD(N)>), (BOOL(!M || N == 1))); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, LIST(M), LBD(_)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, MAP(M), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, MAP(M), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, MAP(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, MAP(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, MAP(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, MAP(M), LBD(N)>), (BOOL(!M || N == 1))); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, MAP(M), LBD(_)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, LBD(M), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, LBD(M), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, LBD(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, LBD(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, LBD(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, LBD(M), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, LBD(M), LBD(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, LBD(_), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, LBD(_), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, LBD(_), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, LBD(_), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, LBD(_), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, LBD(_), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::count_if>, LBD(_), LBD(_)>), (FALSE)); \
    CHECK((metal::count_if<PAIR(M), metal::lambda<metal::is_number>>), (PTRDIFF_T(1))); \
    CHECK((metal::count_if<LIST(M), metal::lambda<metal::is_number>>), (PTRDIFF_T(0))); \
    CHECK((metal::count_if<MAP(M), metal::lambda<metal::is_number>>), (PTRDIFF_T(0))); \
    CHECK((metal::count_if<PAIR(M), metal::lambda<metal::is_pair>>), (PTRDIFF_T(0))); \
    CHECK((metal::count_if<LIST(M), metal::lambda<metal::is_pair>>), (PTRDIFF_T(0))); \
    CHECK((metal::count_if<MAP(M), metal::lambda<metal::is_pair>>), (PTRDIFF_T(M))); \
    CHECK((metal::count_if<PAIR(M), metal::lambda<metal::is_lambda>>), (PTRDIFF_T(0))); \
    CHECK((metal::count_if<LIST(M), metal::lambda<metal::is_lambda>>), (PTRDIFF_T(0))); \
    CHECK((metal::count_if<MAP(M), metal::lambda<metal::is_lambda>>), (PTRDIFF_T(0))); \
    CHECK((metal::count_if<metal::list<ENUM(M, FWD, NUM, PAIR, LBD)>, metal::lambda<metal::is_number>>), (PTRDIFF_T(M))); \
    CHECK((metal::count_if<metal::list<ENUM(M, FWD, NUM, PAIR, LBD)>, metal::lambda<metal::is_pair>>), (PTRDIFF_T(M))); \
    CHECK((metal::count_if<metal::list<ENUM(M, FWD, NUM, PAIR, LBD)>, metal::lambda<metal::is_lambda>>), (PTRDIFF_T(M))); \
/**/

GEN(MATRIX)

