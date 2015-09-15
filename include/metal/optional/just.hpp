// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_OPTIONAL_JUST_HPP
#define METAL_OPTIONAL_JUST_HPP

#include <metal/optional/eval.hpp>
#include <metal/core/voider.hpp>
#include <metal/number/number.hpp>

namespace metal
{
    /// \ingroup optional
    /// \brief ...
    template<typename val>
    struct just
    {
        using type = val;
    };

    /// \ingroup optional
    /// \brief Checks whether an \optional represents some \value.
    ///
    /// Usage
    /// -----
    /// For any \optional `opt`,
    /// \code
    ///     using result = metal::is_just<opt>;
    /// \endcode
    ///
    /// \par Model:
    ///     \number
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
    /// \snippet optional/just.cpp is_just
    ///
    /// See Also
    /// --------
    /// \see is_nothing
    template<typename opt>
    struct is_just;

    /// \ingroup optional
    /// \brief Eager adaptor for \ref is_just.
    template<typename opt>
    using is_just_t = typename metal::is_just<opt>::type;

    namespace detail
    {
        template<typename, typename = void>
        struct is_just_impl :
            boolean<false>
        {};

        template<typename opt>
        struct is_just_impl<opt, voider_t<eval<opt>, int opt::*>> :
            boolean<true>
        {};
    }

    template<typename opt>
    struct is_just :
        detail::is_just_impl<opt>
    {};
}

#endif
