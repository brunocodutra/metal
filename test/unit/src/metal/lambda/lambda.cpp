// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_lambda<VALUE(N)>), (FALSE)); \
    CHECK((metal::is_lambda<NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_lambda<PAIR(N)>), (FALSE)); \
    CHECK((metal::is_lambda<LIST(N)>), (FALSE)); \
    CHECK((metal::is_lambda<MAP(N)>), (FALSE)); \
    CHECK((metal::is_lambda<LAMBDA(N)>), (TRUE)); \
    CHECK((metal::is_lambda<LAMBDA(_)>), (TRUE)); \
    CHECK((metal::is_lambda<metal::lambda<metal::is_lambda>>), (TRUE)); \
    CHECK((metal::is_lambda<metal::lambda<metal::is_lambda>>), (TRUE)); \
/**/

GEN(MATRIX)
