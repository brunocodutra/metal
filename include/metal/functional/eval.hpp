// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_EVAL_HPP
#define METAL_FUNCTIONAL_EVAL_HPP

#include <metal/functional/nothing.hpp>
#include <metal/functional/just.hpp>

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
            template<template<typename...> class e>
            static just<typename e<args...>::type> check(int);

            template<template<typename...> class>
            static nothing check(...);

        public:
            using type = decltype(check<expr>(0));
        };
    }

    /// \ingroup functional
    /// \brief Evaluates an arbitrary \expression `expr`
    /// with \values `args`.
    ///
    /// Usage
    /// -----
    /// For any \expression `expr` and \values `args`,
    /// \code
    ///     using result = metal::eval<expr, args...>;
    /// \endcode
    ///
    /// \par Return Type:
    ///     \optional
    ///
    /// \par Semantics:
    ///     if `expr` is \evaluable with `args`,
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
    /// \see eval_t, is_evaluable, is_strictly_evaluable
    template<template<typename...> class expr, typename... args>
    struct eval :
            detail::eval_impl<expr, args...>::type
    {};

    /// \ingroup functional
    /// \brief Eager adaptor for \ref eval.
    template<template<typename...> class expr, typename... args>
    using eval_t = typename eval<expr, args...>::type;
}

#endif
