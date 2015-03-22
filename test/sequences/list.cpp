/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#include <boost/mpl2/sequences/list.hpp>

typedef boost::mpl2::list<>::type empty;
typedef boost::mpl2::list<void>::type single;
typedef boost::mpl2::list<empty, int, void, single, float>::type list;

list::at<boost::mpl2::size_t_<3> >::type main()
{
    return single::size() + list::size() + empty::size() != 6;
}
