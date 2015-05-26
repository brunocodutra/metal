// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_METAFUNCTIONAL_BIND_HPP
#define BOOST_MPL2_METAFUNCTIONAL_BIND_HPP

#include <boost/mpl2/core/integral.hpp>
#include <boost/mpl2/core/arithmetic/inc.hpp>
#include <boost/mpl2/metafunctional/arg.hpp>
#include <boost/mpl2/metafunctional/call.hpp>

#include <cstddef>

namespace boost
{
    namespace mpl2
    {
        template<typename...>
        struct bind;

        namespace detail
        {
            template<typename params>
            struct _bind;

            template<typename... params>
            struct _bind<detail::args<params...> >
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
                using call = ::boost::mpl2::call<
                    typename parse<params>::template call<args...>::type...
                >;
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
            detail::_bind<typename detail::autocomplete<size_t_<1>, params...>::type>
        {
            using type = bind;
        };
    }
}

#endif
