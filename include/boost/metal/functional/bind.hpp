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
        template<typename... params>
        struct bind
        {
        private:
            template<typename token, typename... args>
            struct parse
            {
                using type = token;
            };

            template<typename arg, typename... args>
            struct parse<protect<arg>, args...>
            {
                using type = arg;
            };

            template<std::size_t n, typename... args>
            struct parse<arg<n>, args...> :
                    ::boost::metal::call<arg<n>, args...>
            {};

            template<typename... _, typename... args>
            struct parse<bind<_...>, args...> :
                    ::boost::metal::call<bind<_...>, args...>
            {};

        public:
            using type = bind;

            template<typename... args>
            struct call :
                    ::boost::metal::call<
                        typename parse<params, args...>::type...
                    >
            {};
        };
    }
}

#endif
