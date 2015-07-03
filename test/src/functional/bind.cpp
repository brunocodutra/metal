// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/metal/functional/bind.hpp>
#include <boost/metal/functional/arg.hpp>
#include <boost/metal/functional/verbatim.hpp>
#include <boost/metal/functional/function.hpp>
#include <boost/metal/functional/quote.hpp>
#include <boost/metal/functional/call.hpp>
#include <boost/metal/functional/traits.hpp>

#include "test/types.hpp"
#include "test/wrap.hpp"
#include "test/main.hpp"

using namespace boost::metal;
using namespace boost::metal::placeholders;

BOOST_METAL_ASSERT((std::is_same<call_t<bind<test::wrapper>, void, void*>, test::wrap<>>));
BOOST_METAL_ASSERT((std::is_same<call_t<bind<test::wrapper, _1>, test::a, test::b, test::c, test::d>, test::wrap<test::a>>));
BOOST_METAL_ASSERT((std::is_same<call_t<bind<test::wrapper, _1, _2>, test::a, test::b, test::c, test::d>, test::wrap<test::a, test::b>>));
BOOST_METAL_ASSERT((std::is_same<call_t<bind<test::wrapper, _1, _2, _3>, test::a, test::b, test::c, test::d>, test::wrap<test::a, test::b, test::c>>));
BOOST_METAL_ASSERT((std::is_same<call_t<bind<test::wrapper, _1, _2, _3, _4>, test::a, test::b, test::c, test::d>, test::wrap<test::a, test::b, test::c, test::d>>));

BOOST_METAL_ASSERT((std::is_same<call_t<bind<verbatim<test::wrapper>>, void, void*>, test::wrap<>>));
BOOST_METAL_ASSERT((std::is_same<call_t<bind<verbatim<test::wrapper>, verbatim<_1>>, test::a, test::b, test::c, test::d>, test::wrap<_1>>));
BOOST_METAL_ASSERT((std::is_same<call_t<bind<verbatim<test::wrapper>, verbatim<_1>, _2>, test::a, test::b, test::c, test::d>, test::wrap<_1, test::b>>));
BOOST_METAL_ASSERT((std::is_same<call_t<bind<verbatim<test::wrapper>, _1, verbatim<_2>, _3>, test::a, test::b, test::c, test::d>, test::wrap<test::a, _2, test::c>>));
BOOST_METAL_ASSERT((std::is_same<call_t<bind<verbatim<test::wrapper>, _1, _2, verbatim<_3>, _4>, test::a, test::b, test::c, test::d>, test::wrap<test::a, test::b, _3, test::d>>));

BOOST_METAL_ASSERT((std::is_same<call_t<bind<function<test::wrapper>>, void, void*>, test::wrap<>>));
BOOST_METAL_ASSERT((std::is_same<call_t<bind<function<test::wrapper>, function<_1>>, test::a, test::b, test::c, test::d>, test::wrap<function<_1>>>));
BOOST_METAL_ASSERT((std::is_same<call_t<bind<function<test::wrapper>, function<_1>, _2>, test::a, test::b, test::c, test::d>, test::wrap<function<_1>, test::b>>));
BOOST_METAL_ASSERT((std::is_same<call_t<bind<function<test::wrapper>, _1, function<_2>, _3>, test::a, test::b, test::c, test::d>, test::wrap<test::a, function<_2>, test::c>>));
BOOST_METAL_ASSERT((std::is_same<call_t<bind<function<test::wrapper>, _1, _2, function<_3>, _4>, test::a, test::b, test::c, test::d>, test::wrap<test::a, test::b, function<_3>, test::d>>));

BOOST_METAL_ASSERT((std::is_same<call_t<bind<_1, _2>, test::wrapper, void>, test::wrap<void>>));
BOOST_METAL_ASSERT((std::is_same<call_t<bind<_1, _2, _1>, test::wrapper, void>, test::wrap<void, test::wrapper>>));

BOOST_METAL_ASSERT((std::is_same<call_t<bind<verbatim<_1>, _2>, test::wrapper, void>, void>));
BOOST_METAL_ASSERT((std::is_same<call_t<bind<verbatim<_1>, _2, _1>, test::wrapper, void>, void>));

BOOST_METAL_ASSERT((std::is_same<call_t<bind<function<_1>, _2>, test::wrapper, void>, void>));
BOOST_METAL_ASSERT((std::is_same<call_t<bind<function<_1>, _2, _1>, test::wrapper, void>, void>));

BOOST_METAL_ASSERT((std::is_same<call_t<bind<_0>, test::wrapper, void>, test::wrap<void>>));
BOOST_METAL_ASSERT((std::is_same<call_t<bind<_0, _0>, test::wrapper, void>, test::wrap<void, test::wrapper, void>>));
BOOST_METAL_ASSERT((std::is_same<call_t<bind<_0, _0, _0>, test::wrapper, void>, test::wrap<void, test::wrapper, void, test::wrapper, void>>));

BOOST_METAL_ASSERT((std::is_same<call_t<bind<_0, verbatim<_0>>, test::wrapper, void>, test::wrap<void, _0>>));
BOOST_METAL_ASSERT((std::is_same<call_t<bind<_0, verbatim<_0>, _0>, test::wrapper, void>, test::wrap<void, _0, test::wrapper, void>>));

BOOST_METAL_ASSERT((std::is_same<call_t<bind<_0, function<_0>>, test::wrapper, void>, test::wrap<void, function<_0>>>));
BOOST_METAL_ASSERT((std::is_same<call_t<bind<_0, function<_0>, _0>, test::wrapper, void>, test::wrap<void, function<_0>, test::wrapper, void>>));

using chain = function<bind<_1, bind<_2, _3>>>;
BOOST_METAL_ASSERT((is_function<chain>));
BOOST_METAL_ASSERT((std::is_same<call_t<chain, quote<std::add_pointer>, quote<std::add_const>, void>, void const*>));
BOOST_METAL_ASSERT((std::is_same<call_t<chain, quote<std::add_const>, quote<std::add_pointer>, void>, void* const>));

using once = function<bind<chain, function<_1>, _1, _2>>;
BOOST_METAL_ASSERT((is_function<once>));
BOOST_METAL_ASSERT((std::is_same<call_t<once, quote<std::add_pointer>, void>, void*>));

using twice = function<bind<chain, _1, _1, _2>>;
BOOST_METAL_ASSERT((is_function<twice>));
BOOST_METAL_ASSERT((std::is_same<call_t<twice, quote<std::add_pointer>, void>, void**>));

using thrice = function<bind<once, _1, bind<twice, _1, _2>>>;
BOOST_METAL_ASSERT((is_function<thrice>));
BOOST_METAL_ASSERT((std::is_same<call_t<thrice, quote<std::add_pointer>, void>, void***>));

using ptr2ptr2ptr = function<bind<thrice, quote<std::add_pointer>, _1>>;
BOOST_METAL_ASSERT((is_function<ptr2ptr2ptr>));
BOOST_METAL_ASSERT((std::is_same<call_t<ptr2ptr2ptr, void>, void***>));
BOOST_METAL_ASSERT((std::is_same<call_t<bind<ptr2ptr2ptr, void>>, void***>));
