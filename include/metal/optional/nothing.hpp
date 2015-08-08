// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_OPTIONAL_NOTHING_HPP
#define METAL_OPTIONAL_NOTHING_HPP

#include <metal/optional/just.hpp>
#include <metal/number/logical/not.hpp>

namespace metal
{
    /// \ingroup optional
    /// \brief A model of empty \optional.
    ///
    /// See Also
    /// --------
    /// \see is_nothing, is_just
    struct nothing {};

    /// \ingroup optional
    /// \brief Checks whether an \optional is empty.
    ///
    /// Usage
    /// -----
    /// For any \optional `opt`,
    /// \code
    ///     using result = metal::is_nothing<opt>;
    /// \endcode
    ///
    /// \par Model:
    ///     \number
    ///
    /// \par Semantics:
    ///     if `opt::type` is undefined, ambiguously defined or is not a model
    ///     of \value, then equivalent to
    ///     \code
    ///         struct result :
    ///             std::true_type
    ///         {};
    ///     \endcode
    ///     otherwise, equivalent to
    ///     \code
    ///         struct result :
    ///             std::false_type
    ///         {};
    ///     \endcode
    ///
    /// Example
    /// -------
    /// \snippet optional/nothing.cpp is_nothing
    ///
    /// See Also
    /// --------
    /// \see is_just
    template<typename opt>
    struct is_nothing :
            not_<is_just_t<opt>>
    {};

    /// \ingroup optional
    /// \brief Eager adaptor for \ref is_nothing.
    template<typename opt>
    using is_nothing_t = typename metal::is_nothing<opt>::type;
}

#endif
