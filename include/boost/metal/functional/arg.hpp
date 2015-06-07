// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

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
        struct arg<0U>;
    }
}

#endif
