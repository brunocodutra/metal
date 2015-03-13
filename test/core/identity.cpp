/*
 * This file is part of metalog, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#include <boost/mpl2/core/identity.hpp>
#include <boost/mpl2/core/integral/boolean.hpp>

int main()
{
    return !boost::mpl2::identity<boost::mpl2::true_>::type();
}
