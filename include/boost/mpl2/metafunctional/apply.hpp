// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_METAFUNCTIONAL_APPLY_HPP
#define BOOST_MPL2_METAFUNCTIONAL_APPLY_HPP

#include <boost/mpl2/metafunctional/arg.hpp>
#include <boost/mpl2/metafunctional/lambda.hpp>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            template<typename args>
            struct _apply
            {};

            template<typename expr, typename... args>
            struct _apply<detail::args<expr, args...> > :
                    lambda<expr>::template call<args...>
            {};
        }

        template<typename... args>
        struct apply :
                detail::_apply<typename detail::args<args...>::type>
        {};
    }
}

#endif
