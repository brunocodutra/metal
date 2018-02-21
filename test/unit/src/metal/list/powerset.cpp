// Copyright Bruno Dutra 2015-2018
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define POWERSET0(M) metal::list<>
#define POWERSET1(M) metal::list<>, metal::list<M(0)>
#define POWERSET2(M) metal::list<>, metal::list<M(0)>, metal::list<M(1)>, metal::list<M(0), M(1)>
#define POWERSET3(M) \
    metal::list<>, metal::list<M(0)>, metal::list<M(1)>, metal::list<M(0), M(1)>, \
    metal::list<M(2)>, metal::list<M(0), M(2)>, metal::list<M(1), M(2)>, metal::list<M(0), M(1), M(2)> \
/**/

#define POWERSET(N, M) CAT(POWERSET, N)(M)

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::powerset>, VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::powerset>, NUMBER(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::powerset>, PAIR(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::powerset>, LIST(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::powerset>, MAP(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::powerset>, LAMBDA(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::powerset>, LAMBDA(_)>), (FALSE)); \
    CHECK((metal::powerset<PAIR(M)>), (metal::list<LIST(0), metal::list<NUMBER(M)>, metal::list<VALUE(M)>, PAIR(M)>)); \
    CHECK((metal::powerset<LIST(0)>), (metal::list<POWERSET(0, VALUE)>)); \
    CHECK((metal::powerset<LIST(1)>), (metal::list<POWERSET(1, VALUE)>)); \
    CHECK((metal::powerset<LIST(2)>), (metal::list<POWERSET(2, VALUE)>)); \
    CHECK((metal::powerset<LIST(3)>), (metal::list<POWERSET(3, VALUE)>)); \
/**/

GEN(MATRIX)

