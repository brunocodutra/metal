// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_NUMBER_HPP
#define METAL_NUMBER_NUMBER_HPP

#include <cstdint>
#include <type_traits>

namespace metal
{
    /// \ingroup number
    /// The underlying integral representation of \numbers.
    using int_ = intmax_t;

    namespace detail
    {
        template<typename val>
        struct _is_number;

        template<int_... vs>
        struct _numbers;
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
    /// \returns: \number
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
    /// \see number, true_, false_
    template<typename val>
    using is_number = typename detail::_is_number<val>::type;

    /// \ingroup number
    /// Constructs a \number out of an integral value.
    template<int_ v>
    using number = std::integral_constant<metal::int_, v>;

    /// \ingroup number
    /// The boolean constant `true`.
    using true_ = metal::number<true>;

    /// \ingroup number
    /// The boolean constant `false`.
    using false_ = metal::number<false>;

    /// \ingroup number
    /// Constructs a list of \numbers out of a possibly empty sequence of
    /// integral values.
    template<int_... vs>
    using numbers =
#if defined(METAL_DOXYGENATING)
        metal::list<metal::number<vs>...>;
#else
        typename detail::_numbers<vs...>::type;
#endif
}

#include <metal/list/list.hpp>

namespace metal
{
    namespace detail
    {
        template<typename val>
        struct _is_number :
            false_
        {};

        template<int_ value>
        struct _is_number<number<value>> :
            true_
        {};

        template<int_... vs>
        struct _numbers
        {
            using type = list<number<vs>...>;
        };
    }
}

#endif
