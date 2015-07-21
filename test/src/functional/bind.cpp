// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/bind.hpp>
#include <metal/functional/protect.hpp>
#include <metal/functional/quote.hpp>
#include <metal/functional/traits/is_callable.hpp>

#include "test.hpp"

using namespace metal;
using namespace metal::placeholders;

METAL_TEST_ASSERT((std::is_same<call_t<bind<test::wrapper>, void, void*>, test::wrap<>>::value));
METAL_TEST_ASSERT((std::is_same<call_t<bind<test::wrapper, _1>, test::a0, test::a1, test::a2, test::a3>, test::wrap<test::a0>>::value));
METAL_TEST_ASSERT((std::is_same<call_t<bind<test::wrapper, _1, _2>, test::a0, test::a1, test::a2, test::a3>, test::wrap<test::a0, test::a1>>::value));
METAL_TEST_ASSERT((std::is_same<call_t<bind<test::wrapper, _1, _2, _3>, test::a0, test::a1, test::a2, test::a3>, test::wrap<test::a0, test::a1, test::a2>>::value));
METAL_TEST_ASSERT((std::is_same<call_t<bind<test::wrapper, _1, _2, _3, _4>, test::a0, test::a1, test::a2, test::a3>, test::wrap<test::a0, test::a1, test::a2, test::a3>>::value));

METAL_TEST_ASSERT((std::is_same<call_t<bind<test::wrapper>, void, void*>, test::wrap<>>::value));
METAL_TEST_ASSERT((std::is_same<call_t<bind<test::wrapper, verbatim<_1>>, test::a0, test::a1, test::a2, test::a3>, test::wrap<_1>>::value));
METAL_TEST_ASSERT((std::is_same<call_t<bind<verbatim<test::wrapper>, verbatim<_1>, _2>, test::a0, test::a1, test::a2, test::a3>, test::wrap<_1, test::a1>>::value));
METAL_TEST_ASSERT((std::is_same<call_t<bind<verbatim<test::wrapper>, _1, verbatim<_2>, _3>, test::a0, test::a1, test::a2, test::a3>, test::wrap<test::a0, _2, test::a2>>::value));
METAL_TEST_ASSERT((std::is_same<call_t<bind<verbatim<test::wrapper>, _1, _2, verbatim<_3>, _4>, test::a0, test::a1, test::a2, test::a3>, test::wrap<test::a0, test::a1, _3, test::a3>>::value));

METAL_TEST_ASSERT((std::is_same<call_t<bind<test::wrapper>, void, void*>, test::wrap<>>::value));
METAL_TEST_ASSERT((std::is_same<call_t<bind<test::wrapper, protect<_1>>, test::a0, test::a1, test::a2, test::a3>, test::wrap<protect<_1>>>::value));
METAL_TEST_ASSERT((std::is_same<call_t<bind<test::wrapper, protect<_1>, _2>, test::a0, test::a1, test::a2, test::a3>, test::wrap<protect<_1>, test::a1>>::value));
METAL_TEST_ASSERT((std::is_same<call_t<bind<test::wrapper, _1, protect<_2>, _3>, test::a0, test::a1, test::a2, test::a3>, test::wrap<test::a0, protect<_2>, test::a2>>::value));
METAL_TEST_ASSERT((std::is_same<call_t<bind<test::wrapper, _1, _2, protect<_3>, _4>, test::a0, test::a1, test::a2, test::a3>, test::wrap<test::a0, test::a1, protect<_3>, test::a3>>::value));

METAL_TEST_ASSERT((std::is_same<call_t<bind<_1, _2>, test::wrapper, void>, test::wrap<void>>::value));
METAL_TEST_ASSERT((std::is_same<call_t<bind<_1, _2, _1>, test::wrapper, void>, test::wrap<void, test::wrapper>>::value));

using chain = protect<bind<_1, bind<_2, _3>>>;
METAL_TEST_ASSERT((is_function<chain>::value));
METAL_TEST_ASSERT((!is_callable<chain>::value));
METAL_TEST_ASSERT((std::is_same<call_t<chain, quote<std::add_pointer>, quote<std::add_const>, void>, void const*>::value));
METAL_TEST_ASSERT((std::is_same<call_t<chain, quote<std::add_const>, quote<std::add_pointer>, void>, void* const>::value));

using once = protect<bind<chain, protect<_1>, _1, _2>>;
METAL_TEST_ASSERT((is_function<once>::value));
METAL_TEST_ASSERT((!is_callable<once>::value));
METAL_TEST_ASSERT((std::is_same<call_t<once, quote<std::add_pointer>, void>, void*>::value));

using twice = protect<bind<chain, _1, _1, _2>>;
METAL_TEST_ASSERT((is_function<twice>::value));
METAL_TEST_ASSERT((!is_callable<twice>::value));
METAL_TEST_ASSERT((std::is_same<call_t<twice, quote<std::add_pointer>, void>, void**>::value));

using thrice = protect<bind<once, _1, bind<twice, _1, _2>>>;
METAL_TEST_ASSERT((is_function<thrice>::value));
METAL_TEST_ASSERT((!is_callable<thrice>::value));
METAL_TEST_ASSERT((std::is_same<call_t<thrice, quote<std::add_pointer>, void>, void***>::value));

using ptr2ptr2ptr = protect<bind<thrice, quote<std::add_pointer>, _1>>;
METAL_TEST_ASSERT((is_function<ptr2ptr2ptr>::value));
METAL_TEST_ASSERT((!is_callable<ptr2ptr2ptr>::value));
METAL_TEST_ASSERT((std::is_same<call_t<ptr2ptr2ptr, void>, void***>::value));
METAL_TEST_ASSERT((std::is_same<call_t<bind<ptr2ptr2ptr, void>>, void***>::value));
