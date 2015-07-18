// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/eval.hpp>
#include <metal/functional/traits/is_nil.hpp>

#include <type_traits>

namespace
{
    /// [main]
    template<typename>
    struct except_void
    {
        struct type;
    };

    template<>
    struct except_void<void>
    {
        //nil
    };

    using r1 = metal::eval<except_void, void>;
    static_assert(metal::is_nil<r1>::value, "");

    using r2 = metal::eval<except_void, int>;
    static_assert(!metal::is_nil<r2>::value, "");
    static_assert(std::is_same<r2::type, except_void<int>::type>::value, "");
    /// [main]
}

int main()
{
    return 0;
}
