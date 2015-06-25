// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_METAL_FUNCTIONAL_BIND_HPP
#define BOOST_METAL_FUNCTIONAL_BIND_HPP

#include <boost/metal/functional/arg.hpp>
#include <boost/metal/functional/protect.hpp>
#include <boost/metal/functional/call.hpp>

#include <cstddef>

namespace boost
{
    namespace metal
    {
        namespace detail
        {
            template<typename...>
            struct pack
            {
                using type = pack;
            };
        }

        template<typename function, typename... params>
        struct bind
        {
        private:
            template<typename token, typename... args>
            struct parse :
                    detail::pack<token>
            {};

            template<typename arg, typename... args>
            struct parse<protect<arg>, args...> :
                    detail::pack<arg>
            {};

            template<typename... args>
            struct parse<arg<0U>, args...> :
                    detail::pack<args...>
            {};

            template<std::size_t n, typename... args>
            struct parse<arg<n>, args...> :
                    detail::pack<call_t<arg<n>, args...>>
            {};

            template<typename f, typename... p, typename... args>
            struct parse<bind<f, p...>, args...> :
                    detail::pack<call_t<bind<f, p...>, args...>>
            {};

            template<typename token, typename... args>
            using parse_t = typename parse<token, args...>::type;

        public:
            using type = bind;

            template<typename... args>
            struct call :
                    call<parse_t<function, args...>, parse_t<params, args...>...>
            {};

            template<typename... xs, typename... ys, typename... tail>
            struct call<detail::pack<xs...>, detail::pack<ys...>, tail...> :
                    call<detail::pack<xs..., ys...>, tail...>
            {};

            template<typename... args>
            struct call<detail::pack<args...>> :
                    ::boost::metal::call<args...>
            {};
        };
    }
}

#endif
