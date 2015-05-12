// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/lambda/traits/factory.hpp>
#include <boost/mpl2/lambda/integral.hpp>
#include <boost/mpl2/lambda/assert.hpp>

BOOST_MPL2_DEFINE_NESTED_TYPE_TRAIT(has_nested, nested);
BOOST_MPL2_DEFINE_NESTED_TEMPLATE_TRAIT(has_nested_template, nested);

#define BOOST_MPL2_ASSERT_TRAIT(TRAIT) \
    BOOST_MPL2_ASSERT_EXPR(TRAIT::value); \
    BOOST_MPL2_ASSERT_EXPR(TRAIT::type::value); \
    BOOST_MPL2_ASSERT_EXPR(TRAIT{}); \
    BOOST_MPL2_ASSERT_EXPR(TRAIT{}()) \
/**/

BOOST_MPL2_ASSERT_TRAIT(!has_nested<int>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<int>);

BOOST_MPL2_ASSERT_TRAIT(!has_nested<int[]>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<int[]>);

BOOST_MPL2_ASSERT_TRAIT(!has_nested<int const volatile[]>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<int const volatile[]>);

BOOST_MPL2_ASSERT_TRAIT(!has_nested<int(&)[]>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<int(&)[]>);

BOOST_MPL2_ASSERT_TRAIT(!has_nested<int const volatile(&)[]>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<int const volatile(&)[]>);

BOOST_MPL2_ASSERT_TRAIT(!has_nested<int*>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<int*>);

BOOST_MPL2_ASSERT_TRAIT(!has_nested<int const volatile* const volatile>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<int const volatile* const volatile>);

BOOST_MPL2_ASSERT_TRAIT(!has_nested<int&>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<int&>);

BOOST_MPL2_ASSERT_TRAIT(!has_nested<int const volatile&>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<int const volatile&>);

BOOST_MPL2_ASSERT_TRAIT(!has_nested<int&&>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<int&&>);

BOOST_MPL2_ASSERT_TRAIT(!has_nested<int const volatile&&>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<int const volatile&&>);

enum test_enum{nested};
BOOST_MPL2_ASSERT_TRAIT(!has_nested<test_enum>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<test_enum>);

enum class test_enum_class{nested};
BOOST_MPL2_ASSERT_TRAIT(!has_nested<test_enum_class>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<test_enum_class>);

using test_function_alias = void();
BOOST_MPL2_ASSERT_TRAIT(!has_nested<test_function_alias>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<test_function_alias>);

using test_function_pointer_alias = void(*)();
BOOST_MPL2_ASSERT_TRAIT(!has_nested<test_function_pointer_alias>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<test_function_pointer_alias>);

using test_function_reference_alias = void(&)();
BOOST_MPL2_ASSERT_TRAIT(!has_nested<test_function_reference_alias>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<test_function_reference_alias>);

struct test_undefined_struct;
BOOST_MPL2_ASSERT_TRAIT(!has_nested<test_undefined_struct>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<test_undefined_struct>);

struct test_empty_struct {};
BOOST_MPL2_ASSERT_TRAIT(!has_nested<test_empty_struct>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<test_empty_struct>);

struct test_member {int nested;};
BOOST_MPL2_ASSERT_TRAIT(!has_nested<test_member>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<test_member>);

struct test_static_member {static int nested;};
BOOST_MPL2_ASSERT_TRAIT(!has_nested<test_static_member>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<test_static_member>);

struct test_member_function {void nested();};
BOOST_MPL2_ASSERT_TRAIT(!has_nested<test_member_function>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<test_member_function>);

struct test_template_member_function {template<typename> void nested();};
BOOST_MPL2_ASSERT_TRAIT(!has_nested<test_template_member_function>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<test_template_member_function>);

struct test_static_member_function {static void nested();};
BOOST_MPL2_ASSERT_TRAIT(!has_nested<test_static_member_function>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<test_static_member_function>);

struct test_static_template_member_function {template<typename...> static void nested();};
BOOST_MPL2_ASSERT_TRAIT(!has_nested<test_static_template_member_function>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<test_static_template_member_function>);

struct test_nested_alias {using nested = void;};
BOOST_MPL2_ASSERT_TRAIT(has_nested<test_nested_alias>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<test_nested_alias>);

#if !defined(__GNUC__) || !defined(__GNUC_MINOR__) || (__GNUC__ >= 4 && __GNUC_MINOR__ >= 8)
    struct test_nested_template_alias {template<typename> using nested = int;};
    BOOST_MPL2_ASSERT_TRAIT(!has_nested<test_nested_template_alias>);
    BOOST_MPL2_ASSERT_TRAIT(has_nested_template<test_nested_template_alias>);
#endif

struct test_nested_struct {struct nested;};
BOOST_MPL2_ASSERT_TRAIT(has_nested<test_nested_struct>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<test_nested_struct>);

struct test_nested_function_alias {using nested = void();};
BOOST_MPL2_ASSERT_TRAIT(has_nested<test_nested_function_alias>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<test_nested_function_alias>);

struct test_nested_template_function_alias {template<typename> using nested = void();};
BOOST_MPL2_ASSERT_TRAIT(!has_nested<test_nested_template_function_alias>);
BOOST_MPL2_ASSERT_TRAIT(has_nested_template<test_nested_template_function_alias>);

struct test_nested_function_pointer_alias {using nested = void(*)();};
BOOST_MPL2_ASSERT_TRAIT(has_nested<test_nested_function_pointer_alias>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<test_nested_function_pointer_alias>);

struct test_nested_template_function_pointer_alias {template<typename> using nested = void(*)();};
BOOST_MPL2_ASSERT_TRAIT(!has_nested<test_nested_template_function_pointer_alias>);
BOOST_MPL2_ASSERT_TRAIT(has_nested_template<test_nested_template_function_pointer_alias>);

struct test_nested_function_reference_alias {using nested = void(&)();};
BOOST_MPL2_ASSERT_TRAIT(has_nested<test_nested_function_reference_alias>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<test_nested_function_reference_alias>);

struct test_nested_template_function_reference_alias {template<typename> using nested = void(&)();};
BOOST_MPL2_ASSERT_TRAIT(!has_nested<test_nested_template_function_reference_alias>);
BOOST_MPL2_ASSERT_TRAIT(has_nested_template<test_nested_template_function_reference_alias>);

struct test_nested_array_alias {typedef char nested[1];};
BOOST_MPL2_ASSERT_TRAIT(has_nested<test_nested_array_alias>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<test_nested_array_alias>);

struct test_nested_array_reference_alias {typedef char (&nested)[1];};
BOOST_MPL2_ASSERT_TRAIT(has_nested<test_nested_array_reference_alias>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<test_nested_array_reference_alias>);

struct test_nested_enum {enum nested {};};
BOOST_MPL2_ASSERT_TRAIT(has_nested<test_nested_enum>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<test_nested_enum>);

struct test_nested_enum_class {enum class nested {};};
BOOST_MPL2_ASSERT_TRAIT(has_nested<test_nested_enum_class>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<test_nested_enum_class>);

struct test_nested_enum_value {enum {nested};};
BOOST_MPL2_ASSERT_TRAIT(!has_nested<test_nested_enum_value>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<test_nested_enum_value>);

struct test_nested_template {template<typename> struct nested;};
BOOST_MPL2_ASSERT_TRAIT(!has_nested<test_nested_template>);
BOOST_MPL2_ASSERT_TRAIT(has_nested_template<test_nested_template>);

struct test_nested_variadic_template {template<typename...> struct nested;};
BOOST_MPL2_ASSERT_TRAIT(!has_nested<test_nested_variadic_template>);
BOOST_MPL2_ASSERT_TRAIT(has_nested_template<test_nested_variadic_template>);

struct test_nested_non_type_template {template<bool> struct nested;};
BOOST_MPL2_ASSERT_TRAIT(!has_nested<test_nested_non_type_template>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<test_nested_non_type_template>);

struct test_nested_mixed_template {template<typename type, type> struct nested;};
BOOST_MPL2_ASSERT_TRAIT(!has_nested<test_nested_mixed_template>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<test_nested_mixed_template>);

struct test_nested_template_template {template<template<typename> class> struct nested;};
BOOST_MPL2_ASSERT_TRAIT(!has_nested<test_nested_template_template>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<test_nested_template_template>);

namespace test_eponym {struct nested{};}
BOOST_MPL2_ASSERT_TRAIT(has_nested<test_eponym::nested>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<test_eponym::nested>);

struct test_derived_eponym final : test_eponym::nested {};
BOOST_MPL2_ASSERT_TRAIT(has_nested<test_derived_eponym>);
BOOST_MPL2_ASSERT_TRAIT(!has_nested_template<test_derived_eponym>);

namespace test_template_eponym {template<typename> struct nested{};}
BOOST_MPL2_ASSERT_TRAIT(has_nested<test_template_eponym::nested<void> >);
BOOST_MPL2_ASSERT_TRAIT(has_nested_template<test_template_eponym::nested<void> >);

struct test_derived_template_eponym final : test_template_eponym::nested<void> {};
BOOST_MPL2_ASSERT_TRAIT(has_nested<test_derived_template_eponym>);
BOOST_MPL2_ASSERT_TRAIT(has_nested_template<test_derived_template_eponym>);

int main()
{
    return 0;
}
