// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/core/introspection.hpp>

#include "test.hpp"

METAL_DEFINE_NESTED_TYPE_TRAIT(has_nested, nested);
METAL_DEFINE_NESTED_TEMPLATE_TRAIT(has_nested_template, nested);

static_assert(!has_nested<int>::value, "");
static_assert(!has_nested_template<int>::value, "");

static_assert(!has_nested<int[]>::value, "");
static_assert(!has_nested_template<int[]>::value, "");

static_assert(!has_nested<int const volatile[]>::value, "");
static_assert(!has_nested_template<int const volatile[]>::value, "");

static_assert(!has_nested<int(&)[]>::value, "");
static_assert(!has_nested_template<int(&)[]>::value, "");

static_assert(!has_nested<int const volatile(&)[]>::value, "");
static_assert(!has_nested_template<int const volatile(&)[]>::value, "");

static_assert(!has_nested<int*>::value, "");
static_assert(!has_nested_template<int*>::value, "");

static_assert(!has_nested<int const volatile* const volatile>::value, "");
static_assert(!has_nested_template<int const volatile* const volatile>::value, "");

static_assert(!has_nested<int&>::value, "");
static_assert(!has_nested_template<int&>::value, "");

static_assert(!has_nested<int const volatile&>::value, "");
static_assert(!has_nested_template<int const volatile&>::value, "");

static_assert(!has_nested<int&&>::value, "");
static_assert(!has_nested_template<int&&>::value, "");

static_assert(!has_nested<int const volatile&&>::value, "");
static_assert(!has_nested_template<int const volatile&&>::value, "");

enum test_enum{nested};
static_assert(!has_nested<test_enum>::value, "");
static_assert(!has_nested_template<test_enum>::value, "");

enum class test_enum_class{nested};
static_assert(!has_nested<test_enum_class>::value, "");
static_assert(!has_nested_template<test_enum_class>::value, "");

using test_function_alias = void();
static_assert(!has_nested<test_function_alias>::value, "");
static_assert(!has_nested_template<test_function_alias>::value, "");

using test_function_pointer_alias = void(*)();
static_assert(!has_nested<test_function_pointer_alias>::value, "");
static_assert(!has_nested_template<test_function_pointer_alias>::value, "");

using test_function_reference_alias = void(&)();
static_assert(!has_nested<test_function_reference_alias>::value, "");
static_assert(!has_nested_template<test_function_reference_alias>::value, "");

struct test_undefined_struct;
static_assert(!has_nested<test_undefined_struct>::value, "");
static_assert(!has_nested_template<test_undefined_struct>::value, "");

struct test_empty_struct {};
static_assert(!has_nested<test_empty_struct>::value, "");
static_assert(!has_nested_template<test_empty_struct>::value, "");

struct test_member {int nested;};
static_assert(!has_nested<test_member>::value, "");
static_assert(!has_nested_template<test_member>::value, "");

struct test_static_member {static int nested;};
static_assert(!has_nested<test_static_member>::value, "");
static_assert(!has_nested_template<test_static_member>::value, "");

struct test_member_function {void nested();};
static_assert(!has_nested<test_member_function>::value, "");
static_assert(!has_nested_template<test_member_function>::value, "");

struct test_template_member_function {template<typename> void nested();};
static_assert(!has_nested<test_template_member_function>::value, "");
static_assert(!has_nested_template<test_template_member_function>::value, "");

struct test_static_member_function {static void nested();};
static_assert(!has_nested<test_static_member_function>::value, "");
static_assert(!has_nested_template<test_static_member_function>::value, "");

struct test_static_template_member_function {template<typename...> static void nested();};
static_assert(!has_nested<test_static_template_member_function>::value, "");
static_assert(!has_nested_template<test_static_template_member_function>::value, "");

struct test_nested_alias {using nested = void;};
static_assert(has_nested<test_nested_alias>::value, "");
static_assert(!has_nested_template<test_nested_alias>::value, "");

struct test_nested_struct {struct nested;};
static_assert(has_nested<test_nested_struct>::value, "");
static_assert(!has_nested_template<test_nested_struct>::value, "");

struct test_nested_function_alias {using nested = void();};
static_assert(has_nested<test_nested_function_alias>::value, "");
static_assert(!has_nested_template<test_nested_function_alias>::value, "");

struct test_nested_function_pointer_alias {using nested = void(*)();};
static_assert(has_nested<test_nested_function_pointer_alias>::value, "");
static_assert(!has_nested_template<test_nested_function_pointer_alias>::value, "");

struct test_nested_function_reference_alias {using nested = void(&)();};
static_assert(has_nested<test_nested_function_reference_alias>::value, "");
static_assert(!has_nested_template<test_nested_function_reference_alias>::value, "");

struct test_nested_array_alias {using nested = char[1];};
static_assert(has_nested<test_nested_array_alias>::value, "");
static_assert(!has_nested_template<test_nested_array_alias>::value, "");

struct test_nested_array_reference_alias {using nested = char(&)[1];};
static_assert(has_nested<test_nested_array_reference_alias>::value, "");
static_assert(!has_nested_template<test_nested_array_reference_alias>::value, "");

struct test_nested_enum {enum nested {};};
static_assert(has_nested<test_nested_enum>::value, "");
static_assert(!has_nested_template<test_nested_enum>::value, "");

struct test_nested_enum_class {enum class nested {};};
static_assert(has_nested<test_nested_enum_class>::value, "");
static_assert(!has_nested_template<test_nested_enum_class>::value, "");

struct test_nested_enum_value {enum {nested};};
static_assert(!has_nested<test_nested_enum_value>::value, "");
static_assert(!has_nested_template<test_nested_enum_value>::value, "");

struct test_nested_template {template<typename> struct nested;};
static_assert(!has_nested<test_nested_template>::value, "");
static_assert(has_nested_template<test_nested_template>::value, "");

struct test_nested_variadic_template {template<typename...> struct nested;};
static_assert(!has_nested<test_nested_variadic_template>::value, "");
static_assert(has_nested_template<test_nested_variadic_template>::value, "");

struct test_nested_non_type_template {template<bool> struct nested;};
static_assert(!has_nested<test_nested_non_type_template>::value, "");
static_assert(!has_nested_template<test_nested_non_type_template>::value, "");

struct test_nested_mixed_template {template<typename type, type> struct nested;};
static_assert(!has_nested<test_nested_mixed_template>::value, "");
static_assert(!has_nested_template<test_nested_mixed_template>::value, "");

struct test_nested_template_template {template<template<typename> class> struct nested;};
static_assert(!has_nested<test_nested_template_template>::value, "");
static_assert(!has_nested_template<test_nested_template_template>::value, "");

namespace test_eponym {struct nested{};}
static_assert(has_nested<test_eponym::nested>::value, "");
static_assert(!has_nested_template<test_eponym::nested>::value, "");

struct test_derived_eponym final : test_eponym::nested {};
static_assert(has_nested<test_derived_eponym>::value, "");
static_assert(!has_nested_template<test_derived_eponym>::value, "");
