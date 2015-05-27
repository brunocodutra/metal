// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_METAFUNCTIONAL_APPLY_HPP
#define BOOST_MPL2_METAFUNCTIONAL_APPLY_HPP

#include <boost/mpl2/metafunctional/arg.hpp>
#include <boost/mpl2/metafunctional/lambda.hpp>
#include <boost/mpl2/metafunctional/call.hpp>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            template<typename args>
            struct apply_impl
            {};

            template<typename expr, typename... args>
            struct apply_impl<detail::args<expr, args...> > :
                    detail::call_impl<detail::args<lambda<expr>, args...> >
            {};
        }

        template<typename... args>
        struct apply :
                detail::apply_impl<typename detail::args<args...>::type>
        {};
    }
}

#endif
