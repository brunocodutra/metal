// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_LOGICAL_AND_HPP
#define METAL_NUMBER_LOGICAL_AND_HPP

#include <metal/number/number.hpp>
#include <metal/number/logical/or.hpp>
#include <metal/number/logical/not.hpp>
#include <metal/optional/conditional.hpp>
#include <metal/optional/just.hpp>

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

    namespace detail
    {
        template<typename op>
        using monadic = conditional_t<is_just_t<op>, op, just<op>>;
    }

    template<typename... nums>
    struct and_ :
            not_<detail::monadic<or_<detail::monadic<not_<nums>>...>>>
    {};
}

#endif
