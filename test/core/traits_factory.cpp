// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/core/traits_factory.hpp>

#include "test/main.hpp"

BOOST_MPL2_DEFINE_NESTED_TYPE_TRAIT(has_nested, nested);
BOOST_MPL2_DEFINE_NESTED_TEMPLATE_TRAIT(has_nested_template, nested);

BOOST_MPL2_ASSERT_EXPR(!has_nested<int>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<int>::value);

BOOST_MPL2_ASSERT_EXPR(!has_nested<int[]>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<int[]>::value);

BOOST_MPL2_ASSERT_EXPR(!has_nested<int const volatile[]>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<int const volatile[]>::value);

BOOST_MPL2_ASSERT_EXPR(!has_nested<int(&)[]>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<int(&)[]>::value);

BOOST_MPL2_ASSERT_EXPR(!has_nested<int const volatile(&)[]>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<int const volatile(&)[]>::value);

BOOST_MPL2_ASSERT_EXPR(!has_nested<int*>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<int*>::value);

BOOST_MPL2_ASSERT_EXPR(!has_nested<int const volatile* const volatile>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<int const volatile* const volatile>::value);

BOOST_MPL2_ASSERT_EXPR(!has_nested<int&>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<int&>::value);

BOOST_MPL2_ASSERT_EXPR(!has_nested<int const volatile&>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<int const volatile&>::value);

BOOST_MPL2_ASSERT_EXPR(!has_nested<int&&>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<int&&>::value);

BOOST_MPL2_ASSERT_EXPR(!has_nested<int const volatile&&>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<int const volatile&&>::value);

enum test_enum{nested};
BOOST_MPL2_ASSERT_EXPR(!has_nested<test_enum>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<test_enum>::value);

enum class test_enum_class{nested};
BOOST_MPL2_ASSERT_EXPR(!has_nested<test_enum_class>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<test_enum_class>::value);

using test_function_alias = void();
BOOST_MPL2_ASSERT_EXPR(!has_nested<test_function_alias>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<test_function_alias>::value);

using test_function_pointer_alias = void(*)();
BOOST_MPL2_ASSERT_EXPR(!has_nested<test_function_pointer_alias>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<test_function_pointer_alias>::value);

using test_function_reference_alias = void(&)();
BOOST_MPL2_ASSERT_EXPR(!has_nested<test_function_reference_alias>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<test_function_reference_alias>::value);

struct test_undefined_struct;
BOOST_MPL2_ASSERT_EXPR(!has_nested<test_undefined_struct>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<test_undefined_struct>::value);

struct test_empty_struct {};
BOOST_MPL2_ASSERT_EXPR(!has_nested<test_empty_struct>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<test_empty_struct>::value);

struct test_member {int nested;};
BOOST_MPL2_ASSERT_EXPR(!has_nested<test_member>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<test_member>::value);

struct test_static_member {static int nested;};
BOOST_MPL2_ASSERT_EXPR(!has_nested<test_static_member>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<test_static_member>::value);

struct test_member_function {void nested();};
BOOST_MPL2_ASSERT_EXPR(!has_nested<test_member_function>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<test_member_function>::value);

struct test_template_member_function {template<typename> void nested();};
BOOST_MPL2_ASSERT_EXPR(!has_nested<test_template_member_function>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<test_template_member_function>::value);

struct test_static_member_function {static void nested();};
BOOST_MPL2_ASSERT_EXPR(!has_nested<test_static_member_function>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<test_static_member_function>::value);

struct test_static_template_member_function {template<typename...> static void nested();};
BOOST_MPL2_ASSERT_EXPR(!has_nested<test_static_template_member_function>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<test_static_template_member_function>::value);

struct test_nested_alias {using nested = void;};
BOOST_MPL2_ASSERT_EXPR(has_nested<test_nested_alias>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<test_nested_alias>::value);

struct test_nested_struct {struct nested;};
BOOST_MPL2_ASSERT_EXPR(has_nested<test_nested_struct>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<test_nested_struct>::value);

struct test_nested_function_alias {using nested = void();};
BOOST_MPL2_ASSERT_EXPR(has_nested<test_nested_function_alias>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<test_nested_function_alias>::value);

struct test_nested_function_pointer_alias {using nested = void(*)();};
BOOST_MPL2_ASSERT_EXPR(has_nested<test_nested_function_pointer_alias>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<test_nested_function_pointer_alias>::value);

struct test_nested_function_reference_alias {using nested = void(&)();};
BOOST_MPL2_ASSERT_EXPR(has_nested<test_nested_function_reference_alias>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<test_nested_function_reference_alias>::value);

struct test_nested_array_alias {typedef char nested[1];};
BOOST_MPL2_ASSERT_EXPR(has_nested<test_nested_array_alias>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<test_nested_array_alias>::value);

struct test_nested_array_reference_alias {typedef char (&nested)[1];};
BOOST_MPL2_ASSERT_EXPR(has_nested<test_nested_array_reference_alias>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<test_nested_array_reference_alias>::value);

struct test_nested_enum {enum nested {};};
BOOST_MPL2_ASSERT_EXPR(has_nested<test_nested_enum>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<test_nested_enum>::value);

struct test_nested_enum_class {enum class nested {};};
BOOST_MPL2_ASSERT_EXPR(has_nested<test_nested_enum_class>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<test_nested_enum_class>::value);

struct test_nested_enum_value {enum {nested};};
BOOST_MPL2_ASSERT_EXPR(!has_nested<test_nested_enum_value>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<test_nested_enum_value>::value);

struct test_nested_template {template<typename> struct nested;};
BOOST_MPL2_ASSERT_EXPR(!has_nested<test_nested_template>::value);
BOOST_MPL2_ASSERT_EXPR(has_nested_template<test_nested_template>::value);

struct test_nested_variadic_template {template<typename...> struct nested;};
BOOST_MPL2_ASSERT_EXPR(!has_nested<test_nested_variadic_template>::value);
BOOST_MPL2_ASSERT_EXPR(has_nested_template<test_nested_variadic_template>::value);

struct test_nested_non_type_template {template<bool> struct nested;};
BOOST_MPL2_ASSERT_EXPR(!has_nested<test_nested_non_type_template>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<test_nested_non_type_template>::value);

struct test_nested_mixed_template {template<typename type, type> struct nested;};
BOOST_MPL2_ASSERT_EXPR(!has_nested<test_nested_mixed_template>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<test_nested_mixed_template>::value);

struct test_nested_template_template {template<template<typename> class> struct nested;};
BOOST_MPL2_ASSERT_EXPR(!has_nested<test_nested_template_template>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<test_nested_template_template>::value);

namespace test_eponym {struct nested{};}
BOOST_MPL2_ASSERT_EXPR(has_nested<test_eponym::nested>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<test_eponym::nested>::value);

struct test_derived_eponym final : test_eponym::nested {};
BOOST_MPL2_ASSERT_EXPR(has_nested<test_derived_eponym>::value);
BOOST_MPL2_ASSERT_EXPR(!has_nested_template<test_derived_eponym>::value);
