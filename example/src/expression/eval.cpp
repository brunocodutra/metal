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

namespace is_evaluable
{
    /// [is_evaluable]
    template<typename...>
    struct expr1
    {
        //evaluable for every set of arguments
        struct type;
    };

    template<typename...>
    struct expr2
    {
        //not evaluable for any set of arguments
    };

    static_assert(metal::is_evaluable<expr1>::value, "");
    static_assert(metal::is_evaluable<expr1, void>::value, "");
    static_assert(metal::is_evaluable<expr1, void, void*>::value, "");

    static_assert(!metal::is_evaluable<expr2>::value, "");
    static_assert(!metal::is_evaluable<expr2, void>::value, "");
    static_assert(!metal::is_evaluable<expr2, void, void*>::value, "");
    /// [is_evaluable]
}

int main()
{
    return 0;
}
