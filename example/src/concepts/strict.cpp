// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_strict.hpp>

#include "example.hpp"

namespace ex1
{
    /// [ex1]
    struct strict_value
    {
        using type = strict_value;
    };
    /// [ex1]

    static_assert(metal::is_strict<strict_value>::value, "");
}

namespace nex1
{
    /// [nex1]
    struct not_strict_value
    {
        struct type;
    };
    /// [nex1]

    static_assert(!metal::is_strict<not_strict_value>::value, "");
}

