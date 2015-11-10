// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_OPTIONAL_OPTIONAL_HPP
#define METAL_OPTIONAL_OPTIONAL_HPP

namespace metal
{
    namespace detail
    {
        struct nil;

        template<typename...>
        struct just;

        template<typename val>
        struct just<val>
        {
            using _ = just<val>;
            using type = val;
        };

        template<>
        struct just<>
        {
            using _ = just<>;
        };

        template<>
        struct just<nil> :
            just<>
        {};

        template<typename opt>
        struct is_just;

        template<typename opt>
        struct optional;
    }

    /// \ingroup optional
    /// ...
    template<typename val = detail::nil>
    using just = typename detail::just<val>::_;

    /// \ingroup optional
    /// A model of empty \optional.
    ///
    /// See Also
    /// --------
    /// \see just, is_just
    using nothing = just<>;

    /// \ingroup optional
    /// Checks whether an \optional represents some \value.
    ///
    /// Usage
    /// -----
    /// For any \optional `opt`,
    /// \code
    ///     using result = metal::is_just<opt>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     if `opt::type` well defined and is a model of \value,
    ///     then equivalent to
    ///     \code
    ///         struct result :
    ///             boolean<true>
    ///         {};
    ///     \endcode
    ///     otherwise, equivalent to
    ///     \code
    ///         struct result :
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
    /// Eager adaptor for \ref is_just.
    template<typename opt>
    using is_just_t = typename metal::is_just<opt>::type;

    /// \ingroup optional
    /// ...
    template<typename opt>
    using optional = detail::optional<opt>;
}

#include <metal/number/logical/not.hpp>

#include <type_traits>

namespace metal
{
    namespace detail
    {
        template<typename opt>
        struct is_just :
            not_<typename std::is_base_of<nothing, optional<opt>>::type>
        {};

        template<typename opt, typename ret = just<typename opt::type>>
        ret optional_impl(void (opt::*)(void));

        template<typename>
        nothing optional_impl(...);

        template<typename opt>
        struct optional :
            decltype(optional_impl<opt>(0))
        {};

        template<typename val>
        struct optional<just<val>> :
            just<val>
        {};
    }
}

#endif
