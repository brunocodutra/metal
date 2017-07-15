// Copyright Bruno Dutra 2015-2017
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

#if !defined(METAL_WORKAROUND)

///[_raw_ex2]
IS_SAME(decltype(3'7'1_raw), metal::numbers<'3', '\'', '7', '\'', '1'>);
///[_raw_ex2]

HIDE(
///[remove]
using tokens = metal::numbers<'3', '\'', '7', '\'', '1'>;

IS_SAME(metal::remove<tokens, metal::number<'\''>>, metal::numbers<'3', '7', '1'>);
///[remove]
)
#endif

///[parse_digit]
template<typename token>
using parse_digit = metal::at_key<
    metal::map<
        metal::pair<metal::number<'0'>, metal::number<0>>,
        metal::pair<metal::number<'1'>, metal::number<1>>,
        metal::pair<metal::number<'2'>, metal::number<2>>,
        metal::pair<metal::number<'3'>, metal::number<3>>,
        metal::pair<metal::number<'4'>, metal::number<4>>,
        metal::pair<metal::number<'5'>, metal::number<5>>,
        metal::pair<metal::number<'6'>, metal::number<6>>,
        metal::pair<metal::number<'7'>, metal::number<7>>,
        metal::pair<metal::number<'8'>, metal::number<8>>,
        metal::pair<metal::number<'9'>, metal::number<9>>,
        metal::pair<metal::number<'a'>, metal::number<10>>,
        metal::pair<metal::number<'b'>, metal::number<11>>,
        metal::pair<metal::number<'c'>, metal::number<12>>,
        metal::pair<metal::number<'d'>, metal::number<13>>,
        metal::pair<metal::number<'e'>, metal::number<14>>,
        metal::pair<metal::number<'f'>, metal::number<15>>,
        metal::pair<metal::number<'A'>, metal::number<10>>,
        metal::pair<metal::number<'B'>, metal::number<11>>,
        metal::pair<metal::number<'C'>, metal::number<12>>,
        metal::pair<metal::number<'D'>, metal::number<13>>,
        metal::pair<metal::number<'E'>, metal::number<14>>,
        metal::pair<metal::number<'F'>, metal::number<15>>
    >,
    token
>;

///[parse_digit]

HIDE(
///[transform]
IS_SAME(metal::transform<metal::lambda<parse_digit>, metal::numbers<'3', '7', '1'>>, metal::numbers<3, 7, 1>);
///[transform]
)

HIDE(
///[accumulate_1]
using radix = metal::number<10>;
using digits = metal::numbers<3, 7, 1>;

template<typename x, typename y>
using expr = metal::add<metal::mul<radix, x>, y>;

using lbd = metal::lambda<expr>;

IS_SAME(metal::accumulate<lbd, metal::number<0>, digits>, metal::number<371>);
///[accumulate_1]
)

HIDE(
///[accumulate_2]
using radix = metal::number<10>;
using digits = metal::numbers<3, 7, 1>;

using lbd = metal::bind<
    metal::lambda<metal::add>,
    metal::bind<metal::lambda<metal::mul>, metal::always<radix>, metal::_1>,
    metal::_2
>;

IS_SAME(metal::accumulate<lbd, metal::number<0>, digits>, metal::number<371>);
///[accumulate_2]
)

///[assemble_number]
template<typename radix, typename digits>
using assemble_number = metal::accumulate<
    metal::bind<
        metal::lambda<metal::add>,
        metal::bind<metal::lambda<metal::mul>, metal::always<radix>, metal::_1>,
        metal::_2
    >,
    metal::number<0>,
    digits
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
struct parse_number {};

template<typename... tokens>
struct parse_number<metal::list<tokens...>> {
    using type = assemble_number<metal::number<10>, parse_digits<metal::list<tokens...>>>;
};

template<typename... tokens>
struct parse_number<metal::list<metal::number<'0'>, tokens...>> {
    using type = assemble_number<metal::number<8>, parse_digits<metal::list<tokens...>>>;
};

template<typename... tokens>
struct parse_number<metal::list<metal::number<'0'>, metal::number<'x'>, tokens...>> {
    using type = assemble_number<metal::number<16>, parse_digits<metal::list<tokens...>>>;
};

template<typename... tokens>
struct parse_number<metal::list<metal::number<'0'>, metal::number<'X'>, tokens...>> {
    using type = assemble_number<metal::number<16>, parse_digits<metal::list<tokens...>>>;
};

template<typename... tokens>
struct parse_number<metal::list<metal::number<'0'>, metal::number<'b'>, tokens...>> {
    using type = assemble_number<metal::number<2>, parse_digits<metal::list<tokens...>>>;
};

template<typename... tokens>
struct parse_number<metal::list<metal::number<'0'>, metal::number<'B'>, tokens...>> {
    using type = assemble_number<metal::number<2>, parse_digits<metal::list<tokens...>>>;
};
///[parse_number]

///[_c]
template<char... cs>
constexpr auto operator ""/**/_c()
    -> metal::eval<parse_number<metal::numbers<cs...>>> {
    return {};
}
///[_c]

///[_c_ex1]
IS_SAME(decltype(01234567_c), metal::number<342391>); //octal
IS_SAME(decltype(123456789_c), metal::number<123456789>); //decimal
IS_SAME(decltype(0xABCDEF_c), metal::number<11259375>); //hexadecimal
///[_c_ex1]

IS_SAME(decltype(0Xabcdef_c), metal::number<11259375>);

#if !defined(METAL_WORKAROUND)

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
IS_SAME(decltype(1'2'3'4'5'6'7'8'9_c), metal::number<123456789>);
///[_c_ex3]

#endif

#if defined(METAL_WORKAROUND)
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
        -> metal::at<metal::list<T...>, metal::number<i>> {
        return std::get<i>(*this);
    }
};
#else
///[augmented_tuple]
template<typename... T>
struct AugmentedTuple :
    std::tuple<T...>
{
    using std::tuple<T...>::tuple;

    template<metal::int_ i>
    constexpr auto operator [](metal::number<i>)
        -> metal::at<metal::list<T...>, metal::number<i>>& {
        return std::get<i>(*this);
    }
};
///[augmented_tuple]
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
