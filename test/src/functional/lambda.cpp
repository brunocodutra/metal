/// @copyright Bruno Dutra 2015
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/lambda.hpp>
#include <metal/functional/arg.hpp>
#include <metal/functional/verbatim.hpp>
#include <metal/functional/function.hpp>
#include <metal/functional/call.hpp>
#include <metal/functional/traits.hpp>

#include "test/types.hpp"
#include "test/wrap.hpp"
#include "test/main.hpp"

using namespace metal;
using namespace metal::placeholders;

METAL_ASSERT((std::is_same<lambda<void>::type, lambda<void>>));

METAL_ASSERT((std::is_same<call_t<lambda<test::a>>, test::a>));
METAL_ASSERT((std::is_same<call_t<lambda<test::b>>, test::b>));
METAL_ASSERT((std::is_same<call_t<lambda<test::c>>, test::c>));
METAL_ASSERT((std::is_same<call_t<lambda<test::d>>, test::d>));
METAL_ASSERT((std::is_same<call_t<lambda<test::e>>, test::e>));
METAL_ASSERT((std::is_same<call_t<lambda<test::f>>, test::f>));
METAL_ASSERT((std::is_same<call_t<lambda<test::g>>, test::g>));
METAL_ASSERT((std::is_same<call_t<lambda<test::h>>, test::h>));
METAL_ASSERT((std::is_same<call_t<lambda<test::i>>, test::i>));
METAL_ASSERT((std::is_same<call_t<lambda<test::j>>, test::j>));

METAL_ASSERT((std::is_same<call_t<lambda<verbatim<test::a>>>, test::a>));
METAL_ASSERT((std::is_same<call_t<lambda<verbatim<test::b>>>, test::b>));
METAL_ASSERT((std::is_same<call_t<lambda<verbatim<test::c>>>, test::c>));
METAL_ASSERT((std::is_same<call_t<lambda<verbatim<test::d>>>, test::d>));
METAL_ASSERT((std::is_same<call_t<lambda<verbatim<test::e>>>, test::e>));
METAL_ASSERT((std::is_same<call_t<lambda<verbatim<test::f>>>, test::f>));
METAL_ASSERT((std::is_same<call_t<lambda<verbatim<test::g>>>, test::g>));
METAL_ASSERT((std::is_same<call_t<lambda<verbatim<test::h>>>, test::h>));
METAL_ASSERT((std::is_same<call_t<lambda<verbatim<test::i>>>, test::i>));
METAL_ASSERT((std::is_same<call_t<lambda<verbatim<test::j>>>, test::j>));

METAL_ASSERT((not_<is_callable_t<lambda<test::call<>>>>));
METAL_ASSERT((std::is_same<call_t<lambda<test::evaluable<>>>, test::evaluable<>::type>));

METAL_ASSERT((std::is_same<call_t<lambda<verbatim<test::call<>>>>, test::call<>>));
METAL_ASSERT((std::is_same<call_t<lambda<verbatim<test::evaluable<>>>>, test::evaluable<>>));

METAL_ASSERT((std::is_same<call_t<lambda<test::wrapper>, void>, test::wrapper>));
METAL_ASSERT((std::is_same<call_t<lambda<verbatim<test::wrapper>>, void>, test::wrapper>));
METAL_ASSERT((std::is_same<call_t<lambda<function<test::wrapper>>, void>, function<test::wrapper>>));

METAL_ASSERT((std::is_same<call_t<lambda<lambda<std::add_pointer<_1>>>, void>, lambda<void*>>));
METAL_ASSERT((std::is_same<call_t<lambda<verbatim<lambda<std::add_pointer<_1>>>>, void>, lambda<std::add_pointer<_1>>>));
METAL_ASSERT((std::is_same<call_t<lambda<function<lambda<std::add_pointer<_1>>>>, void>, function<lambda<std::add_pointer<_1>>>>));

METAL_ASSERT((std::is_same<call_t<lambda<call<lambda<std::add_pointer<_1>>, void>>, void*>, void**>));
METAL_ASSERT((std::is_same<call_t<lambda<call<verbatim<lambda<std::add_pointer<_1>>>, void>>, void*>, void*>));
METAL_ASSERT((std::is_same<call_t<lambda<call<function<lambda<std::add_pointer<_1>>>, void>>, void*>, void*>));

METAL_ASSERT((not_<is_callable_t<lambda<_0>>>));
METAL_ASSERT((std::is_same<call_t<lambda<_1>, test::a, test::b, test::c, test::d>, test::a>));
METAL_ASSERT((std::is_same<call_t<lambda<_2>, test::a, test::b, test::c, test::d>, test::b>));
METAL_ASSERT((std::is_same<call_t<lambda<_3>, test::a, test::b, test::c, test::d>, test::c>));
METAL_ASSERT((std::is_same<call_t<lambda<_4>, test::a, test::b, test::c, test::d>, test::d>));

METAL_ASSERT((std::is_same<call_t<lambda<verbatim<_0>>, test::a, test::b, test::c, test::d>, _0>));
METAL_ASSERT((std::is_same<call_t<lambda<verbatim<_1>>, test::a, test::b, test::c, test::d>, _1>));
METAL_ASSERT((std::is_same<call_t<lambda<verbatim<_2>>, test::a, test::b, test::c, test::d>, _2>));
METAL_ASSERT((std::is_same<call_t<lambda<verbatim<_3>>, test::a, test::b, test::c, test::d>, _3>));
METAL_ASSERT((std::is_same<call_t<lambda<verbatim<_4>>, test::a, test::b, test::c, test::d>, _4>));

METAL_ASSERT((std::is_same<call_t<lambda<function<_0>>, test::a, test::b, test::c, test::d>, function<_0>>));
METAL_ASSERT((std::is_same<call_t<lambda<function<_1>>, test::a, test::b, test::c, test::d>, function<_1>>));
METAL_ASSERT((std::is_same<call_t<lambda<function<_2>>, test::a, test::b, test::c, test::d>, function<_2>>));
METAL_ASSERT((std::is_same<call_t<lambda<function<_3>>, test::a, test::b, test::c, test::d>, function<_3>>));
METAL_ASSERT((std::is_same<call_t<lambda<function<_4>>, test::a, test::b, test::c, test::d>, function<_4>>));

METAL_ASSERT((std::is_same<call_t<lambda<test::wrap<_0>>, test::a, test::b, test::c, test::d>, test::wrap<test::a, test::b, test::c, test::d>>));
METAL_ASSERT((std::is_same<call_t<lambda<test::wrap<_1>>, test::a, test::b, test::c, test::d>, test::wrap<test::a>>));
METAL_ASSERT((std::is_same<call_t<lambda<test::wrap<_1, _2>>, test::a, test::b, test::c, test::d>, test::wrap<test::a, test::b>>));
METAL_ASSERT((std::is_same<call_t<lambda<test::wrap<_1, _2, _3>>, test::a, test::b, test::c, test::d>, test::wrap<test::a, test::b, test::c>>));
METAL_ASSERT((std::is_same<call_t<lambda<test::wrap<_1, _2, _3, _4>>, test::a, test::b, test::c, test::d>, test::wrap<test::a, test::b, test::c, test::d>>));

METAL_ASSERT((std::is_same<call_t<lambda<verbatim<test::wrap<_0>>>, test::a, test::b, test::c, test::d>, test::wrap<_0>>));
METAL_ASSERT((std::is_same<call_t<lambda<verbatim<test::wrap<_1>>>, test::a, test::b, test::c, test::d>, test::wrap<_1>>));
METAL_ASSERT((std::is_same<call_t<lambda<verbatim<test::wrap<_1, _2>>>, test::a, test::b, test::c, test::d>, test::wrap<_1, _2>>));
METAL_ASSERT((std::is_same<call_t<lambda<verbatim<test::wrap<_1, _2, _3>>>, test::a, test::b, test::c, test::d>, test::wrap<_1, _2, _3>>));
METAL_ASSERT((std::is_same<call_t<lambda<verbatim<test::wrap<_1, _2, _3, _4>>>, test::a, test::b, test::c, test::d>, test::wrap<_1, _2, _3, _4>>));

METAL_ASSERT((std::is_same<call_t<lambda<call<_1, _2>>, test::wrapper, void>, test::wrap<void>>));
METAL_ASSERT((std::is_same<call_t<lambda<call<_1, _2, _1>>, test::wrapper, void>, test::wrap<void, test::wrapper>>));

METAL_ASSERT((std::is_same<call_t<lambda<call<verbatim<_1>, _2>>, test::wrapper, void>, void>));
METAL_ASSERT((std::is_same<call_t<lambda<call<verbatim<_1>, _2, _1>>, test::wrapper, void>, void>));

METAL_ASSERT((std::is_same<call_t<lambda<call<function<_1>, _2>>, test::wrapper, void>, void>));
METAL_ASSERT((std::is_same<call_t<lambda<call<function<_1>, _2, _1>>, test::wrapper, void>, void>));

METAL_ASSERT((std::is_same<call_t<lambda<call<_0>>, test::wrapper, void>, test::wrap<void>>));
METAL_ASSERT((std::is_same<call_t<lambda<call<_0, _0>>, test::wrapper, void>, test::wrap<void, test::wrapper, void>>));
METAL_ASSERT((std::is_same<call_t<lambda<call<_0, _0, _0>>, test::wrapper, void>, test::wrap<void, test::wrapper, void, test::wrapper, void>>));

METAL_ASSERT((std::is_same<call_t<lambda<call<_0, verbatim<_0>>>, test::wrapper, void>, test::wrap<void, _0>>));
METAL_ASSERT((std::is_same<call_t<lambda<call<_0, verbatim<_0>, _0>>, test::wrapper, void>, test::wrap<void, _0, test::wrapper, void>>));

METAL_ASSERT((std::is_same<call_t<lambda<call<_0, function<_0>>>, test::wrapper, void>, test::wrap<void, function<_0>>>));
METAL_ASSERT((std::is_same<call_t<lambda<call<_0, function<_0>, _0>>, test::wrapper, void>, test::wrap<void, function<_0>, test::wrapper, void>>));

METAL_ASSERT((std::is_same<call_t<lambda<lambda<_1>>, void>, lambda<void>>));
METAL_ASSERT((std::is_same<call_t<lambda<verbatim<lambda<_1>>>, void>, lambda<_1>>));
METAL_ASSERT((std::is_same<call_t<lambda<lambda<_1>>, verbatim<_1>>, lambda<verbatim<_1>>>));

METAL_ASSERT((std::is_same<call_t<lambda<lambda<_1>>, void>, lambda<void>>));
METAL_ASSERT((std::is_same<call_t<lambda<function<lambda<_1>>>, void>, function<lambda<_1>>>));
METAL_ASSERT((std::is_same<call_t<lambda<lambda<_1>>, function<_1>>, lambda<function<_1>>>));

using chain = function<lambda<call<lambda<_1>, call<lambda<_2>, _3>>>>;
METAL_ASSERT((is_function<chain>));
METAL_ASSERT((std::is_same<call_t<chain, std::add_pointer<_1>, std::add_const<_1>, void>, void const*>));
METAL_ASSERT((std::is_same<call_t<chain, std::add_const<_1>, std::add_pointer<_1>, void>, void* const>));

using once = function<lambda<call<chain, verbatim<_1>, _1, _2>>>;
METAL_ASSERT((is_function<once>));
METAL_ASSERT((std::is_same<call_t<once, std::add_pointer<_1>, void>, void*>));

using twice = function<lambda<call<chain, _1, _1, _2>>>;
METAL_ASSERT((is_function<twice>));
METAL_ASSERT((std::is_same<call_t<twice, std::add_pointer<_1>, void>, void**>));

using thrice = function<lambda<call<once, _1, call<twice, _1, _2>>>>;
METAL_ASSERT((is_function<thrice>));
METAL_ASSERT((std::is_same<call_t<thrice, std::add_pointer<_1>, void>, void***>));

using ptr2ptr2ptr = function<lambda<call<thrice, verbatim<std::add_pointer<_1>>, _1>>>;
METAL_ASSERT((is_function<ptr2ptr2ptr>));
METAL_ASSERT((std::is_same<call_t<ptr2ptr2ptr, void>, void***>));

#include <metal/core/identity.hpp>

using church_true = function<lambda<lambda<identity<_1>>>>;
using church_false = function<lambda<lambda<verbatim<_1>>>>;

using church_not = function<lambda<call<call<_1, church_false>, church_true>>>;

METAL_ASSERT((std::is_same<call_t<church_not, church_true>, church_false>));
METAL_ASSERT((std::is_same<call_t<church_not, church_false>, church_true>));

using church_and = function<lambda<bind<bind<_1, verbatim<_1>>, _1>>>;

METAL_ASSERT((std::is_same<call_t<call_t<church_and, church_true>, church_true>, church_true>));
METAL_ASSERT((std::is_same<call_t<call_t<church_and, church_true>, church_false>, church_false>));
METAL_ASSERT((std::is_same<call_t<call_t<church_and, church_false>, church_true>, church_false>));
METAL_ASSERT((std::is_same<call_t<call_t<church_and, church_false>, church_false>, church_false>));

using church_or = function<lambda<bind<bind<_1, _1>, verbatim<_1>>>>;

METAL_ASSERT((std::is_same<call_t<call_t<church_or, church_true>, church_true>, church_true>));
METAL_ASSERT((std::is_same<call_t<call_t<church_or, church_true>, church_false>, church_true>));
METAL_ASSERT((std::is_same<call_t<call_t<church_or, church_false>, church_true>, church_true>));
METAL_ASSERT((std::is_same<call_t<call_t<church_or, church_false>, church_false>, church_false>));

using church_xor = function<lambda<bind<bind<_1, verbatim<call<church_not, _1>>>, verbatim<_1>>>>;

METAL_ASSERT((std::is_same<call_t<call_t<church_xor, church_true>, church_true>, church_false>));
METAL_ASSERT((std::is_same<call_t<call_t<church_xor, church_true>, church_false>, church_true>));
METAL_ASSERT((std::is_same<call_t<call_t<church_xor, church_false>, church_true>, church_true>));
METAL_ASSERT((std::is_same<call_t<call_t<church_xor, church_false>, church_false>, church_false>));
