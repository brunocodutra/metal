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
    /// \brief Checks whether an arbitrary expression `expr`
    /// is [evaluable](\ref concept_evaluable_expression)
    /// with arguments `args`.
    ///
    /// Model of
    /// --------
    ///
    /// \ref concept_expression
    ///
    /// Usage
    /// -----
    /// For any expression `expr` and arguments `args`,
    /// \code
    ///     using result = is_evaluable<expr, args...>;
    /// \endcode
    /// \par Return type:
    ///     \ref concept_numerical_value
    /// \par Semantics:
    ///     if `expr` is is [evaluable](\ref concept_evaluable_expression)
    ///     with arguments `args`,
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
    /// \snippet is_evaluable.cpp is_evaluable
    /// \see is_evaluable_t, eval
    template<template<typename...> class expr, typename... args>
    struct is_evaluable :
            not_<is_nil<eval<expr, args...>>>
    {};
}

#endif
