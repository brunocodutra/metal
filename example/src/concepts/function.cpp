// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_function.hpp>

#include "example.hpp"

namespace ex1
{
    /// [ex1]
    struct function
    {
        template<typename...>
        struct call;
    };
    /// [ex1]

    static_assert(metal::is_function<function>::value, "");
}

namespace ex2
{
    /// [ex2]
    template<typename x>
    struct function //also model of Expression
    {
        using type = function;

        template<typename...>
        using call = x;
    };
    /// [ex2]

    static_assert(metal::is_function<function<void>>::value, "");
}


namespace nex1
{
    /// [nex1]
    struct not_a_function
    {
        struct call; //not a model of Expression
    };
    /// [nex1]

    static_assert(!metal::is_function<not_a_function>::value, "");
}
