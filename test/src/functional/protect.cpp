// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/metal/functional/protect.hpp>
#include <boost/metal/functional/evaluator.hpp>
#include <boost/metal/functional/bind.hpp>
#include <boost/metal/functional/traits.hpp>

#include "test/main.hpp"

using namespace boost::metal;

using bound = bind<evaluator<std::add_pointer>, void>;

BOOST_METAL_ASSERT((is_function<bound>));
BOOST_METAL_ASSERT((is_function<protect<bound>>));

BOOST_METAL_ASSERT((std::is_same<bound::call<>::type, void*>));
BOOST_METAL_ASSERT((std::is_same<protect<bound>::call<>::type, void*>));

BOOST_METAL_ASSERT((std::is_same<bind<evaluator<std::add_pointer>, bound>::call<>::type, void**>));
BOOST_METAL_ASSERT((std::is_same<bind<evaluator<std::add_pointer>, protect<bound>>::call<>::type, protect<bound>*>));
