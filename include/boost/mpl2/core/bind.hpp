// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_BIND_HPP
#define BOOST_MPL2_CORE_BIND_HPP

#include <boost/mpl2/core/arg.hpp>
#include <boost/mpl2/core/identity.hpp>
#include <boost/mpl2/core/function.hpp>
#include <boost/mpl2/core/call.hpp>

namespace boost
{
    namespace mpl2
    {
        template<typename callable, typename... params>
        struct bind :
                identity<bind<callable, params...> >
        {
        private:
            template<typename param>
            struct parse :
                    nullary<identity<param> >
            {};

            template<std::size_t n>
            struct parse<arg<n> > :
                    arg<n>
            {};

            template<typename nf, typename... prms>
            struct parse<bind<nf, prms...> > :
                    bind<nf, prms...>
            {};

        public:
            template<typename... args>
            using call = boost::mpl2::call<
                typename boost::mpl2::call<parse<callable>, args...>::type,
                typename boost::mpl2::call<parse<params>, args...>::type...
            >;
        };
    }
}

#endif
