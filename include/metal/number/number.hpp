// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_NUMBER_HPP
#define METAL_NUMBER_NUMBER_HPP

#include <type_traits>

namespace metal
{
    /// \ingroup number
    /// The standard constructor for \numbers.
    template<typename type, type value>
    using number = std::integral_constant<type, value>;

    /// \ingroup number
    /// The standard constructor for [booleans](\numbers).
    template<bool value>
    using boolean = metal::number<bool, value>;

    /// \ingroup number
    /// The standard constructor for [integers](\numbers).
    template<int value>
    using integer = metal::number<int, value>;

    /// \ingroup number
    /// The standard constructor for [characters](\numbers).
    template<char value>
    using character = metal::number<char, value>;

    namespace detail
    {
        template<typename num>
        struct is_number;
    }

    /// \ingroup number
    /// Checks whether some \value is a \number.
    ///
    /// Usage
    /// -----
    /// For any \value `val`
    /// \code
    ///     metal::is_number<val>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     If `val` is a \number, then equivalent to
    ///     \code
    ///         template<>
    ///         struct is_number<val> :
    ///             boolean<true>
    ///         {};
    ///     \endcode
    ///     otherwise, equivalent to
    ///     \code
    ///         template<>
    ///         struct is_number<val> :
    ///             boolean<false>
    ///         {};
    ///     \endcode
    ///
    /// Example
    /// -------
    /// \snippet number/number.cpp is_number
    ///
    /// See Also
    /// --------
    /// \see number, boolean, integer
    template<typename num>
    using is_number = detail::is_number<num>;

    /// \ingroup number
    /// Eager adaptor for metal::is_number.
    template<typename num>
    using is_number_t = typename metal::is_number<num>::type;

    namespace detail
    {
        template<typename num>
        struct is_number :
            boolean<false>
        {};

        template<typename type, type value>
        struct is_number<number<type, value>> :
            boolean<true>
        {};
    }
}

#endif
