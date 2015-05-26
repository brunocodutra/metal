// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_METAFUNCTIONAL_BIND_HPP
#define BOOST_MPL2_METAFUNCTIONAL_BIND_HPP

#include <boost/mpl2/core/integral.hpp>
#include <boost/mpl2/core/arithmetic/inc.hpp>
#include <boost/mpl2/metafunctional/arg.hpp>
#include <boost/mpl2/metafunctional/forward.hpp>
#include <boost/mpl2/metafunctional/call.hpp>

#include <cstddef>

namespace boost
{
    namespace mpl2
    {
        template<typename...>
        struct bind
        {};

        namespace detail
        {
            template<typename... params>
            struct _bind
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
                using call = forward<
                    ::boost::mpl2::call,
                    typename ::boost::mpl2::call<parse<params>, args...>::type...
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
                    pack<>
            {};
        }

        template<typename function, typename... params>
        struct bind<function, params...> :
            forward<detail::_bind, typename detail::autocomplete<size_t_<1>, function, params...>::type>
        {
            using type = bind;
        };
    }
}

#endif
