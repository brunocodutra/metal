// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/algebra/logical.hpp>
#include <metal.hpp>

#include "test.hpp"

using namespace metal;

struct undefined;

static_assert(or_<std::false_type, std::true_type>{}, "");
static_assert(or_<std::false_type, std::false_type, std::true_type>{}, "");
static_assert(or_<std::false_type, std::false_type, std::false_type, std::true_type>{}, "");
static_assert(or_<std::false_type, std::false_type, std::false_type, std::false_type, std::true_type>{}, "");
static_assert(or_<std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::true_type>{}, "");
static_assert(or_<std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::true_type>{}, "");
static_assert(or_<std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::true_type>{}, "");

static_assert(not_<or_<std::false_type, std::false_type>>{}, "");
static_assert(not_<or_<std::false_type, std::false_type, std::false_type>>{}, "");
static_assert(not_<or_<std::false_type, std::false_type, std::false_type, std::false_type>>{}, "");
static_assert(not_<or_<std::false_type, std::false_type, std::false_type, std::false_type, std::false_type>>{}, "");
static_assert(not_<or_<std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::false_type>>{}, "");
static_assert(not_<or_<std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::false_type>>{}, "");
static_assert(not_<or_<std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::false_type>>{}, "");

static_assert(and_<std::true_type, std::true_type>{}, "");
static_assert(and_<std::true_type, std::true_type, std::true_type>{}, "");
static_assert(and_<std::true_type, std::true_type, std::true_type, std::true_type>{}, "");
static_assert(and_<std::true_type, std::true_type, std::true_type, std::true_type, std::true_type>{}, "");
static_assert(and_<std::true_type, std::true_type, std::true_type, std::true_type, std::true_type, std::true_type>{}, "");
static_assert(and_<std::true_type, std::true_type, std::true_type, std::true_type, std::true_type, std::true_type, std::true_type>{}, "");
static_assert(and_<std::true_type, std::true_type, std::true_type, std::true_type, std::true_type, std::true_type, std::true_type, std::true_type>{}, "");

static_assert(not_<and_<std::true_type, std::false_type>>{}, "");
static_assert(not_<and_<std::true_type, std::true_type, std::false_type>>{}, "");
static_assert(not_<and_<std::true_type, std::true_type, std::true_type, std::false_type>>{}, "");
static_assert(not_<and_<std::true_type, std::true_type, std::true_type, std::true_type, std::false_type>>{}, "");
static_assert(not_<and_<std::true_type, std::true_type, std::true_type, std::true_type, std::true_type, std::false_type>>{}, "");
static_assert(not_<and_<std::true_type, std::true_type, std::true_type, std::true_type, std::true_type, std::true_type, std::false_type>>{}, "");
static_assert(not_<and_<std::true_type, std::true_type, std::true_type, std::true_type, std::true_type, std::true_type, std::true_type, std::false_type>>{}, "");

static_assert(or_<std::true_type, undefined>{}, "");
static_assert(or_<std::true_type, undefined, undefined>{}, "");
static_assert(or_<std::true_type, undefined, undefined, undefined>{}, "");
static_assert(or_<std::true_type, undefined, undefined, undefined, undefined>{}, "");
static_assert(or_<std::true_type, undefined, undefined, undefined, undefined, undefined>{}, "");
static_assert(or_<std::true_type, undefined, undefined, undefined, undefined, undefined, undefined>{}, "");
static_assert(or_<std::true_type, undefined, undefined, undefined, undefined, undefined, undefined, undefined>{}, "");

static_assert(not_<and_<std::false_type, undefined>>{}, "");
static_assert(not_<and_<std::false_type, undefined, undefined>>{}, "");
static_assert(not_<and_<std::false_type, undefined, undefined, undefined>>{}, "");
static_assert(not_<and_<std::false_type, undefined, undefined, undefined, undefined>>{}, "");
static_assert(not_<and_<std::false_type, undefined, undefined, undefined, undefined, undefined>>{}, "");
static_assert(not_<and_<std::false_type, undefined, undefined, undefined, undefined, undefined, undefined>>{}, "");
static_assert(not_<and_<std::false_type, undefined, undefined, undefined, undefined, undefined, undefined, undefined>>{}, "");
