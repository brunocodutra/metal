// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/lambda/arg.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/lambda/invoke.hpp>

#include "example.hpp"

namespace ex1
{
    /// [ex1]
    using lbd = void;
    /// [ex1]

    static_assert(std::is_same<metal::invoke_t<lbd>, void>::value, "");
}

namespace ex2
{
    /// [ex2]
    using lbd = std::add_pointer<void>;
    /// [ex2]

    static_assert(std::is_same<metal::invoke_t<lbd>, void*>::value, "");
}

namespace ex3
{
    /// [ex3]
    using lbd = metal::_2;
    /// [ex3]

    static_assert(std::is_same<metal::invoke_t<lbd, int, int>, int>::value, "");
}

namespace ex4
{
    /// [ex4]
    using lbd = std::is_convertible<metal::_1, std::add_pointer<metal::_2>>;
    /// [ex4]

    static_assert(metal::invoke_t<lbd, lbd*, void>::value, "");
}
