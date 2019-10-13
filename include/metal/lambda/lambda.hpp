#ifndef METAL_LAMBDA_LAMBDA_HPP
#define METAL_LAMBDA_LAMBDA_HPP

#include "../config.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<class val>
        struct _is_lambda;

        template<class val>
        struct _as_lambda;
    }
    /// \endcond

    /// \ingroup lambda
    ///
    /// ### Description
    /// Checks whether some \value is a \lambda.
    ///
    /// ### Usage
    /// For any \value `val`
    /// \code
    ///     using result = metal::is_lambda<val>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     If `val` is a \lambda, then
    ///     \code
    ///         using result = metal::true_;
    ///     \endcode
    ///     otherwise
    ///     \code
    ///         using result = metal::false_;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet lambda.cpp is_lambda
    ///
    /// ### See Also
    /// \see lambda, is_value, is_number, is_pair, is_list, is_map
    template<class val>
    using is_lambda = typename detail::_is_lambda<val>::type;

    /// \ingroup lambda
    ///
    /// ### Description
    /// Given any \value that is a specialization of a template class or union
    /// whose template parameters are all themselves \values, constructs a
    /// \lambda that contains that template.
    ///
    /// ### Usage
    /// For any \value `val`
    /// \code
    ///     using result = metal::as_lambda<val>;
    /// \endcode
    ///
    /// \returns: \lambda
    ///
    /// ### Example
    /// \snippet lambda.cpp as_lambda
    ///
    /// ### See Also
    /// \see lambda, as_list
    template<class val>
    using as_lambda = typename detail::_as_lambda<val>::type;

    /// \ingroup lambda
    ///
    /// ### Description
    /// Constructs a \lambda out of an \expression.
    ///
    /// ### Usage
    /// For any \expression `expr`
    /// \code
    ///     using result = metal::lambda<expr>;
    /// \endcode
    ///
    /// \returns: \lambda
    ///
    /// ### See Also
    /// \see is_lambda
    template<template<class...> class expr>
#if defined(METAL_DOXYGENATING)
    using lambda = struct {
    };
#else
    struct lambda {
    };
#endif
}

#include "../number/number.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<class val>
        struct _is_lambda : false_ {};

        template<template<class...> class expr>
        struct _is_lambda<lambda<expr>> : true_ {};

        template<class val>
        struct _as_lambda {};

        template<template<class...> class expr, class... vals>
        struct _as_lambda<expr<vals...>> {
            using type = lambda<expr>;
        };
    }
    /// \endcond
}

#endif
