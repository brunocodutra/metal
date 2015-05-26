// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_METAFUNCTIONAL_ARG_HPP
#define BOOST_MPL2_METAFUNCTIONAL_ARG_HPP

#include <cstddef>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            template<typename...>
            struct args;

            template<typename head, typename args>
            struct cons;

            template<typename head, typename... tail>
            struct cons<head, args<tail...> >
            {
                using type = args<head, tail...>;
            };

            template<typename... head, typename... tail>
            struct args<detail::args<head...>, tail...> :
                    args<head..., tail...>
            {};

            template<typename head, typename... tail>
            struct args<head, tail...> :
                    cons<head, typename args<tail...>::type>
            {};

            template<>
            struct args<>
            {
                using type = args;
            };
        }

        template<std::size_t n>
        struct arg
        {
            using type = arg;

            template<typename...>
            struct call
            {};

            template<typename head, typename... tail>
            struct call<head, tail...> :
                    arg<n-1>::template call<tail...>
            {};
        };

        template<>
        struct arg<1U>
        {
            using type = arg;

            template<typename...>
            struct call
            {};

            template<typename head, typename... tail>
            struct call<head, tail...>
            {
                using type = head;
            };
        };

        template<>
        struct arg<0U>
        {
            using type = arg;

            template<typename... args>
            struct call
            {
                using type = detail::args<args...>;
            };
        };

        namespace placeholders
        {
            struct _;
            using _0 = arg<0>;
            using _1 = arg<1>;
            using _2 = arg<2>;
            using _3 = arg<3>;
            using _4 = arg<4>;
            using _5 = arg<5>;
            using _6 = arg<6>;
            using _7 = arg<7>;
            using _8 = arg<8>;
            using _9 = arg<9>;
        }

        using namespace ::boost::mpl2::placeholders;
    }
}

#endif
