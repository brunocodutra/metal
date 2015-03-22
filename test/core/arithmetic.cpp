// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/core/arithmetic.hpp>
#include <boost/mpl2/core/integral.hpp>

int main()
{
    return (boost::mpl2::inc<boost::mpl2::int_<0> >() +
            boost::mpl2::dec<boost::mpl2::int_<0> >());
}
