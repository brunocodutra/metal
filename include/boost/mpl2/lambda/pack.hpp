// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_LAMBDA_PACK_HPP
#define BOOST_MPL2_LAMBDA_PACK_HPP

#include <boost/mpl2/lambda/integral/size_t.hpp>
#include <boost/mpl2/lambda/arithmetic/inc.hpp>
#include <boost/mpl2/lambda/identity.hpp>

namespace boost
{
    namespace mpl2
    {
        template<typename... args>
        struct sizeof_;

        template<typename... args>
        struct pack;

        template<typename... args, typename... tail>
        struct pack<pack<args...>, tail...> :
                pack<args..., tail...>
        {};

        template<typename h, typename... t>
        struct pack<h, t...>
        {
            using type = pack;
            using head = identity<h>;
            using tail = pack<t...>;
            using size = inc<sizeof_<tail> >;
        };

        template<>
        struct pack<>
        {
            using type = pack;
            struct head {};
            using tail = pack<>;
            using size = size_t_<0>;
        };

        template<typename... args>
        using head = typename pack<args...>::head;

        template<typename... args>
        using tail = typename pack<args...>::tail;

        template<typename... args>
        struct sizeof_ :
                pack<args...>::size
        {};
    }
}

#endif
