// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/core/if.hpp>
#include <boost/mpl2/core/integral.hpp>
#include <boost/mpl2/core/identity.hpp>

struct tautology :
        boost::mpl2::char_<'c'>
{};

struct contradiction :
        boost::mpl2::ulong_<0UL>
{};

int main()
{
    return !boost::mpl2::if_<boost::mpl2::true_, boost::mpl2::true_, boost::mpl2::false_>() ||
           !boost::mpl2::if_<tautology, boost::mpl2::true_, boost::mpl2::false_>() ||
            boost::mpl2::if_<contradiction, boost::mpl2::true_, boost::mpl2::false_>();
}
