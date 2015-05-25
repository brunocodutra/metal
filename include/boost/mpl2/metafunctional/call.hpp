// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_METAFUNCTIONAL_CALL_HPP
#define BOOST_MPL2_METAFUNCTIONAL_CALL_HPP

#include <boost/mpl2/core/integral.hpp>
#include <boost/mpl2/metafunctional/traits/is_evaluable.hpp>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            template<typename...> struct args;

            template<typename function, typename args, typename = true_>
            struct call_impl
            {};

            template<typename function, typename... a>
            struct call_impl<function, args<a...>, typename is_evaluable<typename function::template call<a...> >::type> :
                    function::template call<a...>
            {};
        }

        template<typename...>
        struct call
        {};

        template<typename function, typename... args>
        struct call<function, args...> :
                detail::call_impl<function, detail::args<args...> >
        {};
    }
}

#endif
