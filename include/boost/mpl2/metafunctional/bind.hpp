// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_METAFUNCTIONAL_BIND_HPP
#define BOOST_MPL2_METAFUNCTIONAL_BIND_HPP

#include <boost/mpl2/metafunctional/arg.hpp>
#include <boost/mpl2/metafunctional/call.hpp>

#include <cstddef>

namespace boost
{
    namespace mpl2
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

            template<std::size_t n, typename... args>
            struct parse<arg<n>, args...> :
                    ::boost::mpl2::call<arg<n>, args...>
            {};

            template<typename... _, typename... args>
            struct parse<bind<_...>, args...> :
                    ::boost::mpl2::call<bind<_...>, args...>
            {};

        public:
            using type = bind;

            template<typename... args>
            struct call :
                    ::boost::mpl2::call<
                        typename parse<params, args...>::type...
                    >
            {};
        };
    }
}

#endif
