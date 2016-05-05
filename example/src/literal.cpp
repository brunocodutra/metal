// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal.hpp>

#include <cassert>
#include <tuple>

#include "example.hpp"

#if 0
///[naive]
constexpr auto operator ""_c(long long i)
    -> std::integral_constant<long long, i> {
    return {};
}
///[naive]
#endif

///[raw]
template <char... tokens>
constexpr auto operator ""/**/_raw()
    -> metal::list<metal::character<tokens>...> {
    return {};
}
///[raw]

///[raw_examples_1]
static_assert(std::is_same<
    decltype(371_raw),
    metal::list<
        metal::character<'3'>,
        metal::character<'7'>,
        metal::character<'1'>
    >
>::value, "");

static_assert(std::is_same<
    decltype(0x371_raw),
    metal::list<
        metal::character<'0'>, metal::character<'x'>,
        metal::character<'3'>, metal::character<'7'>, metal::character<'1'>
    >
>::value, "");
///[raw_examples_1]

///[raw_examples_2]
static_assert(std::is_same<
    decltype(3'7'1_raw),
    metal::list<
        metal::character<'3'>,
        metal::character<'\''>,
        metal::character<'7'>,
        metal::character<'\''>,
        metal::character<'1'>
    >
>::value, "");
///[raw_examples_2]

HIDDEN(namespace)
{
///[remove]
using tokens = metal::list<
    metal::character<'3'>,
    metal::character<'\''>,
    metal::character<'7'>,
    metal::character<'\''>,
    metal::character<'1'>
>;

static_assert(std::is_same<
    metal::remove_t<tokens, metal::character<'\''>>,
    metal::list<
        metal::character<'3'>,
        metal::character<'7'>,
        metal::character<'1'>
    >
>::value, "");
///[remove]
}

///[to_number]
template<typename c>
struct to_number :
    metal::if_t<
        metal::equal_to_t<c, metal::character<'0'>>, metal::number<long long, 0>,
        metal::equal_to_t<c, metal::character<'1'>>, metal::number<long long, 1>,
        metal::equal_to_t<c, metal::character<'2'>>, metal::number<long long, 2>,
        metal::equal_to_t<c, metal::character<'3'>>, metal::number<long long, 3>,
        metal::equal_to_t<c, metal::character<'4'>>, metal::number<long long, 4>,
        metal::equal_to_t<c, metal::character<'5'>>, metal::number<long long, 5>,
        metal::equal_to_t<c, metal::character<'6'>>, metal::number<long long, 6>,
        metal::equal_to_t<c, metal::character<'7'>>, metal::number<long long, 7>,
        metal::equal_to_t<c, metal::character<'8'>>, metal::number<long long, 8>,
        metal::equal_to_t<c, metal::character<'9'>>, metal::number<long long, 9>,
        metal::equal_to_t<c, metal::character<'a'>>, metal::number<long long, 10>,
        metal::equal_to_t<c, metal::character<'b'>>, metal::number<long long, 11>,
        metal::equal_to_t<c, metal::character<'c'>>, metal::number<long long, 12>,
        metal::equal_to_t<c, metal::character<'d'>>, metal::number<long long, 13>,
        metal::equal_to_t<c, metal::character<'e'>>, metal::number<long long, 14>,
        metal::equal_to_t<c, metal::character<'f'>>, metal::number<long long, 15>,
        metal::equal_to_t<c, metal::character<'A'>>, metal::number<long long, 10>,
        metal::equal_to_t<c, metal::character<'B'>>, metal::number<long long, 11>,
        metal::equal_to_t<c, metal::character<'C'>>, metal::number<long long, 12>,
        metal::equal_to_t<c, metal::character<'D'>>, metal::number<long long, 13>,
        metal::equal_to_t<c, metal::character<'E'>>, metal::number<long long, 14>,
        metal::equal_to_t<c, metal::character<'F'>>, metal::number<long long, 15>
    >
{};
///[to_number]

HIDDEN(namespace)
{
///[transform_1]
using digits = metal::list<
    metal::character<'3'>,
    metal::character<'7'>,
    metal::character<'1'>
>;

static_assert(std::is_same<
    metal::transform_t<to_number<metal::_1>, digits>,
    metal::list<
        metal::number<long long, 3>,
        metal::number<long long, 7>,
        metal::number<long long, 1>
    >
>::value, "");
///[transform_1]
}

HIDDEN(namespace)
{
///[reverse]
using digits = metal::list<
    metal::number<long long, 3>,
    metal::number<long long, 7>,
    metal::number<long long, 1>
>;

static_assert(std::is_same<
    metal::reverse_t<digits>,
    metal::list<
        metal::number<long long, 1>,
        metal::number<long long, 7>,
        metal::number<long long, 3>
    >
>::value, "");
///[reverse]
}

HIDDEN(namespace)
{
///[enumerate]
using digits = metal::list<
    metal::number<long long, 1>,
    metal::number<long long, 7>,
    metal::number<long long, 3>
>;

static_assert(std::is_same<
    metal::enumerate_t<metal::number<long long, 0>, metal::size_t<digits>>,
    metal::list<
        metal::number<long long, 0>,
        metal::number<long long, 1>,
        metal::number<long long, 2>
    >
>::value, "");
///[enumerate]
}

HIDDEN(namespace)
{
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

static_assert(std::is_same<
    metal::transform_t<
        metal::mul<metal::_1, metal::pow<radix, metal::_2>>,
        digits,
        exponents
    >,
    metal::list<
        metal::number<long long, 1>,
        metal::number<long long, 70>,
        metal::number<long long, 300>
    >
>::value, "");
///[transform_2]
}

HIDDEN(namespace)
{
///[sum]
using terms = metal::list<
    metal::number<long long, 1>,
    metal::number<long long, 70>,
    metal::number<long long, 300>
>;

static_assert(std::is_same<
    metal::apply_t<metal::lambda<metal::add>, terms>,
    metal::number<long long, 371>
>::value, "");
///[sum]
}

///[compute]
template<typename radix, typename digits>
struct compute :
    metal::apply<
        metal::lambda<metal::add>,
        metal::transform_t<
            metal::mul<metal::_1, metal::pow<radix, metal::_2>>,
            metal::reverse_t<digits>,
            metal::enumerate_t<
                metal::number<long long, 0>,
                metal::size_t<digits>
            >
        >
    >
{};
///[compute]

///[parse_digits]
template<typename... tokens>
struct parse_digits :
    metal::transform<
        to_number<metal::_1>,
        metal::remove_t<metal::list<tokens...>, metal::character<'\''>>
    >
{};

template<typename... tokens>
using parse_digits_t = typename parse_digits<tokens...>::type;
///[parse_digits]

///[make_number]
template<typename... tokens>
struct make_number :
    compute<metal::number<long long, 10>, parse_digits_t<tokens...>>
{};

template<typename... tokens>
struct make_number<metal::character<'0'>, tokens...> :
    compute<metal::number<long long, 8>, parse_digits_t<tokens...>>
{};

template<typename... tokens>
struct make_number<metal::character<'0'>, metal::character<'x'>, tokens...> :
    compute<metal::number<long long, 16>, parse_digits_t<tokens...>>
{};

template<typename... tokens>
struct make_number<metal::character<'0'>, metal::character<'X'>, tokens...> :
    compute<metal::number<long long, 16>, parse_digits_t<tokens...>>
{};

template<typename... tokens>
struct make_number<metal::character<'0'>, metal::character<'b'>, tokens...> :
    compute<metal::number<long long, 2>, parse_digits_t<tokens...>>
{};

template<typename... tokens>
struct make_number<metal::character<'0'>, metal::character<'B'>, tokens...> :
    compute<metal::number<long long, 2>, parse_digits_t<tokens...>>
{};

template<typename... tokens>
using make_number_t = typename make_number<tokens...>::type;
///[make_number]

///[_c]
template<char... tokens>
constexpr auto operator ""/**/_c()
    -> make_number_t<metal::character<tokens>...> {
    return {};
}
///[_c]

///[test_1]
static_assert(std::is_same<
    decltype(01234567_c), //octal
    metal::number<long long, 342391>
>::value, "");

static_assert(std::is_same<
    decltype(123456789_c), //decimal
    metal::number<long long, 123456789>
>::value, "");

static_assert(std::is_same<
    decltype(0xABCDEF_c), //hexadecimal
    metal::number<long long, 11259375>
>::value, "");
///[test_1]

static_assert(std::is_same<
    decltype(0Xabcdef_c),
    metal::number<long long, 11259375>
>::value, "");


///[test_2]
static_assert(std::is_same<
    decltype(0b111101101011011101011010101100101011110001000111000111000111000_c),
    metal::number<long long, 8888888888888888888>
>::value, "");
///[test_2]

static_assert(std::is_same<
    decltype(0B111101101011011101011010101100101011110001000111000111000111000_c),
    metal::number<long long, 8888888888888888888>
>::value, "");

///[test_3]
static_assert(std::is_same<
    decltype(1'2'3'4'5'6'7'8'9_c),
    metal::number<long long, 123456789>
>::value, "");
///[test_3]

#if __cpp_constexpr >= 201304
///[super_tuple]
template<typename... T>
struct SuperTuple :
    std::tuple<T...>
{
    using std::tuple<T...>::tuple;

    template<typename I, I i>
    constexpr auto operator [](metal::number<I, i>)
        -> typename std::tuple_element<i, std::tuple<T...>>::type& {
        return std::get<i>(*this);
    }
};
///[super_tuple]
#else
template<typename... T>
struct SuperTuple :
    std::tuple<T...>
{
    template<typename... U>
    constexpr SuperTuple(U&&... args) :
        std::tuple<T...>(std::forward<U>(args)...)
    {}

    template<typename I, I i>
    constexpr auto operator [](metal::number<I, i>) const
        -> metal::at_t<SuperTuple, metal::number<I, i>> {
        return std::get<i>(*this);
    }
};
#endif

///[teaser_1]
static_assert(std::get<1>(std::tuple<int, char, double>{42, 'a', 2.5}) == 'a', "");
///[teaser_1]

#if 0
///[teaser_2]
static_assert(SuperTuple<int, char, double>{42, 'a', 2.5}[1] == 'a', "");
///[teaser_2]
#endif

///[teaser_3]
static_assert(SuperTuple<int, char, double>{42, 'a', 2.5}[1_c] == 'a', "");
///[teaser_3]
