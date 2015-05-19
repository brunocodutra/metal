// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_LAMBDA_APPLY_HPP
#define BOOST_MPL2_LAMBDA_APPLY_HPP

#include <boost/mpl2/lambda/integral.hpp>
#include <boost/mpl2/lambda/pack.hpp>
#include <boost/mpl2/lambda/lambda.hpp>
#include <boost/mpl2/lambda/invoke.hpp>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            template<typename pack, typename = typename is_evaluable<head<pack> >::type>
            struct apply_impl
            {};

            template<typename pack>
            struct apply_impl<pack, true_> :
                    invoke<lambda<typename head<pack>::type>, tail<pack> >
            {};
        }

        template<typename... args>
        struct apply :
                detail::apply_impl<pack<args...> >
        {};
    }
}

#endif
