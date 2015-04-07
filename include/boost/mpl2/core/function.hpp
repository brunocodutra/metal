// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_FUNCTION_HPP
#define BOOST_MPL2_CORE_FUNCTION_HPP

#include <boost/mpl2/core/nested_type_trait.hpp>
#include <boost/mpl2/core/identity.hpp>
#include <boost/mpl2/core/if.hpp>

namespace boost
{
    namespace mpl2
    {
        template<template<typename...> class signature>
        struct function
        {
        private:
            BOOST_MPL2_DEFINE_NESTED_TYPE_TRAIT(has_type, type);

        public:
            template<typename... args>
            struct call :
                    if_<
                        has_type<signature<args...> >,
                        signature<args...>,
                        identity<signature<args...> >
                    >::type
            {};
        };
    }
}

#endif
