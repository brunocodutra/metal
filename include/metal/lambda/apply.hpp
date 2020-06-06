#ifndef METAL_LAMBDA_APPLY_HPP
#define METAL_LAMBDA_APPLY_HPP

#include "../config.hpp"

namespace metal {
/// \cond
namespace detail {
    template <class lbd, class seq>
    struct _apply;
}
/// \endcond

/// \ingroup lambda
///
/// ### Description
/// [Invokes](\ref invoke) a \lambda with the \values contained in a \list.
///
/// ### Usage
/// For any \lambda `lbd` and \list `l`
/// \code
///     using result = metal::apply<lbd, l>;
/// \endcode
///
/// \returns: \value
/// \semantics:
///     If `l` contains elements `l[0], ..., l[m-1]`, then
///     \code
///         using result = metal::invoke<lbd, l[0], ..., l[m-1]>;
///     \endcode
///
/// ### Example
/// \snippet lambda.cpp apply
///
/// ### See Also
/// \see lambda, invoke, list
template <class lbd, class seq>
using apply = typename detail::_apply<lbd, seq>::type;
}

#include "../detail/sfinae.hpp"
#include "../lambda/lambda.hpp"
#include "../list/list.hpp"
#include "../number/number.hpp"
#include "../value/value.hpp"

namespace metal {
/// \cond
namespace detail {
    template <class lbd, class seq, class = true_>
    struct _apply_impl {
    };

    template <template <class...> class expr, class... vals>
    struct _apply_impl<lambda<expr>, list<vals...>, is_value<call<expr, vals...>>> {
        using type = expr<vals...>;
    };

    template <class lbd, class seq>
    struct _apply : _apply_impl<lbd, seq> {
    };
}
/// \endcond
}

#endif
