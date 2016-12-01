// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/flatten.hpp>
#include <metal/list/list.hpp>
#include <metal/list/iota.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::flatten>, VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::flatten>, NUMBER(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::flatten>, PAIR(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::flatten>, LIST(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::flatten>, MAP(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::flatten>, LAMBDA(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::flatten>, LAMBDA(_)>), (FALSE)); \
    CHECK((metal::flatten<PAIR(M)>), (PAIR(M))); \
    CHECK((metal::flatten<LIST(M)>), (LIST(M))); \
    CHECK((metal::flatten<MAP(M)>), (metal::list<ENUM(M, FWD, NUMBER, VALUE)>)); \
    CHECK((metal::flatten<metal::iota<NUMBER(0), metal::number<100*M>, NUMBER(N)>>), (metal::iota<NUMBER(0), metal::number<100*M>, NUMBER(N)>)); \
/**/

GEN(MATRIX)
