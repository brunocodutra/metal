// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_DISTINCT_HPP
#define METAL_LIST_DISTINCT_HPP

namespace metal
{
    namespace detail
    {
        template<typename seq>
        struct _distinct;
    }

    /// \ingroup list
    /// ...
    template<typename seq>
    using distinct = typename detail::_distinct<seq>::type;
}

#include <metal/list/list.hpp>
#include <metal/list/indices.hpp>
#include <metal/number/number.hpp>
#include <metal/value/value.hpp>

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
            inherit_second<list<_>, bases>...
        {};

        template<typename... bases>
        struct inherit :
            inherit_impl<indices<list<bases...>>, bases...>
        {};

        template<typename... bases>
        true_ disambiguate(bases*...);

        template<typename derived, typename... bases>
        auto is_unambiguously_derived_from(derived* _) ->
            decltype(disambiguate<bases...>((declptr<bases>(), _)...));

        template<typename...>
        false_ is_unambiguously_derived_from(...);

        template<typename seq>
        struct _distinct
        {};

        template<
            template<typename...> class seq,
            typename... vals
        >
        struct _distinct<seq<vals...>> :
            decltype(
                is_unambiguously_derived_from<
                    inherit<value<vals>...>,
                    value<vals>...
                >(0)
            )
        {};
    }
}

#endif
