// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/metafunctional/quote.hpp>
#include <boost/mpl2/metafunctional/traits.hpp>

#include "test.hpp"

using namespace boost::mpl2;

BOOST_MPL2_ASSERT((is_function<quote<std::add_pointer> >));
BOOST_MPL2_ASSERT((is_callable<quote<std::add_pointer>, void>));
BOOST_MPL2_ASSERT((std::is_same<quote<std::add_pointer>::call<void>::type, std::add_pointer<void> >));

int main()
{
    return 0;
}
