#ifndef METAL_LIST_CARTESIAN_HPP
#define METAL_LIST_CARTESIAN_HPP

#include "../config.hpp"
#include "../lambda/lambda.hpp"
#include "../list/list.hpp"
#include "../value/fold_left.hpp"

namespace metal {
/// \cond
namespace detail {
    template <class, class>
    struct _product;

    template <class seqs, class seq>
    using product = typename _product<seqs, seq>::type;
}
/// \endcond

/// \ingroup list
///
/// ### Description
/// Computes the cartesian product of \lists.
///
/// ### Usage
/// For any \lists `l_0, ..., l_n-1`
/// \code
///     using result = metal::cartesian<l_0, ..., l_n-1>;
/// \endcode
///
/// \returns: \list
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::list<
///             metal::list<l_0[x_0], ...[...], l_n-1[x_n-1]>,
///         >;
///     \endcode
///     where each `x` in `x_0, ..., x_n-1` varies independently from `0` to
///     `n-1`.
///
/// ### Example
/// \snippet list.cpp cartesian
///
/// ### See Also
/// \see list, transpose
template <class... seqs>
using cartesian = fold_left<lambda<detail::product>, list<list<>>, seqs...>;
}

#include "../list/join.hpp"

namespace metal {
/// \cond
namespace detail {
    template <class, class>
    struct _product_impl {
    };

    template <class... xs, class... ys>
    struct _product_impl<list<xs...>, list<ys...>> {
        using type = list<list<xs..., ys>...>;
    };

    template <class seqs, class seq>
    using product_impl = typename _product_impl<seqs, seq>::type;

    template <class, class>
    struct _product {
    };

    template <class... seqs, class... vals>
    struct _product<list<seqs...>, list<vals...>> {
        using type = join<product_impl<seqs, list<vals...>>...>;
    };
}
/// \endcond
}

#endif
