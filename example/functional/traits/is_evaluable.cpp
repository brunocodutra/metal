// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_evaluable.hpp>

namespace
{
    /// [is_evaluable]
    template<typename...>
    struct evaluable
    {
        struct type;
    };

    template<typename...>
    struct not_evaluable
    {
        //empty
    };

    static_assert(metal::is_evaluable<evaluable>::value, "");
    static_assert(metal::is_evaluable<evaluable, void>::value, "");
    static_assert(metal::is_evaluable<evaluable, void, void*>::value, "");

    static_assert(!metal::is_evaluable<not_evaluable>::value, "");
    static_assert(!metal::is_evaluable<not_evaluable, void>::value, "");
    static_assert(!metal::is_evaluable<not_evaluable, void, void*>::value, "");
    /// [is_evaluable]
}

int main()
{
    return 0;
}
