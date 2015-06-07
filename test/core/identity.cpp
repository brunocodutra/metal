// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/core/identity.hpp>

#include "test/main.hpp"

using namespace boost::mpl2;

BOOST_MPL2_ASSERT((std::is_same<identity<void>::type, void>));
