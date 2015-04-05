// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_QUOTE_HPP
#define BOOST_MPL2_CORE_QUOTE_HPP

#include <boost/mpl2/core/trait.hpp>
#include <boost/mpl2/core/identity.hpp>
#include <boost/mpl2/core/if.hpp>

namespace boost
{
    namespace mpl2
    {
        template<template<typename...> class fctn>
        struct quote
        {
        private:
            template<typename... args>
            struct apply :
                    if_<
                        is_nullary_function<fctn<args...> >,
                        fctn<args...>,
                        identity<fctn<args...> >
                    >::type
            {};
        public:
            template<typename... args>
            using type = apply<args...>;
        };
    }
}

#endif
