// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/lambda/lambda.hpp>

#include "test.hpp"

#define _boilerplate(M, N) \
    _assert((metal::lambda<_expr()>::type<_vals(N)>::type), (_expr()<_vals(N)>::type)); \
    _assert((metal::lambda<_expr(M)>::type<_vals(M)>::type), (_expr(M)<_vals(M)>::type)); \
/**/

_gen(_boilerplate)
