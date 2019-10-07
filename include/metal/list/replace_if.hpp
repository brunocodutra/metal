#ifndef METAL_LIST_REPLACE_IF_HPP
#define METAL_LIST_REPLACE_IF_HPP

#include "../config.hpp"
#include "../list/transform.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<class, class, class...>
        struct _replace_if;
    }
    /// \endcond

    /// \ingroup list
    ///
    /// ### Description
    /// Replaces every element in a \list that satisfies a predicate by some
    /// \value.
    ///
    /// ### Usage
    /// For any \list `l`, \lambda `lbd` and \values `val_0, ..., val_n-1`
    /// \code
    ///     using result = metal::replace_if<l, lbd, val_0, ..., val_n-1>;
    /// \endcode
    ///
    /// \pre: For any element `l[i]` contained in `l`,
    /// `metal::invoke<lbd, l[i]>` returns a \number
    /// \returns: \list
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::list<...>;
    ///     \endcode
    ///     where `result` contains all and only the elements in `l`, except
    ///     that every element `l[i]` for which
    ///     `metal::invoke<lbd, l[i]>{} != false` has been replaced by
    ///     `val_0, ..., val_n-1`.
    ///
    /// ### Example
    /// \snippet list.cpp replace_if
    ///
    /// ### See Also
    /// \see list, replace, copy_if, remove_if
    template<class seq, class lbd, class... vals>
    using replace_if =
        typename detail::_replace_if<seq, transform<lbd, seq>, vals...>::type;
}

#include "../list/join.hpp"
#include "../list/list.hpp"
#include "../number/if.hpp"
#include "../number/number.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<class vals, class vs, class...>
        struct _replace_if {};

        template<
            class... vals, int_... vs, class x, class y, class... t>
        struct _replace_if<list<vals...>, list<number<vs>...>, x, y, t...> {
            using type = join<if_<number<vs>, list<x, y, t...>, list<vals>>...>;
        };

        template<class... vals, int_... vs, class x>
        struct _replace_if<list<vals...>, list<number<vs>...>, x> {
            using type = list<if_<number<vs>, x, vals>...>;
        };

        template<class... vals, int_... vs>
        struct _replace_if<list<vals...>, list<number<vs>...>> {
            using type = join<if_<number<vs>, list<>, list<vals>>...>;
        };

        template<class x, class y, class... t>
        struct _replace_if<list<>, list<>, x, y, t...> {
            using type = list<>;
        };

        template<class x>
        struct _replace_if<list<>, list<>, x> {
            using type = list<>;
        };

        template<>
        struct _replace_if<list<>, list<>> {
            using type = list<>;
        };
    }
    /// \endcond
}

#endif
