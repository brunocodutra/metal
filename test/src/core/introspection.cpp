// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/core/introspection.hpp>
#include <metal.hpp>

#include "test.hpp"

METAL_DEFINE_NESTED_TYPE_TRAIT(has_nested, nested);
METAL_DEFINE_NESTED_TEMPLATE_TRAIT(has_nested_template, nested);

static_assert(!has_nested<int>{}, "");
static_assert(!has_nested_template<int>{}, "");

static_assert(!has_nested<int[]>{}, "");
static_assert(!has_nested_template<int[]>{}, "");

static_assert(!has_nested<int const volatile[]>{}, "");
static_assert(!has_nested_template<int const volatile[]>{}, "");

static_assert(!has_nested<int(&)[]>{}, "");
static_assert(!has_nested_template<int(&)[]>{}, "");

static_assert(!has_nested<int const volatile(&)[]>{}, "");
static_assert(!has_nested_template<int const volatile(&)[]>{}, "");

static_assert(!has_nested<int*>{}, "");
static_assert(!has_nested_template<int*>{}, "");

static_assert(!has_nested<int const volatile* const volatile>{}, "");
static_assert(!has_nested_template<int const volatile* const volatile>{}, "");

static_assert(!has_nested<int&>{}, "");
static_assert(!has_nested_template<int&>{}, "");

static_assert(!has_nested<int const volatile&>{}, "");
static_assert(!has_nested_template<int const volatile&>{}, "");

static_assert(!has_nested<int&&>{}, "");
static_assert(!has_nested_template<int&&>{}, "");

static_assert(!has_nested<int const volatile&&>{}, "");
static_assert(!has_nested_template<int const volatile&&>{}, "");

enum test_enum{nested};
static_assert(!has_nested<test_enum>{}, "");
static_assert(!has_nested_template<test_enum>{}, "");

enum class test_enum_class{nested};
static_assert(!has_nested<test_enum_class>{}, "");
static_assert(!has_nested_template<test_enum_class>{}, "");

using test_function_alias = void();
static_assert(!has_nested<test_function_alias>{}, "");
static_assert(!has_nested_template<test_function_alias>{}, "");

using test_function_pointer_alias = void(*)();
static_assert(!has_nested<test_function_pointer_alias>{}, "");
static_assert(!has_nested_template<test_function_pointer_alias>{}, "");

using test_function_reference_alias = void(&)();
static_assert(!has_nested<test_function_reference_alias>{}, "");
static_assert(!has_nested_template<test_function_reference_alias>{}, "");

struct test_undefined_struct;
static_assert(!has_nested<test_undefined_struct>{}, "");
static_assert(!has_nested_template<test_undefined_struct>{}, "");

struct test_empty_struct {};
static_assert(!has_nested<test_empty_struct>{}, "");
static_assert(!has_nested_template<test_empty_struct>{}, "");

struct test_member {int nested;};
static_assert(!has_nested<test_member>{}, "");
static_assert(!has_nested_template<test_member>{}, "");

struct test_static_member {static int nested;};
static_assert(!has_nested<test_static_member>{}, "");
static_assert(!has_nested_template<test_static_member>{}, "");

struct test_member_function {void nested();};
static_assert(!has_nested<test_member_function>{}, "");
static_assert(!has_nested_template<test_member_function>{}, "");

struct test_template_member_function {template<typename> void nested();};
static_assert(!has_nested<test_template_member_function>{}, "");
static_assert(!has_nested_template<test_template_member_function>{}, "");

struct test_static_member_function {static void nested();};
static_assert(!has_nested<test_static_member_function>{}, "");
static_assert(!has_nested_template<test_static_member_function>{}, "");

struct test_static_template_member_function {template<typename...> static void nested();};
static_assert(!has_nested<test_static_template_member_function>{}, "");
static_assert(!has_nested_template<test_static_template_member_function>{}, "");

struct test_nested_alias {using nested = void;};
static_assert(has_nested<test_nested_alias>{}, "");
static_assert(!has_nested_template<test_nested_alias>{}, "");

struct test_nested_struct {struct nested;};
static_assert(has_nested<test_nested_struct>{}, "");
static_assert(!has_nested_template<test_nested_struct>{}, "");

struct test_nested_function_alias {using nested = void();};
static_assert(has_nested<test_nested_function_alias>{}, "");
static_assert(!has_nested_template<test_nested_function_alias>{}, "");

struct test_nested_function_pointer_alias {using nested = void(*)();};
static_assert(has_nested<test_nested_function_pointer_alias>{}, "");
static_assert(!has_nested_template<test_nested_function_pointer_alias>{}, "");

struct test_nested_function_reference_alias {using nested = void(&)();};
static_assert(has_nested<test_nested_function_reference_alias>{}, "");
static_assert(!has_nested_template<test_nested_function_reference_alias>{}, "");

struct test_nested_array_alias {using nested = char[1];};
static_assert(has_nested<test_nested_array_alias>{}, "");
static_assert(!has_nested_template<test_nested_array_alias>{}, "");

struct test_nested_array_reference_alias {using nested = char(&)[1];};
static_assert(has_nested<test_nested_array_reference_alias>{}, "");
static_assert(!has_nested_template<test_nested_array_reference_alias>{}, "");

struct test_nested_enum {enum nested {};};
static_assert(has_nested<test_nested_enum>{}, "");
static_assert(!has_nested_template<test_nested_enum>{}, "");

struct test_nested_enum_class {enum class nested {};};
static_assert(has_nested<test_nested_enum_class>{}, "");
static_assert(!has_nested_template<test_nested_enum_class>{}, "");

struct test_nested_enum_value {enum {nested};};
static_assert(!has_nested<test_nested_enum_value>{}, "");
static_assert(!has_nested_template<test_nested_enum_value>{}, "");

struct test_nested_template {template<typename> struct nested;};
static_assert(!has_nested<test_nested_template>{}, "");
static_assert(has_nested_template<test_nested_template>{}, "");

struct test_nested_variadic_template {template<typename...> struct nested;};
static_assert(!has_nested<test_nested_variadic_template>{}, "");
static_assert(has_nested_template<test_nested_variadic_template>{}, "");

struct test_nested_non_type_template {template<bool> struct nested;};
static_assert(!has_nested<test_nested_non_type_template>{}, "");
static_assert(!has_nested_template<test_nested_non_type_template>{}, "");

struct test_nested_mixed_template {template<typename type, type> struct nested;};
static_assert(!has_nested<test_nested_mixed_template>{}, "");
static_assert(!has_nested_template<test_nested_mixed_template>{}, "");

struct test_nested_template_template {template<template<typename> class> struct nested;};
static_assert(!has_nested<test_nested_template_template>{}, "");
static_assert(!has_nested_template<test_nested_template_template>{}, "");

namespace test_eponym {struct nested{};}
static_assert(has_nested<test_eponym::nested>{}, "");
static_assert(!has_nested_template<test_eponym::nested>{}, "");

struct test_derived_eponym final : test_eponym::nested {};
static_assert(has_nested<test_derived_eponym>{}, "");
static_assert(!has_nested_template<test_derived_eponym>{}, "");
