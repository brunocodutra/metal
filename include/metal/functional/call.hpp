// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_CALL_HPP
#define METAL_FUNCTIONAL_CALL_HPP

#include <metal/functional/eval.hpp>
#include <metal/functional/detail/function.hpp>

namespace metal
{
    template<typename function, typename... args>
    struct call :
            eval<detail::function<function>::template call, args...>
    {};

    /// \ingroup functional_traits
    /// \brief Eager adaptor for \ref call.
    template<typename... args>
    using call_t = typename call<args...>::type;
}

#endif
