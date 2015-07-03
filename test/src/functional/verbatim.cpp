// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/metal/functional/verbatim.hpp>
#include <boost/metal/functional/quote.hpp>
#include <boost/metal/functional/arg.hpp>
#include <boost/metal/functional/bind.hpp>
#include <boost/metal/functional/lambda.hpp>
#include <boost/metal/functional/call.hpp>

#include "test/main.hpp"

using namespace boost::metal;

BOOST_METAL_ASSERT((std::is_same<verbatim<void>::type, verbatim<void>>));
BOOST_METAL_ASSERT((std::is_same<call_t<quote<verbatim>, void>, verbatim<void>>));

BOOST_METAL_ASSERT((call_t<bind<verbatim<placeholders::_1>, verbatim<std::true_type>>>));
BOOST_METAL_ASSERT((call_t<lambda<verbatim<std::true_type>>>));

using bound = bind<quote<std::add_pointer>, placeholders::_1>;

BOOST_METAL_ASSERT((std::is_same<call_t<bind<verbatim<quote<std::add_pointer>>, verbatim<bound>>, void>, bound*>));
BOOST_METAL_ASSERT((std::is_same<call_t<bind<quote<std::add_pointer>, verbatim<verbatim<bound>>>, void>, verbatim<bound>*>));

using lexpr = std::add_pointer<placeholders::_1>;

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<verbatim<lexpr>>, void>, lexpr>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<verbatim<verbatim<lexpr>>>, void>, verbatim<lexpr>>));
