#ifndef METAL_LIST_PARTITION_HPP
#define METAL_LIST_PARTITION_HPP

#include "../config.hpp"
#include "../list/transform.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<class conds, class seq>
        struct _partition;
    }
    /// \endcond

    /// \ingroup list
    ///
    /// ### Description
    /// Splits a \list in two according to a predicate.
    ///
    /// ### Usage
    /// For any \list `l` and \lambda `lbd`
    /// \code
    ///     using result = metal::partition<l, lbd>;
    /// \endcode
    ///
    /// \pre: For any element `l[i]` contained in `l`,
    /// `metal::invoke<lbd, l[i]>` returns a \number
    /// \returns: \pair
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::pair<l_1, l_2>;
    ///     \endcode
    ///     where `l_1` contains all and only the elements `l[i]` in `l` for
    ///     which `metal::invoke<lbd, l[i]>{} != false` and `l_2` contains the
    ///     remaining elements.
    ///
    /// ### Example
    /// \snippet list.cpp partition
    ///
    /// ### See Also
    /// \see list, copy_if, remove_if
    template<class seq, class lbd>
    using partition =
        typename detail::_partition<transform<lbd, seq>, seq>::type;
}

#include "../lambda/lambda.hpp"
#include "../list/join.hpp"
#include "../list/list.hpp"
#include "../number/if.hpp"
#include "../number/number.hpp"
#include "../pair/pair.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<class conds, class seq>
        struct _partition {};

        template<int_... ns, class... vals>
        struct _partition<list<number<ns>...>, list<vals...>> {
            using type = pair<
                join<if_<number<ns>, list<vals>, list<>>...>,
                join<if_<number<ns>, list<>, list<vals>>...>>;
        };
    }
    /// \endcond
}

#endif
