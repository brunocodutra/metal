// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/lambda/lambda.hpp>
#include <metal/list/list.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_lambda<VAL(N)>), (FALSE)); \
    CHECK((metal::is_lambda<NUM(N)>), (FALSE)); \
    CHECK((metal::is_lambda<PAIR(N)>), (FALSE)); \
    CHECK((metal::is_lambda<LIST(N)>), (FALSE)); \
    CHECK((metal::is_lambda<MAP(N)>), (FALSE)); \
    CHECK((metal::is_lambda<LBD(N)>), (TRUE)); \
    CHECK((metal::is_lambda<LBD(_)>), (TRUE)); \
    CHECK((metal::is_lambda<metal::lambda<metal::is_lambda>>), (TRUE)); \
    CHECK((metal::is_lambda<metal::lambda<metal::is_lambda>>), (TRUE)); \
/**/

GEN(MATRIX)
