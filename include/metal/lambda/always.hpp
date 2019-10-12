#ifndef METAL_LAMBDA_ALWAYS_HPP
#define METAL_LAMBDA_ALWAYS_HPP

#include "../config.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<class val>
        struct _always;
    }
    /// \endcond

    /// \ingroup lambda
    ///
    /// ### Description
    /// Lifts a \value to an n-ary \lambda that always evaluates to that \value,
    /// regardless of the argument(s) it's [invoked](\ref invoke) with.
    ///
    /// ### Usage
    /// For any and \value `val`
    /// \code
    ///     using result = metal::always<val>;
    /// \endcode
    ///
    /// \returns: \lambda
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::lambda<expr>;
    ///     \endcode
    ///     where `expr` is an \expression such that
    ///     \code
    ///         template<class...>
    ///         using expr = val;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet lambda.cpp always
    ///
    /// ### See Also
    /// \see lambda, invoke, partial, bind
    template<class val>
    using always = typename detail::_always<val>::type;
}

#include "../lambda/lambda.hpp"
#include "../value/identity.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<class val>
        struct _always {
            template<class...>
            using impl = identity<val>;

            using type = lambda<impl>;
        };
    }
    /// \endcond
}

#endif
