/*
 * This file is part of metalog, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#include <boost/mpl2/arithmetic.hpp>
#include <boost/mpl2/datatypes/integer.hpp>

int main()
{
    return boost::mpl2::inc<boost::mpl2::int_<-1> >();
}
