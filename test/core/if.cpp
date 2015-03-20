/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#include <boost/mpl2/core/if.hpp>
#include <boost/mpl2/core/integral.hpp>
#include <boost/mpl2/core/identity.hpp>

struct tautology :
        boost::mpl2::char_<'c'>
{};

struct contradiction
{
    typedef boost::mpl2::ulong_<0UL> type;
};

int main()
{
    return !boost::mpl2::if_<boost::mpl2::true_, boost::mpl2::true_, boost::mpl2::false_>() ||
            boost::mpl2::if_<boost::mpl2::identity<boost::mpl2::false_>, boost::mpl2::true_, boost::mpl2::false_>()||
           !boost::mpl2::if_<tautology, boost::mpl2::true_, boost::mpl2::false_>() ||
            boost::mpl2::if_<contradiction, boost::mpl2::true_, boost::mpl2::false_>();
}
