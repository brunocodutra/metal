// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_EVAL_HPP
#define METAL_FUNCTIONAL_EVAL_HPP

#include <metal/functional/nil.hpp>
#include <metal/functional/identity.hpp>

#include <type_traits>

namespace metal
{
    namespace detail
    {
        template<
            template<typename...> class expr,
            typename... args
        >
        struct eval_impl
        {
        private:
            template<typename> struct type_wrapper;

            template<
                template<typename...> class e,
                typename = type_wrapper<typename e<args...>::type>
            >
            static typename std::conditional<
                std::is_class<e<args...>>::value,
                e<args...>,
                nil
            >::type check(int);

            template<template<typename...> class>
            static nil check(...);

        public:
            using type = decltype(check<expr>(0));
        };
    }

    template<template<typename...> class expr, typename... args>
    struct eval;

    /// \ingroup functional
    /// \brief Eager adaptor for \ref eval.
    template<template<typename...> class expr, typename... args>
    using eval_t = typename eval<expr, args...>::type;

    /// \ingroup functional
    /// \brief Evaluates an arbitrary \ref concept_expression `expr`
    /// with [Values](\ref concept_value) `args`.
    ///
    /// Usage
    /// -----
    /// For any \ref concept_expression `expr` and
    /// [Values](\ref concept_value) `args`,
    /// \code
    ///     using result = eval<expr, args...>;
    /// \endcode
    /// \par Model:
    ///     \ref concept_nullable_value
    /// \par Semantics:
    ///     if `expr` [is evaluable](\ref is_evaluable) with `args`,
    ///     then equivalent to
    ///     \code
    ///         struct result :
    ///             expr<args...>
    ///         {};
    ///     \endcode
    ///     otherwise, equivalent to
    ///     \code
    ///         struct result {};
    ///     \endcode
    ///
    /// Example
    /// -------
    /// \snippet functional/eval.cpp main
    ///
    /// See Also
    /// --------
    /// \see eval_t, is_evaluable
    template<template<typename...> class expr, typename... args>
    struct eval :
            detail::eval_impl<expr, args...>::type
    {};
}

#endif
