// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/verbatim.hpp>
#include <metal.hpp>

#include "test.hpp"

using namespace metal;

static_assert(std::is_same<verbatim<void>::type, void>::value, "");
static_assert(std::is_same<call_t<quote<verbatim>, void>, void>::value, "");

static_assert(call_t<bind<verbatim<placeholders::_1>, verbatim<std::true_type>>>::value, "");
static_assert(call_t<lambda<verbatim<std::true_type>>>::value, "");

using bound = bind<quote<std::add_pointer>, placeholders::_1>;

static_assert(std::is_same<call_t<bind<quote<std::add_pointer>, verbatim<bound>>, void>, bound*>::value, "");
static_assert(std::is_same<call_t<bind<quote<std::add_pointer>, verbatim<verbatim<bound>>>, void>, verbatim<bound>*>::value, "");

using lexpr = std::add_pointer<placeholders::_1>;

static_assert(std::is_same<call_t<lambda<verbatim<lexpr>>, void>, lexpr>::value, "");
static_assert(std::is_same<call_t<lambda<verbatim<verbatim<lexpr>>>, void>, verbatim<lexpr>>::value, "");
