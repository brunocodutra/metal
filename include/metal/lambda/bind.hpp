#ifndef METAL_LAMBDA_BIND_HPP
#define METAL_LAMBDA_BIND_HPP

#include "../config.hpp"

namespace metal {
/// \cond
namespace detail {
    template <class lbd, class... vals>
    struct _bind;
}
/// \endcond

/// \ingroup lambda
///
/// ### Description
/// Provides higher-order composition of \lambdas.
///
/// \tip{Use metal::arg<n> as a placeholder for the n-th argument.}
///
/// ### Usage
/// For any \lambdas `lbd` and `lbd_0, ..., lbd_n-1`
/// \code
///     using result = metal::bind<lbd, lbd_0, ..., lbd_n-1>;
/// \endcode
///
/// \returns: \lambda
/// \semantics:
///     If `lbd` holds \expression `f` and, likewise, `lbd_0, ..., lbd_n-1`
///     hold \expressions `f_0, ..., f_n-1`, then
///     \code
///         using result = metal::lambda<g>;
///     \endcode
///     where `g` is an \expression such that
///     \code
///         template<class... args>
///         using g = f<f_0<args...>, ...<args...>, f_n-1<args...>>;
///     \endcode
///
/// ### Example
/// \snippet lambda.cpp bind
///
/// ### See Also
/// \see lambda, invoke, arg, always
template <class lbd, class... vals>
using bind = typename detail::_bind<lbd, vals...>::type;
}

#include "../detail/sfinae.hpp"
#include "../lambda/lambda.hpp"

namespace metal {
/// \cond
namespace detail {
    template <class... vals>
    struct _bind_impl {
        template <template <class...> class expr, template <class...> class... params>
        using type =
#if defined(METAL_WORKAROUND)
            call<expr, call<params, vals...>...>;
#else
            expr<params<vals...>...>;
#endif
    };

    template <class lbd, class... vals>
    struct _bind {
    };

    template <template <class...> class expr, template <class...> class... params>
    struct _bind<lambda<expr>, lambda<params>...> {
        template <class... vals>
        using impl = forward<_bind_impl<vals...>::template type, expr, params...>;

        using type = lambda<impl>;
    };
}
/// \endcond
}

#endif
