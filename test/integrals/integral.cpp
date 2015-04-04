// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/core/assert.hpp>
#include <boost/mpl2/integrals/integral.hpp>
#include <boost/mpl2/integrals/boolean.hpp>
#include <boost/mpl2/integrals/character.hpp>
#include <boost/mpl2/integrals/integer.hpp>
#include <boost/mpl2/integrals/size_t.hpp>

#include <type_traits>
#include <climits>

#if !defined(SIZE_MAX)
    #define SIZE_MAX static_cast<std::size_t>(-1)
#endif

template<typename integral>
constexpr bool test_integral(integral const& constant)
{
    BOOST_MPL2_ASSERT((std::is_same<typename integral::type::value_type, typename integral::value_type>));
    BOOST_MPL2_ASSERT_EXPR(integral::type::value == integral::value);

    return integral::value == constant;
}

BOOST_MPL2_ASSERT_EXPR(test_integral(boost::mpl2::true_{}));
BOOST_MPL2_ASSERT_EXPR(test_integral(boost::mpl2::false_{}));
BOOST_MPL2_ASSERT_EXPR(test_integral(boost::mpl2::bool_<true>{}));
BOOST_MPL2_ASSERT_EXPR(test_integral(boost::mpl2::bool_<false>{}));
BOOST_MPL2_ASSERT_EXPR(test_integral(boost::mpl2::char_<' '>{}));
BOOST_MPL2_ASSERT_EXPR(test_integral(boost::mpl2::uchar_<255>{}));
BOOST_MPL2_ASSERT_EXPR(test_integral(boost::mpl2::schar_<SCHAR_MIN>{}));
BOOST_MPL2_ASSERT_EXPR(test_integral(boost::mpl2::wchar_t_<L' '>{}));
BOOST_MPL2_ASSERT_EXPR(test_integral(boost::mpl2::char16_t_<u' '>{}));
BOOST_MPL2_ASSERT_EXPR(test_integral(boost::mpl2::char32_t_<U' '>{}));
BOOST_MPL2_ASSERT_EXPR(test_integral(boost::mpl2::short_<SHRT_MIN>{}));
BOOST_MPL2_ASSERT_EXPR(test_integral(boost::mpl2::ushort_<USHRT_MAX>{}));
BOOST_MPL2_ASSERT_EXPR(test_integral(boost::mpl2::int_<INT_MIN>{}));
BOOST_MPL2_ASSERT_EXPR(test_integral(boost::mpl2::uint_<UINT_MAX>{}));
BOOST_MPL2_ASSERT_EXPR(test_integral(boost::mpl2::long_<LONG_MIN>{}));
BOOST_MPL2_ASSERT_EXPR(test_integral(boost::mpl2::ulong_<ULONG_MAX>{}));
BOOST_MPL2_ASSERT_EXPR(test_integral(boost::mpl2::long_long_<LLONG_MIN>{}));
BOOST_MPL2_ASSERT_EXPR(test_integral(boost::mpl2::ulong_long_<ULLONG_MAX>{}));
BOOST_MPL2_ASSERT_EXPR(test_integral(boost::mpl2::size_t_<SIZE_MAX>{}));

int main()
{
    return 0;
}
