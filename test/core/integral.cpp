// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/core/integral.hpp>

int main()
{
    return !(boost::mpl2::true_::next::next::next::prior() &&
             boost::mpl2::integral<std::ptrdiff_t, -1>() &&
             boost::mpl2::int_<41>::next() &&
             boost::mpl2::char_<'b'>::prior::type());
}
