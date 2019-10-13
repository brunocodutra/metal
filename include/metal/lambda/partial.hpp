#ifndef METAL_LAMBDA_PARTIAL_HPP
#define METAL_LAMBDA_PARTIAL_HPP

#include "../config.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<class lbd, class... vals>
        struct _partial;
    }
    /// \endcond

    /// \ingroup lambda
    ///
    /// ### Description
    /// Partially [invokes](\ref invoke) a \lambda with some \values.
    ///
    /// ### Usage
    /// For any \lambda `lbd` and \values `val_0, ..., val_n-1`
    /// \code
    ///     using result = metal::partial<lbd, val_0, ..., val_n-1>;
    /// \endcode
    ///
    /// \returns: \lambda
    /// \semantics:
    ///     If `lbd` holds \expression `f`, then
    ///     \code
    ///         using result = metal::lambda<g>;
    ///     \endcode
    ///     where `g` is an \expression such that
    ///     \code
    ///         template<class... args>
    ///         using g = f<val_0, ..., val_n-1, args...>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet lambda.cpp partial
    ///
    /// ### See Also
    /// \see lambda, invoke, bind, always
    template<class lbd, class... vals>
    using partial = typename detail::_partial<lbd, vals...>::type;
}

#include "../lambda/invoke.hpp"
#include "../lambda/lambda.hpp"
#include "../value/same.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<class lbd, class... leading>
        struct _partial {};

        template<template<class...> class expr, class... leading>
        struct _partial<lambda<expr>, leading...> {
            template<class... trailing>
            using impl = invoke<lambda<expr>, leading..., trailing...>;

            using type = lambda<impl>;
        };

        template<class x>
        struct _partial<lambda<same>, x> {
            template<class y>
            using impl = same<x, y>;

            using type = lambda<impl>;
        };

        template<template<class...> class expr>
        struct _partial<lambda<expr>> {
            using type = lambda<expr>;
        };
    }
    /// \endcond
}

#endif
