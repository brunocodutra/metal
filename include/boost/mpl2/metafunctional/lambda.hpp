// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_METAFUNCTIONAL_LAMBDA_HPP
#define BOOST_MPL2_METAFUNCTIONAL_LAMBDA_HPP

#include <boost/mpl2/core/if.hpp>
#include <boost/mpl2/metafunctional/arg.hpp>
#include <boost/mpl2/metafunctional/quoter.hpp>
#include <boost/mpl2/metafunctional/function.hpp>
#include <boost/mpl2/metafunctional/protect.hpp>
#include <boost/mpl2/metafunctional/bind.hpp>
#include <boost/mpl2/metafunctional/call.hpp>
#include <boost/mpl2/metafunctional/traits/is_callable.hpp>

#include <cstddef>

namespace boost
{
    namespace mpl2
    {
        template<typename expr>
        struct lambda
        {
        private:
            template<typename invariant>
            struct parse :
                    bind<protect<arg<1>>, invariant>
            {};

            template<std::size_t n>
            struct parse<arg<n>> :
                    arg<n>
            {};

            template<typename function>
            struct parse<protect<function>> :
                    protect<function>
            {};

            template<template<typename...> class parametric, typename... args>
            struct parse<parametric<args...>> :
                    bind<
                        function<if_>,
                        bind<function<is_callable>, function<parametric>, typename parse<args>::type...>,
                        bind<quoter<::boost::mpl2::call>, function<parametric>, typename parse<args>::type...>,
                        bind<quoter<::boost::mpl2::call>, quoter<parametric>, typename parse<args>::type...>
                    >
            {};

        public:
            using type = lambda;

            template<typename... args>
            struct call :
                    ::boost::mpl2::call<typename parse<expr>::type, args...>
            {};
        };
    }
}

#endif
