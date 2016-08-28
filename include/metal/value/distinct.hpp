// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_VALUE_DISTINCT_HPP
#define METAL_VALUE_DISTINCT_HPP

#include <metal/config.hpp>

namespace metal
{
    namespace detail
    {
        template<typename... vals>
        struct _distinct;
    }

    /// \ingroup value
    ///
    /// ### Description
    /// Checks whether no \values are identical.
    ///
    /// ### Usage
    /// For any \values `val_1, ..., val_n`
    /// \code
    ///     using result = metal::distinct<val_1, ..., val_n>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     If at least two \values in `val_1, ..., val_n` are identical to
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
    template<typename... vals>
    using distinct = typename detail::_distinct<vals...>::type;
}

#include <metal/value/value.hpp>
#include <metal/list/list.hpp>
#include <metal/list/indices.hpp>
#include <metal/number/number.hpp>

#include <metal/detail/declptr.hpp>

namespace metal
{
    namespace detail
    {
        template<typename, typename base>
        struct inherit_second :
            base
        {};

        template<typename, typename...>
        struct inherit_impl
        {};

        template<typename... _, typename... bases>
        struct inherit_impl<list<_...>, bases...> :
            inherit_second<_, bases>...
        {};

        template<typename... bases>
        struct inherit :
            inherit_impl<indices<list<bases...>>, bases...>
        {};

        template<typename... bases>
        true_ disambiguate(bases*...);

        template<typename derived, typename... bases>
        auto _distinct_impl(derived* _) ->
            decltype(disambiguate<bases...>((declptr<bases>(), void(), _)...));

        template<typename...>
        false_ _distinct_impl(...);

        template<typename... vals>
        struct _distinct :
            decltype(_distinct_impl<inherit<value<vals>...>, value<vals>...>(0))
        {};
    }
}

#endif
