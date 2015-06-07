// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_FUNCTIONAL_LAMBDA_HPP
#define BOOST_MPL2_FUNCTIONAL_LAMBDA_HPP

#include <boost/mpl2/algebra/if.hpp>
#include <boost/mpl2/functional/arg.hpp>
#include <boost/mpl2/functional/quoter.hpp>
#include <boost/mpl2/functional/evaluator.hpp>
#include <boost/mpl2/functional/protect.hpp>
#include <boost/mpl2/functional/bind.hpp>
#include <boost/mpl2/functional/call.hpp>
#include <boost/mpl2/functional/traits/is_callable.hpp>

#include <cstddef>

namespace boost
{
    namespace mpl2
    {
        template<typename expr>
        struct lambda
        {
        private:
            template<typename token>
            struct parse;

            template<typename token>
            using parse_t = typename parse<token>::type;

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
                        evaluator<if_>,
                        bind<evaluator<is_callable>, evaluator<parametric>, parse_t<args>...>,
                        bind<quoter< ::boost::mpl2::call>, evaluator<parametric>, parse_t<args>...>,
                        bind<quoter< ::boost::mpl2::call>, quoter<parametric>, parse_t<args>...>
                    >
            {};

        public:
            using type = lambda;

            template<typename... args>
            struct call :
                    ::boost::mpl2::call<parse_t<expr>, args...>
            {};
        };
    }
}

#endif
