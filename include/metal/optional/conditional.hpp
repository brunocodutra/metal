// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_OPTIONAL_CONDITIONAL_HPP
#define METAL_OPTIONAL_CONDITIONAL_HPP

namespace metal
{
    namespace detail
    {
        template<typename if_, typename then, typename... else_>
        struct conditional;
    }

    /// \ingroup optional
    /// Conditionally evaluates \optionals.
    ///
    /// Usage
    /// -----
    /// For any \value `val` and \optional `opt`
    /// \code
    ///     metal::conditional<val, opt>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     Equivalent to
    ///     \code
    ///         template<>
    ///         struct metal::conditional<val, opt>
    ///             metal::conditional<val, opt, metal::nothing>
    ///         {};
    ///     \endcode
    ///
    /// ________________________________________________________________________
    ///
    /// For any \value `val` and \optionals `opt1` and `opt2`
    /// \code
    ///     metal::conditional<val, opt1, opt2>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     If `val` is a \number and `!!val::value == true`, then equivalent to
    ///     \code
    ///         template<>
    ///         struct metal::conditional<val, opt1, opt2>
    ///             metal::optional<opt1>
    ///         {};
    ///     \endcode
    ///     otherwise, if `val` is a \number and `val::value == false`,
    ///     then equivalent to
    ///     \code
    ///         template<>
    ///         struct metal::conditional<val, opt1, opt2>
    ///             metal::optional<opt2>
    ///         {};
    ///     \endcode
    ///     otherwise, equivalent to `metal::nothing`
    ///
    /// ________________________________________________________________________
    ///
    /// For any \values `val1, val2, val3, val4, ..., valn`
    /// \code
    ///     metal::conditional<val1, val2, val3, val4, ..., valn>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     Equivalent to
    ///     \code
    ///         template<>
    ///         struct metal::conditional<val1, val2, val3, val4, ..., valn>
    ///             metal::conditional<val1, val2, metal::conditional<val3, val4, ..., valn>>
    ///         {};
    ///     \endcode
    ///
    /// Example
    /// -------
    /// \snippet optional/conditional.cpp conditional
    ///
    /// See Also
    /// --------
    /// \see number, eval
    template<typename if_, typename then, typename... else_>
    using conditional = detail::conditional<if_, then, else_...>;

    /// \ingroup optional
    /// Eager adaptor for \ref conditional.
    template<typename if_, typename then, typename... else_>
    using conditional_t = typename metal::conditional<if_, then, else_...>::type;
}

#include <metal/optional/optional.hpp>
#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename if_, typename then, typename... else_>
        struct conditional
        {};

        template<
            typename if1, typename then1,
            typename if2, typename then2,
            typename... else_
        >
        struct conditional<if1, then1, if2, then2, else_...> :
            conditional<if1, then1, conditional<if2, then2, else_...>>
        {};

        template<typename if_, typename then>
        struct conditional<if_, then> :
            conditional<if_, then, nothing>
        {};

        template<typename t, t v, typename then, typename else_>
        struct conditional<number<t, v>, then, else_> :
            conditional<boolean<v && true>, then, else_>
        {};

        template<typename then, typename else_>
        struct conditional<boolean<true>, then, else_> :
            optional<then>
        {};

        template<typename then, typename else_>
        struct conditional<boolean<false>, then, else_> :
            optional<else_>
        {};
    }
}

#endif
