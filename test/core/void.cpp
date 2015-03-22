// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/core/void.hpp>

int main()
{
    return !boost::mpl2::is_void_<boost::mpl2::void_>() ||
            boost::mpl2::is_not_void_<boost::mpl2::void_>();
}
