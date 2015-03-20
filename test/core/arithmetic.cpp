/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#include <boost/mpl2/core/arithmetic.hpp>
#include <boost/mpl2/core/integral.hpp>

int main()
{
    return (boost::mpl2::inc<boost::mpl2::int_<0> >() +
            boost::mpl2::dec<boost::mpl2::int_<0> >());
}
