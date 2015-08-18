// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_RANGE_HPP
#define METAL_LIST_RANGE_HPP

#include <metal/list/join.hpp>
#include <metal/list/list.hpp>
#include <metal/number/number.hpp>
#include <metal/optional/extract.hpp>

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<typename first, typename last>
    struct range
    {};

    /// \ingroup optional
    /// \brief Eager adaptor for \ref range.
    template<typename first, typename last>
    using range_t = extract<metal::range<first, last>>;

    namespace detail
    {
        template<typename t, t... vs>
        static list<number<t, vs>...> list_numbers();

        template<typename, typename>
        struct offset;

        template<typename o, typename ns>
        using offset_t = extract<offset<o, ns>>;

        template<typename t, t o, template<typename...> class list, t... vs>
        struct offset<number<t, o>, list<number<t, vs>...>> :
                decltype(list_numbers<t, o + vs...>())
        {};
    }

    template<typename f, f fv, typename l, l lv>
    struct range<number<f, fv>, number<l, lv>> :
            range<
                number<extract<std::common_type<f, l>>, fv>,
                number<extract<std::common_type<f, l>>, lv>
            >
    {};

    template<typename t, t f, t l>
    struct range<number<t, f>, number<t, l>> :
            join<
                detail::offset_t<
                    number<t, f>, range_t<number<t, 0>, number<t, (l - f)/2>>
                >,
                detail::offset_t<
                    number<t, f + (l - f)/2>,
                    range_t<number<t, 0>, number<t, l - f - (l - f)/2>>
                >
            >
    {};

    template<typename t, t f>
    struct range<number<t, f>, number<t, f + 1>> :
            list<number<t, f>>
    {};

    template<typename t, t f>
    struct range<number<t, f>, number<t, f - 1>> :
            list<number<t, f>>
    {};

    template<typename t, t f>
    struct range<number<t, f>, number<t, f>> :
            list<>
    {};
}

#endif
