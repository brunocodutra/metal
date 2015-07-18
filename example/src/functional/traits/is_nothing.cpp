// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_nothing.hpp>

namespace
{
    /// [main]
    struct nothing
    {};

    struct something
    {
        struct type;
    };

    static_assert(metal::is_nothing<nothing>::value, "");
    static_assert(!metal::is_nothing<something>::value, "");
    /// [main]
}

int main()
{
    return 0;
}
