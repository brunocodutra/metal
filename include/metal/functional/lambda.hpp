// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_LAMBDA_HPP
#define METAL_FUNCTIONAL_LAMBDA_HPP

#include <metal/functional/arg.hpp>
#include <metal/functional/quote.hpp>
#include <metal/functional/verbatim.hpp>
#include <metal/functional/bind.hpp>
#include <metal/functional/call.hpp>

#include <cstddef>

namespace metal
{
    template<typename lexpr>
    struct lambda
    {
    ///\cond
    private:
        template<typename value>
        struct parse :
                parse<verbatim<value>>
        {};

        template<typename token>
        using parse_t = typename parse<token>::type;

        template<typename value>
        struct parse<verbatim<value>>
        {
            using type = verbatim<value>;

            template<typename...>
            using call = type;
        };

        template<std::size_t n>
        struct parse<arg<n>> :
                arg<n>
        {};

        template<template<typename...> class expr, typename... args>
        struct parse<expr<args...>> :
                bind<quote<expr>, parse_t<args>...>
        {};

    ///\endcond
    public:
        using type = lambda;

        template<typename... args>
        using call = ::metal::call<parse<lexpr>, args...>;
    };
}

#endif
