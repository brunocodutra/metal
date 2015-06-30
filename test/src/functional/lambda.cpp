// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

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

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<protect<test::a>>>, test::a>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<protect<test::b>>>, test::b>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<protect<test::c>>>, test::c>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<protect<test::d>>>, test::d>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<protect<test::e>>>, test::e>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<protect<test::f>>>, test::f>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<protect<test::g>>>, test::g>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<protect<test::h>>>, test::h>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<protect<test::i>>>, test::i>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<protect<test::j>>>, test::j>));

BOOST_METAL_ASSERT((not_<is_callable_t<lambda<test::call<>>>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::evaluable<>>>, test::evaluable<>::type>));

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<protect<test::call<>>>>, test::call<>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<protect<test::evaluable<>>>>, test::evaluable<>>));

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::wrapper>, void>, test::wrapper>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<protect<test::wrapper>>, void>, test::wrapper>));

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<std::add_pointer<_1>>, void>, void*>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<protect<lambda<std::add_pointer<_1>>>>, void>, lambda<std::add_pointer<_1>>>));

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<call<lambda<std::add_pointer<_1>>, void>>, void*>, void**>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<call<protect<lambda<std::add_pointer<_1>>>, void>>, void*>, void*>));

BOOST_METAL_ASSERT((not_<is_callable_t<lambda<_0>>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<_1>, short, int, long, long long>, short>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<_2>, short, int, long, long long>, int>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<_3>, short, int, long, long long>, long>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<_4>, short, int, long, long long>, long long>));

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<protect<_0>>, short, int, long, long long>, _0>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<protect<_1>>, short, int, long, long long>, _1>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<protect<_2>>, short, int, long, long long>, _2>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<protect<_3>>, short, int, long, long long>, _3>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<protect<_4>>, short, int, long, long long>, _4>));

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::wrap<_0>>, short, int, long, long long>, test::wrap<short, int, long, long long>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::wrap<_1>>, short, int, long, long long>, test::wrap<short>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::wrap<_1, _2>>, short, int, long, long long>, test::wrap<short, int>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::wrap<_1, _2, _3>>, short, int, long, long long>, test::wrap<short, int, long>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<test::wrap<_1, _2, _3, _4>>, short, int, long, long long>, test::wrap<short, int, long, long long>>));

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<protect<test::wrap<_0>>>, short, int, long, long long>, test::wrap<_0>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<protect<test::wrap<_1>>>, short, int, long, long long>, test::wrap<_1>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<protect<test::wrap<_1, _2>>>, short, int, long, long long>, test::wrap<_1, _2>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<protect<test::wrap<_1, _2, _3>>>, short, int, long, long long>, test::wrap<_1, _2, _3>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<protect<test::wrap<_1, _2, _3, _4>>>, short, int, long, long long>, test::wrap<_1, _2, _3, _4>>));

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<call<_0>>, test::wrapper, void>, test::wrap<void>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<call<_0, _0>>, test::wrapper, void>, test::wrap<void, test::wrapper, void>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<call<_0, _0, _0>>, test::wrapper, void>, test::wrap<void, test::wrapper, void, test::wrapper, void>>));

BOOST_METAL_ASSERT((not_<is_callable_t<lambda<call<protect<_0>>>, test::wrapper, void>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<call<_0, protect<_0>>>, test::wrapper, void>, test::wrap<void, _0>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<call<_0, protect<_0>, _0>>, test::wrapper, void>, test::wrap<void, _0, test::wrapper, void>>));

BOOST_METAL_ASSERT((std::is_same<call_t<lambda<lambda<_1>>, void>, lambda<void>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<protect<lambda<_1>>>, void>, lambda<_1>>));
BOOST_METAL_ASSERT((std::is_same<call_t<lambda<lambda<_1>>, protect<_1>>, lambda<protect<_1>>>));

using chain = protect<lambda<call<lambda<_1>, call<lambda<_2>, _3>>>>;
BOOST_METAL_ASSERT((is_function<chain>));
BOOST_METAL_ASSERT((std::is_same<call_t<chain, std::add_pointer<_1>, std::add_const<_1>, void>, void const*>));
BOOST_METAL_ASSERT((std::is_same<call_t<chain, std::add_const<_1>, std::add_pointer<_1>, void>, void* const>));

using once = protect<lambda<call<chain, protect<_1>, _1, _2>>>;
BOOST_METAL_ASSERT((is_function<once>));
BOOST_METAL_ASSERT((std::is_same<call_t<once, std::add_pointer<_1>, void>, void*>));

using twice = protect<lambda<call<chain, _1, _1, _2>>>;
BOOST_METAL_ASSERT((is_function<twice>));
BOOST_METAL_ASSERT((std::is_same<call_t<twice, std::add_pointer<_1>, void>, void**>));

using thrice = protect<lambda<call<once, _1, call<twice, _1, _2>>>>;
BOOST_METAL_ASSERT((is_function<thrice>));
BOOST_METAL_ASSERT((std::is_same<call_t<thrice, std::add_pointer<_1>, void>, void***>));

using ptr2ptr2ptr = protect<lambda<call<thrice, protect<std::add_pointer<_1>>, _1>>>;
BOOST_METAL_ASSERT((is_function<ptr2ptr2ptr>));
BOOST_METAL_ASSERT((std::is_same<call_t<ptr2ptr2ptr, void>, void***>));
