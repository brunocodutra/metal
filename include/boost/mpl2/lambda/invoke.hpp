// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_LAMBDA_INVOKE_HPP
#define BOOST_MPL2_LAMBDA_INVOKE_HPP

#include <boost/mpl2/lambda/logical/and.hpp>
#include <boost/mpl2/lambda/pack.hpp>
#include <boost/mpl2/lambda/eval.hpp>
#include <boost/mpl2/lambda/traits.hpp>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            template<typename pack, typename = typename is_function<typename head<pack>::type>::type>
            struct invoke_pack
            {};

            template<typename... args>
            struct invoke_pack<pack<args...>, true_> :
                    eval<head<pack<args...> >::type::template call, tail<pack<args...> > >
            {};
        }

        template<typename... args>
        struct invoke :
                detail::invoke_pack<pack<args...> >
        {};

        template<typename... args>
        using is_invocable = is_evaluable<invoke, args...>;
    }
}

#endif
