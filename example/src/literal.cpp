// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include <cassert>
#include <tuple>

#include "example.hpp"

#if 0
///[naive]
constexpr auto operator ""_c(long long i)
    -> metal::number<long long, i> {
    return {};
}
///[naive]
#endif

///[raw]
template<char... tokens>
constexpr auto operator ""/**/_raw()
    -> metal::list<metal::char_<tokens>...> {
    return {};
}
///[raw]

///[raw_examples_1]
static_assert(metal::equal<
    decltype(371_raw),
    metal::list<
        metal::char_<'3'>,
        metal::char_<'7'>,
        metal::char_<'1'>
    >
>::value, "");

static_assert(metal::equal<
    decltype(0x371_raw),
    metal::list<
        metal::char_<'0'>, metal::char_<'x'>,
        metal::char_<'3'>, metal::char_<'7'>, metal::char_<'1'>
    >
>::value, "");
///[raw_examples_1]

///[raw_examples_2]
static_assert(metal::equal<
    decltype(3'7'1_raw),
    metal::list<
        metal::char_<'3'>,
        metal::char_<'\''>,
        metal::char_<'7'>,
        metal::char_<'\''>,
        metal::char_<'1'>
    >
>::value, "");
///[raw_examples_2]

HIDE(
///[remove]
using tokens = metal::list<
    metal::char_<'3'>,
    metal::char_<'\''>,
    metal::char_<'7'>,
    metal::char_<'\''>,
    metal::char_<'1'>
>;

static_assert(metal::equal<
    metal::remove<tokens, metal::char_<'\''>>,
    metal::list<
        metal::char_<'3'>,
        metal::char_<'7'>,
        metal::char_<'1'>
    >
>::value, "");
///[remove]
)

///[to_number]
template<typename c>
using to_number = metal::if_<
    metal::equal<c, metal::char_<'0'>>, metal::number<long long, 0>,
    metal::equal<c, metal::char_<'1'>>, metal::number<long long, 1>,
    metal::equal<c, metal::char_<'2'>>, metal::number<long long, 2>,
    metal::equal<c, metal::char_<'3'>>, metal::number<long long, 3>,
    metal::equal<c, metal::char_<'4'>>, metal::number<long long, 4>,
    metal::equal<c, metal::char_<'5'>>, metal::number<long long, 5>,
    metal::equal<c, metal::char_<'6'>>, metal::number<long long, 6>,
    metal::equal<c, metal::char_<'7'>>, metal::number<long long, 7>,
    metal::equal<c, metal::char_<'8'>>, metal::number<long long, 8>,
    metal::equal<c, metal::char_<'9'>>, metal::number<long long, 9>,
    metal::equal<c, metal::char_<'a'>>, metal::number<long long, 10>,
    metal::equal<c, metal::char_<'b'>>, metal::number<long long, 11>,
    metal::equal<c, metal::char_<'c'>>, metal::number<long long, 12>,
    metal::equal<c, metal::char_<'d'>>, metal::number<long long, 13>,
    metal::equal<c, metal::char_<'e'>>, metal::number<long long, 14>,
    metal::equal<c, metal::char_<'f'>>, metal::number<long long, 15>,
    metal::equal<c, metal::char_<'A'>>, metal::number<long long, 10>,
    metal::equal<c, metal::char_<'B'>>, metal::number<long long, 11>,
    metal::equal<c, metal::char_<'C'>>, metal::number<long long, 12>,
    metal::equal<c, metal::char_<'D'>>, metal::number<long long, 13>,
    metal::equal<c, metal::char_<'E'>>, metal::number<long long, 14>,
    metal::equal<c, metal::char_<'F'>>, metal::number<long long, 15>
>;
///[to_number]

HIDE(
///[transform_1]
using digits = metal::list<
    metal::char_<'3'>,
    metal::char_<'7'>,
    metal::char_<'1'>
>;

static_assert(metal::equal<
    metal::transform<metal::lambda<to_number>, digits>,
    metal::list<
        metal::number<long long, 3>,
        metal::number<long long, 7>,
        metal::number<long long, 1>
    >
>::value, "");
///[transform_1]
)

HIDE(
///[reverse]
using digits = metal::list<
    metal::number<long long, 3>,
    metal::number<long long, 7>,
    metal::number<long long, 1>
>;

static_assert(metal::equal<
    metal::reverse<digits>,
    metal::list<
        metal::number<long long, 1>,
        metal::number<long long, 7>,
        metal::number<long long, 3>
    >
>::value, "");
///[reverse]
)

HIDE(
///[enumerate]
using digits = metal::list<
    metal::number<long long, 1>,
    metal::number<long long, 7>,
    metal::number<long long, 3>
>;

static_assert(metal::equal<
    metal::enumerate<metal::number<long long, 0>, metal::size<digits>>,
    metal::list<
        metal::number<long long, 0>,
        metal::number<long long, 1>,
        metal::number<long long, 2>
    >
>::value, "");
///[enumerate]
)

HIDE(
///[transform_2]
using radix = metal::number<long long, 10>;
using digits = metal::list<
    metal::number<long long, 1>,
    metal::number<long long, 7>,
    metal::number<long long, 3>
>;
using exponents = metal::list<
    metal::number<long long, 0>,
    metal::number<long long, 1>,
    metal::number<long long, 2>
>;

static_assert(metal::equal<
    metal::transform<
        metal::bind<
            metal::lambda<metal::mul>,
            metal::_1,
            metal::bind<
                metal::lambda<metal::pow>,
                metal::quote<radix>,
                metal::_2
            >
        >,
        digits, exponents
    >,
    metal::list<
        metal::number<long long, 1>,
        metal::number<long long, 70>,
        metal::number<long long, 300>
    >
>::value, "");
///[transform_2]
)

HIDE(
///[sum]
using terms = metal::list<
    metal::number<long long, 1>,
    metal::number<long long, 70>,
    metal::number<long long, 300>
>;

static_assert(metal::equal<
    metal::apply<metal::lambda<metal::add>, terms>,
    metal::number<long long, 371>
>::value, "");
///[sum]
)

///[compute]
template<typename radix, typename digits>
using compute = metal::apply<
    metal::lambda<metal::add>,
    metal::transform<
        metal::bind<
            metal::lambda<metal::mul>,
            metal::_1,
            metal::bind<
                metal::lambda<metal::pow>,
                metal::quote<radix>,
                metal::_2
            >
        >,
        metal::reverse<digits>,
        metal::enumerate<
            metal::number<long long, 0>,
            metal::size<digits>
        >
    >
>;
///[compute]

///[parse_digits]
template<typename... tokens>
using parse_digits = metal::transform<
    metal::lambda<to_number>,
    metal::remove<metal::list<tokens...>, metal::char_<'\''>>
>;
///[parse_digits]

///[make_number]
template<typename... tokens>
struct make_number_impl
{
    using type = compute<metal::number<long long, 10>, parse_digits<tokens...>>;
};

template<typename... tokens>
struct make_number_impl<metal::char_<'0'>, tokens...>
{
    using type = compute<metal::number<long long, 8>, parse_digits<tokens...>>;
};

template<typename... tokens>
struct make_number_impl<metal::char_<'0'>, metal::char_<'x'>, tokens...>
{
    using type = compute<metal::number<long long, 16>, parse_digits<tokens...>>;
};

template<typename... tokens>
struct make_number_impl<metal::char_<'0'>, metal::char_<'X'>, tokens...> :
    make_number_impl<metal::char_<'0'>, metal::char_<'x'>, tokens...>
{};

template<typename... tokens>
struct make_number_impl<metal::char_<'0'>, metal::char_<'b'>, tokens...>
{
    using type = compute<metal::number<long long, 2>, parse_digits<tokens...>>;
};

template<typename... tokens>
struct make_number_impl<metal::char_<'0'>, metal::char_<'B'>, tokens...> :
    make_number_impl<metal::char_<'0'>, metal::char_<'b'>, tokens...>
{};

template<typename... tokens>
using make_number = typename make_number_impl<tokens...>::type;
///[make_number]

///[_c]
template<char... tokens>
constexpr auto operator ""/**/_c()
    -> make_number<metal::char_<tokens>...> {
    return {};
}
///[_c]

///[test_1]
static_assert(metal::equal<
    decltype(01234567_c), //octal
    metal::number<long long, 342391>
>::value, "");

static_assert(metal::equal<
    decltype(123456789_c), //decimal
    metal::number<long long, 123456789>
>::value, "");

static_assert(metal::equal<
    decltype(0xABCDEF_c), //hexadecimal
    metal::number<long long, 11259375>
>::value, "");
///[test_1]

static_assert(metal::equal<
    decltype(0Xabcdef_c),
    metal::number<long long, 11259375>
>::value, "");


///[test_2]
static_assert(metal::equal<
    decltype(0b111101101011011101011010101100101011110001000111000111000111000_c),
    metal::number<long long, 8888888888888888888>
>::value, "");
///[test_2]

static_assert(metal::equal<
    decltype(0B111101101011011101011010101100101011110001000111000111000111000_c),
    metal::number<long long, 8888888888888888888>
>::value, "");

///[test_3]
static_assert(metal::equal<
    decltype(1'2'3'4'5'6'7'8'9_c),
    metal::number<long long, 123456789>
>::value, "");
///[test_3]

#if __cpp_constexpr >= 201304
///[augmented_tuple]
template<typename... T>
struct AugmentedTuple :
    std::tuple<T...>
{
    using std::tuple<T...>::tuple;

    template<typename I, I i>
    constexpr auto operator [](metal::number<I, i>)
        -> std::tuple_element_t<i, std::tuple<T...>>& {
        return std::get<i>(*this);
    }
};
///[augmented_tuple]
#else
template<typename... T>
struct AugmentedTuple :
    std::tuple<T...>
{
    template<typename... U>
    constexpr AugmentedTuple(U&&... args) :
        std::tuple<T...>(std::forward<U>(args)...)
    {}

    template<typename I, I i>
    constexpr auto operator [](metal::number<I, i>) const
        -> std::tuple_element_t<i, std::tuple<T...>> {
        return std::get<i>(*this);
    }
};
#endif

///[teaser_1]
static_assert(std::get<1>(std::tuple<int, char, double>{42, 'a', 2.5}) == 'a', "");
///[teaser_1]

#if 0
///[teaser_2]
static_assert(AugmentedTuple<int, char, double>{42, 'a', 2.5}[1] == 'a', "");
///[teaser_2]
#endif

///[teaser_3]
static_assert(AugmentedTuple<int, char, double>{42, 'a', 2.5}[1_c] == 'a', "");
///[teaser_3]
