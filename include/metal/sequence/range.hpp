// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_SEQUENCE_RANGE_HPP
#define METAL_SEQUENCE_RANGE_HPP

#include <metal/sequence/join.hpp>
#include <metal/sequence/list.hpp>
#include <metal/number/number.hpp>
#include <metal/optional/extract.hpp>

#if defined(_MSC_VER)
#include <metal/number/arithmetic/add.hpp>
#endif

namespace metal
{
    /// \ingroup sequence
    /// \brief ...
    template<typename first, typename last>
    struct range;

    /// \ingroup optional
    /// \brief Eager adaptor for \ref range.
    template<typename first, typename last>
    using range_t = typename metal::range<first, last>::type;

    namespace detail
    {
        template<typename, typename>
        struct offset;

        template<typename o, typename ns>
        using offset_t = typename offset<o, ns>::type;

        template<typename o, template<typename...> class list>
        struct offset<o, list<>> :
                list<>
        {};

#if !defined(_MSC_VER)
        template<
            typename ot, ot ov,
            template<typename...> class list,
            typename ts, ts... vs
        >
        struct offset<number<ot, ov>, list<number<ts, vs>...>> :
                list<number<ts, ov + vs>...>
        {};
#else
        template<typename o, template<typename...> class list, typename... ns>
        struct offset<o, list<ns...>> :
                list<add_t<o, ns>...>
        {};
#endif
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
