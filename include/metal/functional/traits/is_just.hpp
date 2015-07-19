// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_TRAITS_IS_JUST_HPP
#define METAL_FUNCTIONAL_TRAITS_IS_JUST_HPP

#include <metal/detail/introspection.hpp>

namespace metal
{
    /// \ingroup functional_traits
    /// \brief Checks whether an \optional has some value.
    ///
    /// Usage
    /// -----
    /// For any \optional `opt`,
    /// \code
    ///     using result = metal::is_just<opt>;
    /// \endcode
    ///
    /// \par Return Type:
    ///     \number
    ///
    /// \par Semantics:
    ///     if `opt::type` well defined defined and is a model of \value,
    ///     then equivalent to
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
    /// \snippet functional/traits/is_just.cpp main
    ///
    /// See Also
    /// --------
    /// \see is_nil
    template<typename opt>
    struct is_just;

    METAL_DEFINE_NESTED_TYPE_TRAIT(is_just, type);

    /// \ingroup functional_traits
    /// \brief Eager adaptor for \ref is_just.
    template<typename opt>
    using is_just_t = typename is_just<opt>::type;
}

#endif
