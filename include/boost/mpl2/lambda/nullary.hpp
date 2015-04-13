// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_LAMBDA_NULLARY_HPP
#define BOOST_MPL2_LAMBDA_NULLARY_HPP

#include <boost/mpl2/lambda/identity.hpp>

namespace boost
{
    namespace mpl2
    {
        template<typename nullexpr>
        struct nullary :
                identity<nullary<nullexpr> >
        {
            template<typename...>
            using call = nullexpr;
        };
    }
}

#endif
