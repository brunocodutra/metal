// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/lambda/logical/not.hpp>
#include <boost/mpl2/lambda/invoke.hpp>
#include <boost/mpl2/lambda/evaluator.hpp>
#include <boost/mpl2/lambda/bind.hpp>
#include <boost/mpl2/lambda/arg.hpp>
#include <boost/mpl2/lambda/traits.hpp>
#include <boost/mpl2/lambda/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

BOOST_MPL2_ASSERT((not_<is_function<invoke<_1, void> > >));
BOOST_MPL2_ASSERT((not_<is_function<invoke<evaluator<std::add_pointer>, void> > >));
BOOST_MPL2_ASSERT((is_invocable<evaluator<std::add_pointer>, void>));

BOOST_MPL2_ASSERT((std::is_same<invoke<evaluator<std::add_pointer>, void>::type, void*>));
BOOST_MPL2_ASSERT((std::is_same<invoke<bind<evaluator<std::add_pointer>, void> >::type, void*>));


int main()
{
    return 0;
}

