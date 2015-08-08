// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_EXPRESSION_EVAL_HPP
#define METAL_EXPRESSION_EVAL_HPP

#include <metal/optional/nothing.hpp>
#include <metal/optional/maybe.hpp>

namespace metal
{
    /// \ingroup expression
    /// \brief Lazily evaluates an arbitrary \expression `expr`
    ///  with \values `args`.
    ///
    /// Usage
    /// -----
    /// For any \expression `expr` and \values `args`,
    /// \code
    ///     using result = metal::eval<expr, args...>;
    /// \endcode
    ///
    /// \par Model:
    ///     \optional
    ///
    /// \par Semantics:
    ///     if `expr` is \evaluable with `args`, then equivalent to
    ///     \code
    ///         using result = metal::maybe<expr<args...>>
    ///     \endcode
    ///     otherwise, equivalent to
    ///     \code
    ///         using result = metal::nothing;
    ///     \endcode
    ///
    /// Example
    /// -------
    /// \snippet expression/eval.cpp eval
    ///
    /// See Also
    /// --------
    /// \see eval_t, is_evaluable, maybe, nothing
    template<template<typename...> class expr, typename... args>
    struct eval;

    /// \ingroup expression
    /// \brief Eager adaptor for \ref eval.
    template<template<typename...> class expr, typename... args>
    using eval_t = typename eval<expr, args...>::type;

    /// \ingroup expression
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
    /// \par Model:
    ///     \number
    ///
    /// \par Semantics:
    ///     if `expr<args...>` is well defined and \just some \value,
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
    /// \snippet expression/eval.cpp is_evaluable
    ///
    /// See Also
    /// --------
    /// \see is_evaluable_t, eval, is_just, is_nothing
    template<template<typename...> class expr, typename... args>
    struct is_evaluable;

    /// \ingroup expression
    /// \brief Eager adaptor for \ref is_evaluable.
    template<template<typename...> class expr, typename... args>
    using is_evaluable_t = typename is_evaluable<expr, args...>::type;

    namespace detail
    {
        template<template<typename...> class expr, typename... args>
        struct eval_impl
        {
        private:
            template<template<typename...> class e, typename ret = e<args...>>
            static maybe<ret> check(int);

            template<template<typename...> class>
            static nothing check(...);

        public:
            using type = decltype(check<expr>(0));
        };
    }

    template<template<typename...> class expr, typename... args>
    struct eval :
            detail::eval_impl<expr, args...>::type
    {};

    template<template<typename...> class expr, typename... args>
    struct is_evaluable :
            is_just<eval<expr, args...>>
    {};
}

#endif
