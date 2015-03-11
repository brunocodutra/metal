/*
 * This file is part of metalog, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#include <boost/mpl2/core/void.hpp>

int main()
{
    return !boost::mpl2::is_void_<boost::mpl2::void_>() ||
            boost::mpl2::is_not_void_<boost::mpl2::void_>();
}
