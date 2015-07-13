// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/bind.hpp>
#include <metal/functional/protect.hpp>
#include <metal/functional/quote.hpp>

#include "test.hpp"

using namespace metal;
using namespace metal::placeholders;

static_assert(std::is_same<call_t<bind<test::wrapper>, void, void*>, test::wrap<>>::value, "");
static_assert(std::is_same<call_t<bind<test::wrapper, _1>, test::a0, test::a1, test::a2, test::a3>, test::wrap<test::a0>>::value, "");
static_assert(std::is_same<call_t<bind<test::wrapper, _1, _2>, test::a0, test::a1, test::a2, test::a3>, test::wrap<test::a0, test::a1>>::value, "");
static_assert(std::is_same<call_t<bind<test::wrapper, _1, _2, _3>, test::a0, test::a1, test::a2, test::a3>, test::wrap<test::a0, test::a1, test::a2>>::value, "");
static_assert(std::is_same<call_t<bind<test::wrapper, _1, _2, _3, _4>, test::a0, test::a1, test::a2, test::a3>, test::wrap<test::a0, test::a1, test::a2, test::a3>>::value, "");

static_assert(std::is_same<call_t<bind<test::wrapper>, void, void*>, test::wrap<>>::value, "");
static_assert(std::is_same<call_t<bind<test::wrapper, verbatim<_1>>, test::a0, test::a1, test::a2, test::a3>, test::wrap<_1>>::value, "");
static_assert(std::is_same<call_t<bind<verbatim<test::wrapper>, verbatim<_1>, _2>, test::a0, test::a1, test::a2, test::a3>, test::wrap<_1, test::a1>>::value, "");
static_assert(std::is_same<call_t<bind<verbatim<test::wrapper>, _1, verbatim<_2>, _3>, test::a0, test::a1, test::a2, test::a3>, test::wrap<test::a0, _2, test::a2>>::value, "");
static_assert(std::is_same<call_t<bind<verbatim<test::wrapper>, _1, _2, verbatim<_3>, _4>, test::a0, test::a1, test::a2, test::a3>, test::wrap<test::a0, test::a1, _3, test::a3>>::value, "");

static_assert(std::is_same<call_t<bind<test::wrapper>, void, void*>, test::wrap<>>::value, "");
static_assert(std::is_same<call_t<bind<test::wrapper, protect<_1>>, test::a0, test::a1, test::a2, test::a3>, test::wrap<protect<_1>>>::value, "");
static_assert(std::is_same<call_t<bind<test::wrapper, protect<_1>, _2>, test::a0, test::a1, test::a2, test::a3>, test::wrap<protect<_1>, test::a1>>::value, "");
static_assert(std::is_same<call_t<bind<test::wrapper, _1, protect<_2>, _3>, test::a0, test::a1, test::a2, test::a3>, test::wrap<test::a0, protect<_2>, test::a2>>::value, "");
static_assert(std::is_same<call_t<bind<test::wrapper, _1, _2, protect<_3>, _4>, test::a0, test::a1, test::a2, test::a3>, test::wrap<test::a0, test::a1, protect<_3>, test::a3>>::value, "");

static_assert(std::is_same<call_t<bind<_1, _2>, test::wrapper, void>, test::wrap<void>>::value, "");
static_assert(std::is_same<call_t<bind<_1, _2, _1>, test::wrapper, void>, test::wrap<void, test::wrapper>>::value, "");

static_assert(std::is_same<call_t<bind<_0>, test::wrapper, void>, test::wrap<void>>::value, "");
static_assert(std::is_same<call_t<bind<_0, _0>, test::wrapper, void>, test::wrap<void, test::wrapper, void>>::value, "");
static_assert(std::is_same<call_t<bind<_0, _0, _0>, test::wrapper, void>, test::wrap<void, test::wrapper, void, test::wrapper, void>>::value, "");

static_assert(std::is_same<call_t<bind<_0, verbatim<_0>>, test::wrapper, void>, test::wrap<void, _0>>::value, "");
static_assert(std::is_same<call_t<bind<_0, verbatim<_0>, _0>, test::wrapper, void>, test::wrap<void, _0, test::wrapper, void>>::value, "");

static_assert(std::is_same<call_t<bind<_0, protect<_0>>, test::wrapper, void>, test::wrap<void, protect<_0>>>::value, "");
static_assert(std::is_same<call_t<bind<_0, protect<_0>, _0>, test::wrapper, void>, test::wrap<void, protect<_0>, test::wrapper, void>>::value, "");

using chain = protect<bind<_1, bind<_2, _3>>>;
static_assert(is_function<chain>::value, "");
static_assert(std::is_same<call_t<chain, quote<std::add_pointer>, quote<std::add_const>, void>, void const*>::value, "");
static_assert(std::is_same<call_t<chain, quote<std::add_const>, quote<std::add_pointer>, void>, void* const>::value, "");

using once = protect<bind<chain, protect<_1>, _1, _2>>;
static_assert(is_function<once>::value, "");
static_assert(std::is_same<call_t<once, quote<std::add_pointer>, void>, void*>::value, "");

using twice = protect<bind<chain, _1, _1, _2>>;
static_assert(is_function<twice>::value, "");
static_assert(std::is_same<call_t<twice, quote<std::add_pointer>, void>, void**>::value, "");

using thrice = protect<bind<once, _1, bind<twice, _1, _2>>>;
static_assert(is_function<thrice>::value, "");
static_assert(std::is_same<call_t<thrice, quote<std::add_pointer>, void>, void***>::value, "");

using ptr2ptr2ptr = protect<bind<thrice, quote<std::add_pointer>, _1>>;
static_assert(is_function<ptr2ptr2ptr>::value, "");
static_assert(std::is_same<call_t<ptr2ptr2ptr, void>, void***>::value, "");
static_assert(std::is_same<call_t<bind<ptr2ptr2ptr, void>>, void***>::value, "");
