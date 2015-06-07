// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_METAL_FUNCTIONAL_APPLY_HPP
#define BOOST_METAL_FUNCTIONAL_APPLY_HPP

#include <boost/metal/functional/lambda.hpp>
#include <boost/metal/functional/call.hpp>

namespace boost
{
    namespace metal
    {
        template<typename...>
        struct apply
        {};

        template<typename expr, typename... args>
        struct apply<expr, args...> :
                call<lambda<expr>, args...>
        {};

        template<typename... _>
        using apply_t = typename apply<_...>::type;
    }
}

#endif
