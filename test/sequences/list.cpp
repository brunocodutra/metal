/*
 * This file is part of metalog, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#define BOOST_MPL2_LIMIT_METAFUNCTION_ARITY 5

#include <boost/mpl2/sequences/list.hpp>

typedef boost::mpl2::list<>::type empty;
typedef boost::mpl2::list<void>::type single;
typedef boost::mpl2::list<int, void, float>::type list;

int main()
{
    return single::size + list::size + empty::size - 4;
}
