// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/optional/nothing.hpp>

namespace is_nothing
{
    /// [is_nothing]
    struct nothing
    {};

    struct something
    {
        struct type;
    };

    static_assert(metal::is_nothing<nothing>::value, "");
    static_assert(!metal::is_nothing<something>::value, "");
    /// [is_nothing]
}

int main()
{
    return 0;
}
