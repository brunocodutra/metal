/*
 * This file is part of metalog, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#include <boost/mpl2/datatypes/integral.hpp>
#include <boost/mpl2/datatypes/boolean.hpp>
#include <boost/mpl2/datatypes/integer.hpp>
#include <boost/mpl2/datatypes/character.hpp>
#include <boost/mpl2/datatypes/size_t.hpp>

int main()
{
    return !(boost::mpl2::true_() &&
             boost::mpl2::integral<std::ptrdiff_t, -1>() &&
             boost::mpl2::int_<42>() &&
             boost::mpl2::char_<'a'>::type());
}
