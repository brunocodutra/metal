// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include <cassert>
#include <tuple>

#include "example.hpp"

#if 0
///[naive_1]
constexpr auto operator [](std::size_t i)
    -> std::tuple_element_t<i, std::tuple<T...>>& {
    return std::get<i>(*this);
}
///[naive_1]

///[naive_2]
constexpr auto operator ""_c(long long i)
    -> metal::number<i> {
    return {};
}
///[naive_2]
#endif

///[_raw]
template<char... cs>
constexpr auto operator ""/**/_raw()
    -> metal::numbers<cs...> {
    return {};
}
///[_raw]

///[_raw_ex1]
IS_SAME(decltype(371_raw), metal::numbers<'3', '7', '1'>);
IS_SAME(decltype(0x371_raw), metal::numbers<'0', 'x', '3', '7', '1'>);
///[_raw_ex1]

///[_raw_ex2]
IS_SAME(decltype(3'7'1_raw), metal::numbers<'3', '\'', '7', '\'', '1'>);
///[_raw_ex2]

HIDE(
///[remove]
using tokens = metal::numbers<'3', '\'', '7', '\'', '1'>;

IS_SAME(
    metal::remove<tokens, metal::number<'\''>>,
    metal::numbers<'3', '7', '1'>
);
///[remove]
)

///[parse_digit]
template<typename c>
using parse_digit = metal::if_<
    metal::same<c, metal::number<'0'>>, metal::number<0>,
    metal::same<c, metal::number<'1'>>, metal::number<1>,
    metal::same<c, metal::number<'2'>>, metal::number<2>,
    metal::same<c, metal::number<'3'>>, metal::number<3>,
    metal::same<c, metal::number<'4'>>, metal::number<4>,
    metal::same<c, metal::number<'5'>>, metal::number<5>,
    metal::same<c, metal::number<'6'>>, metal::number<6>,
    metal::same<c, metal::number<'7'>>, metal::number<7>,
    metal::same<c, metal::number<'8'>>, metal::number<8>,
    metal::same<c, metal::number<'9'>>, metal::number<9>,
    metal::same<c, metal::number<'a'>>, metal::number<10>,
    metal::same<c, metal::number<'b'>>, metal::number<11>,
    metal::same<c, metal::number<'c'>>, metal::number<12>,
    metal::same<c, metal::number<'d'>>, metal::number<13>,
    metal::same<c, metal::number<'e'>>, metal::number<14>,
    metal::same<c, metal::number<'f'>>, metal::number<15>,
    metal::same<c, metal::number<'A'>>, metal::number<10>,
    metal::same<c, metal::number<'B'>>, metal::number<11>,
    metal::same<c, metal::number<'C'>>, metal::number<12>,
    metal::same<c, metal::number<'D'>>, metal::number<13>,
    metal::same<c, metal::number<'E'>>, metal::number<14>,
    metal::same<c, metal::number<'F'>>, metal::number<15>
>;
///[parse_digit]

HIDE(
///[transform]
IS_SAME(
    metal::transform<metal::lambda<parse_digit>, metal::numbers<'3', '7', '1'>>,
    metal::numbers<3, 7, 1>
);
///[transform]
)

HIDE(
///[reverse]
IS_SAME(metal::reverse<metal::numbers<3, 7, 1>>, metal::numbers<1, 7, 3>);
///[reverse]
)

HIDE(
///[enumerate]
IS_SAME(
    metal::enumerate<metal::number<0>, metal::size<metal::numbers<1, 7, 3>>>,
    metal::numbers<0, 1, 2>
);
///[enumerate]
)

HIDE(
///[zip]
using radix = metal::number<10>;
using digits = metal::numbers<1, 7, 3>;
using exponents = metal::numbers<0, 1, 2>;

IS_SAME(
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
        digits,
        exponents
    >,
    metal::numbers<1, 70, 300>
);
///[zip]
)

HIDE(
///[sum]
IS_SAME(
    metal::apply<metal::lambda<metal::add>, metal::numbers<1, 70, 300>>,
    metal::number<371>
);
///[sum]
)

///[assemble_number]
template<typename radix, typename digits>
using assemble_number = metal::apply<
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
        metal::enumerate<metal::number<0>, metal::size<digits>>
    >
>;
///[assemble_number]

///[parse_digits]
template<typename tokens>
using parse_digits = metal::transform<
    metal::lambda<parse_digit>,
    metal::remove<tokens, metal::number<'\''>>
>;
///[parse_digits]

///[parse_number]
template<typename tokens>
struct parse_number_impl
{};

template<typename... tokens>
struct parse_number_impl<
    metal::list<tokens...>
>
{
    using type = assemble_number<
        metal::number<10>,
        parse_digits<metal::list<tokens...>>
    >;
};

template<typename... tokens>
struct parse_number_impl<
    metal::list<metal::number<'0'>, tokens...>
>
{
    using type = assemble_number<
        metal::number<8>,
        parse_digits<metal::list<tokens...>>
    >;
};

template<typename... tokens>
struct parse_number_impl<
    metal::list<metal::number<'0'>, metal::number<'x'>, tokens...>
>
{
    using type = assemble_number<
        metal::number<16>,
        parse_digits<metal::list<tokens...>>
    >;
};

template<typename... tokens>
struct parse_number_impl<
    metal::list<metal::number<'0'>, metal::number<'X'>, tokens...>
>
{
    using type = assemble_number<
        metal::number<16>,
        parse_digits<metal::list<tokens...>>
    >;
};

template<typename... tokens>
struct parse_number_impl<
    metal::list<metal::number<'0'>, metal::number<'b'>, tokens...>
>
{
    using type = assemble_number<
        metal::number<2>,
        parse_digits<metal::list<tokens...>>
    >;
};

template<typename... tokens>
struct parse_number_impl<
    metal::list<metal::number<'0'>, metal::number<'B'>, tokens...>
>
{
    using type = assemble_number<
        metal::number<2>,
        parse_digits<metal::list<tokens...>>
    >;
};

template<typename tokens>
using parse_number = typename parse_number_impl<tokens>::type;
///[parse_number]

///[_c]
template<char... cs>
constexpr auto operator ""/**/_c()
    -> parse_number<metal::numbers<cs...>> {
    return {};
}
///[_c]

///[_c_ex1]
IS_SAME(
    decltype(01234567_c), //octal
    metal::number<342391>
);

IS_SAME(
    decltype(123456789_c), //decimal
    metal::number<123456789>
);

IS_SAME(
    decltype(0xABCDEF_c), //hexadecimal
    metal::number<11259375>
);
///[_c_ex1]

IS_SAME(
    decltype(0Xabcdef_c),
    metal::number<11259375>
);

///[_c_ex2]
IS_SAME(
    decltype(0b111101101011011101011010101100101011110001000111000111000111000_c),
    metal::number<8888888888888888888>
);
///[_c_ex2]

IS_SAME(
    decltype(0B111101101011011101011010101100101011110001000111000111000111000_c),
    metal::number<8888888888888888888>
);

///[_c_ex3]
IS_SAME(
    decltype(1'2'3'4'5'6'7'8'9_c),
    metal::number<123456789>
);
///[_c_ex3]

#if __cpp_constexpr >= 201304
///[augmented_tuple]
template<typename... T>
struct AugmentedTuple :
    std::tuple<T...>
{
    using std::tuple<T...>::tuple;

    template<metal::int_ i>
    constexpr auto operator [](metal::number<i>)
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

    template<metal::int_ i>
    constexpr auto operator [](metal::number<i>) const
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
static_assert(AugmentedTuple<int, char, double>{42, 'a', 2.5}[metal::number<1>{}] == 'a', "");
///[teaser_3]

///[teaser_4]
static_assert(AugmentedTuple<int, char, double>{42, 'a', 2.5}[1_c] == 'a', "");
///[teaser_4]
