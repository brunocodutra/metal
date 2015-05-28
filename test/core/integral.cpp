// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/core/assert.hpp>
#include <boost/mpl2/core/integral.hpp>

#include <type_traits>
#include <climits>

#if !defined(SIZE_MAX)
    #define SIZE_MAX static_cast<std::size_t>(-1)
#endif

using namespace boost::mpl2;

typedef integral<int, 42> number;

BOOST_MPL2_ASSERT((std::is_same<number::type::type, number::type>));
BOOST_MPL2_ASSERT((std::is_same<number::type::value_type, number::value_type>));
BOOST_MPL2_ASSERT((std::is_same<number::value_type, std::decay<decltype(number::value)>::type>));
BOOST_MPL2_ASSERT_EXPR(number::type::value == number::value);
BOOST_MPL2_ASSERT_EXPR(number::value == number{});

BOOST_MPL2_ASSERT((std::is_same<true_, bool_<true>::type>));
BOOST_MPL2_ASSERT((std::is_same<true_, integral<bool, true>::type>));
BOOST_MPL2_ASSERT((std::is_same<true_, std::true_type>));

BOOST_MPL2_ASSERT((std::is_same<false_, bool_<false>::type>));
BOOST_MPL2_ASSERT((std::is_same<false_, integral<bool, false>::type>));
BOOST_MPL2_ASSERT((std::is_same<false_, std::false_type>));

BOOST_MPL2_ASSERT((std::is_same<bool_<true>::type, integral<bool, true>::type>));
BOOST_MPL2_ASSERT((std::is_same<bool_<false>::type, integral<bool, false>::type>));
BOOST_MPL2_ASSERT((std::is_same<char_<' '>::type, integral<char, ' '>::type>));
BOOST_MPL2_ASSERT((std::is_same<uchar_<255>::type, integral<unsigned char, 255>::type>));
BOOST_MPL2_ASSERT((std::is_same<schar_<SCHAR_MIN>::type, integral<signed char, SCHAR_MIN>::type>));
BOOST_MPL2_ASSERT((std::is_same<wchar_t_<L' '>::type, integral<wchar_t, L' '>::type>));
BOOST_MPL2_ASSERT((std::is_same<char16_t_<u' '>::type, integral<char16_t, u' '>::type>));
BOOST_MPL2_ASSERT((std::is_same<char32_t_<U' '>::type, integral<char32_t, U' '>::type>));
BOOST_MPL2_ASSERT((std::is_same<short_<SHRT_MIN>::type, integral<short, SHRT_MIN>::type>));
BOOST_MPL2_ASSERT((std::is_same<ushort_<USHRT_MAX>::type, integral<unsigned short, USHRT_MAX>::type>));
BOOST_MPL2_ASSERT((std::is_same<int_<INT_MIN>::type, integral<int, INT_MIN>::type>));
BOOST_MPL2_ASSERT((std::is_same<uint_<UINT_MAX>::type, integral<unsigned int, UINT_MAX>::type>));
BOOST_MPL2_ASSERT((std::is_same<long_<LONG_MIN>::type, integral<long, LONG_MIN>::type>));
BOOST_MPL2_ASSERT((std::is_same<ulong_<ULONG_MAX>::type, integral<unsigned long, ULONG_MAX>::type>));
BOOST_MPL2_ASSERT((std::is_same<long_long_<LLONG_MIN>::type, integral<long long, LLONG_MIN>::type>));
BOOST_MPL2_ASSERT((std::is_same<ulong_long_<ULLONG_MAX>::type, integral<unsigned long long, ULLONG_MAX>::type>));
BOOST_MPL2_ASSERT((std::is_same<size_t_<SIZE_MAX>::type, integral<size_t, SIZE_MAX>::type>));

int main()
{
    return 0;
}
