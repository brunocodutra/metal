/*
 * This file is part of metalog, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#include "boost/mpl2/seq.hpp"

int main()
{
    typedef boost::mpl2::seq<int, void, float> seq;

    return 0;
}
