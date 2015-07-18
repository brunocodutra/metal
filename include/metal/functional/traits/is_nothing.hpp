// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_TRAITS_IS_NOTHING_HPP
#define METAL_FUNCTIONAL_TRAITS_IS_NOTHING_HPP

#include <metal/functional/traits/is_just.hpp>
#include <metal/algebra/logical/not.hpp>

namespace metal
{
    namespace detail
    {
        METAL_DEFINE_NESTED_TYPE_TRAIT(has_type, type);
    }

    /// \ingroup functional_traits
    /// \brief Checks whether an \optional is empty.
    ///
    /// Usage
    /// -----
    /// For any \optional `opt`,
    /// \code
    ///     using result = metal::is_nothing<opt>;
    /// \endcode
    ///
    /// \par Return Type:
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
    /// \snippet functional/traits/is_nothing.cpp main
    ///
    /// See Also
    /// --------
    /// \see is_just
    template<typename opt>
    struct is_nothing :
            not_<is_just<opt>>
    {};

    /// \ingroup functional_traits
    /// \brief Eager adaptor for \ref is_nothing.
    template<typename opt>
    using is_nothing_t = typename is_nothing<opt>::type;
}

#endif
