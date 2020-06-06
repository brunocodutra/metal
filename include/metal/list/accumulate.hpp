#ifndef METAL_LIST_ACCUMULATE_HPP
#define METAL_LIST_ACCUMULATE_HPP

#include "../config.hpp"
#include "../detail/sfinae.hpp"
#include "../list/size.hpp"
#include "../number/if.hpp"
#include "../value/same.hpp"

namespace metal {
/// \cond
namespace detail {
    template <class lbd>
    struct _accumulate;
}
/// \endcond

/// \ingroup list
///
/// ### Description
/// Computes the recursive invocation of a binary \lambda with the result of
/// the previous invocation and each element of one or more \lists traversed
/// in parallel from the beginning to the end.
///
/// ### Usage
/// For any \lambda `lbd`, \value `val` and \lists `l_0, ..., l_n-1`
/// \code
///     using result = metal::accumulate<lbd, val, l_0, ..., l_n-1>;
/// \endcode
///
/// \pre: `metal::size<l_0>{} == metal::size<>{}... == metal::size<l_n-1>{}`
/// \returns: \value
/// \semantics:
///     Equivalent to
///     \code
///         using result =
///             lbd(... lbd(lbd(val, l[0]...), l[1]...), ..., l[m-1]...)
///     \endcode
///     where `l[N]...` stands for `l_0[N], ...[N], l_n-1[N]` and
///     `lbd(x, y)` stands for `metal::invoke<lbd, x, y>`.
///
/// ### Example
/// \snippet list.cpp accumulate
///
/// ### See Also
/// \see list, transform, fold_left
template <class lbd, class state, class... seqs>
using accumulate = detail::call<
    if_<same<size<seqs>...>, detail::_accumulate<lbd>>::template type,
    state, seqs...>;
}

#include "../lambda/apply.hpp"
#include "../lambda/partial.hpp"
#include "../list/list.hpp"
#include "../list/transpose.hpp"
#include "../value/fold_left.hpp"

namespace metal {
/// \cond
namespace detail {
    template <class state, class vals>
    struct accumulator_impl {
    };

    template <class state, class... vals>
    struct accumulator_impl<state, list<vals...>> {
        template <template <class...> class expr>
        using type = expr<state, vals...>;
    };

    template <template <class...> class expr>
    struct accumulator {
        template <class state, class vals>
        using type = forward<accumulator_impl<state, vals>::template type, expr>;
    };

    template <class state, class... seqs>
    struct _accumulate_impl {
        template <template <class...> class expr>
        using type = forward<
            _accumulate_impl<state, transpose<list<seqs...>>>::template type,
            accumulator<expr>::template type>;
    };

    template <class state, class... vals>
    struct _accumulate_impl<state, list<vals...>> {
        template <template <class...> class expr>
        using type = fold_left<lambda<expr>, state, vals...>;
    };

    template <class state>
    struct _accumulate_impl<state> {
        template <template <class...> class expr>
        using type = state;
    };

    template <class lbd>
    struct _accumulate {
    };

    template <template <class...> class expr>
    struct _accumulate<lambda<expr>> {
        template <class state, class... seqs>
        using type = forward<_accumulate_impl<state, seqs...>::template type, expr>;
    };
}
/// \endcond
}

#endif
