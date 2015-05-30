// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_METAFUNCTIONAL_CALL_HPP
#define BOOST_MPL2_METAFUNCTIONAL_CALL_HPP

#include <boost/mpl2/core/integral.hpp>
#include <boost/mpl2/metafunctional/arg.hpp>
#include <boost/mpl2/metafunctional/traits/is_evaluable.hpp>
#include <boost/mpl2/metafunctional/traits/is_function.hpp>

#include <type_traits>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            template<template<typename...> class expr, typename... args>
            struct instantiate
            {
            private:
                struct empty{};

                template<typename...>
                static empty eval(...);
                template<typename... _>
                static typename std::enable_if<is_evaluable<expr<_...> >::value, expr<_...> >::type eval(int);

            public:
                using type = decltype(eval<args...>(0));
            };

            template<typename args, typename = true_>
            struct call_impl
            {};

            template<typename function, typename... args>
            struct call_impl<detail::args<function, args...>, typename is_function<function>::type> :
                    instantiate<function::template call, args...>::type
            {};
        }

        template<typename... args>
        struct call :
                detail::call_impl<typename detail::args<args...>::type>
        {};
    }
}

#endif
