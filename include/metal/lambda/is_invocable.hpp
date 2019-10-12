#ifndef METAL_LAMBDA_IS_INVOCABLE_HPP
#define METAL_LAMBDA_IS_INVOCABLE_HPP

#include "../config.hpp"
#include "../detail/sfinae.hpp"
#include "../lambda/invoke.hpp"
#include "../value/same.hpp"

#include <type_traits>

namespace metal {
    /// \ingroup lambda
    ///
    /// ### Description
    /// Checks whether a \lambda is [invocable](\ref invoke) with some \values.
    ///
    /// ### Usage
    /// For any \lambda `lbd` and \values `val_0, ..., val_n-1`
    /// \code
    ///     using result = metal::is_invocable<lbd, val_0, ..., val_n-1>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     If `lbd` holds \expression `expr`, and `expr<val_0, ..., val_n-1>`
    ///     is well defined after template substitution, then
    ///     \code
    ///         using result = metal::true_;
    ///     \endcode
    ///     otherwise
    ///     \code
    ///         using result = metal::false_;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet lambda.cpp is_invocable
    ///
    /// ### See Also
    /// \see lambda, invoke
    template<class lbd, class... vals>
    using is_invocable = same<
        std::false_type,
        typename std::is_base_of<
            value<>, detail::caller<invoke, lbd, vals...>>::type>;
}

#endif
