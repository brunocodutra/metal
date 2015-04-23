// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_LAMBDA_ARGS_PACK_HPP
#define BOOST_MPL2_LAMBDA_ARGS_PACK_HPP

#include <boost/mpl2/lambda/integral/size_t.hpp>
#include <boost/mpl2/lambda/arithmetic/inc.hpp>
#include <boost/mpl2/lambda/identity.hpp>
#include <boost/mpl2/lambda/if.hpp>

namespace boost
{
    namespace mpl2
    {
        template<typename pack>
        struct sizeof_;

        template<typename... args>
        struct pack;

        template<typename h, typename... t>
        struct pack<h, t...> :
                pack<h, pack<t...> >
        {};

        template<typename... largs, typename... rargs>
        struct pack<pack<largs...>, pack<rargs...> > :
                pack<largs..., rargs...>
        {};

        template<typename h, typename... t>
        struct pack<h, pack<t...> > :
                identity<pack<h, pack<t...> > >
        {
            using head = identity<h>;
            using tail = pack<t...>;
            using size = inc<sizeof_<tail> >;
        };

        template<typename... args>
        struct pack<pack<args...> > :
                pack<args...>
        {};

        template<typename h>
        struct pack<h> :
                pack<h, pack<> >
        {};

        template<>
        struct pack<> :
                identity<pack<> >
        {
            struct head {};
            using tail = pack<>;
            using size = size_t_<0>;
        };

        template<typename... args>
        using head = typename pack<args...>::head;

        template<typename... args>
        using tail = typename pack<args...>::tail;

        template<typename pack>
        struct sizeof_ :
                pack::size
        {};

        template<template<typename...> class tmpl, typename pack, typename... unpacked>
        struct unpack;

        template<template<typename...> class tmpl, typename... args, typename... unpacked>
        struct unpack<tmpl, pack<args...>, unpacked...> :
                if_<
                    sizeof_<pack<args...> >,
                    unpack<
                        tmpl,
                        tail<pack<args...> >,
                        unpacked...,
                        head<pack<args...> >
                    >,
                    tmpl<typename unpacked::type...>
                >
        {};
    }
}

#endif
