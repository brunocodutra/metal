// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_LAMBDA_UNPACK_HPP
#define BOOST_MPL2_LAMBDA_UNPACK_HPP

#include <boost/mpl2/lambda/integral/size_t.hpp>
#include <boost/mpl2/lambda/pack.hpp>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            template<typename...>
            struct unpacked;

            template<
                template<typename...> class expr,
                typename packed, typename = unpacked<>,
                typename = typename sizeof_<packed>::type
            >
            struct unpack_impl;

            template<
                template<typename...> class expr,
                typename... args,
                typename... unpacked_args,
                std::size_t size
            >
            struct unpack_impl<expr, pack<args...>, unpacked<unpacked_args...>, size_t_<size> > :
                    unpack_impl<
                        expr,
                        tail<args...>,
                        unpacked<unpacked_args..., typename head<args...>::type>
                    >
            {};

            template<
                template<typename...> class expr,
                typename... args,
                typename... unpacked_args
            >
            struct unpack_impl<expr, pack<args...>, unpacked<unpacked_args...>, size_t_<0> > :
                    expr<unpacked_args...>
            {};
        }

        template<template<typename...> class expr, typename... args>
        struct unpack :
                detail::unpack_impl<expr, pack<args...> >
        {};
    }
}

#endif
