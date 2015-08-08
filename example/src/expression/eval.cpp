// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/expression/eval.hpp>
#include <metal/optional/nothing.hpp>
#include <metal/optional/just.hpp>

#include <type_traits>

namespace eval
{
    /// [eval]
    template<typename>
    struct except_void
    {
        struct type;
    };

    template<>
    struct except_void<void>
    {};

    using r1 = metal::eval<except_void, void>;
    static_assert(metal::is_nothing<r1>::value, "");

    using r2 = metal::eval<except_void, int>;
    static_assert(metal::is_just<r2>::value, "");
    static_assert(std::is_same<r2::type, except_void<int>::type>::value, "");
    /// [eval]
}

int main()
{
    return 0;
}
