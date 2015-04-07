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
        private:
            template<std::size_t index, typename... args>
            struct select;

            template<std::size_t index, typename head, typename... tail>
            struct select<index, head, tail...> :
                    select<index - 1, tail...>
            {};

            template<typename head, typename... tail>
            struct select<1, head, tail...> :
                    identity<head>
            {};

        public:
            template<typename... args>
            using call = select<n, args...>;
        };

        template<>
        struct arg<0>;
    }
}

#endif
