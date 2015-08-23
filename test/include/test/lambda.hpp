// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_TEST_LAMBDA_HPP
#define METAL_TEST_LAMBDA_HPP

#include "test/expressions.hpp"
#include "test/preprocessor.hpp"

#include <cstddef>

namespace metal
{
    template<std::size_t>
    struct arg;
}

using arg0 = metal::arg<1>;
using arg1 = metal::arg<2>;
using arg2 = metal::arg<3>;
using arg3 = metal::arg<4>;
using arg4 = metal::arg<5>;
using arg5 = metal::arg<6>;
using arg6 = metal::arg<7>;
using arg7 = metal::arg<8>;
using arg8 = metal::arg<9>;
using arg9 = metal::arg<10>;

#define _arg(N) _cat(arg, N)
#define _args(N) _enum(N, arg)

using lbd0 = expr0<>;
using lbd1 = expr1<_args(1)>;
using lbd2 = expr2<_args(2)>;
using lbd3 = expr3<_args(3)>;
using lbd4 = expr4<_args(4)>;
using lbd5 = expr5<_args(5)>;
using lbd6 = expr6<_args(6)>;
using lbd7 = expr7<_args(7)>;
using lbd8 = expr8<_args(8)>;
using lbd9 = expr9<_args(9)>;

#define _lbd(N) _cat(lbd, N)
#define _lbds(N) _enum(N, lbd)

#endif
