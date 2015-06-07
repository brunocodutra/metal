// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_METAL_FUNCTIONAL_PROTECT_HPP
#define BOOST_METAL_FUNCTIONAL_PROTECT_HPP

#include <boost/metal/functional/detail/function.hpp>

namespace boost
{
    namespace metal
    {
        template<typename function>
        struct protect :
                detail::function<function>
        {
            using type = protect;
        };
    }
}

#endif
