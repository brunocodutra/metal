#ifndef METAL_LAMBDA_TRAIT_HPP
#define METAL_LAMBDA_TRAIT_HPP

#include "../config.hpp"
#include "../lambda/bind.hpp"
#include "../lambda/lambda.hpp"
#include "../number/number.hpp"

namespace metal {
/// \ingroup lambda
///
/// ### Description
/// Constructs a _predicate_ out of a _trait_, that is a \lambda that
/// evaluates to a \number, out of an \expression that defines a nested
/// integral constant `value` convertible to metal::int_.
///
/// ### Usage
/// For any \expression `expr`
/// \code
///     using result = metal::trait<expr>;
/// \endcode
///
/// \returns: \lambda
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::lambda<pred>;
///     \endcode
///     where `pred` is an \expression such that
///     \code
///         template<class... args>
///         using pred = metal::number<expr<args...>::value>;
///     \endcode
///
/// ### Example
/// \snippet lambda.cpp trait
///
/// ### See Also
/// \see lambda, number
template <template <class...> class expr>
using trait = metal::bind<metal::lambda<metal::as_number>, metal::lambda<expr>>;
}

#endif
