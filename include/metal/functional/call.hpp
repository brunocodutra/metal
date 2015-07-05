// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_CALL_HPP
#define METAL_FUNCTIONAL_CALL_HPP

#include <metal/functional/eval.hpp>
#include <metal/functional/function.hpp>

namespace metal
{
    template<typename func, typename... args>
    struct call :
            eval<function<func>::template call, args...>
    {};

    template<typename... _>
    using call_t = typename call<_...>::type;
}

#endif
