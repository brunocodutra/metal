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
            template<typename args, typename function = true_>
            struct invoke_impl
            {};

            template<typename args>
            struct invoke_impl<args, typename is_function<typename head<args>::type>::type> :
                    forward<head<args>::type::template call, tail<args> >
            {};
        }

        template<typename... args>
        struct invoke :
                detail::invoke_impl<pack<args...> >
        {};
    }
}

#endif
