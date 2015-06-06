// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_METAFUNCTIONAL_BIND_HPP
#define BOOST_MPL2_METAFUNCTIONAL_BIND_HPP

#include <boost/mpl2/core/arithmetic/inc.hpp>
#include <boost/mpl2/metafunctional/arg.hpp>
#include <boost/mpl2/metafunctional/placeholders.hpp>
#include <boost/mpl2/metafunctional/call.hpp>

#include <cstddef>
#include <type_traits>

namespace boost
{
    namespace mpl2
    {
        template<typename... params>
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

            template<typename... _>
            struct parse<bind<_...> > :
                    bind<_...>
            {};

        public:
            using type = bind;

            template<typename... args>
            struct call :
                    ::boost::mpl2::call<
                        typename parse<params>::template call<args...>::type...
                    >
            {};
        };
    }
}

#endif
