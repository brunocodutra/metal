// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/metal/functional/evaluator.hpp>
#include <boost/metal/functional/traits.hpp>

#include "test/main.hpp"

using namespace boost::metal;

BOOST_METAL_ASSERT((is_function<evaluator<std::add_pointer>>));
BOOST_METAL_ASSERT((is_callable<evaluator<std::add_pointer>, void>));
BOOST_METAL_ASSERT((std::is_same<evaluator<std::add_pointer>::call<void>::type, void*>));
