// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_OPTIONAL_COND_HPP
#define METAL_OPTIONAL_COND_HPP

namespace metal
{
    namespace detail
    {
        template<typename if_, typename then, typename... else_>
        struct cond;
    }

    /// \ingroup optional
    /// Conditionally evaluates \optionals.
    ///
    /// Usage
    /// -----
    /// For any \optionals `cond` and `opt1`
    /// \code
    ///     metal::cond<cond, opt1>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     Equivalent to
    ///     \code
    ///         template<>
    ///         struct cond<cond, opt1> :
    ///             cond<cond, opt1, metal::nothing>
    ///         {};
    ///     \endcode
    ///
    /// ________________________________________________________________________
    ///
    /// For any \optionals `cond`, `opt1` and `opt2`
    /// \code
    ///     metal::cond<cond, opt1, opt2>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     If `cond::type` is a \number and `cond::type::value` is true,
    ///     then equivalent to
    ///     \code
    ///         template<>
    ///         struct cond<cond, opt1, opt2> :
    ///             optional<opt1>
    ///         {};
    ///     \endcode
    ///     otherwise, if `cond::type` is a \number and `cond::type::value`
    ///     is false, then equivalent to
    ///     \code
    ///         template<>
    ///         struct cond<cond, opt1, opt2> :
    ///             optional<opt2>
    ///         {};
    ///     \endcode
    ///     otherwise, equivalent to `metal::nothing`
    ///
    /// ________________________________________________________________________
    ///
    /// For any \optionals `opt1, opt2, opt3, opt4, ..., optn`
    /// \code
    ///     metal::cond<opt1, opt2, opt3, opt4, ..., optn>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     Equivalent to
    ///     \code
    ///         template<>
    ///         struct cond<opt1, opt2, opt3, opt4, ..., optn> :
    ///             cond<opt1, opt2, cond<opt3, opt4, ..., optn>>
    ///         {};
    ///     \endcode
    ///
    /// Example
    /// -------
    /// \snippet optional/cond.cpp cond
    ///
    /// See Also
    /// --------
    /// \see number, eval
    template<typename if_, typename then, typename... else_>
    using cond = detail::cond<if_, then, else_...>;

    /// \ingroup optional
    /// Eager adaptor for metal::cond.
    template<typename if_, typename then, typename... else_>
    using cond_t = typename metal::cond<if_, then, else_...>::type;
}

#include <metal/optional/optional.hpp>
#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename, typename, typename, typename = boolean<true>>
        struct conditional_impl
        {};

        template<typename if_, typename then, typename else_>
        struct conditional_impl<if_, then, else_,
            boolean<!!if_::type::value>
        > :
            optional<then>
        {};

        template<typename if_, typename then, typename else_>
        struct conditional_impl<if_, then, else_,
            boolean<!if_::type::value>
        > :
            optional<else_>
        {};

        template<typename if_, typename then, typename... else_>
        struct cond
        {};

        template<
            typename if1, typename then1,
            typename if2, typename then2,
            typename... else_
        >
        struct cond<if1, then1, if2, then2, else_...> :
            conditional_impl<if1, then1, cond<if2, then2, else_...>>
        {};

        template<typename if_, typename then, typename else_>
        struct cond<if_, then, else_> :
            conditional_impl<if_, then, else_>
        {};

        template<typename if_, typename then>
        struct cond<if_, then> :
            conditional_impl<if_, then, nothing>
        {};
    }
}

#endif
