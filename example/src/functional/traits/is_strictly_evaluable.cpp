// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_strictly_evaluable.hpp>

namespace
{
    /// [main]
    template<typename...>
    struct e1
    {
        //strictly evaluable for every set of arguments
        using type = e1;
    };

    template<typename...>
    struct e2
    {
        //not strictly evaluable for any set of arguments
        struct type;
    };

    static_assert(metal::is_strictly_evaluable<e1>::value, "");
    static_assert(metal::is_strictly_evaluable<e1, void>::value, "");
    static_assert(metal::is_strictly_evaluable<e1, void, void*>::value, "");

    static_assert(!metal::is_strictly_evaluable<e2>::value, "");
    static_assert(!metal::is_strictly_evaluable<e2, void>::value, "");
    static_assert(!metal::is_strictly_evaluable<e2, void, void*>::value, "");
    /// [main]
}

int main()
{
    return 0;
}
