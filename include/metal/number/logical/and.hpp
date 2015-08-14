// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_LOGICAL_AND_HPP
#define METAL_NUMBER_LOGICAL_AND_HPP

#include <metal/number/logical/or.hpp>
#include <metal/number/logical/not.hpp>
#include <metal/lambda/apply.hpp>

namespace metal
{
    /// \ingroup logical
    /// \brief ...
    template<typename... nums>
    struct and_
    {};

    /// \ingroup logical
    /// \brief Eager adaptor for \ref and_.
    template<typename... nums>
    using and_t = typename and_<nums...>::type;

    template<typename head, typename... tail>
    struct and_<head, tail...> :
            apply<not_<or_<not_<head>, not_<tail>...>>>
    {};
}

#endif
