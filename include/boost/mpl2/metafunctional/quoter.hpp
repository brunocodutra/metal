// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_METAFUNCTIONAL_QUOTER_HPP
#define BOOST_MPL2_METAFUNCTIONAL_QUOTER_HPP

#include <boost/mpl2/core/identity.hpp>

namespace boost
{
    namespace mpl2
    {
        template<template<typename...> class expr>
        struct quoter
        {
        private:
            template<typename> struct type_wrapper;
            struct empty {};

            template<template<typename...> class, typename...>
            static empty impl(...);
            template<template<typename...> class e, typename... args>
            static identity<e<args...>> impl(type_wrapper<identity_t<e<args...>>>*);

        public:
            using type = quoter;

            template<typename... args>
            struct call :
                    decltype(impl<expr, args...>(0))
            {};
        };
    }
}

#endif
