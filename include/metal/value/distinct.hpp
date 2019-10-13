#ifndef METAL_VALUE_DISTINCT_HPP
#define METAL_VALUE_DISTINCT_HPP

#include "../config.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<class... vals>
        struct _distinct;
    }
    /// \endcond

    /// \ingroup value
    ///
    /// ### Description
    /// Checks whether no \values are identical.
    ///
    /// ### Usage
    /// For any \values `val_0, ..., val_n-1`
    /// \code
    ///     using result = metal::distinct<val_0, ..., val_n-1>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     If at least two \values in `val_0, ..., val_n-1` are identical to
    ///     each other, then
    ///     \code
    ///         using result = metal::false_;
    ///     \endcode
    ///     otherwise
    ///     \code
    ///         using result = metal::true_;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet value.cpp distinct
    ///
    /// ### See Also
    /// \see same
    template<class... vals>
    using distinct = typename detail::_distinct<vals...>::type;
}

#include "../detail/declptr.hpp"
#include "../list/indices.hpp"
#include "../list/list.hpp"
#include "../number/number.hpp"
#include "../value/value.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<class, class base>
        struct inherit_second : base {};

        template<class, class...>
        struct inherit_impl {};

        template<class... _, class... bases>
        struct inherit_impl<list<_...>, bases...>
            : inherit_second<_, bases>... {};

        template<class... bases>
        struct inherit : inherit_impl<indices<list<bases...>>, bases...> {};

        template<class... bases>
        true_ disambiguate(bases*...);

        template<class derived, class... bases>
        auto _distinct_impl(derived* _) -> decltype(
            disambiguate<bases...>((declptr<bases>(), void(), _)...));

        template<class...>
        false_ _distinct_impl(...);

        template<class... vals>
        struct _distinct
            : decltype(
                  _distinct_impl<inherit<maybe<vals>...>, maybe<vals>...>(0)) {
        };
    }
    /// \endcond
}

#endif
