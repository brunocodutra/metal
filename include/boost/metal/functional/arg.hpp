/// @copyright Bruno Dutra 2015
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_METAL_FUNCTIONAL_ARG_HPP
#define BOOST_METAL_FUNCTIONAL_ARG_HPP

#include <cstddef>

namespace boost
{
    namespace metal
    {
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
        };

        namespace placeholders
        {
            using _0 = arg<0U>;
            using _1 = arg<1U>;
            using _2 = arg<2U>;
            using _3 = arg<3U>;
            using _4 = arg<4U>;
            using _5 = arg<5U>;
            using _6 = arg<6U>;
            using _7 = arg<7U>;
            using _8 = arg<8U>;
            using _9 = arg<9U>;
        }
    }
}

#endif
