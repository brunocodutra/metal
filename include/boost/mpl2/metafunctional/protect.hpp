// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_METAFUNCTIONAL_PROTECT_HPP
#define BOOST_MPL2_METAFUNCTIONAL_PROTECT_HPP

#include <boost/mpl2/core/assert.hpp>
#include <boost/mpl2/metafunctional/traits/is_function.hpp>

namespace boost
{
    namespace mpl2
    {
        template<typename function>
        struct protect :
                function
        {
            BOOST_MPL2_ASSERT_MSG((is_function<function>), "not a function");

            using type = protect;
            using function::call;
        };
    }
}

#endif
