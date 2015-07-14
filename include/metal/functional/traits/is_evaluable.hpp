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
    /// \ingroup functional_traits
    /// \brief Checks whether an arbitrary \expression `expr`
    /// is evaluable with \values `args`.
    ///
    /// Usage
    /// -----
    /// For any \expression `expr` and \values `args`,
    /// \code
    ///     using result = metal::is_evaluable<expr, args...>;
    /// \endcode
    ///
    /// \par Return Type:
    ///     \number
    ///
    /// \par Semantics:
    ///     if `expr<args...>` is well defined and not \nil, then equivalent to
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
    /// \see is_evaluable_t, is_strictly_evaluable, is_nil, eval
    template<template<typename...> class expr, typename... args>
    struct is_evaluable :
            not_<is_nil<eval<expr, args...>>>
    {};

    /// \ingroup functional_traits
    /// \brief Eager adaptor for \ref is_evaluable.
    template<template<typename...> class expr, typename... args>
    using is_evaluable_t = typename is_evaluable<expr, args...>::type;
}

#endif
