/// @copyright Bruno Dutra 2015
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_METAL_FUNCTIONAL_BIND_HPP
#define BOOST_METAL_FUNCTIONAL_BIND_HPP

#include <boost/metal/functional/arg.hpp>
#include <boost/metal/functional/verbatim.hpp>
#include <boost/metal/functional/call.hpp>

#include <cstddef>

namespace boost
{
    namespace metal
    {
        namespace detail
        {
            template<typename...>
            struct args
            {
                using type = args;
            };
        }

        template<typename function, typename... params>
        struct bind
        {
        private:
            template<typename token, typename... args>
            struct parse :
                    detail::args<token>
            {};

            template<typename arg, typename... args>
            struct parse<verbatim<arg>, args...> :
                    detail::args<arg>
            {};

            template<typename... args>
            struct parse<arg<0U>, args...> :
                    detail::args<args...>
            {};

            template<std::size_t n, typename... args>
            struct parse<arg<n>, args...> :
                    detail::args<call_t<arg<n>, args...>>
            {};

            template<typename f, typename... p, typename... args>
            struct parse<bind<f, p...>, args...> :
                    detail::args<call_t<bind<f, p...>, args...>>
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
            struct call<detail::args<xs...>, detail::args<ys...>, tail...> :
                    call<detail::args<xs..., ys...>, tail...>
            {};

            template<typename... args>
            struct call<detail::args<args...>> :
                    ::boost::metal::call<args...>
            {};
        };
    }
}

#endif
