// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_INVOKE_HPP
#define METAL_LAMBDA_INVOKE_HPP

#include <metal/lambda/apply.hpp>
#include <metal/list/list.hpp>

namespace metal
{
    /// \ingroup lambda
    /// \brief ...
    template<typename...>
    struct invoke
    {};

    /// \ingroup lambda
    /// \brief Eager adaptor for \ref invoke.
    template<typename... args>
    using invoke_t = typename invoke<args...>::type;

    template<typename lbd, typename... args>
    struct invoke<lbd, args...> :
            apply<lbd, list<args...>>
    {};
}

#endif
