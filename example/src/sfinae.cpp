// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "example.hpp"

#include <array>
#include <chrono>
#include <tuple>
#include <type_traits>
#include <utility>

#include <boost/hana/config.hpp>

#if defined(METAL_COMPAT_MODE)
#   define SKIP
#endif

#if defined(BOOST_HANA_CONFIG_GCC) && \
    BOOST_HANA_CONFIG_GCC < BOOST_HANA_CONFIG_VERSION(5, 4, 0)
#   define SKIP
#endif

#if defined(BOOST_HANA_CONFIG_CLANG) && \
    BOOST_HANA_CONFIG_CLANG < BOOST_HANA_CONFIG_VERSION(3, 5, 0)
#   define SKIP
#endif

#if !defined(SKIP)

#include <boost/hana/ext/std/tuple.hpp>
#include <boost/hana/transform.hpp>
#include <boost/hana/type.hpp>
#include <boost/hana/unpack.hpp>
#include <boost/hana/zip.hpp>

/// [make_array]
template<typename... Xs,
    typename R = std::array<std::common_type_t<Xs...>, sizeof...(Xs)>
>
constexpr R make_array(Xs&&... xs) {
    return R{{std::forward<Xs>(xs)...}};
}
/// [make_array]

/// [common_tuple_t]
template<typename... Ts>
using common_tuple_t = metal::apply<
    std::common_type_t<metal::lambda<std::tuple>, metal::as_lambda<Ts>...>,
    metal::transform<metal::lambda<std::common_type_t>, metal::as_list<Ts>...>
>;
/// [common_tuple_t]

/// [make_array_of_tuples]
template<typename Head, typename... Tail,
    typename R = std::array<
        common_tuple_t<std::decay_t<Head>, std::decay_t<Tail>...>,
        1 + sizeof...(Tail)
    >
>
constexpr R make_array(Head&& head, Tail&&... tail) {
    return R{{std::forward<Head>(head), std::forward<Tail>(tail)...}};
}
/// [make_array_of_tuples]

/// [array_of_tuples]
using namespace std::chrono;
using namespace std::literals::chrono_literals;

IS_SAME(
    decltype(
        make_array(
            std::make_tuple(42ns, 0x42, 42.f),
            std::make_tuple(42us, 042L, 42.L),
            std::make_tuple(42ms, 42LL, 42.0)
        )
    ),
    std::array<std::tuple<nanoseconds, long long, long double>, 3>
);
/// [array_of_tuples]

/// [array_of_numbers]
IS_SAME(decltype(make_array(42, 42L, 42LL)), std::array<long long, 3>);
/// [array_of_numbers]

/// [naive_common_tuple_t]
template<typename... Ts>
using naive_common_tuple_t = typename decltype(
    boost::hana::unpack(
        boost::hana::zip_with(
            boost::hana::template_<std::common_type_t>,
            boost::hana::zip_with(boost::hana::decltype_, std::declval<Ts>())...
        ),
        boost::hana::template_<std::tuple>
    )
)::type;
/// [naive_common_tuple_t]

namespace {
/// [naive_make_array_of_tuples]
template<typename... Xs,
    typename R = std::array<std::common_type_t<Xs...>, sizeof...(Xs)>
>
constexpr R make_array(Xs&&... xs) {
    return R{{std::forward<Xs>(xs)...}};
}

template<typename Head, typename... Tail,
    typename R = std::array<
        naive_common_tuple_t<std::decay_t<Head>, std::decay_t<Tail>...>,
        1 + sizeof...(Tail)
    >
>
constexpr R make_array(Head&& head, Tail&&... tail) {
    return R{{std::forward<Head>(head), std::forward<Tail>(tail)...}};
}
/// [naive_make_array_of_tuples]
}

using x = std::tuple<nanoseconds, int, float>;
using y = std::tuple<microseconds, long, long double>;
using z = std::tuple<milliseconds, long long, double>;

using common_tuple = std::tuple<
    std::common_type_t<nanoseconds, microseconds, milliseconds>,
    std::common_type_t<int, long, long long>,
    std::common_type_t<float, long double, double>
>;

IS_SAME(common_tuple_t<x, y, z>, common_tuple);
IS_SAME(naive_common_tuple_t<x, y, z>, common_tuple);

#endif
