// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_OPTIONAL_JUST_HPP
#define METAL_OPTIONAL_JUST_HPP

#include <metal/detail/nil.hpp>

namespace metal
{
    namespace detail
    {
        template<typename val>
        struct just;

        template<typename opt>
        struct is_just;
    }

    /// \ingroup optional
    /// Constructs an \optional.
    ///
    /// Usage
    /// -----
    /// \code
    ///     metal::just<>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     Equivalent to
    ///     \code
    ///         template<>
    ///         struct just<>
    ///         {};
    ///     \endcode
    ///
    /// ________________________________________________________________________
    ///
    /// For any \value `val`
    /// \code
    ///     metal::just<val>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     Equivalent to
    ///     \code
    ///         template<>
    ///         struct just<val>
    ///         {
    ///             using type = val;
    ///         };
    ///     \endcode
    ///
    /// Example
    /// -------
    /// \snippet optional/optional.cpp just
    ///
    /// See Also
    /// --------
    /// \see nothing, is_just
    template<typename val = detail::nil>
    using just = detail::just<val>;

    /// \ingroup optional
    /// A model of empty \optional.
    ///
    /// See Also
    /// --------
    /// \see just, is_just
    using nothing = metal::just<>;

    /// \ingroup optional
    /// Checks whether an \optional represents some \value.
    ///
    /// Usage
    /// -----
    /// For any \optional `opt`
    /// \code
    ///     metal::is_just<opt>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     If `opt::type` is well defined and is a \value,
    ///     then equivalent to
    ///     \code
    ///         template<>
    ///         struct is_just<opt> :
    ///             boolean<true>
    ///         {};
    ///     \endcode
    ///     otherwise, equivalent to
    ///     \code
    ///         template<>
    ///         struct is_just<opt> :
    ///             boolean<false>
    ///         {};
    ///     \endcode
    ///
    /// Example
    /// -------
    /// \snippet optional/optional.cpp is_just
    ///
    /// See Also
    /// --------
    /// \see just, nothing
    template<typename opt>
    using is_just = detail::is_just<opt>;

    /// \ingroup optional
    /// Eager adaptor for metal::is_just.
    template<typename opt>
    using is_just_t = typename metal::is_just<opt>::type;
}

#include <metal/number/logical/not.hpp>

#include <metal/detail/void.hpp>

namespace metal
{
    namespace detail
    {
        template<typename val>
        struct just
        {
            using type = val;
        };

        template<>
        struct just<nil>
        {};

        template<typename opt, typename = void>
        struct is_just_impl :
            boolean<false>
        {};

        template<typename opt>
        struct is_just_impl<opt, void_t<typename opt::type>> :
            boolean<true>
        {};

        template<typename opt>
        struct is_just :
            is_just_impl<opt>
        {};
    }
}

#endif
