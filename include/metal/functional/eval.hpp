// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_EVAL_HPP
#define METAL_FUNCTIONAL_EVAL_HPP

namespace metal
{
    namespace detail
    {
        template<template<typename...> class expr, typename... args>
        struct eval
        {
        private:
            struct empty {};

            template<template<typename...> class>
            static empty impl(...);
            template<template<typename...> class e, typename = typename e<args...>::type>
            static e<args...> impl(int);

        public:
            using type = decltype(impl<expr>(0));
        };
    }

    template<template<typename...> class expr, typename... args>
    struct eval;

    /// \ingroup functional
    /// \brief Eager adaptor for \ref eval.
    template<template<typename...> class expr, typename... args>
    using eval_t = typename eval<expr, args...>::type;

    /// \ingroup functional
    /// \brief Evaluates an arbitrary expression `expr` with arguments `args`.
    ///
    /// Usage
    /// -----
    /// For any expression `expr` and arguments `args`,
    /// \code
    ///     using result = eval<expr, args...>;
    /// \endcode
    /// \par Return type:
    ///     \ref concept_lazy_value
    /// \par Semantics:
    ///     if `expr` [is evaluable](\ref is_evaluable) with arguments `args`,
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
    /// \snippet eval.cpp eval
    /// \see eval_t, is_evaluable
    template<template<typename...> class expr, typename... args>
    struct eval :
            detail::eval<expr, args...>::type
    {};
}

#endif
