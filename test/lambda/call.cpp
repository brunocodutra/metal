// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/lambda/call.hpp>
#include <boost/mpl2/lambda/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

struct function
{
    template<typename... args>
    struct call{struct type {};};
};

BOOST_MPL2_ASSERT((std::is_same<call<function, void>::type, function::template call<void>::type >));

int main()
{
    return 0;
}

