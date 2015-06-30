// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_METAL_FUNCTIONAL_LAMBDA_HPP
#define BOOST_METAL_FUNCTIONAL_LAMBDA_HPP

#include <boost/metal/functional/arg.hpp>
#include <boost/metal/functional/quote.hpp>
#include <boost/metal/functional/protect.hpp>
#include <boost/metal/functional/bind.hpp>
#include <boost/metal/functional/call.hpp>

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
                    parse<protect<invariant>>
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
                    bind<quote<parametric>, parse_t<args>...>
            {};

        public:
            using type = lambda;

            template<typename... args>
            struct call :
                    ::boost::metal::call<parse<expr>, args...>
            {};
        };
    }
}

#endif
