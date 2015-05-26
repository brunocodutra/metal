// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_METAFUNCTIONAL_CALL_HPP
#define BOOST_MPL2_METAFUNCTIONAL_CALL_HPP

#include <boost/mpl2/core/integral.hpp>
#include <boost/mpl2/metafunctional/arg.hpp>
#include <boost/mpl2/metafunctional/traits/is_evaluable.hpp>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            template<typename args, typename = true_>
            struct _call
            {};

            template<typename function, typename... args>
            struct _call<detail::args<function, args...>, typename is_evaluable<typename function::template call<args...> >::type> :
                    function::template call<args...>
            {};
        }

        template<typename... args>
        struct call :
                detail::_call<typename detail::args<args...>::type>
        {};
    }
}

#endif
