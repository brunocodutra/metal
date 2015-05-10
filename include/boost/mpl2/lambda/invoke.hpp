// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_LAMBDA_INVOKE_HPP
#define BOOST_MPL2_LAMBDA_INVOKE_HPP

#include <boost/mpl2/lambda/pack.hpp>
#include <boost/mpl2/lambda/unpack.hpp>
#include <boost/mpl2/lambda/call.hpp>

namespace boost
{
    namespace mpl2
    {
        template<typename... args>
        struct invoke :
                unpack<call, pack<args...> >
        {};

        template<typename... args>
        using is_invocable = detail::has_type<invoke<args...> >;
    }
}

#endif
