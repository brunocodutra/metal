// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_IS_CALLABLE_HPP
#define BOOST_MPL2_CORE_IS_CALLABLE_HPP

#include <boost/mpl2/core/nested_template_trait.hpp>

namespace boost
{
    namespace mpl2
    {
        BOOST_MPL2_DEFINE_NESTED_TEMPLATE_TRAIT(is_callable, call);
    }
}

#endif
