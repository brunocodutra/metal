// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/replace_if.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>
#include <metal/pair/pair.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, VAL(M), VAL(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, VAL(M), NUM(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, VAL(M), PAIR(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, VAL(M), LIST(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, VAL(M), MAP(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, VAL(M), LBD(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, VAL(M), LBD(_), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, NUM(M), VAL(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, NUM(M), NUM(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, NUM(M), PAIR(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, NUM(M), LIST(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, NUM(M), MAP(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, NUM(M), LBD(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, NUM(M), LBD(_), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, PAIR(M), VAL(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, PAIR(M), NUM(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, PAIR(M), PAIR(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, PAIR(M), LIST(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, PAIR(M), MAP(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, PAIR(M), LBD(N), VAL(M)>), (BOOL(N == 1))); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, PAIR(M), LBD(_), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, LIST(M), VAL(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, LIST(M), NUM(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, LIST(M), PAIR(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, LIST(M), LIST(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, LIST(M), MAP(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, LIST(M), LBD(N), VAL(M)>), (BOOL(!M || N == 1))); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, LIST(M), LBD(_), VAL(M)>), (BOOL(!M))); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, MAP(M), VAL(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, MAP(M), NUM(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, MAP(M), PAIR(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, MAP(M), LIST(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, MAP(M), MAP(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, MAP(M), LBD(N), VAL(M)>), (BOOL(!M || N == 1))); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, MAP(M), LBD(_), VAL(M)>), (BOOL(!M))); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, LBD(M), VAL(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, LBD(M), NUM(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, LBD(M), PAIR(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, LBD(M), LIST(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, LBD(M), MAP(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, LBD(M), LBD(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, LBD(M), LBD(_), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, LBD(_), VAL(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, LBD(_), NUM(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, LBD(_), PAIR(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, LBD(_), LIST(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, LBD(_), MAP(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, LBD(_), LBD(N), VAL(M)>), (FALSE)); \
    ASSERT((metal::is_invocable<metal::lambda<metal::replace_if>, LBD(_), LBD(_), VAL(M)>), (FALSE)); \
    ASSERT((metal::replace_if<PAIR(M), metal::lambda<metal::is_number>, VAL(N)>), (metal::list<VAL(N), VAL(M)>)); \
    ASSERT((metal::replace_if<LIST(M), metal::lambda<metal::is_number>, VAL(N)>), (LIST(M))); \
    ASSERT((metal::replace_if<MAP(M), metal::lambda<metal::is_number>, VAL(N)>), (MAP(M))); \
    ASSERT((metal::replace_if<PAIR(M), metal::lambda<metal::is_pair>, VAL(N)>), (PAIR(M))); \
    ASSERT((metal::replace_if<LIST(M), metal::lambda<metal::is_pair>, VAL(N)>), (LIST(M))); \
    ASSERT((metal::replace_if<MAP(M), metal::lambda<metal::is_pair>, VAL(N)>), (metal::list<ENUM(M, VAL FIX(N))>)); \
    ASSERT((metal::replace_if<PAIR(M), metal::lambda<metal::is_lambda>, VAL(N)>), (PAIR(M))); \
    ASSERT((metal::replace_if<LIST(M), metal::lambda<metal::is_lambda>, VAL(N)>), (LIST(M))); \
    ASSERT((metal::replace_if<MAP(M), metal::lambda<metal::is_lambda>, VAL(N)>), (MAP(M))); \
    ASSERT((metal::replace_if<metal::list<ENUM(M, FWD, NUM, PAIR, LBD)>, metal::lambda<metal::is_number>, VAL(N)>), (metal::list<ENUM(M, FWD, VAL(N) NIL, PAIR, LBD)>)); \
    ASSERT((metal::replace_if<metal::list<ENUM(M, FWD, NUM, PAIR, LBD)>, metal::lambda<metal::is_pair>, VAL(N)>), (metal::list<ENUM(M, FWD, NUM, VAL(N) NIL, LBD)>)); \
    ASSERT((metal::replace_if<metal::list<ENUM(M, FWD, NUM, PAIR, LBD)>, metal::lambda<metal::is_lambda>, VAL(N)>), (metal::list<ENUM(M, FWD, NUM, PAIR, VAL(N) NIL)>)); \
/**/

GEN(MATRIX)
