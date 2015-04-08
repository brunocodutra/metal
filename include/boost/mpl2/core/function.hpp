// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_FUNCTION_HPP
#define BOOST_MPL2_CORE_FUNCTION_HPP

#include <boost/mpl2/core/if.hpp>
#include <boost/mpl2/core/detail/traits.hpp>

namespace boost
{
    namespace mpl2
    {
        template<template<typename...> class sig>
        struct function
        {
        private:
            struct empty {};

        public:
            template<typename... args>
            struct call :
                    if_<
                        detail::has_type<sig<args...> >,
                        sig<args...>,
                        empty
                    >
            {};
        };
    }
}

#endif
