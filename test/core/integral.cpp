// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/core/integral.hpp>
#include <boost/mpl2/core/assert.hpp>
#include <boost/mpl2/core/equal.hpp>

#include <climits>

template<typename integral>
bool test_integral(integral const& constant)
{
    using boost::mpl2::equal;
    using boost::mpl2::bool_;

    BOOST_MPL2_ASSERT((equal<typename integral::type::value_type, typename integral::value_type>));
    BOOST_MPL2_ASSERT(bool_<integral::type::value == integral::value>);

    return integral::value == constant;
}

#if !defined(SIZE_MAX)
    #define SIZE_MAX static_cast<std::size_t>(-1)
#endif

int main()
{
    return  !test_integral(boost::mpl2::true_())                    ||
            !test_integral(boost::mpl2::false_())                   ||
            !test_integral(boost::mpl2::bool_<true>())              ||
            !test_integral(boost::mpl2::bool_<false>())             ||
            !test_integral(boost::mpl2::char_<' '>())               ||
            !test_integral(boost::mpl2::uchar_<255>())              ||
            !test_integral(boost::mpl2::schar_<SCHAR_MIN>())        ||
            !test_integral(boost::mpl2::wchar_t_<L' '>())           ||
            !test_integral(boost::mpl2::char16_t_<u' '>())          ||
            !test_integral(boost::mpl2::char32_t_<U' '>())          ||
            !test_integral(boost::mpl2::short_<SHRT_MIN>())         ||
            !test_integral(boost::mpl2::ushort_<USHRT_MAX>())       ||
            !test_integral(boost::mpl2::int_<INT_MIN>())            ||
            !test_integral(boost::mpl2::uint_<UINT_MAX>())          ||
            !test_integral(boost::mpl2::long_<LONG_MIN>())          ||
            !test_integral(boost::mpl2::ulong_<ULONG_MAX>())        ||
            !test_integral(boost::mpl2::long_long_<LLONG_MIN>())     ||
            !test_integral(boost::mpl2::ulong_long_<ULLONG_MAX>())   ||
            !test_integral(boost::mpl2::size_t_<SIZE_MAX>());
}
