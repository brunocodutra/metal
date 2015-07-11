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
        using type = function;

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
    struct parametric_function //also model of Expression
    {
        using type = parametric_function;

        template<typename...>
        using call = x;
    };
    /// [ex2]

    static_assert(metal::is_function<parametric_function<void>>::value, "");
}

namespace nex1
{
    /// [nex1]
    struct not_a_function //not a model of Strict Value
    {
        template<typename...>
        struct call;
    };
    /// [nex1]

    static_assert(!metal::is_function<not_a_function>::value, "");
}

namespace nex2
{
    /// [nex2]
    struct not_a_function
    {
        using type = not_a_function;
        struct call; //not a model of Expression
    };
    /// [nex2]

    static_assert(!metal::is_function<not_a_function>::value, "");
}

namespace nex3
{
    /// [nex3]
    struct function
    {
        using type = function;

        template<typename...>
        struct call;
    };

    struct not_a_function :
            function
    {
        template<typename...>
        struct call; //not inherited from ::type
    };
    /// [nex3]

    static_assert(!metal::is_function<not_a_function>::value, "");
}
