// Copyright Bruno Dutra 2015-2017
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

        template<typename val>
        struct _as_number;

        using int_ = std::intmax_t;
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
    /// For any integral constant `N`
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
    /// \see number, int_
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
    /// Constructs a \number out of any \value that defines a nested integral
    /// constant `value` convertible to metal::int_.
    ///
    /// ### Usage
    /// For any \value `val`
    /// \code
    ///     using result = metal::as_number<val>;
    /// \endcode
    ///
    /// \returns: \number
    ///
    /// ### Example
    /// \snippet number.cpp as_number
    ///
    /// ### See Also
    /// \see number
    template<typename val>
    using as_number = typename detail::_as_number<val>::type;

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

        template<typename val, typename = std::true_type>
        struct has_enum_value :
            std::false_type
        {};

        template<typename val>
        struct has_enum_value<val,
            typename std::is_enum<decltype(val::value)>::type
        > :
            std::true_type
        {};

        template<typename val>
        struct is_pointer_to_const_integral :
            std::false_type
        {};

        template<typename val>
        struct is_pointer_to_const_integral<val const*> :
            std::is_integral<val>
        {};

        template<typename val, typename = std::true_type>
        struct has_integral_value_impl :
            has_enum_value<val>
        {};

        template<typename val>
        struct has_integral_value_impl<val,
            typename is_pointer_to_const_integral<decltype(&val::value)>::type
        > :
            std::true_type
        {};

        template<typename val>
        struct has_integral_value_impl<val,
            typename std::is_member_pointer<decltype(&val::value)>::type
        > :
            std::false_type
        {};

        template<typename val, typename = std::true_type>
        struct has_integral_value :
            has_integral_value_impl<val>
        {};

        template<typename val>
        struct has_integral_value<val, typename std::is_enum<val>::type> :
            has_enum_value<val>
        {};

        template<typename val, typename = std::true_type>
        struct _as_number_impl
        {};

        template<typename val>
        struct _as_number_impl<val, typename has_integral_value<val>::type>
        {
            using type = number<val::value>;
        };

        template<typename val>
        struct _as_number :
            _as_number_impl<val>
        {};
    }
    /// \endcond
}

#endif
