// Copyright Bruno Dutra 2015-2018
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "example.hpp"

#if !defined(METAL_WORKAROUND)

#include <array>
#include <chrono>
#include <complex>
#include <tuple>
#include <type_traits>
#include <utility>

/// [make_array]
template<typename... Xs,
    typename R = std::array<std::common_type_t<Xs...>, sizeof...(Xs)>
>
constexpr R make_array(Xs&&... xs) {
    return R{{std::forward<Xs>(xs)...}};
}
/// [make_array]

/// [tuples]
using namespace std::chrono;
using namespace std::literals::chrono_literals;
using namespace std::literals::complex_literals;

auto tup1 = std::make_tuple(42ns, 0x42, 42.f);
auto tup2 = std::make_tuple(42us, 042L, 42.L);
auto tup3 = std::make_tuple(42ms, 42LL, 42.i);
/// [tuples]

#if 0
/// [naive_array_of_tuples]
auto array_of_tuples =  make_array(tup1, tup2, tup3);
/// [naive_array_of_tuples]
#endif

#include <boost/hana/config.hpp>

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

namespace hana {
/// [hana_common_tuple_t]
template<typename... xs>
using hana_common_tuple_t = typename decltype(
    boost::hana::unpack(
        boost::hana::zip_with(
            boost::hana::template_<std::common_type_t>,
            boost::hana::zip_with(boost::hana::decltype_, std::declval<xs>())...
        ),
        boost::hana::template_<std::tuple>
    )
)::type;
/// [hana_common_tuple_t]

/// [hana_make_array_of_tuples]
template<typename... Xs,
    typename R = std::array<std::common_type_t<Xs...>, sizeof...(Xs)>
>
constexpr R hana_make_array(Xs&&... xs) {
    return R{{std::forward<Xs>(xs)...}};
}

template<typename Head, typename... Tail,
    typename R = std::array<hana_common_tuple_t<std::decay_t<Head>, std::decay_t<Tail>...>, 1 + sizeof...(Tail)>
>
constexpr R hana_make_array(Head&& head, Tail&&... tail) {
    return R{{std::forward<Head>(head), std::forward<Tail>(tail)...}};
}
/// [hana_make_array_of_tuples]

#if !defined(_LIBCPP_VERSION) || _LIBCPP_VERSION >= 5000
/// [hana_array_of_tuples]
auto array_of_tuples = hana_make_array(tup1, tup2, tup3);

IS_SAME(decltype(array_of_tuples), std::array<std::tuple<nanoseconds, long long, std::complex<double>>, 3>);
/// [hana_array_of_tuples]
#endif

#if 0
/// [hana_array_of_numbers]
IS_SAME(decltype(hana_make_array(42, 42L, 42LL)), std::array<long long, 3>);
/// [hana_array_of_numbers]
#endif
}
#endif

namespace
{
/// [common_tuple_t]
template<typename... xs>
using common_tuple_t = metal::apply<
    std::common_type_t<metal::lambda<std::tuple>, metal::as_lambda<xs>...>,
    metal::transform<metal::lambda<std::common_type_t>, metal::as_list<xs>...>
>;
/// [common_tuple_t]

/// [make_array_of_tuples]
template<typename... Xs,
    typename R = std::array<std::common_type_t<Xs...>, sizeof...(Xs)>
>
constexpr R make_array(Xs&&... xs) {
    return R{{std::forward<Xs>(xs)...}};
}

template<typename Head, typename... Tail,
    typename R = std::array<common_tuple_t<std::decay_t<Head>, std::decay_t<Tail>...>, 1 + sizeof...(Tail)>
>
constexpr R make_array(Head&& head, Tail&&... tail) {
    return R{{std::forward<Head>(head), std::forward<Tail>(tail)...}};
}
/// [make_array_of_tuples]

#if !defined(_LIBCPP_VERSION) || _LIBCPP_VERSION >= 5000
/// [array_of_tuples]
auto array_of_tuples = make_array(tup1, tup2, tup3);

IS_SAME(decltype(array_of_tuples), std::array<std::tuple<nanoseconds, long long, std::complex<double>>, 3>);
/// [array_of_tuples]
#endif

/// [array_of_numbers]
IS_SAME(decltype(make_array(42, 42L, 42LL)), std::array<long long, 3>);
/// [array_of_numbers]
}
#endif
