// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_METAFUNCTIONAL_BIND_HPP
#define BOOST_MPL2_METAFUNCTIONAL_BIND_HPP

#include <boost/mpl2/metafunctional/arg.hpp>
#include <boost/mpl2/metafunctional/forward.hpp>
#include <boost/mpl2/metafunctional/call.hpp>


namespace boost
{
    namespace mpl2
    {
        template<typename function, typename... parameters>
        struct bind
        {
        private:
            template<typename param>
            struct parse
            {
                template<typename...>
                struct call
                {
                    using type = param;
                };
            };

            template<std::size_t n>
            struct parse<arg<n> > :
                    arg<n>
            {};

            template<typename func, typename... params>
            struct parse<bind<func, params...> > :
                    bind<func, params...>
            {};

        public:
            using type = bind;

            template<typename... args>
            using call = forward<
                ::boost::mpl2::call,
                typename ::boost::mpl2::call<parse<function>, args...>::type,
                typename ::boost::mpl2::call<parse<parameters>, args...>::type...
            >;
        };
    }
}

#endif
