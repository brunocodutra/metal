// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_LAMBDA_CALL_HPP
#define BOOST_MPL2_LAMBDA_CALL_HPP

#include <boost/mpl2/lambda/integral/boolean.hpp>
#include <boost/mpl2/lambda/traits.hpp>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            template<typename...>
            struct args_pack;

            template<typename function, typename args, typename = typename is_function<function>::type>
            struct call_impl
            {};

            template<typename function, typename... args>
            struct call_impl<function, args_pack<args...>, true_> :
                    function::template call<args...>
            {};
        }

        template<typename function, typename... args>
        struct call :
                detail::call_impl<function, detail::args_pack<args...> >
        {};

        template<typename function, typename... args>
        struct is_callable :
                detail::has_type<call<function, args...> >
        {};
    }
}

#endif
