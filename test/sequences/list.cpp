// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/sequences/list.hpp>

typedef boost::mpl2::list<>::type empty;
typedef boost::mpl2::list<void>::type single;
typedef boost::mpl2::list<empty, int, void, single, float>::type list;

list::at<boost::mpl2::size_t_<3> >::type main()
{
    return single::size() + list::size() + empty::size() != 6;
}
