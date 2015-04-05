// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/core/protect.hpp>
#include <boost/mpl2/core/bind.hpp>
#include <boost/mpl2/core/apply.hpp>
#include <boost/mpl2/core/assert.hpp>

#include <type_traits>

using boost::mpl2::protect;
using boost::mpl2::bindf;
using boost::mpl2::apply;

BOOST_MPL2_ASSERT((
    std::is_same<
        apply<bindf<std::add_pointer, protect<bindf<std::add_pointer, void> > > >::type,
        protect<bindf<std::add_pointer, void> >*
    >
));

int main()
{
    return 0;
}
