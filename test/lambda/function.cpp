// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/lambda/logical/not.hpp>
#include <boost/mpl2/lambda/function.hpp>
#include <boost/mpl2/lambda/invoke.hpp>
#include <boost/mpl2/lambda/traits.hpp>
#include <boost/mpl2/lambda/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

using f = function<std::add_pointer>;

BOOST_MPL2_ASSERT(is_function<f>);
BOOST_MPL2_ASSERT((is_callable<f, void>));
BOOST_MPL2_ASSERT((std::is_same<invoke<f, void>::type, void*>));

int main()
{
    return 0;
}
