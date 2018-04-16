#ifndef METAL_LAMBDA_INVOKE_HPP
#define METAL_LAMBDA_INVOKE_HPP

#include "../config.hpp"
#include "../lambda/apply.hpp"
#include "../list/list.hpp"

namespace metal {
    /// \ingroup lambda
    ///
    /// ### Description
    /// Invokes a \lambda with the given \values as arguments.
    ///
    /// ### Usage
    /// For any \lambda `lbd` and \values `val_0, ..., val_n-1`
    /// \code
    ///     using result = metal::invoke<lbd, val_0, ..., val_n-1>;
    /// \endcode
    ///
    /// \returns: \value
    /// \semantics:
    ///     If `lbd` holds \expression `expr`, then
    ///     \code
    ///         using result = expr<val_0, ..., val_n-1>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet lambda.cpp invoke
    ///
    /// ### See Also
    /// \see lambda, is_invocable
    template<typename lbd, typename... vals>
    using invoke = metal::apply<lbd, metal::list<vals...>>;
}

#endif
