// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_nil.hpp>

#include "example.hpp"

namespace ex1
{
    /// [ex1]
    struct nullable_value
    {
        struct type; //non-nil
    };
    /// [ex1]

    static_assert(!metal::is_nil<nullable_value>::value, "");
}

namespace ex2
{
    /// [ex2]
    struct nullable_value
    {
        //nil - undefined ::type
    };
    /// [ex2]

    static_assert(metal::is_nil<nullable_value>::value, "");
}

namespace ex3
{
    /// [ex3]
    union nullable_value
    {
        struct type; //nil - union types are always nil
    };
    /// [ex3]

    static_assert(metal::is_nil<nullable_value>::value, "");
}

namespace ex4
{
    /// [ex4]
    using nullable_value = void; //nil - undefined ::type
    /// [ex4]

    static_assert(metal::is_nil<nullable_value>::value, "");
}

namespace ex5
{
    /// [ex5]
    struct nullable_value1
    {
        struct type; //non-nil
    };

    struct nullable_value2
    {
        struct type; //non-nil
    };

    struct nullable_value3 :
            nullable_value1,
            nullable_value2
    {
        //nil - ambiguous ::type
    };
    /// [ex5]

    static_assert(!metal::is_nil<nullable_value1>::value, "");
    static_assert(!metal::is_nil<nullable_value2>::value, "");
    static_assert(metal::is_nil<nullable_value3>::value, "");
}

