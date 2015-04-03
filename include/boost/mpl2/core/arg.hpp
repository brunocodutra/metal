// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_ARG_HPP
#define BOOST_MPL2_CORE_ARG_HPP

#include <boost/mpl2/core/identity.hpp>

#include <cstddef>

namespace boost
{
    namespace mpl2
    {
        template<std::size_t n>
        struct arg
        {
            template<typename head, typename... tail>
            struct type_ :
                    arg<n - 1>::template type<tail...>
            {};

            template<typename head, typename... tail>
            using type = type_<head, tail...>;
        };

        template<>
        struct arg<1>
        {
            template<typename head, typename... tail>
            using type = identity<head>;
        };

        template<>
        struct arg<0>;
    }
}

#endif
