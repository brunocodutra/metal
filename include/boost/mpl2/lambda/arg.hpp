// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_LAMBDA_ARG_HPP
#define BOOST_MPL2_LAMBDA_ARG_HPP

#include <boost/mpl2/lambda/identity.hpp>
#include <boost/mpl2/lambda/call.hpp>

#include <cstddef>

namespace boost
{
    namespace mpl2
    {
        template<std::size_t n>
        struct arg :
                identity<arg<n> >
        {
        private:
            template<std::size_t index, typename... args>
            struct select
            {};

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
        struct arg<0> :
                identity<arg<0> >
        {
            template<typename... args>
            using call = identity<detail::args_pack<args...> >;
        };

        using _ = arg<0>;
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
}

#endif
