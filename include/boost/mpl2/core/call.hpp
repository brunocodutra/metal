// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_CALL_HPP
#define BOOST_MPL2_CORE_CALL_HPP

#include <boost/mpl2/core/function.hpp>
#include <boost/mpl2/core/detail/traits.hpp>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            template<typename func, typename = typename has_template_call<func>::type>
            struct forward;

            template<typename func>
            struct forward<func, true_> :
                    function<func::template call>
            {};

            template<typename unfunc>
            struct forward<unfunc, false_>
            {
                template<typename...>
                struct call
                {};
            };
        }

        template<typename callable, typename... args>
        using call = typename detail::forward<callable>::template call<args...>;

        template<typename callable, typename... args>
        using is_callable = detail::has_type<call<callable, args...> >;
    }
}

#endif
