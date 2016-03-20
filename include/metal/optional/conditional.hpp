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
    /// For any \optionals `cond` and `opt1`
    /// \code
    ///     metal::conditional<cond, opt1>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     Equivalent to
    ///     \code
    ///         template<>
    ///         struct conditional<cond, opt1> :
    ///             conditional<cond, opt1, metal::nothing>
    ///         {};
    ///     \endcode
    ///
    /// ________________________________________________________________________
    ///
    /// For any \optionals `cond`, `opt1` and `opt2`
    /// \code
    ///     metal::conditional<cond, opt1, opt2>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     If `cond::type` is a \number and `cond::type::value` is true,
    ///     then equivalent to
    ///     \code
    ///         template<>
    ///         struct conditional<cond, opt1, opt2> :
    ///             optional<opt1>
    ///         {};
    ///     \endcode
    ///     otherwise, if `cond::type` is a \number and `cond::type::value`
    ///     is false, then equivalent to
    ///     \code
    ///         template<>
    ///         struct conditional<cond, opt1, opt2> :
    ///             optional<opt2>
    ///         {};
    ///     \endcode
    ///     otherwise, equivalent to `metal::nothing`
    ///
    /// ________________________________________________________________________
    ///
    /// For any \optionals `opt1, opt2, opt3, opt4, ..., optn`
    /// \code
    ///     metal::conditional<opt1, opt2, opt3, opt4, ..., optn>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     Equivalent to
    ///     \code
    ///         template<>
    ///         struct conditional<opt1, opt2, opt3, opt4, ..., optn> :
    ///             conditional<opt1, opt2, conditional<opt3, opt4, ..., optn>>
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
#include <metal/number/logical/not.hpp>

namespace metal
{
    namespace detail
    {
        template<typename, typename, typename, typename = boolean<true>>
        struct conditional_impl
        {};

        template<typename if_, typename then, typename else_>
        struct conditional_impl<if_, then, else_,
            not_t<not_t<typename if_::type>>
        > :
            optional<then>
        {};

        template<typename if_, typename then, typename else_>
        struct conditional_impl<if_, then, else_,
            not_t<typename if_::type>
        > :
            optional<else_>
        {};

        template<typename if_, typename then, typename... else_>
        struct conditional
        {};

        template<
            typename if1, typename then1,
            typename if2, typename then2,
            typename... else_
        >
        struct conditional<if1, then1, if2, then2, else_...> :
            conditional_impl<if1, then1, conditional<if2, then2, else_...>>
        {};

        template<typename if_, typename then, typename else_>
        struct conditional<if_, then, else_> :
            conditional_impl<if_, then, else_>
        {};

        template<typename if_, typename then>
        struct conditional<if_, then> :
            conditional_impl<if_, then, nothing>
        {};
    }
}

#endif
