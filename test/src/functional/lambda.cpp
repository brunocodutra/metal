/// @copyright Bruno Dutra 2015
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/metal/functional/lambda.hpp>
#include <boost/metal/functional/placeholders.hpp>
#include <boost/metal/functional/call.hpp>
#include <boost/metal/functional/protect.hpp>
#include <boost/metal/functional/traits.hpp>

#include "test/variadic.hpp"
#include "test/types.hpp"
#include "test/wrap.hpp"
#include "test/main.hpp"

using namespace boost::metal;
using namespace boost::metal::placeholders;

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::a>>, test::a>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::b>>, test::b>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::c>>, test::c>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::d>>, test::d>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::e>>, test::e>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::f>>, test::f>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::g>>, test::g>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::h>>, test::h>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::i>>, test::i>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::j>>, test::j>));

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::call<>>>, test::call<>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::evaluable<>>>, test::evaluable<>::type>));

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<_1>, void>, void>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<std::add_pointer<_1>>, void>, void*>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<protect<lambda<std::add_pointer<_1>>>>, void>, void*>));

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::wrapper>, short, int, long, long long>, test::wrapper>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<protect<test::wrapper>>, void>, test::wrap<void>>));

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::wrap<_1>>, short, int, long, long long>, test::wrap<short>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::wrap<_1, _2>>, short, int, long, long long>, test::wrap<short, int>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::wrap<_1, _2, _3>>, short, int, long, long long>, test::wrap<short, int, long>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::wrap<_1, _2, _3, _4>>, short, int, long, long long>, test::wrap<short, int, long, long long>>));

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<lambda<_1>>, void>, lambda<void>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<protect<lambda<_1>>>, void>, void>));

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<lambda<_1>>, protect<_1>>, lambda<protect<_1>>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<protect<_1>>, lambda<_1>>, lambda<_1>>));

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<quoter<protect>>, _1>, quoter<protect>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<protect<quoter<protect>>>, _1>, protect<_1>>));

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<call<lambda<std::add_pointer<_1>>, void>>, void*>, void**>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<call<_1, void>>, lambda<std::add_pointer<_1>>>, void*>));

using compose = protect<lambda<call<lambda<_1>, call<lambda<_2>, _3>>>>;
BOOST_METAL_ASSERT((is_function<compose>));
BOOST_METAL_ASSERT((std::is_same<call_t<compose, std::add_pointer<_1>, std::add_const<_1>, void>, void const*>));
BOOST_METAL_ASSERT((std::is_same<call_t<compose, std::add_const<_1>, std::add_pointer<_1>, void>, void* const>));

using once = protect<lambda<call<compose, protect<_1>, _1, _2>>>;
BOOST_METAL_ASSERT((is_function<once>));
BOOST_METAL_ASSERT((std::is_same<call_t<once, std::add_pointer<_1>, void>, void*>));

using twice = protect<lambda<call<compose, _1, _1, _2>>>;
BOOST_METAL_ASSERT((is_function<twice>));
BOOST_METAL_ASSERT((std::is_same<call_t<twice, std::add_pointer<_1>, void>, void**>));

using thrice = protect<lambda<call<once, _1, call<twice, _1, _2>>>>;
BOOST_METAL_ASSERT((is_function<thrice>));
BOOST_METAL_ASSERT((std::is_same<call_t<thrice, std::add_pointer<_1>, void>, void***>));

using ptr2ptr2ptr = protect<lambda<call<thrice, protect<lambda<std::add_pointer<_1>>>, _1>>>;
BOOST_METAL_ASSERT((is_function<ptr2ptr2ptr>));
BOOST_METAL_ASSERT((std::is_same<call_t<ptr2ptr2ptr, void>, void***>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<ptr2ptr2ptr>, void>, void***>));
