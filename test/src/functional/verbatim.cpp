// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/verbatim.hpp>
#include <metal/functional/lambda.hpp>

#include "test.hpp"

using namespace metal;

METAL_TEST_ASSERT((std::is_same<verbatim<void>::type, void>::value));
METAL_TEST_ASSERT((std::is_same<call_t<quote<verbatim>, void>, void>::value));

METAL_TEST_ASSERT((call_t<bind<verbatim<placeholders::_1>, verbatim<std::true_type>>>::value));
METAL_TEST_ASSERT((call_t<lambda<verbatim<std::true_type>>>::value));

using bound = bind<quote<std::add_pointer>, placeholders::_1>;

METAL_TEST_ASSERT((std::is_same<call_t<bind<quote<std::add_pointer>, verbatim<bound>>, void>, bound*>::value));
METAL_TEST_ASSERT((std::is_same<call_t<bind<quote<std::add_pointer>, verbatim<verbatim<bound>>>, void>, verbatim<bound>*>::value));

using lexpr = std::add_pointer<placeholders::_1>;

METAL_TEST_ASSERT((std::is_same<call_t<lambda<verbatim<lexpr>>, void>, lexpr>::value));
METAL_TEST_ASSERT((std::is_same<call_t<lambda<verbatim<verbatim<lexpr>>>, void>, verbatim<lexpr>>::value));
