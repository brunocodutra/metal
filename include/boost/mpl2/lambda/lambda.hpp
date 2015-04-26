// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_LAMBDA_LAMBDA_HPP
#define BOOST_MPL2_LAMBDA_LAMBDA_HPP

#include <boost/mpl2/lambda/if.hpp>
#include <boost/mpl2/lambda/arg.hpp>
#include <boost/mpl2/lambda/function.hpp>
#include <boost/mpl2/lambda/quote.hpp>
#include <boost/mpl2/lambda/bind.hpp>
#include <boost/mpl2/lambda/protect.hpp>
#include <boost/mpl2/lambda/call.hpp>
#include <boost/mpl2/lambda/traits.hpp>

namespace boost
{
    namespace mpl2
    {
        template<typename expr>
        struct lambda
        {
        private:
            template<typename invariant>
            struct parse_expr
            {
                using type = bind<protect<_1>, invariant>;
            };

            template<typename function>
            using parse = if_<
                is_function<function>,
                identity<function>,
                parse_expr<function>
            >;

            template<template<typename...> class parametric, typename... args>
            struct parse_expr<parametric<args...> >
            {
                using type = bind<
                    protect<
                        bind<
                            function<if_>,
                            bind<function<is_callable>, function<parametric>, _>,
                            bind<quote<parametric>, _>,
                            bind<quote<call>, quote<parametric>, _>
                        >
                    >,
                    typename parse<args>::type...
                >;
            };

        public:
            template<typename... args>
            using call = call<typename parse<expr>::type, args...>;
        };
    }
}

#endif
