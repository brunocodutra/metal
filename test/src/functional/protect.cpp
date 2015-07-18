// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/protect.hpp>
#include <metal/functional/lambda.hpp>
#include <metal/functional/traits/is_nothing.hpp>
#include <metal/functional/traits/is_callable.hpp>

#include "test.hpp"

using namespace metal;

static_assert(is_nothing<protect<test::a0>>::value, "");
static_assert(is_nothing<protect<test::a1>>::value, "");
static_assert(is_nothing<protect<test::a2>>::value, "");
static_assert(is_nothing<protect<test::a3>>::value, "");
static_assert(is_nothing<protect<test::a4>>::value, "");
static_assert(is_nothing<protect<test::a5>>::value, "");
static_assert(is_nothing<protect<test::a6>>::value, "");
static_assert(is_nothing<protect<test::a7>>::value, "");
static_assert(is_nothing<protect<test::a8>>::value, "");
static_assert(is_nothing<protect<test::a9>>::value, "");

static_assert(protect<std::true_type>::value, "");

static_assert(is_function<protect<test::wrapper>>::value, "");
static_assert(is_callable<protect<test::wrapper>>::value, "");
static_assert(std::is_same<call_t<protect<test::wrapper>>, call_t<test::wrapper>>::value, "");

using bound = bind<quote<std::add_pointer>, placeholders::_1>;

static_assert(std::is_same<call_t<protect<bound>, void>, void*>::value, "");
static_assert(std::is_same<call_t<protect<protect<bound>>, void>, void*>::value, "");

static_assert(std::is_same<call_t<bind<quote<std::add_pointer>, protect<bound>>, void>, protect<bound>*>::value, "");
static_assert(std::is_same<call_t<bind<quote<std::add_pointer>, protect<protect<bound>>>, void>, protect<protect<bound>>*>::value, "");

using lexpr = std::add_pointer<placeholders::_1>;

static_assert(std::is_same<call_t<protect<lambda<lexpr>>, void>, void*>::value, "");
static_assert(std::is_same<call_t<protect<protect<lambda<lexpr>>>, void>, void*>::value, "");

static_assert(std::is_same<call_t<lambda<protect<lexpr>>, void>, protect<lexpr>>::value, "");
static_assert(std::is_same<call_t<lambda<protect<protect<lexpr>>>, void>, protect<protect<lexpr>>>::value, "");
