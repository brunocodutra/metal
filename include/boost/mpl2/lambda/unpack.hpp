// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_LAMBDA_UNPACK_HPP
#define BOOST_MPL2_LAMBDA_UNPACK_HPP

#include <boost/mpl2/lambda/pack.hpp>
#include <boost/mpl2/lambda/if.hpp>

namespace boost
{
    namespace mpl2
    {
        template<template<typename...> class expr, typename pack, typename... unpacked>
        struct unpack;

        template<template<typename...> class expr, typename... args, typename... unpacked>
        struct unpack<expr, pack<args...>, unpacked...> :
                if_<
                    sizeof_<pack<args...> >,
                    unpack<
                        expr,
                        tail<pack<args...> >,
                        unpacked...,
                        head<pack<args...> >
                    >,
                    expr<typename unpacked::type...>
                >
        {};
    }
}

#endif
