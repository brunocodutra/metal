// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_NUMBER_HPP
#define METAL_NUMBER_NUMBER_HPP

#include <type_traits>

namespace metal
{
    /// \ingroup number
    /// Standard constructor for \numbers.
    template<typename type, type value>
    using number = std::integral_constant<type, value>;

    /// \ingroup number
    /// Standard constructor for boolean \numbers.
    template<bool value>
    using boolean = std::integral_constant<bool, value>;

    /// \ingroup number
    /// Standard constructor for integer \numbers.
    template<int value>
    using integer = std::integral_constant<int, value>;

    /// \ingroup number
    /// ...
    template<typename num>
    struct is_number;

    /// \ingroup number
    /// Eager adaptor for \ref is_number.
    template<typename num>
    using is_number_t = typename metal::is_number<num>::type;

    template<typename num>
    struct is_number :
        boolean<false>
    {};

    template<typename type, type value>
    struct is_number<number<type, value>> :
        boolean<true>
    {};
}

#endif
