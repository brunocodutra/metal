// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/eval.hpp>

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
        //empty
    };

    using r1 = metal::eval<except_void, int>;
    static_assert(std::is_base_of<except_void<int>, r1>::value, "");

    using r2 = metal::eval<except_void, void>; //except_void<void> is nil
    static_assert(!std::is_base_of<except_void<void>, r2>::value, "");
    /// [main]
}

int main()
{
    return 0;
}
