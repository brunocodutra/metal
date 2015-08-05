// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/lambda/arg.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/lambda/apply.hpp>

#include "example.hpp"

namespace ex1
{
    /// [ex1]
    using lbd = std::add_pointer<void>;
    /// [ex1]

    static_assert(metal::is_applicable<lbd>::value, "");
}

namespace ex2
{
    /// [ex2]
    using lbd = metal::_3;
    /// [ex2]

    static_assert(metal::is_applicable<lbd, void, void, void>::value, "");
}

namespace ex3
{
    /// [ex3]
    using lbd = std::is_convertible<std::add_pointer<metal::_1>, metal::_2>;
    /// [ex3]

    static_assert(metal::is_applicable<lbd, void, lbd*>::value, "");
}

namespace nex1
{
    /// [nex1]
    using lbd = void;
    /// [nex1]

    static_assert(!metal::is_applicable<lbd>::value, "");
}

namespace nex2
{
    /// [nex2]
    using lbd = std::integral_constant<bool, true>;
    /// [nex2]

    static_assert(!metal::is_applicable<lbd>::value, "");
}
