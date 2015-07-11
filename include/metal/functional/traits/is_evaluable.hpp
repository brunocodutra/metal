// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_TRAITS_IS_EVALUABLE_HPP
#define METAL_FUNCTIONAL_TRAITS_IS_EVALUABLE_HPP

#include <metal/functional/eval.hpp>
#include <metal/functional/traits/is_nil.hpp>
#include <metal/algebra/logical/not.hpp>

namespace metal
{
    template<template<typename...> class expr, typename... args>
    struct is_evaluable;

    /// \ingroup functional_traits
    /// \brief Eager adaptor for is_evaluable.
    template<template<typename...> class expr, typename... args>
    using is_evaluable_t = typename is_evaluable<expr, args...>::type;

    /// \ingroup functional_traits
    /// \brief Checks whether an arbitrary \ref concept_expression `expr`
    /// is evaluable with [Values](\ref concept_value) `args`.
    ///
    /// Usage
    /// -----
    /// For any \ref concept_expression `expr` and
    /// [Values](\ref concept_value) `args`,
    /// \code
    ///     using result = metal::is_evaluable<expr, args...>;
    /// \endcode
    /// \par Model:
    ///     \ref concept_numerical_value
    /// \par Semantics:
    ///     if `expr<args...>` is not nil, then equivalent to
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
    /// \snippet functional/traits/is_evaluable.cpp main
    ///
    /// See Also
    /// --------
    /// \see is_evaluable_t, eval
    template<template<typename...> class expr, typename... args>
    struct is_evaluable :
            not_<is_nil<eval<expr, args...>>>
    {};
}

#endif
