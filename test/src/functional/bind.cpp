// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/bind.hpp>
#include <metal/functional/arg.hpp>
#include <metal/functional/verbatim.hpp>
#include <metal/functional/protect.hpp>
#include <metal/functional/quote.hpp>
#include <metal/functional/call.hpp>
#include <metal/functional/traits.hpp>

#include "test/values.hpp"
#include "test/wrap.hpp"
#include "test/main.hpp"

using namespace metal;
using namespace metal::placeholders;

METAL_ASSERT((std::is_same<bind<test::wrapper>::type, bind<test::wrapper>>));

METAL_ASSERT((std::is_same<call_t<bind<test::wrapper>, void, void*>, test::wrap<>>));
METAL_ASSERT((std::is_same<call_t<bind<test::wrapper, _1>, test::a, test::b, test::c, test::d>, test::wrap<test::a>>));
METAL_ASSERT((std::is_same<call_t<bind<test::wrapper, _1, _2>, test::a, test::b, test::c, test::d>, test::wrap<test::a, test::b>>));
METAL_ASSERT((std::is_same<call_t<bind<test::wrapper, _1, _2, _3>, test::a, test::b, test::c, test::d>, test::wrap<test::a, test::b, test::c>>));
METAL_ASSERT((std::is_same<call_t<bind<test::wrapper, _1, _2, _3, _4>, test::a, test::b, test::c, test::d>, test::wrap<test::a, test::b, test::c, test::d>>));

METAL_ASSERT((std::is_same<call_t<bind<test::wrapper>, void, void*>, test::wrap<>>));
METAL_ASSERT((std::is_same<call_t<bind<test::wrapper, verbatim<_1>>, test::a, test::b, test::c, test::d>, test::wrap<_1>>));
METAL_ASSERT((std::is_same<call_t<bind<verbatim<test::wrapper>, verbatim<_1>, _2>, test::a, test::b, test::c, test::d>, test::wrap<_1, test::b>>));
METAL_ASSERT((std::is_same<call_t<bind<verbatim<test::wrapper>, _1, verbatim<_2>, _3>, test::a, test::b, test::c, test::d>, test::wrap<test::a, _2, test::c>>));
METAL_ASSERT((std::is_same<call_t<bind<verbatim<test::wrapper>, _1, _2, verbatim<_3>, _4>, test::a, test::b, test::c, test::d>, test::wrap<test::a, test::b, _3, test::d>>));

METAL_ASSERT((std::is_same<call_t<bind<test::wrapper>, void, void*>, test::wrap<>>));
METAL_ASSERT((std::is_same<call_t<bind<test::wrapper, protect<_1>>, test::a, test::b, test::c, test::d>, test::wrap<protect<_1>>>));
METAL_ASSERT((std::is_same<call_t<bind<test::wrapper, protect<_1>, _2>, test::a, test::b, test::c, test::d>, test::wrap<protect<_1>, test::b>>));
METAL_ASSERT((std::is_same<call_t<bind<test::wrapper, _1, protect<_2>, _3>, test::a, test::b, test::c, test::d>, test::wrap<test::a, protect<_2>, test::c>>));
METAL_ASSERT((std::is_same<call_t<bind<test::wrapper, _1, _2, protect<_3>, _4>, test::a, test::b, test::c, test::d>, test::wrap<test::a, test::b, protect<_3>, test::d>>));

METAL_ASSERT((std::is_same<call_t<bind<_1, _2>, test::wrapper, void>, test::wrap<void>>));
METAL_ASSERT((std::is_same<call_t<bind<_1, _2, _1>, test::wrapper, void>, test::wrap<void, test::wrapper>>));

METAL_ASSERT((std::is_same<call_t<bind<_0>, test::wrapper, void>, test::wrap<void>>));
METAL_ASSERT((std::is_same<call_t<bind<_0, _0>, test::wrapper, void>, test::wrap<void, test::wrapper, void>>));
METAL_ASSERT((std::is_same<call_t<bind<_0, _0, _0>, test::wrapper, void>, test::wrap<void, test::wrapper, void, test::wrapper, void>>));

METAL_ASSERT((std::is_same<call_t<bind<_0, verbatim<_0>>, test::wrapper, void>, test::wrap<void, _0>>));
METAL_ASSERT((std::is_same<call_t<bind<_0, verbatim<_0>, _0>, test::wrapper, void>, test::wrap<void, _0, test::wrapper, void>>));

METAL_ASSERT((std::is_same<call_t<bind<_0, protect<_0>>, test::wrapper, void>, test::wrap<void, protect<_0>>>));
METAL_ASSERT((std::is_same<call_t<bind<_0, protect<_0>, _0>, test::wrapper, void>, test::wrap<void, protect<_0>, test::wrapper, void>>));

using chain = protect<bind<_1, bind<_2, _3>>>;
METAL_ASSERT((is_function<chain>));
METAL_ASSERT((std::is_same<call_t<chain, quote<std::add_pointer>, quote<std::add_const>, void>, void const*>));
METAL_ASSERT((std::is_same<call_t<chain, quote<std::add_const>, quote<std::add_pointer>, void>, void* const>));

using once = protect<bind<chain, protect<_1>, _1, _2>>;
METAL_ASSERT((is_function<once>));
METAL_ASSERT((std::is_same<call_t<once, quote<std::add_pointer>, void>, void*>));

using twice = protect<bind<chain, _1, _1, _2>>;
METAL_ASSERT((is_function<twice>));
METAL_ASSERT((std::is_same<call_t<twice, quote<std::add_pointer>, void>, void**>));

using thrice = protect<bind<once, _1, bind<twice, _1, _2>>>;
METAL_ASSERT((is_function<thrice>));
METAL_ASSERT((std::is_same<call_t<thrice, quote<std::add_pointer>, void>, void***>));

using ptr2ptr2ptr = protect<bind<thrice, quote<std::add_pointer>, _1>>;
METAL_ASSERT((is_function<ptr2ptr2ptr>));
METAL_ASSERT((std::is_same<call_t<ptr2ptr2ptr, void>, void***>));
METAL_ASSERT((std::is_same<call_t<bind<ptr2ptr2ptr, void>>, void***>));
