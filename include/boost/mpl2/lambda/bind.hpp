// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_LAMBDA_BIND_HPP
#define BOOST_MPL2_LAMBDA_BIND_HPP

#include <boost/mpl2/lambda/arg.hpp>
#include <boost/mpl2/lambda/call.hpp>
#include <boost/mpl2/lambda/invoke.hpp>

namespace boost
{
    namespace mpl2
    {
        template<typename function, typename... params>
        struct bind
        {
        private:
            template<typename param, typename...>
            struct parse
            {
                using type = param;
            };

            template<std::size_t n, typename... args>
            struct parse<arg<n>, args...> :
                    call<arg<n>, args...>
            {};

            template<typename nf, typename... prms, typename... args>
            struct parse<bind<nf, prms...>, args...> :
                    call<bind<nf, prms...>, args...>
            {};

        public:
            template<typename... args>
            using call = invoke<
                typename parse<function, args...>::type,
                typename parse<params, args...>::type...
            >;
        };
    }
}

#endif
