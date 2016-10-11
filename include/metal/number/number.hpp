// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_NUMBER_HPP
#define METAL_NUMBER_NUMBER_HPP

#include <metal/config.hpp>

#include <cstdint>
#include <type_traits>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename val>
        struct _is_number;

        using int_ = std::intmax_t;

        template<int_... vs>
        struct _numbers;
    }
    /// \endcond

    /// \ingroup number
    ///
    /// ### Description
    /// Checks whether some \value is a \number.
    ///
    /// ### Usage
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
    /// ### Example
    /// \snippet number.cpp is_number
    ///
    /// ### See Also
    /// \see number, is_value, is_lambda, is_pair, is_list, is_map
    template<typename val>
    using is_number = typename detail::_is_number<val>::type;

    /// \ingroup number
    ///
    /// ### Description
    /// The underlying integral representation of \numbers.
    ///
    /// ### See Also
    /// \see number
    using int_ = detail::int_;

    /// \ingroup number
    ///
    /// ### Description
    /// Constructs a \number out of an integral value.
    ///
    /// ### Usage
    /// For any integral value `N`
    /// \code
    ///     using result = metal::number<N>;
    /// \endcode
    ///
    /// \returns: \number
    ///
    /// ### See Also
    /// \see int_, true_, false_, is_number
    template<int_ v>
    using number = std::integral_constant<metal::int_, v>;

    /// \ingroup number
    ///
    /// ### Description
    /// The boolean constant `true`.
    ///
    /// ### See Also
    /// \see number
    using true_ = metal::number<true>;

    /// \ingroup number
    ///
    /// ### Description
    /// The boolean constant `false`.
    ///
    /// ### See Also
    /// \see number
    using false_ = metal::number<false>;

    /// \ingroup number
    ///
    /// ### Description
    /// Constructs a \list of \numbers out of a sequence of integral values.
    ///
    /// ### Example
    /// \snippet number.cpp numbers
    ///
    /// ### See Also
    /// \see int_, number, list
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
    /// \cond
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
    /// \endcond
}

#endif
