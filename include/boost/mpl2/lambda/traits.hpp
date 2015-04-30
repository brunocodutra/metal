// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_LAMBDA_TRAITS_HPP
#define BOOST_MPL2_LAMBDA_TRAITS_HPP

#include <boost/mpl2/lambda/detail/traits_factory.hpp>

namespace boost
{
    namespace mpl2
    {
        BOOST_MPL2_DETAIL_DEFINE_NESTED_TEMPLATE_TRAIT(is_function, call);
    }
}

#endif
