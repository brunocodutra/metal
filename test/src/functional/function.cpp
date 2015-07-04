/// @copyright Bruno Dutra 2015
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/function.hpp>
#include <metal/functional/quote.hpp>
#include <metal/functional/arg.hpp>
#include <metal/functional/bind.hpp>
#include <metal/functional/lambda.hpp>
#include <metal/functional/call.hpp>
#include <metal/functional/traits/is_function.hpp>
#include <metal/functional/traits/is_callable.hpp>

#include "test/wrap.hpp"
#include "test/expressions.hpp"
#include "test/functions.hpp"
#include "test/types.hpp"
#include "test/main.hpp"

using namespace metal;

METAL_ASSERT((is_function<function<test::a>>));
METAL_ASSERT((is_function<function<test::b>>));
METAL_ASSERT((is_function<function<test::c>>));
METAL_ASSERT((is_function<function<test::d>>));
METAL_ASSERT((is_function<function<test::e>>));
METAL_ASSERT((is_function<function<test::f>>));
METAL_ASSERT((is_function<function<test::g>>));
METAL_ASSERT((is_function<function<test::h>>));
METAL_ASSERT((is_function<function<test::i>>));
METAL_ASSERT((is_function<function<test::j>>));

METAL_ASSERT((not_<is_callable<function<test::a>>>));
METAL_ASSERT((not_<is_callable<function<test::b>>>));
METAL_ASSERT((not_<is_callable<function<test::c>>>));
METAL_ASSERT((not_<is_callable<function<test::d>>>));
METAL_ASSERT((not_<is_callable<function<test::e>>>));
METAL_ASSERT((not_<is_callable<function<test::f>>>));
METAL_ASSERT((not_<is_callable<function<test::g>>>));
METAL_ASSERT((not_<is_callable<function<test::h>>>));
METAL_ASSERT((not_<is_callable<function<test::i>>>));
METAL_ASSERT((not_<is_callable<function<test::j>>>));

METAL_ASSERT((is_function<test::nullary<test::incomplete>>));
METAL_ASSERT((is_function<test::nullary<test::empty>>));
METAL_ASSERT((is_function<test::nullary<test::evaluable>>));
METAL_ASSERT((is_function<test::nullary<test::call>>));

METAL_ASSERT((not_<is_callable<test::nullary<test::incomplete>>>));
METAL_ASSERT((not_<is_callable<test::nullary<test::empty>>>));
METAL_ASSERT((is_callable<test::nullary<test::evaluable>>));
METAL_ASSERT((not_<is_callable<test::nullary<test::call>>>));

METAL_ASSERT((is_function<test::unary<test::incomplete>>));
METAL_ASSERT((is_function<test::unary<test::empty>>));
METAL_ASSERT((is_function<test::unary<test::evaluable>>));
METAL_ASSERT((is_function<test::unary<test::call>>));

METAL_ASSERT((not_<is_callable<test::unary<test::incomplete>, test::a>>));
METAL_ASSERT((not_<is_callable<test::unary<test::empty>, test::a>>));
METAL_ASSERT((is_callable<test::unary<test::evaluable>, test::a>));
METAL_ASSERT((not_<is_callable<test::unary<test::call>, test::a>>));

METAL_ASSERT((is_function<test::binary<test::incomplete>>));
METAL_ASSERT((is_function<test::binary<test::empty>>));
METAL_ASSERT((is_function<test::binary<test::evaluable>>));
METAL_ASSERT((is_function<test::binary<test::call>>));

METAL_ASSERT((not_<is_callable<test::binary<test::incomplete>, test::a, test::b>>));
METAL_ASSERT((not_<is_callable<test::binary<test::empty>, test::a, test::b>>));
METAL_ASSERT((is_callable<test::binary<test::evaluable>, test::a, test::b>));
METAL_ASSERT((not_<is_callable<test::binary<test::call>, test::a, test::b>>));

METAL_ASSERT((is_function<test::n_ary<test::incomplete>>));
METAL_ASSERT((is_function<test::n_ary<test::empty>>));
METAL_ASSERT((is_function<test::n_ary<test::evaluable>>));
METAL_ASSERT((is_function<test::n_ary<test::call>>));

METAL_ASSERT((not_<is_callable<test::n_ary<test::incomplete>>>));
METAL_ASSERT((not_<is_callable<test::n_ary<test::empty>>>));
METAL_ASSERT((is_callable<test::n_ary<test::evaluable>>));
METAL_ASSERT((not_<is_callable<test::n_ary<test::call>>>));

METAL_ASSERT((std::is_same<function<void>::type, function<void>>));
METAL_ASSERT((std::is_same<function<test::wrapper>::type, function<test::wrapper>>));
METAL_ASSERT((std::is_same<call_t<call_t<quote<function>, placeholders::_1>, test::a>, test::a>));

using bound = bind<quote<std::add_pointer>, placeholders::_1>;

METAL_ASSERT((std::is_same<call_t<function<bound>, void>, void*>));
METAL_ASSERT((std::is_same<call_t<function<function<bound>>, void>, void*>));

METAL_ASSERT((std::is_same<call_t<bind<quote<std::add_pointer>, function<bound>>, void>, function<bound>*>));
METAL_ASSERT((std::is_same<call_t<bind<quote<std::add_pointer>, function<function<bound>>>, void>, function<function<bound>>*>));

using lexpr = std::add_pointer<placeholders::_1>;

METAL_ASSERT((std::is_same<call_t<function<lambda<lexpr>>, void>, void*>));
METAL_ASSERT((std::is_same<call_t<function<function<lambda<lexpr>>>, void>, void*>));

METAL_ASSERT((std::is_same<call_t<lambda<function<lexpr>>, void>, function<lexpr>>));
METAL_ASSERT((std::is_same<call_t<lambda<function<function<lexpr>>>, void>, function<function<lexpr>>>));
