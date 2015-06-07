// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_METAFUNCTIONAL_QUOTE_HPP
#define BOOST_MPL2_METAFUNCTIONAL_QUOTE_HPP

#include <boost/mpl2/metafunctional/quoter.hpp>

namespace boost
{
    namespace mpl2
    {
        template<template<typename...> class expr, typename... args>
        struct quote :
                quoter<expr>::template call<args...>
        {};

        template<template<typename...> class expr, typename... args>
        using quote_t = typename quote<expr, args...>::type;
    }
}

#endif
