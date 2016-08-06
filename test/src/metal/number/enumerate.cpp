// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/number/enumerate.hpp>
#include <metal/number/number.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define ENTRY(N, A, B) metal::number<A*N + B>

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, VAL(M), VAL(N), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, VAL(M), NUM(N), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, VAL(M), PAIR(N), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, VAL(M), LIST(N), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, VAL(M), MAP(N), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, VAL(M), LBD(N), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, VAL(M), LBD(_), VAL(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, NUM(M), VAL(N), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, NUM(M), NUM(N), NUM(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, NUM(M), PAIR(N), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, NUM(M), LIST(N), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, NUM(M), MAP(N), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, NUM(M), LBD(N), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, NUM(M), LBD(_), NUM(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, PAIR(M), VAL(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, PAIR(M), NUM(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, PAIR(M), PAIR(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, PAIR(M), LIST(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, PAIR(M), MAP(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, PAIR(M), LBD(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, PAIR(M), LBD(_), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LIST(M), VAL(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LIST(M), NUM(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LIST(M), PAIR(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LIST(M), LIST(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LIST(M), MAP(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LIST(M), LBD(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LIST(M), LBD(_), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, MAP(M), VAL(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, MAP(M), NUM(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, MAP(M), PAIR(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, MAP(M), LIST(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, MAP(M), MAP(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, MAP(M), LBD(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, MAP(M), LBD(_), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LBD(M), VAL(N), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LBD(M), NUM(N), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LBD(M), PAIR(N), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LBD(M), LIST(N), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LBD(M), MAP(N), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LBD(M), LBD(N), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LBD(M), LBD(_), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LBD(_), VAL(N), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LBD(_), NUM(N), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LBD(_), PAIR(N), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LBD(_), LIST(N), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LBD(_), MAP(N), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LBD(_), LBD(N), LBD(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::enumerate>, LBD(_), LBD(_), LBD(N)>), (FALSE)); \
    CHECK((metal::enumerate<NUM(M), NUM(N)>), (metal::list<ENUM(N, ENTRY, 1, M)>)); \
    CHECK((metal::enumerate<NUM(M), NUM(N), NUM(M)>), (metal::list<ENUM(N, ENTRY, M, M)>)); \
    CHECK((metal::enumerate<NUM(M), metal::number<-N>, metal::number<-M>>), (metal::list<ENUM(N, ENTRY, M, M)>)); \
    CHECK((metal::enumerate<metal::number<-M>, NUM(N)>), (metal::list<ENUM(N, ENTRY, 1, -M)>)); \
    CHECK((metal::enumerate<metal::number<-M>, NUM(N), NUM(M)>), (metal::list<ENUM(N, ENTRY, M, -M)>)); \
    CHECK((metal::enumerate<metal::number<-M>, metal::number<-N>>), (metal::list<ENUM(N, ENTRY, -1, -M)>)); \
    CHECK((metal::enumerate<metal::number<-M>, metal::number<-N>, NUM(M)>), (metal::list<ENUM(N, ENTRY, -M, -M)>)); \
    CHECK((metal::enumerate<metal::number<-M>, NUM(N), metal::number<-M>>), (metal::list<ENUM(N, ENTRY, -M, -M)>)); \
    CHECK((metal::enumerate<metal::number<-M>, metal::number<-N>, metal::number<-M>>), (metal::list<ENUM(N, ENTRY, M, -M)>)); \
/**/

GEN(MATRIX)
