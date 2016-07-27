// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_NUMBER_HPP
#define METAL_NUMBER_NUMBER_HPP

#include <cstddef>
#include <type_traits>

namespace metal
{
    namespace detail
    {
        template<typename val>
        struct _is_number;
    }

    /// \ingroup number
    /// Checks whether some \value is a \number.
    ///
    /// Usage
    /// -----
    /// For any \value `val`
    /// \code
    ///     using result = metal::is_number<val>;
    /// \endcode
    ///
    /// \returns: \boolean
    /// \semantics:
    ///     If `val` is a \number, then
    ///     \code
    ///         using result = metal::true_;
    ///     \endcode
    ///     otherwise
    ///     \code
    ///         using result = metal::false_;
    ///     \endcode
    ///
    /// Example
    /// -------
    /// \snippet number.cpp is_number
    ///
    /// See Also
    /// --------
    /// \see number, bool_, int_, char_, size_t, ptrdiff_t
    template<typename val>
    using is_number = typename detail::_is_number<val>::type;

    /// \ingroup number
    /// The standard constructor for \numbers.
    template<typename type, type value>
    using number = std::integral_constant<type, value>;

    /// \ingroup number
    /// The standard constructor for \numbers of type `std::size_t`.
    template<std::size_t value>
    using size_t = metal::number<std::size_t, value>;

    /// \ingroup number
    /// The standard constructor for \numbers of type `std::ptrdiff_t`.
    template<std::size_t value>
    using ptrdiff_t = metal::number<std::ptrdiff_t, value>;

    /// \ingroup number
    /// The standard constructor for \numbers of type `int`.
    template<int value>
    using int_ = metal::number<int, value>;

    /// \ingroup number
    /// The standard constructor for \numbers of type `char`.
    template<char value>
    using char_ = metal::number<char, value>;

    /// \ingroup number
    /// The standard constructor for \booleans.
    template<bool value>
    using bool_ = metal::number<bool, value>;

    /// \ingroup number
    /// The standard representation for the \boolean constant `true`.
    using true_ = bool_<true>;

    /// \ingroup number
    /// The standard representation for the \boolean constant `false`.
    using false_ = bool_<false>;

    namespace detail
    {
        template<typename val>
        struct _is_number :
            false_
        {};

        template<typename type, type value>
        struct _is_number<number<type, value>> :
            true_
        {};
    }
}

#endif
