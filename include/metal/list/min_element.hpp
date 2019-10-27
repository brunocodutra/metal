#ifndef METAL_LIST_MIN_ELEMENT_HPP
#define METAL_LIST_MIN_ELEMENT_HPP

#include "../config.hpp"
#include "../detail/sfinae.hpp"
#include "../lambda/lambda.hpp"
#include "../number/if.hpp"
#include "../number/less.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<class lbd>
        struct _min_element;
    }
    /// \endcond

    /// \ingroup list
    ///
    /// ### Description
    /// Finds a minimum element in a \list according to an ordering relation.
    ///
    /// \note{The _first_ minimum element is returned if the ordering relation is [strict].}
    /// [strict]:
    /// https://en.wikipedia.org/wiki/Weak_ordering#Strict_weak_orderings
    ///
    /// ### Usage
    /// For any \list `l` and \lambda `lbd`
    /// \code
    ///     using result = metal::min_element<l, lbd>;
    /// \endcode
    ///
    /// \pre: `l` is not empty, and for any two \values `val_i` and `val_j`
    /// contained in `l` `metal::invoke<lbd, val_i, val_j>` returns a \number
    /// \returns: \value
    /// \semantics:
    ///     If `l` contains elements `val_0, ..., val_k, ..., val_m-1`, then
    ///     \code
    ///         using result = val_k;
    ///     \endcode
    ///     where `val_k` is an element in `l` such that
    ///       * `metal::invoke<lbd, val_k, val_j>{} != false` for all `j` in
    ///         `[0, k)` and
    ///       * `metal::invoke<lbd, val_i, val_k>{} == false` for all
    ///         `i` in `(k, m-1]`.
    ///
    /// \tip{TODO `lbd` may be omitted, in which case it defaults to `metal::lambda<metal::less>`.}
    ///
    /// ### Example
    /// \snippet list.cpp min_element
    ///
    /// ### See Also
    /// \see min, sort
    template<class seq, class lbd>
    using min_element = detail::call<
        detail::_min_element<if_<is_lambda<lbd>, lbd>>::template type, seq>;
}

#include "../lambda/apply.hpp"
#include "../lambda/invoke.hpp"
#include "../lambda/partial.hpp"
#include "../value/fold_left.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<class lbd>
        struct _min_element {
            template<class x, class y>
            using custom_min = if_<invoke<lbd, y, x>, y, x>;

            template<class seq>
            using type =
                apply<partial<lambda<fold_left>, lambda<custom_min>>, seq>;
        };
    }
    /// \endcond
}

#endif
