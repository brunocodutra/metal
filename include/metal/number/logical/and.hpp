// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_LOGICAL_AND_HPP
#define METAL_NUMBER_LOGICAL_AND_HPP

#include <metal/number/number.hpp>
#include <metal/number/logical/or.hpp>
#include <metal/number/logical/not.hpp>
#include <metal/optional/extract.hpp>

namespace metal
{
    /// \ingroup logical
    /// \brief ...
    template<typename... nums>
    struct and_;

    /// \ingroup logical
    /// \brief Eager adaptor for \ref and_.
    template<typename... nums>
    using and_t = typename and_<nums...>::type;

    template<typename... nums>
    struct and_ :
            not_<from_maybe<or_<from_maybe<not_<nums>, void>...>, void>>
    {};
}

#endif
