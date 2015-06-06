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
        template<typename...>
        struct bind;

        namespace detail
        {
            template<typename params>
            struct bind_impl;

            template<typename... params>
            struct bind_impl<detail::args<params...> >
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
                template<typename... args>
                struct call :
                        ::boost::mpl2::call<
                            typename parse<params>::template call<args...>::type...
                        >
                {};
            };

            template<typename rank, typename... params>
            struct autocomplete;

            template<typename rank, typename head, typename... tail>
            struct autocomplete<rank, head, tail...> :
                    cons<head, typename autocomplete<rank, tail...>::type>
            {};

            template<typename rank, typename... tail>
            struct autocomplete<rank, placeholders::_, tail...> :
                    cons<arg<rank::value>, typename autocomplete<inc<rank>, tail...>::type>
            {};

            template<typename rank>
            struct autocomplete<rank> :
                    detail::args<>
            {};
        }

        template<typename... params>
        struct bind :
            detail::bind_impl<typename detail::autocomplete<std::integral_constant<std::size_t, 1>, params...>::type>
        {
            using type = bind;
        };
    }
}

#endif
