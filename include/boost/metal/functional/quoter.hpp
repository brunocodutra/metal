/// @copyright Bruno Dutra 2015
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_METAL_FUNCTIONAL_QUOTER_HPP
#define BOOST_METAL_FUNCTIONAL_QUOTER_HPP

#include <boost/metal/functional/quote.hpp>

namespace boost
{
    namespace metal
    {
        template<template<typename...> class expr>
        struct quoter
        {
            using type = quoter;

            template<typename... args>
            struct call :
                    quote<expr, args...>
            {};
        };
    }
}

#endif
