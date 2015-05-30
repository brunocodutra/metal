// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/core/assert.hpp>
#include <boost/mpl2/core/logical.hpp>

#include <type_traits>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            template<typename...>
            struct args;
        }
    }

}

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

    namespace detail
    {
        template<typename... _>
        using args = boost::mpl2::detail::args<_...>;
    }

    using args0 = detail::args<detail::args<>, detail::args<detail::args<>, detail::args<>, detail::args<> > >;
    using args1 = detail::args<args0, short, args0>;
    using args2 = detail::args<int, args1>;
    using args3 = detail::args<detail::args<long>, detail::args<detail::args<args2> > >;
    using args4 = detail::args<args0, args0, args0, long long, detail::args<detail::args<args3> > >;

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
