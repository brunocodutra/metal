// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/metal/functional/protect.hpp>
#include <boost/metal/functional/quote.hpp>
#include <boost/metal/functional/bind.hpp>
#include <boost/metal/functional/lambda.hpp>
#include <boost/metal/functional/call.hpp>
#include <boost/metal/functional/placeholders.hpp>
#include <boost/metal/functional/traits/is_function.hpp>

#include "test/main.hpp"

using namespace boost::metal;

using bound = bind<quote<std::add_pointer>, placeholders::_1>;
using lexpr = std::add_pointer<placeholders::_1>;

BOOST_METAL_ASSERT((is_function<bound>));
BOOST_METAL_ASSERT((is_function<protect<bound>>));
BOOST_METAL_ASSERT((is_function<protect<protect<bound>>>));

BOOST_METAL_ASSERT((std::is_same<call_t<bound, void>, void*>));
BOOST_METAL_ASSERT((std::is_same<call_t<protect<bound>, void>, void*>));
BOOST_METAL_ASSERT((std::is_same<call_t<protect<protect<bound>>, void>, void*>));

BOOST_METAL_ASSERT((std::is_same<call_t<bind<quote<std::add_pointer>, bound>, void>, void**>));
BOOST_METAL_ASSERT((std::is_same<call_t<bind<quote<std::add_pointer>, protect<bound>>, void>, bound*>));
BOOST_METAL_ASSERT((std::is_same<call_t<bind<quote<std::add_pointer>, protect<protect<bound>>>, void>, protect<bound>*>));

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<lexpr>, void>, void*>));
BOOST_METAL_ASSERT((std::is_same<call_t<protect<lambda<lexpr>>, void>, void*>));

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<protect<lexpr>>, void>, lexpr>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<protect<protect<lexpr>>>, void>, protect<lexpr>>));
