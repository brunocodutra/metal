// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/core/assert.hpp>
#include <boost/mpl2/core/logical.hpp>

#include <type_traits>

namespace test
{
    using fundamental = void;
    using function = void();
    struct incomplete;
    struct empty {};

    template<typename...>
    struct call {};
    struct eponym : ::test::call<> {};

    struct evaluable {struct type{};};

    template<typename... args>
    struct wrap
    {
        using type = wrap<args...>;
    };

    struct wrapper
    {
        template<typename... args>
        struct call :
                wrap<args...>
        {};
    };
}
