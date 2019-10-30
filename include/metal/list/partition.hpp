#ifndef METAL_LIST_PARTITION_HPP
#define METAL_LIST_PARTITION_HPP

#include "../config.hpp"
#include "../detail/sfinae.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<class lbd>
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
    using partition = detail::call<detail::_partition<lbd>::template type, seq>;
}

#include "../list/join.hpp"
#include "../list/list.hpp"
#include "../list/transform.hpp"
#include "../number/number.hpp"
#include "../pair/pair.hpp"

namespace metal {
    /// \cond
    namespace detail {

        template<bool>
        struct _partition_filter {};

        template<>
        struct _partition_filter<true> {
            template<class val>
            using type = list<val>;
        };

        template<>
        struct _partition_filter<false> {
            template<class val>
            using type = list<>;
        };

        template<class conds, class seq>
        struct _partition_impl {};

        template<int_... ns, class... vals>
        struct _partition_impl<list<number<ns>...>, list<vals...>> {
#if defined(METAL_WORKAROUND)
            using type = pair<
                join<call<_partition_filter<!!ns>::template type, vals>...>,
                join<call<_partition_filter<!ns>::template type, vals>...>>;
#else
            using type = pair<
                join<typename _partition_filter<!!ns>::template type<vals>...>,
                join<typename _partition_filter<!ns>::template type<vals>...>>;
#endif
        };

        template<class lbd>
        struct _partition {
            template<class seq>
            using type =
                typename _partition_impl<transform<lbd, seq>, seq>::type;
        };
    }
    /// \endcond
}

#endif
