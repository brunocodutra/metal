// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_METAFUNCTIONAL_INVOKE_HPP
#define BOOST_MPL2_METAFUNCTIONAL_INVOKE_HPP

#include <boost/mpl2/metafunctional/pack.hpp>
#include <boost/mpl2/metafunctional/forward.hpp>
#include <boost/mpl2/metafunctional/traits/is_function.hpp>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            template<typename pack, typename = true_>
            struct invoke_impl
            {};

            template<typename pack>
            struct invoke_impl<pack, typename is_function<typename head<pack>::type>::type> :
                    forward<head<pack>::type::template call, tail<pack> >
            {};
        }

        template<typename... args>
        struct invoke :
                detail::invoke_impl<pack<args...> >
        {};
    }
}

#endif
