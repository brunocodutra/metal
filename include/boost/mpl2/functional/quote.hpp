// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_FUNCTIONAL_QUOTE_HPP
#define BOOST_MPL2_FUNCTIONAL_QUOTE_HPP

#include <boost/mpl2/core/identity.hpp>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            template<template<typename...> class expr, typename... args>
            struct quote
            {
            private:
                struct empty {};

                template<template<typename...> class>
                static empty impl(...);
                template<template<typename...> class e>
                static identity<e<args...>> impl(int);

            public:
                using type = decltype(impl<expr>(0));
            };
        }

        template<template<typename...> class expr, typename... args>
        struct quote :
                detail::quote<expr, args...>::type
        {};

        template<template<typename...> class expr, typename... args>
        using quote_t = typename quote<expr, args...>::type;
    }
}

#endif
