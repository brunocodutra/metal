// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/core/quote.hpp>
#include <boost/mpl2/core/assert.hpp>

#include <type_traits>

using boost::mpl2::quote;

template<typename x>
using f = std::add_pointer<x>;

template<typename x>
using g = quote<std::add_pointer>::type<x>;

BOOST_MPL2_ASSERT((std::is_same<f<void>::type, g<void>::type>));

int main()
{
    return 0;
}
