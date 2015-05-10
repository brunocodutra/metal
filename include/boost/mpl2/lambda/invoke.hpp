// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_LAMBDA_INVOKE_HPP
#define BOOST_MPL2_LAMBDA_INVOKE_HPP

#include <boost/mpl2/lambda/integral/boolean.hpp>
#include <boost/mpl2/lambda/pack.hpp>
#include <boost/mpl2/lambda/eval.hpp>
#include <boost/mpl2/lambda/traits.hpp>

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
                    eval<head<pack>::type::template call, tail<pack> >
            {};
        }

        template<typename... args>
        struct invoke :
                detail::invoke_impl<pack<args...> >
        {};

        template<typename... args>
        using is_invocable = is_evaluable<invoke, args...>;
    }
}

#endif
