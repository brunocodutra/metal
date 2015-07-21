// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_BIND_HPP
#define METAL_FUNCTIONAL_BIND_HPP

#include <metal/functional/arg.hpp>
#include <metal/functional/verbatim.hpp>
#include <metal/functional/call.hpp>

#include <cstddef>

namespace metal
{
    template<typename func, typename... params>
    struct bind
    {
    ///\cond
    private:
        template<typename value, typename... args>
        struct parse :
                parse<verbatim<value>>
        {};

        template<typename value, typename... args>
        struct parse<verbatim<value>, args...> :
                verbatim<value>
        {};

        template<std::size_t n, typename... args>
        struct parse<arg<n>, args...> :
                ::metal::call<arg<n>, args...>
        {};

        template<typename f, typename... p, typename... args>
        struct parse<bind<f, p...>, args...> :
                ::metal::call<bind<f, p...>, args...>
        {};

        template<typename token, typename... args>
        using parse_t = typename parse<token, args...>::type;

    ///\endcond
    public:
        using type = bind;

        template<typename... args>
        using call = ::metal::call<
            parse_t<func, args...>,
            parse_t<params, args...>...
        >;
    };
}

#endif
