// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/core/arithmetic.hpp>
#include <boost/mpl2/core/integral.hpp>
#include <boost/mpl2/core/comparison/equal.hpp>
#include <boost/mpl2/core/assert.hpp>

int main()
{
    using boost::mpl2::inc;
    using boost::mpl2::dec;
    using boost::mpl2::negate;
    using boost::mpl2::equal;
    using boost::mpl2::true_;
    using boost::mpl2::false_;

    typedef boost::mpl2::int_<0> zero;
    typedef boost::mpl2::int_<1> one;

    BOOST_MPL2_ASSERT((equal<inc<zero>, one>));
    BOOST_MPL2_ASSERT((equal<dec<zero>, negate<one> >));
    BOOST_MPL2_ASSERT((equal<inc<dec<one> >, one>));
    BOOST_MPL2_ASSERT((equal<inc<dec<one> >, dec<inc<one> > >));
    BOOST_MPL2_ASSERT((equal<negate<zero>, zero>));
    BOOST_MPL2_ASSERT((equal<inc<negate<one> >, zero>));
    BOOST_MPL2_ASSERT((equal<negate<negate<one> >, one>));
    BOOST_MPL2_ASSERT(negate<false_>);
    BOOST_MPL2_ASSERT(negate<negate<true_> >);

    return zero() || dec<one>() || inc<negate<one> >();
}
