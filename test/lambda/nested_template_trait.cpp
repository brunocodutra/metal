// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/lambda/integral/boolean.hpp>
#include <boost/mpl2/lambda/logical/not.hpp>
#include <boost/mpl2/lambda/nested_template_trait.hpp>
#include <boost/mpl2/lambda/assert.hpp>

BOOST_MPL2_DEFINE_NESTED_TEMPLATE_TRAIT(has_nested_template, nested);

#define BOOST_MPL2_DETAIL_HAS_NESTED_TEMPLATE(X) \
    BOOST_MPL2_ASSERT(has_nested_template<X>); \
    BOOST_MPL2_ASSERT(has_nested_template<X>::type); \
    BOOST_MPL2_ASSERT_EXPR(has_nested_template<X>{}); \
    BOOST_MPL2_ASSERT_EXPR(has_nested_template<X>{}()) \
/**/

#define BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(X) \
    BOOST_MPL2_ASSERT(boost::mpl2::not_<has_nested_template<X> >); \
    BOOST_MPL2_ASSERT(boost::mpl2::not_<has_nested_template<X>::type>); \
    BOOST_MPL2_ASSERT_EXPR(!has_nested_template<X>{}); \
    BOOST_MPL2_ASSERT_EXPR(!has_nested_template<X>{}()) \
/**/

BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(int);
BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(int[]);
BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(int const volatile[]);
BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(int(&)[]);
BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(int const volatile(&)[]);
BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(int*);
BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(int const volatile* const volatile);
BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(int&);
BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(int const volatile&);
BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(int&&);
BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(int const volatile&&);

enum test_enum{nested};
BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(test_enum);

enum class test_enum_class{nested};
BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(test_enum_class);

using test_function_alias = void();
BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(test_function_alias);

using test_function_pointer_alias = void(*)();
BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(test_function_pointer_alias);

using test_function_reference_alias = void(&)();
BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(test_function_reference_alias);

struct test_undefined_struct;
BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(test_undefined_struct);

struct test_empty_struct {};
BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(test_empty_struct);

struct test_member {int nested;};
BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(test_member);

struct test_static_member {static int nested;};
BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(test_static_member);

struct test_member_function {void nested();};
BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(test_member_function);

struct test_template_member_function {template<typename> void nested();};
BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(test_template_member_function);

struct test_static_member_function {static void nested();};
BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(test_static_member_function);

struct test_static_template_member_function {template<typename...> static void nested();};
BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(test_static_template_member_function);

struct test_nested_alias {using nested = void;};
BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(test_nested_alias);

struct test_nested_template_alias {template<typename> using nested = int;};
BOOST_MPL2_DETAIL_HAS_NESTED_TEMPLATE(test_nested_template_alias);

struct test_nested_struct {struct nested;};
BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(test_nested_struct);

struct test_nested_function_alias {using nested = void();};
BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(test_nested_function_alias);

struct test_nested_template_function_alias {template<typename> using nested = void();};
BOOST_MPL2_DETAIL_HAS_NESTED_TEMPLATE(test_nested_template_function_alias);

struct test_nested_function_pointer_alias {using nested = void(*)();};
BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(test_nested_function_pointer_alias);

struct test_nested_template_function_pointer_alias {template<typename> using nested = void(*)();};
BOOST_MPL2_DETAIL_HAS_NESTED_TEMPLATE(test_nested_template_function_pointer_alias);

struct test_nested_function_reference_alias {using nested = void(&)();};
BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(test_nested_function_reference_alias);

struct test_nested_template_function_reference_alias {template<typename> using nested = void(&)();};
BOOST_MPL2_DETAIL_HAS_NESTED_TEMPLATE(test_nested_template_function_reference_alias);

struct test_nested_array_alias {typedef char nested[1];};
BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(test_nested_array_alias);

struct test_nested_array_reference_alias {typedef char (&nested)[1];};
BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(test_nested_array_reference_alias);

struct test_nested_enum {enum nested {};};
BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(test_nested_enum);

struct test_nested_enum_class {enum class nested {};};
BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(test_nested_enum_class);

struct test_nested_enum_value {enum {nested};};
BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(test_nested_enum_value);

struct test_nested_template {template<typename> struct nested;};
BOOST_MPL2_DETAIL_HAS_NESTED_TEMPLATE(test_nested_template);

struct test_nested_variadic_template {template<typename...> struct nested;};
BOOST_MPL2_DETAIL_HAS_NESTED_TEMPLATE(test_nested_variadic_template);

struct test_nested_non_type_template {template<bool> struct nested;};
BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(test_nested_non_type_template);

struct test_nested_mixed_template {template<typename type, type> struct nested;};
BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(test_nested_mixed_template);

struct test_nested_template_template {template<template<typename> class> struct nested;};
BOOST_MPL2_DETAIL_NO_NESTED_TEMPLATE(test_nested_template_template);

int main()
{
    return 0;
}
