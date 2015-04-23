// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_LAMBDA_ARG_HPP
#define BOOST_MPL2_LAMBDA_ARG_HPP

#include <boost/mpl2/lambda/integral/boolean.hpp>
#include <boost/mpl2/lambda/pack.hpp>
#include <boost/mpl2/lambda/if.hpp>
#include <boost/mpl2/lambda/call.hpp>

#include <cstddef>

namespace boost
{
    namespace mpl2
    {
        template<std::size_t n>
        struct arg
        {
            template<typename... args>
            struct call :
                    if_<
                        bool_<n == 0>,
                        pack<args...>,
                        bool_<n == 1>,
                        head<args...>,
                        boost::mpl2::call<arg<n - 1>, tail<args...> >
                    >
            {};
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
