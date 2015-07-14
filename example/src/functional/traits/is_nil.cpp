// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_nil.hpp>

namespace
{
    /// [main]
    struct n1
    {
        //nil
    };

    struct n2
    {
        //not nil
        struct type;
    };

    static_assert(metal::is_nil<n1>::value, "");
    static_assert(!metal::is_nil<n2>::value, "");
    /// [main]
}

int main()
{
    return 0;
}
