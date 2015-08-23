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
    ///     if `expr` is evaluable with `args`, then equivalent to
    ///     \code
    ///         using result = metal::just<expr<args...>::type>
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
    /// \see just, nothing
    template<template<typename...> class expr, typename... args>
    struct eval;

    /// \ingroup expression
    /// \brief Eager adaptor for \ref eval.
    template<template<typename...> class expr, typename... args>
    using eval_t = typename eval<expr, args...>::type;

    namespace detail
    {
        template<template<typename...> class expr, typename... args>
        struct eval_impl
        {
        private:
            template<template<typename...> class e, typename ret = e<args...>>
            static maybe<ret> impl(int);

            template<template<typename...> class>
            static nothing impl(...);

        public:
            using type = decltype(impl<expr>(0));
        };
    }

    template<template<typename...> class expr, typename... args>
    struct eval :
            detail::eval_impl<expr, args...>::type
    {};
}

#endif
