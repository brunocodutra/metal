// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_LAMBDA_LOGICAL_NOT_HPP
#define BOOST_MPL2_LAMBDA_LOGICAL_NOT_HPP

#include <boost/mpl2/lambda/integral/boolean.hpp>

namespace boost
{
    namespace mpl2
    {
        template<typename x>
        using not_ = bool_<not x::value>;
    }
}

#endif
