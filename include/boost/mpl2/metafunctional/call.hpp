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
            template<typename...> struct pack;

            template<typename function, typename args, typename = true_>
            struct _call
            {};

            template<typename function, typename... args>
            struct _call<function, pack<args...>, typename is_evaluable<typename function::template call<args...> >::type> :
                    function::template call<args...>
            {};
        }

        template<typename...>
        struct call
        {};

        template<typename function, typename... args>
        struct call<function, args...> :
                detail::_call<function, detail::pack<args...> >
        {};
    }
}

#endif
