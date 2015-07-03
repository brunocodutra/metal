// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/metal/functional/function.hpp>
#include <boost/metal/functional/quote.hpp>
#include <boost/metal/functional/arg.hpp>
#include <boost/metal/functional/bind.hpp>
#include <boost/metal/functional/lambda.hpp>
#include <boost/metal/functional/call.hpp>
#include <boost/metal/functional/traits/is_function.hpp>
#include <boost/metal/functional/traits/is_callable.hpp>

#include "test/expressions.hpp"
#include "test/functions.hpp"
#include "test/types.hpp"
#include "test/main.hpp"

using namespace boost::metal;

BOOST_METAL_ASSERT((is_function<function<test::a>>));
BOOST_METAL_ASSERT((is_function<function<test::b>>));
BOOST_METAL_ASSERT((is_function<function<test::c>>));
BOOST_METAL_ASSERT((is_function<function<test::d>>));
BOOST_METAL_ASSERT((is_function<function<test::e>>));
BOOST_METAL_ASSERT((is_function<function<test::f>>));
BOOST_METAL_ASSERT((is_function<function<test::g>>));
BOOST_METAL_ASSERT((is_function<function<test::h>>));
BOOST_METAL_ASSERT((is_function<function<test::i>>));
BOOST_METAL_ASSERT((is_function<function<test::j>>));

BOOST_METAL_ASSERT((not_<is_callable<function<test::a>>>));
BOOST_METAL_ASSERT((not_<is_callable<function<test::b>>>));
BOOST_METAL_ASSERT((not_<is_callable<function<test::c>>>));
BOOST_METAL_ASSERT((not_<is_callable<function<test::d>>>));
BOOST_METAL_ASSERT((not_<is_callable<function<test::e>>>));
BOOST_METAL_ASSERT((not_<is_callable<function<test::f>>>));
BOOST_METAL_ASSERT((not_<is_callable<function<test::g>>>));
BOOST_METAL_ASSERT((not_<is_callable<function<test::h>>>));
BOOST_METAL_ASSERT((not_<is_callable<function<test::i>>>));
BOOST_METAL_ASSERT((not_<is_callable<function<test::j>>>));

BOOST_METAL_ASSERT((is_function<test::nullary<test::incomplete>>));
BOOST_METAL_ASSERT((is_function<test::nullary<test::empty>>));
BOOST_METAL_ASSERT((is_function<test::nullary<test::evaluable>>));
BOOST_METAL_ASSERT((is_function<test::nullary<test::call>>));

BOOST_METAL_ASSERT((not_<is_callable<test::nullary<test::incomplete>>>));
BOOST_METAL_ASSERT((not_<is_callable<test::nullary<test::empty>>>));
BOOST_METAL_ASSERT((is_callable<test::nullary<test::evaluable>>));
BOOST_METAL_ASSERT((not_<is_callable<test::nullary<test::call>>>));

BOOST_METAL_ASSERT((is_function<test::unary<test::incomplete>>));
BOOST_METAL_ASSERT((is_function<test::unary<test::empty>>));
BOOST_METAL_ASSERT((is_function<test::unary<test::evaluable>>));
BOOST_METAL_ASSERT((is_function<test::unary<test::call>>));

BOOST_METAL_ASSERT((not_<is_callable<test::unary<test::incomplete>, test::a>>));
BOOST_METAL_ASSERT((not_<is_callable<test::unary<test::empty>, test::a>>));
BOOST_METAL_ASSERT((is_callable<test::unary<test::evaluable>, test::a>));
BOOST_METAL_ASSERT((not_<is_callable<test::unary<test::call>, test::a>>));

BOOST_METAL_ASSERT((is_function<test::binary<test::incomplete>>));
BOOST_METAL_ASSERT((is_function<test::binary<test::empty>>));
BOOST_METAL_ASSERT((is_function<test::binary<test::evaluable>>));
BOOST_METAL_ASSERT((is_function<test::binary<test::call>>));

BOOST_METAL_ASSERT((not_<is_callable<test::binary<test::incomplete>, test::a, test::b>>));
BOOST_METAL_ASSERT((not_<is_callable<test::binary<test::empty>, test::a, test::b>>));
BOOST_METAL_ASSERT((is_callable<test::binary<test::evaluable>, test::a, test::b>));
BOOST_METAL_ASSERT((not_<is_callable<test::binary<test::call>, test::a, test::b>>));

BOOST_METAL_ASSERT((is_function<test::n_ary<test::incomplete>>));
BOOST_METAL_ASSERT((is_function<test::n_ary<test::empty>>));
BOOST_METAL_ASSERT((is_function<test::n_ary<test::evaluable>>));
BOOST_METAL_ASSERT((is_function<test::n_ary<test::call>>));

BOOST_METAL_ASSERT((not_<is_callable<test::n_ary<test::incomplete>>>));
BOOST_METAL_ASSERT((not_<is_callable<test::n_ary<test::empty>>>));
BOOST_METAL_ASSERT((is_callable<test::n_ary<test::evaluable>>));
BOOST_METAL_ASSERT((not_<is_callable<test::n_ary<test::call>>>));

BOOST_METAL_ASSERT((std::is_same<call_t<call_t<quote<function>, placeholders::_1>, test::a>, test::a>));

using bound = bind<quote<std::add_pointer>, placeholders::_1>;

BOOST_METAL_ASSERT((is_function<bound>));
BOOST_METAL_ASSERT((is_function<function<bound>>));
BOOST_METAL_ASSERT((is_function<function<function<bound>>>));

BOOST_METAL_ASSERT((std::is_same<call_t<bound, void>, void*>));
BOOST_METAL_ASSERT((std::is_same<call_t<function<bound>, void>, void*>));
BOOST_METAL_ASSERT((std::is_same<call_t<function<function<bound>>, void>, void*>));

BOOST_METAL_ASSERT((std::is_same<call_t<bind<quote<std::add_pointer>, bound>, void>, void**>));
BOOST_METAL_ASSERT((std::is_same<call_t<bind<quote<std::add_pointer>, function<bound>>, void>, function<bound>*>));
BOOST_METAL_ASSERT((std::is_same<call_t<bind<quote<std::add_pointer>, function<function<bound>>>, void>, function<function<bound>>*>));

using lexpr = std::add_pointer<placeholders::_1>;

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<lexpr>, void>, void*>));
BOOST_METAL_ASSERT((std::is_same<call_t<function<lambda<lexpr>>, void>, void*>));

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<function<lexpr>>, void>, function<lexpr>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<function<function<lexpr>>>, void>, function<function<lexpr>>>));
