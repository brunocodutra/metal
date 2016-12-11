// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_IOTA_HPP
#define METAL_NUMBER_IOTA_HPP

#include <metal/config.hpp>

#include <metal/number/number.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename, typename, typename>
        struct _iota;
    }
    /// \endcond

    /// \ingroup list
    ///
    /// ### Description
    /// Generates a sequence of \numbers.
    ///
    /// ### Usage
    /// For any \numbers `st`, `sz` and `sd`
    /// \code
    ///     using result = metal::iota<st, sz, sd>;
    /// \endcode
    ///
    /// \returns: \list
    /// \semantics:
    ///     If `sz` is positive, then
    ///     \code
    ///         using result = metal::numbers<
    ///             st{}, st{} + sd{}, ..., st{} + (sz{} - 1)*sd{}
    ///         >;
    ///     \endcode
    ///     otherwise, if `sz` is negative, then
    ///     \code
    ///         using result = metal::numbers<
    ///             st{}, st{} - sd{}, ..., st{} - (1 - sz{})*sd{}
    ///         >;
    ///     \endcode
    ///     otherwise
    ///     \code
    ///         using result = metal::numbers<>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet list.cpp iota
    ///
    /// ### See Also
    /// \see numbers
    template<typename start, typename size, typename stride = number<1>>
    using iota = typename detail::_iota<start, size, stride>::type;
}

#include <metal/list/list.hpp>

#include <utility>

#if defined(__has_builtin)
#   if __has_builtin(__make_integer_seq)
#       define METAL_USE_BUILTIN_MAKE_INTEGER_SEQ
#   endif
#endif

namespace metal
{
    /// \cond
    namespace detail
    {
        template<int_... vs>
        using integer_sequence = std::integer_sequence<int_, vs...>;

#if defined(METAL_USE_BUILTIN_MAKE_INTEGER_SEQ)
        template<int_ n>
        using make_integer_sequence =
            __make_integer_seq<std::integer_sequence, int_, n>;
#else
        template<int_ n>
        using make_integer_sequence = std::make_integer_sequence<int_, n>;
#endif

        template<typename, int_ a, int_ b>
        struct _stretch
        {};

        template<int_... vs, int_ a, int_ b>
        struct _stretch<integer_sequence<vs...>, a, b>
        {
            using type = numbers<(b + a*vs)...>;
        };

        template<typename, typename, typename>
        struct _iota
        {};

        template<int_ st, int_ sz, int_ sd>
        struct _iota<number<st>, number<sz>, number<sd>> :
            _stretch<
                make_integer_sequence<(sz < 0) ? (0 - sz) : sz>,
                (sz < 0) ? (0 - sd) : sd,
                st
            >
        {};
    }
    /// \endcond
}

#endif
