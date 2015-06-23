// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_METAL_FUNCTIONAL_LAMBDA_HPP
#define BOOST_METAL_FUNCTIONAL_LAMBDA_HPP

#include <boost/metal/algebra/if.hpp>
#include <boost/metal/functional/arg.hpp>
#include <boost/metal/functional/quoter.hpp>
#include <boost/metal/functional/evaluator.hpp>
#include <boost/metal/functional/protect.hpp>
#include <boost/metal/functional/bind.hpp>
#include <boost/metal/functional/call.hpp>
#include <boost/metal/functional/traits/is_callable.hpp>

#include <cstddef>

namespace boost
{
    namespace metal
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

            template<typename invariant>
            struct parse<protect<invariant>> :
                    bind<protect<arg<1>>, protect<invariant>>
            {};

            template<std::size_t n>
            struct parse<arg<n>> :
                    arg<n>
            {};

            template<template<typename...> class parametric, typename... args>
            struct parse<parametric<args...>> :
                    bind<
                        evaluator<if_>,
                        bind<evaluator<is_callable>, evaluator<parametric>, parse_t<args>...>,
                        bind<quoter< ::boost::metal::call>, evaluator<parametric>, parse_t<args>...>,
                        bind<quoter< ::boost::metal::call>, quoter<parametric>, parse_t<args>...>
                    >
            {};

        public:
            using type = lambda;

            template<typename... args>
            struct call :
                    ::boost::metal::call<parse_t<expr>, args...>
            {};
        };
    }
}

#endif
