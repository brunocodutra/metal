// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_METAFUNCTIONAL_LAMBDA_HPP
#define BOOST_MPL2_METAFUNCTIONAL_LAMBDA_HPP

#include <boost/mpl2/core/if.hpp>
#include <boost/mpl2/core/identity.hpp>
#include <boost/mpl2/metafunctional/quote.hpp>
#include <boost/mpl2/metafunctional/function.hpp>
#include <boost/mpl2/metafunctional/protect.hpp>
#include <boost/mpl2/metafunctional/bind.hpp>
#include <boost/mpl2/metafunctional/arg.hpp>
#include <boost/mpl2/metafunctional/pack.hpp>
#include <boost/mpl2/metafunctional/call.hpp>
#include <boost/mpl2/metafunctional/traits/is_function.hpp>
#include <boost/mpl2/metafunctional/traits/is_evaluable.hpp>

namespace boost
{
    namespace mpl2
    {
        template<typename expr>
        struct lambda
        {
        private:
            template<typename function, typename = typename is_function<function>::type>
            struct parse;

            template<typename invariant>
            struct adapt :
                    bind<protect<_1>, invariant>
            {};

            template<typename... args>
            struct adapt<pack<args...> > :
                    bind<protect<_>, typename parse<args>::type...>
            {};

            template<template<typename...> class parametric, typename... args>
            struct adapt<parametric<args...> > :
                    bind<
                        protect<
                            bind<
                                function<if_>,
                                bind<function<is_evaluable>, bind<quote<parametric>, _> >,
                                bind<quote<parametric>, _>,
                                bind<quote<identity>, bind<quote<parametric>, _> >
                            >
                        >,
                        typename parse<args>::type...
                    >
            {};

            template<typename function, typename>
            struct parse :
                    protect<bind<protect<function>, _> >
            {};

            template<typename lexpr>
            struct parse<lexpr, false_> :
                    adapt<lexpr>
            {};

            template<std::size_t n, typename _>
            struct parse<arg<n>, _> :
                    arg<n>
            {};

        public:
            using type = lambda;

            template<typename... args>
            using call = call<parse<expr>, args...>;
        };
    }
}

#endif
