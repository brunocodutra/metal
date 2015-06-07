// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/functional/evaluator.hpp>
#include <boost/mpl2/functional/traits.hpp>

#include "test/main.hpp"

using namespace boost::mpl2;

BOOST_MPL2_ASSERT((is_function<evaluator<std::add_pointer>>));
BOOST_MPL2_ASSERT((is_callable<evaluator<std::add_pointer>, void>));
BOOST_MPL2_ASSERT((std::is_same<evaluator<std::add_pointer>::call<void>::type, void*>));
