// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_METAL_FUNCTIONAL_CALL_HPP
#define BOOST_METAL_FUNCTIONAL_CALL_HPP

#include <boost/metal/functional/eval.hpp>
#include <boost/metal/functional/detail/function.hpp>

namespace boost
{
    namespace metal
    {
        template<typename...>
        struct call
        {};

        template<typename function, typename... args>
        struct call<function, args...> :
                eval<detail::function<function>::template call, args...>
        {};

        template<typename... _>
        using call_t = typename call<_...>::type;
    }
}

#endif
