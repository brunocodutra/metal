// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_METAFUNCTIONAL_FORWARD_HPP
#define BOOST_MPL2_METAFUNCTIONAL_FORWARD_HPP

#include <boost/mpl2/metafunctional/arg.hpp>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            template<typename...>
            struct pack;

            template<typename x, typename pack>
            struct cons;

            template<typename x, typename... args>
            struct cons<x, pack<args...> >
            {
                using type = pack<x, args...>;
            };

            template<typename... args, typename... tail>
            struct pack<detail::args<args...>, tail...> :
                    pack<args..., tail...>
            {};

            template<typename head, typename... tail>
            struct pack<head, tail...> :
                    cons<head, typename pack<tail...>::type>
            {};

            template<>
            struct pack<>
            {
                using type = pack;
            };
        }

        template<template<typename...> class expr, typename... args>
        struct forward :
                forward<expr, typename detail::pack<args...>::type>
        {};

        template<template<typename...> class expr, typename... args>
        struct forward<expr, detail::pack<args...> > :
                expr<args...>
        {};
    }
}

#endif
