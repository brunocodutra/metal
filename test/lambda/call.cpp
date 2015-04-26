// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/lambda/logical/not.hpp>
#include <boost/mpl2/lambda/call.hpp>
#include <boost/mpl2/lambda/function.hpp>
#include <boost/mpl2/lambda/bind.hpp>
#include <boost/mpl2/lambda/arg.hpp>
#include <boost/mpl2/lambda/traits.hpp>
#include <boost/mpl2/lambda/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

BOOST_MPL2_ASSERT((not_<is_function<call<function<std::add_pointer>, void> > >));
BOOST_MPL2_ASSERT((is_callable<function<std::add_pointer>, void>));
BOOST_MPL2_ASSERT((is_evaluable<call<function<std::add_pointer>, void> >));
BOOST_MPL2_ASSERT((
    std::is_base_of<
        std::add_pointer<void>,
        call<function<std::add_pointer>, void>
    >
));

BOOST_MPL2_ASSERT((std::is_same<call<function<std::add_pointer>, void>::type, void*>));
BOOST_MPL2_ASSERT((std::is_same<call<bind<function<std::add_pointer>, void> >::type, void*>));

BOOST_MPL2_ASSERT((call<function<not_>, false_>));
BOOST_MPL2_ASSERT((call<function<not_>, false_>::type));

int main()
{
    return 0;
}

